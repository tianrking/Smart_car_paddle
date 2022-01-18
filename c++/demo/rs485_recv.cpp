#include"core/rs485.hpp"
#include<memory>
#include <unistd.h>

std::shared_ptr<RS485> rs485 = nullptr;

int main(int argc, char *argv[]) {  
    int ret = 0;
    unsigned int cout = 0;
    //与下文接收一个字节的数据并打印相关
    size_t timeout_ms = 5000;//阻塞时间5000ms。
    uint8_t recv_data;

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
        //循环阻塞接收一字节数据并打印
        ret = rs485->recv(recv_data, timeout_ms);
        if(ret == 0){
            cout++;
            printf("接收到的数据为%x,已经接受到了%d次\r\n",recv_data,cout);
        }
        if (cout == 200)
        {
            cout = 0;
            printf("程序执行结束\r\n");
            return 0;
        }
        
    }

    return 0;

}