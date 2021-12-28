#pragma once
#include <opencv2/core.hpp> // Basic OpenCV structures (cv::Mat)
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include "../common/model_config.hpp"
#include <paddle_api.h>
#include <paddle_image_preprocess.h>
#include "core/capture.hpp"
using namespace std;
using namespace cv;
using namespace paddle::lite_api;
typedef paddle::lite_api::Tensor Tensor;
typedef paddle::lite_api::DataLayoutType LayoutType;
typedef paddle::lite::utils::cv::FlipParam FlipParam;
typedef paddle::lite::utils::cv::TransParam TransParam;
typedef paddle::lite::utils::cv::ImageFormat ImageFormat;
typedef paddle::lite::utils::cv::ImagePreprocess ImagePreprocess;

inline void fpga_preprocess(cv::Mat img, std::shared_ptr<ModelConfig> &config,
                            std::unique_ptr<Tensor> &tensor) {

  int width = img.cols;
  int height = img.rows;

  if (height > 1080) {
    float fx = img.cols / config->input_width;
    float fy = img.rows / config->input_height;
    Mat resize_mat;
    resize(img, resize_mat, Size(config->input_width, config->input_height), fx,
           fy);
    img = resize_mat;
    height = img.rows;
    width = img.cols;
  }

  uint8_t *src = (uint8_t *)malloc(3 * width * height);
  if (img.isContinuous()) {
    memcpy(src, img.data, 3 * width * height * sizeof(uint8_t));
  } else {
    uint8_t *img_data = img.data;
    for (int i = 0; i < img.rows; ++i) {
      src = src + i * (width * 3);
      img_data = img_data + i * (width * 3);
      memcpy(src, img_data, width * 3 * sizeof(uint8_t));
    }
  }
  TransParam tparam;
  tparam.ih = img.rows;
  tparam.iw = img.cols;
  tparam.oh = config->input_height;
  tparam.ow = config->input_width;

  ImagePreprocess image_preprocess(
      ImageFormat::BGR,
      config->format == "RGB" ? ImageFormat::RGB : ImageFormat::BGR, tparam);
  image_preprocess.image_to_tensor(src, tensor.get(), LayoutType::kNHWC,
                                   config->means, config->scales);
  free(src);
}

class TraditionalPreprocessor {
  public:
  TraditionalPreprocessor() {}  
  Mat ImagePreprocess(Mat &frame) {
    Mat imageGray,imageBinary;
    //GaussianBlur(frame, output, cv::Size(3, 3), 0, 0);		//高斯降噪

    cvtColor(frame, imageGray, COLOR_BGR2GRAY);  				//RGB转灰度图
    // imshow("imageGray", imageGray);

    blur(imageGray, imageGray, Size(3, 3));						//平滑图像

    //int th = GetOSTUThreshold(gray);
    threshold(imageGray, imageBinary, 0, 255, THRESH_OTSU);		//OTSU二值化方法
    // imshow("imageBinary", imageBinary);

    return imageBinary;
  }

  Mat LaneEdgeDetection(Mat &imageBinary) {

    Mat imageEdge = Mat::zeros(imageBinary.size(), CV_8UC3);

    vector<vector<Point>> points;	//赛道轮廓搜索
    vector<Point> pointsEdge;		//赛道边沿点
    findContours(imageBinary, points, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    //绘制轮廓

    for (uint16_t i = 0; i < points.size(); i++)//遍历
    {
        //计算面积和周长
        //double length = arcLength(points[i], true);
        double area = contourArea(points[i]);

        vector<vector<Point>> pointsPoly(points.size());		//多边形点集
        approxPolyDP(points[i], pointsPoly[i], 4, true);		//多边形逼近

        if(pointsPoly[i].size() > 8 && area >120000) 			//多边形边大于6绘制边界 && 白块面积区域>MinNum
        {
            // Head on Lane
            if(imageBinary.at<uchar>(320, 400) == 255)
                drawContours(imageEdge, points, i, Scalar(0, 255, 0), 2);
            else
                drawContours(imageEdge, points, i, Scalar(0, 0, 255), 2);
            for (size_t n = 0; n < points[i].size(); n++)
            {
                pointsEdge.push_back(points[i].at(n));		//存储有效边缘点
            }
        }
    }

    //赛道左右边缘提取
    //vector<Point> point = find_if(pointsEdge.begin(),pointsEdge.end(), [&](Point p) { return p.y == p.x;} );
    //cout << "contoursEdge size:" << contoursEdge.size() << endl;
    if(imageBinary.at<uchar>(320, 400) == 255)
        floodFill(imageEdge, cv::Point(320,400), Scalar(0, 0, 255));
    else
        floodFill(imageEdge, cv::Point(320,400), Scalar(255, 0, 0));
    // floodFill(imageEdge, cv::Point(320,400), Scalar(0, 0, 255));

    //imshow("imageEdge", imageEdge);

    return imageEdge;
  }


};

