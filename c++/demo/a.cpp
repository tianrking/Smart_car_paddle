#include <fstream>
#include <iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
// #include <iostream>
#include <string>

using namespace cv;
Mat src, gray_src, dst;
int t1_val = 302;
int t1_max = 500;
int i = 0;
int t2_val = 480;
int t2_max = 500;
int j = 0;
int PI = 3.14159;
const char *outputtitle = "result image";
void Canny_Demo1(int, void *){};
Mat Canny_Demo(Mat, int, int);
void detect(Mat edge_output_1);


using std::cout;
using std::endl;

int main()
{

    VideoCapture capture(0);
    if (!capture.isOpened())
    {
        std::cout << "can not open video device " << std::endl;
        return 1;
    }

    // double rate = capture.get(CAP_PROP_FPS);
    double width = capture.get(CAP_PROP_FRAME_WIDTH);
    double height = capture.get(CAP_PROP_FRAME_HEIGHT);

    int width_ = 640;
    int height_ = 480;

    capture.set(CV_CAP_PROP_FRAME_WIDTH, width_); //

    capture.set(CV_CAP_PROP_FRAME_HEIGHT, height_);

    Mat frame;

    namedWindow("frame", CV_WINDOW_NORMAL);
    namedWindow(outputtitle, WINDOW_AUTOSIZE);

    while (1)
    {

        if (!capture.read(frame))
        {
            std::cout << "error";
            continue;
        }

        cvtColor(frame, gray_src, COLOR_BGR2GRAY);

		Mat draw_line_block_img_gbr = frame.clone();
        threshold(gray_src, src, 0, 255, THRESH_BINARY | THRESH_OTSU);

        imshow("frame", src);

        //////////////////////////// DRAW LINE BEGIN
        Mat draw_line_block_img = gray_src.clone();
        int image_shape_width = src.rows;  // y
        int image_shape_height = src.cols; // x 
        int image_shape_width_mid = image_shape_width/2;
        int image_shape_height_mid = image_shape_height/2;

        cout << image_shape_height << image_shape_width << src.size() << endl;
        int image_shape_height_step = image_shape_height / 4;
        int image_shape_width_step = image_shape_width / 4;

        // int L_edge[image_shape_width],R_edge[image_shape_width]; /// EDGE LINE BEGIN

        int y_points[] = {image_shape_height_step, image_shape_height_step * 2, image_shape_height_step * 3};
        int y_points_len = sizeof(y_points) / sizeof(y_points[0]);

        for (int ky = 0; ky < y_points_len; ky++)
        {
            for (int i = 0; i < image_shape_width; i++)
            {
                circle(draw_line_block_img_gbr, Point(y_points[ky], i), 1, (0, 255, 100));
            }
        }

        int x_points[] = {image_shape_width_step, image_shape_width_step * 2, image_shape_width_step * 3};
        int x_points_len = sizeof(x_points) / sizeof(x_points[0]);

        for (int i = 0; i < image_shape_height; i++)
        {
            for (int ky = 0; ky < y_points_len; ky++)
            {
                circle(draw_line_block_img_gbr, Point(i, y_points[ky]), 1, (0, 255, 100));
            }
        }

        for (int i = 0; i < image_shape_width; i++)
        {
            circle(draw_line_block_img_gbr, Point(image_shape_height_mid,i), 2, (144, 0, 255));
        }

        // imshow("draw_line_block_img", draw_line_block_img);

        //////////////////////////// DRAW LINE END

        //////////////////////////// EDGE LINE BEGIN

		Mat draw_line_block_img_LINE_BLOCK = src.clone();
        int L_edge[image_shape_width]; int L_edge_index=0;
		int R_edge[image_shape_width]; int R_edge_index=0;

    /////////////////////////////LR BLOCK BEGIN /////
 		// for (int _x = 1; _x < image_shape_width; _x++)
    	// {
        
		// 	for (int _y = 0; _y < image_shape_height ; _y++)
		// 	{
		// 		if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 255))
		// 		{
					
		// 			if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x+1) == 0))
		// 			{
		// 				circle(draw_line_block_img_gbr,Point(_x,_y), 3, (14,152,20));
		// 				L_edge[L_edge_index] = _y;
		// 				// L_edge_index++;
		// 			}
		// 		}

		// 		if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 0))
		// 		{
		// 			if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x+1) == 255))
		// 			{
		// 				circle(draw_line_block_img_gbr,Point(_x,_y), 3, (14, 152, 20));
		// 				R_edge[R_edge_index] = _y;
		// 				// R_edge_index++;
		// 			}
		// 		}
		// 	}   
    	// }

    /////////////////////////////////////////////LR BLOCK END /////
		L_edge_index = 0 ;
		R_edge_index = 0 ;

        int _flag_block_L_Line ;
        int _flag_block_R_Line ;

        for (int _y = 0; _y < image_shape_width ; _y++)
        {
            for (int _x = image_shape_height_mid; _x < image_shape_height; _x++)
            {
                if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 255)){
                    if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x+1) == 0)){
                        if(_flag_block_R_Line == 1)
                        {
                            circle(draw_line_block_img_gbr,Point(_x,_y), 10, (110, 12, 90));
                            R_edge[R_edge_index] = _x;
                            _flag_block_R_Line =  0;
                            R_edge_index++;
                        }
                    }
                }
            }
            for (int _x = image_shape_height_mid; _x > 0; _x--)
            {
                if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 0)){
                    if(((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x+1) == 255)){
                        if(_flag_block_L_Line == 1)
                        {
                            circle(draw_line_block_img_gbr,Point(_x,_y), 10, (110, 12, 90));
                            L_edge[L_edge_index] = _x;
                            _flag_block_L_Line =  0;
                            L_edge_index++;
                        }                     
                    }
                }
            }

            _flag_block_L_Line = 1;
            _flag_block_R_Line = 1;
        }

        
        

		for (int _y = 0; _y < image_shape_width; _y++)
		{
            int mid_point = (L_edge[_y]+R_edge[_y])/2;
            // circle(draw_line_block_img,Point(mid_point,_y), 20, (51, 40, 20));
            circle(draw_line_block_img_gbr,Point(mid_point,_y), 4, (10, 20, 80));

		}

		imshow("draw_line_block_img", draw_line_block_img_gbr);

        //////////////////////////// EDGE LINE END

        if (waitKey(100) == 'W')
            break;
        // // std::cout<<"A";
    }
    // Canny_Demo(0, 0);
    // waitKey(0);
    return 0;
}
// Mat Canny_Demo(Mat src1, int t1_val, int t2_val)
// {
//     // Mat edge_output = src1.clone();
//     Mat src;
//     cvtColor(src1, src, COLOR_BGR2GRAY);
//     Mat element;
//     element = getStructuringElement(MORPH_RECT, Size(3, 3));
//     erode(src, src, element);
//     // std::cout<<t1_val<<" "<<t2_val<<std::endl;
//     // blur(src1, src1, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
//     Canny(src, src, t1_val, t2_val, 3, false);
//     // std::cout<<t1_val<<" "<<t2_val<<std::endl;
//     // imwrite("blur.jpg", edge_output);

//     // dst.create(src.size(), src.type());
//     //将图像的边缘显示，是彩色的边缘。像素为1的时候，将原像素的值copy到上。
//     // src.copyTo(dst, edge_output);
//     //  imshow("Canny", src);
//     //  detect(edge_output);
//     //  std::cout<<" Canny    "<<src.cols<<" "<<src.rows <<std::endl;

//     return src;
// }

// void detect(Mat edge_output)
// {
//     namedWindow("circle", WINDOW_AUTOSIZE);
//     Mat edge_output_draw = edge_output.clone();
//     int avail[10][10];
//     int y_points[] = {680, 620, 580, 520, 440};
//     int y_points_len = sizeof(y_points) / sizeof(int);
//     for (int i = 1; i < 560; i++)
//     {
//         // break;
//         for (int ky = 0; ky < y_points_len; ky++)
//         {
//             if (((int)edge_output.at<uchar>(y_points[ky], i) == 255))
//             {
//                 avail[ky][j] = i;
//                 j++;
//                 if (j == 2)
//                 {
//                     j = 0;
//                 }
//                 // std::cout<<i<<"\n";
//                 // std::cout<<y_points[ky];
//                 circle(edge_output_draw, Point(i, y_points[ky]), 10, (0, 255, 100));

//                 // std::cout<<(avail[2][0]+avail[2][1])/2<<" "<<(avail[0][0]+avail[0][1])/2<<std::endl;
//             }
//         }
//         // std::cout<<endl;
//     }
//     double a = atan2((avail[2][0] + avail[2][1]) / 2 - (avail[0][0] + avail[0][1]) / 2, 100);
//     std::cout << a * 180 / PI << " ";
//     // std::cout<<(avail[2][0]+avail[2][1])/2<<" "<<(avail[0][0]+avail[0][1])/2<<std::endl;/
//     cv::Point start1 = cv::Point((avail[0][0] + avail[0][1]) / 2, 680);
//     cv::Point end1 = cv::Point((avail[2][0] + avail[2][1]) / 2, 580);
//     cv::arrowedLine(edge_output_draw, start1, end1, cv::Scalar(255, 255, 0), 4, 8, 0);
//     cv::Point start2 = cv::Point((avail[2][0] + avail[2][1]) / 2, 580);
//     cv::Point end2 = cv::Point((avail[4][0] + avail[4][1]) / 2, 440);
//     cv::arrowedLine(edge_output_draw, start2, end2, cv::Scalar(255, 255, 0), 4, 8, 0);
//     imshow("circle", edge_output_draw);
// }