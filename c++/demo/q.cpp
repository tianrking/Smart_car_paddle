

#include <fstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(){
    Mat aa = imread("/media/root/Data/Desktop/Smart_car_paddle-main/image/22.png");
    Mat img_gray;
    cvtColor(aa, img_gray, COLOR_BGR2GRAY);//转灰度
    Mat thresh;
    threshold(img_gray,thresh,150,255,THRESH_BINARY);
    imwrite("image_thres1.jpg", thresh);
    destroyAllWindows();
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    for (int i=0;i<contours.size();i++)
	{
		for (int j=0;j<contours[i].size();j++)
		{
			cout<<contours[i][j].x<<"	"<<contours[i][j].y<<endl;
			ofstream f;
			f.open("E:/坐标轮廓线.txt",ios::out|ios::app);
			f<<contours[i][j].x<<"	"<<contours[i][j].y<<endl;
		}
	}
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
// draw contours on the original image
    Mat image_copy = aa.clone();
    drawContours(image_copy, contours, -1, Scalar(138,43,226),3);//画线
    
    imshow("None approximation", image_copy);
    waitKey(0);
    imwrite("contours_none_image1.jpg", image_copy);
    destroyAllWindows();
    Mat image_copy3 = aa.clone();
    for(int i=0; i<contours.size(); i=i+1){
        for (int j=0; j<contours[i].size(); j=j+1){
         circle(image_copy3, (contours[i][0], contours[i][1]), 2, Scalar(0, 255, 0), 2);
         }
      }
    imshow("CHAIN_APPROX_SIMPLE Point only", image_copy3);
    waitKey(0);
    imwrite("contour_point_simple.jpg", image_copy3);
    return 0;
}