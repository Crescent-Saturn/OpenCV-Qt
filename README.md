# OpenCV-Qt
OpenCV application by Qt platform (in Ubuntu)
---
  
系统版本： Elementary OS Loki 0.4  
OpenCV版本：3.2.0  
Qt版本：5.8

### Installation
#### Install OpenCV
1. 下载压缩包opencv3.2.0
2. 安装OpenCV所需的库（编译器、必须库、可选库）
	```
	[compiler] sudo apt-get install build-essential
	[required] sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
	[optional] sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev
	```
	
3. CMake编译  		
 	```  		
	cd home/usr/local/opencv-3.2.0  
    mkdir build  
    cd build  
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..  
    sudo make -j4
    # run 4 jobs in parallel	  
	```  			


4. 安装   
    ```  
    sudo make install  
    ``` 

  
  
5. 添加到系统环境变量  
    ```  
    echo "# Use OpenCV and other custom-built libraries." >> ~/.bashrc
    echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/" >> ~/.bashrc
    source ~/.bashrc
    ```
  
   
  
  
#### Install Qt  

1. 在QT官网下载最新的版本5.8.0: qt-unified-linux-x64-2.0.5-online.run，并执行安装

    ```
    sudo chmod a+x qt-unified-linux-x64-2.0.5-online.run
    ./qt-unified-linux-x64-2.0.5-online.run
    ```  
2. 将qmake加入环境变量    
	```  		
	echo "# Use Qt qmake." >> ~/.bashrc
	echo "QTDIR=/home/usr/Qt/5.8/gcc_64
	echo "export PATH=$QTDIR/bin:$PATH" >> ~/.bashrc
	source ~/.bashrc
	```	

  
  
### Qt Configuration
1. 首先在终端查看所有可用OpenCV库：  
    ```  
	ls /usr/local/lib/*.so  
    ```  
2. 在Qt Creator中新建Qt Widgets Application, 并在.pro文件中 `SOURCES`之前加入以下：     
    ```
    INCLUDEPATH += /usr/local/include/opencv  
    
    LIBS += -L/usr/local/include/opencv \        
            -lopencv_core \                
            ... # All the opencv libs found in 'ls /usr/local/lib/*.so '    
    ```  
3. 之后可在`main.cpp`或`mainwindow.cpp`中插入OpenCV常规代码，运行即可。  

### Test
参考 Hello_Qt_OpenCV



### Examples
Linux_Video_Cap中完全使用Qt自带库来实现开启摄像头及捕捉图像（Qt-Media）    
同时添加了交互按键       


Qt_Video_Cap则使用OpenCV在Qt窗口中开启摄像头以及捕捉图像(VideoCapture)     
移除按键

### Qt True OpenCV configuration    
在Qt Creator中新建Non-Qt Project--Plain C++ Application.     
修改.pro文件为：     
    
	``` 
    TEMPLATE = app
    #CONFIG += console
    CONFIG -= app_bundle
    CONFIG -= qt
    CONFIG += c++17

    INCLUDEPATH +=/usr/local/include/opencv
    LIBS += \
         -L/usr/local/lib\
        -lopencv_calib3d \
        -lopencv_photo \
        -lopencv_core\
        -lopencv_shape\
        -lopencv_features2d\
        -lopencv_stitching\
        -lopencv_flann \
        -lopencv_superres\
        -lopencv_highgui\
        -lopencv_videoio\
        -lopencv_imgcodecs\
        -lopencv_video\
        -lopencv_imgproc\
        -lopencv_videostab\
        -lopencv_ml\
        -lopencv_objdetect

    SOURCES += main.cpp
 	```
    
   将console注释掉以解决无法在Application Output显示结果的错误
