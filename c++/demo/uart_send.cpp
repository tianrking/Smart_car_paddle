#include "core/uart.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>

std::shared_ptr<Driver> driver = nullptr;

int main(int argc, char *argv[]) 
{   //预留串口的设备名为/dev/ttyPS1
    driver = std::make_shared<Driver>("/dev/ttyPS1", BaudRate::BAUD_115200, false,true);
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