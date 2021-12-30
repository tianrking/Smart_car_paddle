#include "core/stock.hpp"
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <signal.h>
#include "core/detection.hpp"

#include <unistd.h>

std::shared_ptr<Driver> driver = nullptr;
int main()
{
    driver = std::make_shared<Driver>("/dev/ttyUSB0", BaudRate::BAUD_115200, false,true);
    if (driver == nullptr) 
    {
    std::cout << "Create Driver Error ." << std::endl;
    return -1;
    }
    int ret = driver->open();
    if (ret != 0)
    {
    std::cout << "Driver Open failed ." << std::endl;
    return -1;
    }

    while (1)
    {
        driver->move(0.2);
        sleep(1);//linux下，sleep里的单位s，延时1s发一次
    }
    return 0;
    

}