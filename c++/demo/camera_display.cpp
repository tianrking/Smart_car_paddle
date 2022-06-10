

#include <fstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {

  
  /*注意：
    使用 0 和 /dev/video0 的分辨率不同：
      0           : opencv 内部的采集，可能是基于 V4L2, 分辨率：1280 * 960
      /dev/video0 : 基于Gstreamer ， 分辨率：640 * 480
  */
  VideoCapture capture("/dev/video1");
  if (!capture.isOpened()) {
    std::cout << "can not open video device "  << std::endl;
    return 1;
  }

  capture.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
  // double rate = capture.get(CAP_PROP_FPS);
  // double width = capture.get(CAP_PROP_FRAME_WIDTH);
  // double height = capture.get(CAP_PROP_FRAME_HEIGHT);
  capture.set(CV_CAP_PROP_FPS, 300);
  capture.set(CV_CAP_PROP_FRAME_WIDTH,300);
  capture.set(CV_CAP_PROP_FRAME_HEIGHT, 200);
  std::string window_name = "usbcamera";
  namedWindow(window_name, WINDOW_NORMAL);


  int width_ = 640;
  int height_ = 480;
  double fps=30;
  double t;
  Mat frame;

  static int kk = 1;
  while (1) {
    //  t = (double)cv::getTickCount();
    //     if (!capture.read(frame))
    //     {
    //         std::cout << "error";
    //         continue;
    //     }

    //     t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
		// fps = 1.0 / t ;
		// cout<< t <<endl;
    if (!capture.read(frame)) {
      std::cout << "no video frame" << std::endl;
      continue;


    }


    imshow(window_name, frame);
    waitKey(1);
  }
  capture.release();
}