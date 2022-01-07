# SmartCarToolKits

将SmartCarToolKits工程放到/root/workspace/下


串口或者网口进入Edgeboard中linux系统。（具体详见`EdgeBoard 可视化访问的方法说明`手册）

## SmartCarToolKits/c++

### camera2video

#### 依赖的源文件

`SmartCarToolKits/c++/demo`中：`camera2video.cpp`

#### 功能介绍：

将采集到的图片，转换成灰度视频

#### 准备工作：

准备要转换的图片文件夹放到`/root/workspace/`路径下，以命名为`train`为例（可任意命名）。

#### 编译方法：

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make camera2video -j
```

会在`build`目录下产生一个`camera2video`的应用程序

#### 使用方式：

在build目录下执行 `./camera2video 图片文件夹的路径`

```sh
./camera2video /root/workspace/train/
```

#### 产生效果：

会在`build`目录下得到由`train`中图片组成的灰度的`camera.avi`文件





### camera_display

#### 依赖的源文件

`SmartCarToolKits/c++/demo`中的`camera_display.cpp`

#### 功能介绍：

实时显示，外接显示器直接显示或者通过vnc显示

#### 准备工作：

连接好网口。

将摄像头插入`EdgeBoard`上的`USB`口中。

连接好显示器，或者通过vnc显示（具体详见`EdgeBoard 可视化访问的方法说明`手册）


#### 编译方法：

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make camera_display -j
```

会在`build`目录下产生一个`camera_display`的应用程序

#### 使用方式：

在`build`目录下执行 ：

```sh
./camera_display
```

#### 产生效果：

可以在`VNC`或者显示器中，看到一个名为`usbcamera`的视频框。



### rgb_mat2gray_array

#### 依赖的源文件：

`SmartCarToolKits/c++/demo`中：`rgb_mat2gray_array.cpp`

#### 功能介绍：

将一张`RGB`图转换成灰度图

#### 准备工作：

将准备要转换的图片文件夹放到`/root/workspace/`路径下，以命名为`train`为例（可任意命名）。

假设`train`中的图片以0.jpg，1.jpg，2.jpg ...等格式递增。

#### 编译方法：

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make rgb_mat2gray_array -j
```

会在`build`目录下产生一个`rgb_mat2gray_array`的应用程序

#### 使用方式：

在`build`目录下执行 `./rgb_mat2gray_array 图片的路径`

```sh
./rgb_mat2gray_array /root/workspace/train/0.jpg
```

#### 产生效果：

会在`build`目录下得到`0.jpg`灰度的文件，命名为`gray.jpg`



### predict

#### 依赖的源文件：

`SmartCarToolKits/c++/demo`中：`predict.cpp.cpp`

#### 功能介绍：

查看训练的模型识别情况。

#### 准备工作：

将想要识别的地标放到赛道。

将小车放到赛道上，

连接好网口

将摄像头插入`EdgeBoard`上的`USB`口中。

连接好显示器，打开VNC。（具体详见`EdgeBoard 可视化访问的方法说明`手册）

将准备含有模型的文件夹放到`/root/workspace/`路径下，以命名为`mobilenet-ssd`为例（可任意命名）。

#### 模型文件夹：

以`mobilenet-ssd`为例，包含四个文件

`config.json`、`label_list.txt`、`mobilenet_v2_ssd-model`、`mobilenet_v2_ssd-params`

`config.json`中内容：

```sh
{	
	"model_file_name":"mobilenet_v2_ssd-model",
	"params_file_name":"mobilenet_v2_ssd-params",

	"labels_file_name":"label_list.txt",

	"format":"RGB",
	"input_width":300,
	"input_height":300,
		
	"mean":[127.5,127.5,127.5],
    "scale":[0.007843,0.007843,0.007843],
	"threshold":0.5
}
```

**参数说明：**

`model_file_name`：指定模型文件的名字

`params_file_name`：指定模型参数文件的名字

`labels_file_name`：指定标签文件的名字



`label_list.txt`中内容：

```sh
background
Exit Two
Exit One
Pedestrian
Safety Cone
Gas Station
Prohibitory
Flooded Area
```

按照顺序排列训练的模型标签名字。

#### 编译方法：

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make predict -j
```

会在`build`目录下产生一个`predict`的应用程序

#### 使用方式：

在`build`目录下执行 `./predict 模型所在文件夹的路径`

```sh
./rgb_mat2gray_array /root/workspace/SmartCarToolKits/mobilenet-ssd/
```

#### 产生效果：

在`VNC`或者显示器中查看自己训练的模型的识别情况。







## SmartCarToolKits/python

进入到`SmartCarToolKits/python`文件夹中

```
cd /root/workspace/SmartCarToolKits/python/
```

### capture.py

#### 功能介绍：

通过摄像头抓取图片并保存到执行目录下

#### 准备工作：

将摄像头插入到`Edgeboard`上的`USB`口中

#### 使用方式：

```sh
cd /root/workspace/SmartCarToolKits/python/
python3  capture.py
```

#### 产生效果：

在`python`文件夹当中生成一个`0.jpg`的文件，此文件为当前摄像头采集的图片。



### collect.py

#### 功能介绍：

测试手柄驱动：

#### 准备工作：

将摄像头插入到`Edgeboard`上的`USB`口中。

将手柄插入到`Edgeboard`上的`USB`口中。

由于`Edgeboard`资源限制。需要用到`USB`扩展口。将`USB`扩展口插入到`Edgeboard`上。摄像头与手柄在扩展口上插上即可。

关于适配的`USB`扩展口与摄像头，手柄的购买链接，已经同步出来了。（具体详见`EdgeBoard 可视化访问的方法说明`）

#### 使用方式

执行此程序前先将小车架起来，因为执行此程序，小车会动起来。

```sh
cd /root/workspace/SmartCarToolKits/python/
python3  collect.py
```

双手抓住手柄。

点击右手食指部位的RB键。小车后轮会动起来。

晃动左手侧摇杆，小车前轮左右方向会跟随摇杆左右方向晃动而切换。

前侧左手食指部位的LB键。小车停止运动。

#### 产生效果：

会在当前文件夹生成一个`train`文件夹。

`train`文件夹中包含，执行`python3  collect.py`后采集的图片序列，以及一个json文件



# 串口通信

将`SmartCarToolKits`工程放到板子上的`/root/workspace/`文件夹下。

串口或者网口进入Edgeboard中linux系统。（具体详见`EdgeBoard 可视化访问的方法说明`手册）

概述

## USB转串口

### 依赖的源文件

`usb_uart_send.cpp`

`usb_uart_recv.cpp`

### 功能介绍

主要有`usb_uart_send`、`usb_uart_recv`应用程序

`usb_uart_send`：`EdgeBoard`通过`usb`转串口，循环1ms发送`00-09`的数据

`usb_uart_recv`：`EdgeBoard`通过`usb`转串口，阻塞固定的时间接收一个字节的数据

### 准备工作

所需要的物品：三根杜邦线：`TX`，`RX`，`GND`、2个`USB`转串口工具、`PC`电脑上安装串口调试助手、`PC`安装相应适配的`USB`转串口驱动。

**附连接示意图：**

![d27ba35bcfc13066cb1eeff90c81ed8a](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/d27ba35bcfc13066cb1eeff90c81ed8a.png)



由于一些`USB`转串口商家考虑到人们使用习惯，在`USB`转串口设备的串口标识出做出修改，连接方式为`TX`与`TX`相连，`RX`与`RX`相连。

但是串口协议规定为下图交叉相连方式。具体连接视情况而定。

![6d7dcee70ff1e72750e85781a7bb940f](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/6d7dcee70ff1e72750e85781a7bb940f.png)

### 编译方式

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make usb_uart_send -j
make usb_uart_recv -j
```

会在`build`目录下产生`usb_uart_send`、`usb_uart_recv`的应用程序

### 使用方式

按照准备工作中的连接示意图连接好之后。

打开`PC`上的串口调试助手，`PC`端选择插入的`USB`转串口识别的串口号，并在串口调试助手中设置。

`PC`上串口调试助手中设置16进制显示。

`usb_uart_send.cpp`、`usb_uart_recv`程序中设置的，波特率为115200，8位数据位，无校验位。PC上串口调试助手需要相应的设置。

附`PC`上串口调试助手设置图。

![ebca75c60dac4d124ca22f60f573cbd2](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/ebca75c60dac4d124ca22f60f573cbd2.png)

在`EdgeBoard`上linux中执行

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
./usb_uart_send
```

或者

在`PC`上串口调试助手，发送区设置循环数据，以`0x56`为例

在`EdgeBoard`上linux中执行

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
./usb_uart_recv
```



### 产生的效果

在`EdgeBoard`上linux中执行`./usb_uart_send`结果：

此时查看`PC`上的串口调试助手，会发现接收区出现，`EdgeBoard`发过来的数据，十六进制显示为`00-09`。

![ae2d0cf728070971e8aebeaa017969fc](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/ae2d0cf728070971e8aebeaa017969fc.png)

在`EdgeBoard`上`linux`中执行`./usb_uart_recv`结果：

此时在`EdgeBoard`上`linux`终端，会接收到`PC`上的串口调试助手发过来的数据`0x56`。

![7cee403c5a5508cb66b21bd689245556](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/7cee403c5a5508cb66b21bd689245556.png)

### 问题排查方法

`EdgeBoard` 目前支持的`USB`转串口的 控制器 也写上 `CH340` 和 `CP210x`

1、查看硬件是否连接良好。

2、`lsmod`：显示已载入系统的模块。

执行 `lsmod` 命令，对比刚开机或者重启后执行`lsmod`与插上`USB`转串口，系统模块的差异

接入`usb`转串口后执行`lsmod`，有可能是`CH340`与`CP210x`其中任何一个。

![279e800b6136d84eff137733e0ab8d38](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/279e800b6136d84eff137733e0ab8d38.png)

3、第一步： lsusb 查看是否有新设备 。证明 USB设备是否被识别了。

![dee252f246a7aee82c8081b8a7297c70](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/dee252f246a7aee82c8081b8a7297c70.png)

4、查看设备`USB`设备节点：`ls` `/dev/tty.xxx`  证明 

![1213781d29bf9e4b6987f9d5eb163b89](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/1213781d29bf9e4b6987f9d5eb163b89.png)







## 串口通信

### 依赖的源文件

`uart_send.cpp`

`uart_recv.cpp`

### 功能介绍

主要有`uart_send`、`uart_recv`应用程序

`uart_send`：`EdgeBoard`通过`usb`转串口，循环1ms发送`00-09`的数据

`uart_recv`：`EdgeBoard`通过`usb`转串口，阻塞固定的时间接收一个字节的数据

### 准备工作

所需要的物品：三根杜邦线，`TX`，`RX`，`GND`、1个`USB`转串口工具、`PC`电脑上安装串口调试助手、`PC`上安装相应适配的`USB`转串口驱动。

**附连接示意图：**

`EdgeBoard`串口方形的为`TX`，圆形为`RX`

![image2021-12-24_19-26-37](/Users/v_yangxiaohu/Desktop/image2021-12-24_19-26-37.png)

![fa3a4b475f55efd9ec202ba84ea9e642](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/fa3a4b475f55efd9ec202ba84ea9e642.jpg)



由于一些`USB`转串口商家考虑到人们使用习惯，在`USB`转串口设备的串口标识出做出修改，连接方式为`TX`与`TX`相连，`RX`与`RX`相连。

但是串口协议规定为下图交叉相连方式。具体连接视情况而定。

![9fd6a24147da46fc5c6e5be50f501557](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/9fd6a24147da46fc5c6e5be50f501557.png)





### 编译方式

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
cmake .. 
make uart_send -j
make uart_recv -j
```

会在`build`目录下产生`uart_send`、`uart_recv`的应用程序

### 使用方式

按照准备工作中的连接示意图连接好之后。

打开`PC`上的串口调试助手，`PC`端选择插入的`USB`转串口识别的串口号，并在串口调试助手中设置。

`PC`上串口调试助手中设置16进制显示。

`uart_send.cpp`、`uart_recv`程序中设置的，波特率为115200，8位数据位，无校验位。`PC`上串口调试助手需要相应的设置。

附`PC`上串口调试助手设置图。

![ebca75c60dac4d124ca22f60f573cbd2](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/ebca75c60dac4d124ca22f60f573cbd2.png)

在`EdgeBoard`上linux中执行

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
./uart_send
```

或者

在`PC`上串口调试助手，发送区设置循环数据，以`0x56`为例

在`EdgeBoard`上linux中执行

```sh
cd /root/workspace/SmartCarToolKits/c++
mkdir build
cd build
./uart_recv
```



### 产生的效果

在`EdgeBoard`上linux中执行`./uart_send`结果：

此时查看`PC`上的串口调试助手，会发现接收区出现，`EdgeBoard`发过来的数据，十六进制显示为`00-09`。

![760b668d0fb603110898403cd593a346](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/760b668d0fb603110898403cd593a346.png)



在`EdgeBoard`上`linux`中执行`./uart_recv`结果：

此时在`EdgeBoard`上`linux`终端，会接收到`PC`上的串口调试助手发过来的数据`0x56`。

![80f51e54dfdb43cac13cbb396a729d28](/Users/v_yangxiaohu/Library/Caches/BaiduMacHi/Share/images/80f51e54dfdb43cac13cbb396a729d28.png)

### 问题排查的方法

1、查看硬件是否连接良好。

2、串口`TX`、`RX`是否反接

