#include"core/rs485.hpp"
#include<memory>
#include <unistd.h>
#include <iomanip>

std::shared_ptr<RS485> rs485 = nullptr;
using namespace std;
int main(int argc, char *argv[]) {  
    int ret = 0;
    unsigned int count = 0;
    //与下文接收一个字节的数据并打印相关
    size_t timeout_ms = 5000;//阻塞时间5000ms。
    uint8_t recv_data;   //存放接收到的数据

    std::shared_ptr<RS485> rs485 = std::make_shared<RS485>(
        "/dev/ttyS2", BaudRate::BAUD_115200, "/dev/gpiochip0", 81);
    if (rs485 == nullptr) {
    std::cout << "Create RS485 Error ." << std::endl;
    return -1;
    }
    //启动485通讯
    ret = rs485->start();
    if (ret !=0 ){
    std::cout << "RS485 Open failed ." << std::endl;
    return -1;
    }

    while (1){
        //循环阻塞接收一字节数据并打印
        ret = rs485->recv(recv_data, timeout_ms);
        if(ret == 0){
            count++;
            std::cout<<" The data received is "<< hex << int(recv_data) 
                        <<" , and has been received "<< dec << count << std::endl;
        }        
    }

    return 0;

}