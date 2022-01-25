#include"core/rs485.hpp"
#include<memory>
#include <unistd.h>
#include<iostream>
#include <iomanip>


std::shared_ptr<RS485> rs485 = nullptr;
using namespace std;
int main(int argc, char *argv[]){

    int ret = 0;
    unsigned int count = 0;     //计数
    unsigned char senddata = 0x56;    //要发送的数据
    
    std::shared_ptr<RS485> rs485 = std::make_shared<RS485>(
        "/dev/ttyS2", BaudRate::BAUD_115200,"/dev/gpiochip0" , 81);
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
        //485通讯发送数据
        ret = rs485->send(senddata);
        if (ret ==0 ){
        count++;
        std::cout <<"The data sent is " << hex << int(senddata) 
                    << ", sent "<< dec <<count << " times. "<<std::endl;
        }else{
            std::cout <<"----------------fail in send----------------"<<std::endl;
            exit(-1);
        }
        sleep(1);//linux下，sleep里的单位s，延时1s发一次
        
    }
    
    return 0;

}