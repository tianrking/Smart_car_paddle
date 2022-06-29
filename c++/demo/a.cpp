#include "core/uart_test.hpp"
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <math.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <sstream>

#include<memory>
#include <unistd.h>
#include <iomanip>

using namespace cv;
Mat src, gray_src, dst;
int t1_val = 302;
int t1_max = 500;
int i = 0;
int t2_val = 480;
int t2_max = 500;
int j = 0;
int PI = 3.14159;
int endline;
int state = 11;
///////各种flag///////////
int flag_lose = 0; //无左右边线
int flag_full = 0; //无左右边线
int flag_out1;     //出库
int flag_ahead;    //直线
const char *outputtitle = "result image";

using std::cout;
using std::endl;
using std::string;
std::shared_ptr<Driver> driver = nullptr;

///////////参数
float Turn_Kp=3.0;//3.0 3.0
float Turn_Kd=2.8;//2.5 3.0

float Turn_Pwm_Control(float error)
{
    static float T_out,Last_error;
	T_out=error*Turn_Kp+Turn_Kd*(error-Last_error);
	Last_error=error;
	if(T_out>80)
	{
		T_out=80;
	}
	if(T_out<-90)
	{
		T_out=-90;
	}
	return T_out;
}


int main(int argc, char *argv[])
{

    // driver = std::make_shared<Driver>("/dev/ttyUSB0", BaudRate::BAUD_115200);
    driver = std::make_shared<Driver>("/dev/ttyPS1", BaudRate::BAUD_115200);
    if (driver == nullptr)
    {
        std::cout << "Create Driver Error ." << std::endl;
        return -1;
    }
    //串口初始化，打开串口设备及配置串口数据格式
    int ret = driver->open();
    if (ret != 0)
    {
        std::cout << "Driver Open failed ." << std::endl;
        return -1;
    }
    VideoCapture capture("/dev/video0");
    if (!capture.isOpened())
    {
        std::cout << "can not open video device " << std::endl;
        return 1;
    }

   

    capture.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
    // double width = capture.get(CAP_PROP_FRAME_WIDTH);
    // double height = capture.get(CAP_PROP_FRAME_HEIGHT);
    capture.set(CV_CAP_PROP_FPS, 300);
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 300);//300 200
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 200);
    std::string window_name = "usbcamera";

    namedWindow(window_name, WINDOW_NORMAL);
    int width_ = 640;
    int height_ = 480;
    double fps = 30;
    double t;
    Mat frame;
    // namedWindow(outputtitle, CV_WINDOW_NORMAL);
    while (1)
    {
        double rate = capture.get(CAP_PROP_FPS);
        cout << rate << endl;
        if (!capture.read(frame))
        {
            std::cout << "no video frame" << std::endl;
            continue;
        }
        cvtColor(frame, gray_src, COLOR_BGR2GRAY);

        Mat draw_line_block_img_gbr = frame.clone();
        threshold(gray_src, src, 0, 255, THRESH_BINARY | THRESH_OTSU);

        // imshow("frame", src);

        //////////////////////////// DRAW LINE BEGIN////////////////
        Mat draw_line_block_img = gray_src.clone();
        int image_shape_width = src.rows;  // y
        int image_shape_height = src.cols; // x
        int image_shape_width_mid = image_shape_width / 2;
        int image_shape_height_mid = image_shape_height / 2;

        // cout << image_shape_height << image_shape_width << src.size() << endl;
        int image_shape_height_step = image_shape_height / 4;
        int image_shape_width_step = image_shape_width / 4;

        // int L_edge[image_shape_width],R_edge[image_shape_width]; /// EDGE LINE BEGIN

        int y_points[] = {image_shape_height_step, image_shape_height_step * 2, image_shape_height_step * 3};
        int y_points_len = sizeof(y_points) / sizeof(y_points[0]);

        int x_points[] = {image_shape_width_step, image_shape_width_step * 2, image_shape_width_step * 3};
        int x_points_len = sizeof(x_points) / sizeof(x_points[0]);

        for (int i = 0; i < image_shape_height; i++)
        {
            for (int ky = 0; ky < y_points_len; ky++)
            {
                circle(draw_line_block_img_gbr, Point(i, y_points[ky]), 0.5, (0, 255, 100));
            }
        }
        // imshow("draw_line_block_img", draw_line_block_img);

        //////////////////////////// DRAW LINE END

        //////////////////////////// EDGE LINE BEGIN
        Mat draw_line_block_img_LINE_BLOCK = src.clone();
        int L_edge[image_shape_width];
        int L_edge_index = 0;
        int R_edge[image_shape_width];
        int R_edge_index = 0;
        int M_edge[image_shape_width];
        int T_edge;
        L_edge_index = 0;
        R_edge_index = 0;
        int endline;
        int white_account = 0;
        int _flag_block_L_Line;
        int _flag_block_R_Line;
        // image_shape_heigh是高，image_shape_width是长

        for (int _y = image_shape_width / 10; _y <= image_shape_width / 2; _y++) //顶线判断
        {
            if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, image_shape_height / 2) == 0) && ((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y + 1, image_shape_height) == 255))
                if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y + 4, image_shape_height / 2) == 255) && ((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y - 3, image_shape_height / 2) == 0))
                {
                    T_edge = _y;
                    break;
                }
        }
        for (int _x = 0; _x <= image_shape_height; _x++)
        {
            circle(draw_line_block_img_gbr, Point(_x, T_edge), 0.8, (10, 12, 90)); //顶线
        }

        for (int _y = image_shape_width / 6; _y <= image_shape_width; _y++)
        {
            for (int _x = image_shape_height_mid / 2; _x <= image_shape_height; _x++)
            {
                if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x + 1) == 0))
                {
                    if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 255) && ((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x - 1) == 255))
                    {
                        if (_flag_block_R_Line == 1)
                        {
                            if (_x >= image_shape_height-2)
                            {
                                _x == image_shape_height;
                            }
                            circle(draw_line_block_img_gbr, Point(_x+1, _y), 3, (110, 12, 90)); //右边线
                            R_edge[_y] = _x+1;
                            _flag_block_R_Line = 0;
                            break;
                        }
                    }
                }
            }

            for (int _x = image_shape_height_mid * 3 / 2; _x >= 0; _x--)
            {
                if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x - 1) == 0))
                {
                    if (((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x) == 255) && ((int)draw_line_block_img_LINE_BLOCK.at<uchar>(_y, _x + 1) == 255))
                    {
                        if (_flag_block_L_Line == 1)
                        {
                            if (_x <= 2)
                            {
                                _x == 0;
                            }
                            circle(draw_line_block_img_gbr, Point(_x, _y), 3, (110, 12, 90)); // 左边线
                            L_edge[_y] = _x;
                            _flag_block_L_Line = 0;
                        }
                    }
                }
            }

            _flag_block_L_Line = 1;
            _flag_block_R_Line = 1;
        }
        
        /////////////////////////////////////////////////////////功能线////////////////////////////////////////////////////////////
        for (int i = 0; i < image_shape_width; i++)
        {
            circle(draw_line_block_img_gbr, Point(image_shape_height / 2, i), 1, (14, 245, 20)); //屏幕中线
        }
        for (int _y = image_shape_width * 3 / 24; _y <= image_shape_width / 6; _y++)
        {
            M_edge[_y] = (L_edge[_y] + R_edge[_y]) / 2;
            circle(draw_line_block_img_gbr, Point(M_edge[_y], _y), 1.5, (110, 245, 200)); //中线——前
        }
        for (int _y = image_shape_width / 6; _y < image_shape_width; _y++)
        {
            M_edge[_y] = (L_edge[_y] + R_edge[_y]) / 2;
            if ((M_edge[_y] <= image_shape_height / 5) || (M_edge[_y] >= image_shape_height * 4 / 5))
            {
                if(flag_lose==0)
                {
                    M_edge[_y] = image_shape_height / 2; //两边空白时自动补中线为屏幕中线
                    flag_lose=1;
                }
            }
            else
                flag_lose = 0;
            circle(draw_line_block_img_gbr, Point(M_edge[_y], _y), 1.5, (110, 245, 200)); //中线
        }
        ////////////////////////////////偏差处理/////////////////////////////////////
        int _LINE_return = image_shape_width *0.65;
        int _LINE_return_1 = image_shape_width * 0.8;
        int _LINE_return_2 = image_shape_width * 0.9;

        int error = image_shape_height_mid - M_edge[_LINE_return];
        int error_1 = image_shape_height_mid - M_edge[_LINE_return_1];
        int error_2 = image_shape_height_mid - M_edge[_LINE_return_2];
        error = (1.0 * error + 1.1 * error_1 + 1.1 * error_2)/3;
        error=Turn_Pwm_Control(error);
        if ((25 > error > 0) || (-20 < error < 0))
            error = 0.85 * error;
        else if ((error > 60) || (error < -60))
            error = 0.95 * error;
        ////////////////////
        for(int _x = 0; _x <= image_shape_height; _x++)
        {
            if((int)draw_line_block_img_LINE_BLOCK.at<uchar>(image_shape_width/2, _x) == 255)
            white_account++;

        }
        if(white_account>0.5*image_shape_height)
            {
                // flag_full=1;
                state = 11;
                white_account=0;
            }
            else if((white_account<0.1*image_shape_height)&&(-20<error<20))
            {
                state = 22;
                white_account=0;
            }








        circle(draw_line_block_img_gbr, Point(image_shape_height_mid, _LINE_return), 3, (255, 0, 0), 2);   //检测线
        circle(draw_line_block_img_gbr, Point(image_shape_height_mid, _LINE_return_1), 3, (255, 0, 0), 2); 
        circle(draw_line_block_img_gbr, Point(image_shape_height_mid, _LINE_return_2), 3, (255, 0, 0), 2); 
        circle(draw_line_block_img_gbr, Point((M_edge[_LINE_return]), _LINE_return), 3, (255, 0, 0), 2);

        int font_face = cv::FONT_HERSHEY_COMPLEX;
        double font_scale = 1;
        int thickness = 1;

        cv::Point origin;
        origin.x = 10;
        origin.y = 20;
        string disp = std::to_string(error);

        int speed = 0 ;
        if((error>40)||(error<-40))
        {
            speed=speed-10;
        }
        else if(-20<=error<=20)
        {
            speed=speed+10;
        }
        // speed=speed>200?200:speed;
        // speed=speed<-200?-200:speed;
        
        /////////////////////////////////////////////串口发送/////////////////////////////////////
        driver->senddata(state);
        driver->senddata((size_t)error);
        // driver->senddata((size_t)speed);
        /////
        cv::putText(draw_line_block_img_gbr, disp, origin, font_face, font_scale, cv::Scalar(0, 255, 255), thickness, 8, 0);
        cv::namedWindow("draw_line_block_img", CV_WINDOW_NORMAL); // CV_WINDOW_NORMAL就是0
        cv::imshow("draw_line_block_img", draw_line_block_img_gbr);
        imshow(window_name, frame);
        // if (waitKey(45) == 'W')
        //     break;
        waitKey(1);
    }
    capture.release();
    return 0;
}