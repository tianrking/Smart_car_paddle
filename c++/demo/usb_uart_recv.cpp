#include "core/uart_test.hpp"
#include <fstream>
#include <iostream> 
#include <unistd.h>
std::shared_ptr<Driver> driver = nullptr;
using namespace LibSerial;

int main(int argc, char *argv[]) 
{  
    int ret = 0;

    #if 0   //与下文接收一个字节的数据并打印相关
    size_t timeout_ms = 5000;//超时为5000ms.
    uint8_t recv_data;
    #endif

    DataBuffer dataBuffer(sizeof(Pkt));
    size_t numberOfBytes = 6;   //接收数据的固定长度
    size_t msTimeout = 5000;    //阻塞时间5000ms

    //USB转串口的设备名为/dev/ttyUSB0
    driver = std::make_shared<Driver>("/dev/ttyUSB0", BaudRate::BAUD_115200);
    if (driver == nullptr) 
    {
    std::cout << "Create Driver Error ." << std::endl;
    return -1;
    }
    //串口初始化，打开串口设备及配置串口数据格式
    ret = driver->open();
    if (ret != 0)
    {
    std::cout << "Driver Open failed ." << std::endl;
    return -1;
    }

    while (1)
    {
        #if 0
        //循环阻塞接收一字节数据并打印
        ret = driver->recvdata(recv_data, timeout_ms);
        if(ret == 0)
        {
            printf("The received data is %x\r\n",recv_data);
        }
        #endif
        
        //循环阻塞接收固定长度的数据并打印
        ret = driver->recvpacketdata(dataBuffer,numberOfBytes,msTimeout);
        if(ret == 0)
        { 
            Pkt *pkt = (Pkt *)&dataBuffer[0];
            printf("接受到的数据为 %x,%x,%x,%x,%x\r\n",pkt->head,pkt->cmd,pkt->data,pkt->check_sum,pkt->tail);
        }
        
    }

    return 0;
    


}