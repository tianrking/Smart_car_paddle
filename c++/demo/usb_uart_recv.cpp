#include "core/uart_test.hpp"
#include <fstream>
#include <iostream>
#include <unistd.h>

std::shared_ptr<Driver> driver = nullptr;

int main(int argc, char *argv[]) 
{  
    int ret = 0;
    size_t timeout_ms = 5000;//超时为5000ms，1ms,10000次发送
    uint8_t recv_data;
    //预留串口的设备名为/dev/ttyPS1
    driver = std::make_shared<Driver>("/dev/ttyUSB0", BaudRate::BAUD_115200);
    if (driver == nullptr) 
    {
    std::cout << "Create Driver Error ." << std::endl;
    return -1;
    }
    ret = driver->open();
    if (ret != 0)
    {
    std::cout << "Driver Open failed ." << std::endl;
    return -1;
    }

    while (1)
    {
        ret = driver->recvdata(recv_data, timeout_ms);
        if(ret == 0)
        {
            printf("The received data is %x\r\n",recv_data);
        }
    }
    return 0;
    


}