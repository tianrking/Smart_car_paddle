#include "core/uart_test.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>

std::shared_ptr<Driver> driver = nullptr;

int main(int argc, char *argv[]) 
{   //USB转串口的设备名为/dev/ttyUSB0
    driver = std::make_shared<Driver>("/dev/ttyUSB0", BaudRate::BAUD_115200);
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

    while (1)
    {
        //循环延时1s发送
        driver->senddata(0xFF);
        sleep(1);//linux下，sleep里的单位s，延时1s发一次
    }
    return 0;
    


}