#include"core/rs485.hpp"
#include<memory>
#include <unistd.h>
#include<iostream>


std::shared_ptr<RS485> rs485 = nullptr;

int main(int argc, char *argv[]){

    int ret = 0;
    unsigned int count = 0;
    unsigned char senddata = 0x56;
    std::string m_path_gpiochip;
    std::string m_line1;
    int line;
    if (argc > 1)
    {
        m_path_gpiochip =  argv[1];
        std::cout<<"传入的参数1为"<<m_path_gpiochip<<std::endl;
        m_line1 = argv[2];
        line = atoi(m_line1.c_str());
        std::cout<<"传入的参数2为"<<line<<std::endl;
    }
    
    std::shared_ptr<RS485> rs485 = std::make_shared<RS485>(
        "/dev/ttyS2", BaudRate::BAUD_115200, m_path_gpiochip, line);
    if (rs485 == nullptr) {
    std::cout << "Create RS485 Error ." << std::endl;
    return -1;
    }

    ret = rs485->start();
    if (ret !=0 ){
    std::cout << "RS485 Open failed ." << std::endl;
    return -1;
    }

    while (1){
        ret = rs485->send(senddata);
        if (ret ==0 ){
        count++;
        printf("发送的数据为%x，发出%d次\r\n",senddata,count);
        }
        if (count == 100)
        {
            count = 0;
            printf("程序执行结束\r\n");
            return 0;
        }

        
        sleep(1);//linux下，sleep里的单位s，延时1s发一次

        
    }
    
    return 0;

}