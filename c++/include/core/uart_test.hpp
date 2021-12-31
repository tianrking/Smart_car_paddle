#include "util/stop_watch.hpp"
#include <iostream>
#include <libserial/SerialPort.h>
#include <memory>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <thread>

using namespace LibSerial;

class Driver
{
    #define PKT_HEAD 0x42
    #define PKT_CMD  0x01
    #define PKT_TAIL 0x10

    //1字节对齐
    #pragma pack(1)
    //上位机与下位机通讯的协议结构体
    struct Pkt {
        uint8_t head;
        uint8_t cmd;
        uint8_t data;
        uint16_t check_sum;//校验和=head+cmd+data
        uint8_t tail;
    };
    #pragma pack()

private:
    std::shared_ptr<SerialPort> _serial_port = nullptr;
    std::string _port_name;
    BaudRate _bps;

private:
    uint16_t check_sum(Pkt *pkt) //校验和计算
    {
        uint16_t check_sum = 0;
        check_sum += (uint16_t)pkt->head;
        check_sum += (uint16_t)pkt->cmd;
        check_sum += (uint16_t)pkt->data;
        return check_sum;
    }
    int recv(unsigned char &charBuffer, size_t msTimeout = 0) 
    {
        try {
        // Read a single byte of data from the serial ports.
        //从串口读取一个数据
        _serial_port->ReadByte(charBuffer, msTimeout);

        } catch (const ReadTimeout &) {
            std::cerr << "The ReadByte() call has timed out." << std::endl;
            return -2;
        } catch (const NotOpen &) {
            std::cerr << "Port Not Open ..." << std::endl;
            return -1;
        }
        return 0;
    };
public:
    Driver(const std::string &port_name, BaudRate bps): _port_name(port_name), _bps(bps){};
    ~Driver() { close(); };

public:
    int open(){
        _serial_port = std::make_shared<SerialPort>();
        if (_serial_port == nullptr) {
        std::cerr << "Serial Create Failed ." << std::endl;
        return -1;
        } 
        try {
        _serial_port->Open(_port_name);//打开串口
        _serial_port->SetBaudRate(_bps);//设置波特率
        _serial_port->SetCharacterSize(CharacterSize::CHAR_SIZE_8);//8位数据位
        _serial_port->SetFlowControl(FlowControl::FLOW_CONTROL_NONE);//设置流控
        _serial_port->SetParity(Parity::PARITY_NONE);//无校验
        _serial_port->SetStopBits(StopBits::STOP_BITS_1);//1个停止位
        } catch (const OpenFailed &) {
        std::cerr << "Serial port: " << _port_name << "open failed ..."
                    << std::endl;
        return -2;
        } catch (const AlreadyOpen &) {
        std::cerr << "Serial port: " << _port_name << "open failed ..."
                    << std::endl;
        return -3;
        } catch (...) {
        std::cerr << "Serial port: " << _port_name << " recv exception ..."
                    << std::endl;
        return -4;
        }
        return 0;
    };

    int senddata(uint8_t data)
    {
        DataBuffer pkt_buf(sizeof(Pkt));
        Pkt *pkt = (Pkt *)&pkt_buf[0];
        
        pkt->head = PKT_HEAD;
        pkt->cmd = PKT_CMD;
        pkt->data = (uint16_t)data;
        pkt->check_sum = check_sum(pkt);
        pkt->tail = PKT_TAIL;

        try {
        _serial_port->Write(pkt_buf);//写数据到串口
        } catch (const std::runtime_error &) {
        std::cerr << "The Write() runtime_error." << std::endl;
        return -1;
        } catch (const NotOpen &) {
        std::cerr << "Port Not Open ..." << std::endl;
        return -1;
        }
        _serial_port->DrainWriteBuffer();//等待，直到写缓冲区耗尽，然后返回。
        return 0;
    }

    int recvdata(unsigned char &charBuffer, size_t msTimeout){return recv(charBuffer,msTimeout);}

        
    void close() 
    {
        if (_serial_port != nullptr) {
        _serial_port->Close();
        _serial_port = nullptr;
        }
    };







};

