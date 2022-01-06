# SmartCarToolKits

将SmartCarToolKits工程放到/root/workspace/下

串口或者网口进入Edgeboard中linux系统。

## SmartCarToolKits/c++

### camera2video

#### 依赖的源文件

`SmartCarToolKits/c++/demo`中：`camera2video.cpp`

#### 功能介绍：

将采集到的图片，转换成灰度视频

#### 准备工作：

准备要转换的图片文件夹放到`/root/workspace/`路径下，以命名为`train`为例（可任意命名）。

#### 获取程序：

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

测试`VNC`。

#### 准备工作：

连接好网口。

将摄像头插入`EdgeBoard`上的`USB`口中。

打开电脑，下载`VNC Viewer`（具体详见`VNC`使用手册）。

#### 获取程序：

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

可以在`VNC`中，看到一个名为`usbcamera`的摄像头框。



### rgb_mat2gray_array

#### 依赖的源文件

`SmartCarToolKits/c++/demo`中：`rgb_mat2gray_array.cpp`

#### 功能介绍：

将一张`RGB`图转换成灰度图

#### 准备工作：

将准备要转换的图片文件夹放到`/root/workspace/`路径下，以命名为`train`为例（可任意命名）。

假设`train`中的图片以0.jpg，1.jpg，2.jpg ...等格式递增。

#### 获取程序：

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



## SmartCarToolKits/python

进入到`SmartCarToolKits/python`文件夹中

```
cd /root/workspace/SmartCarToolKits/python/
```

### capture.py

#### 功能介绍：

测试摄像头驱动

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

关于适配的`USB`扩展口与摄像头，手柄的购买链接，已经同步出来了。（具体详见购买链接手册）

#### 使用方式

执行此程序前先将小车架起来，因为执行此程序，小车会动起来。

```sh
cd /root/workspace/SmartCarToolKits/python/
python3  collect.py
```

双手抓住手柄。

点击右手食指手柄侧面，上边的按钮。小车后轮会动起来。

晃动左手边大拇指位置旋钮，小车前轮会跟随大拇指晃动而晃动。

前侧左手食指手柄侧面，上边的按钮。小车停止运动。

#### 产生效果：

会在当前文件夹生成一个`train`文件夹。

`train`文件夹中包含，执行`python3  collect.py`后采集的图片。