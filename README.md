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
3. CMake编译
    ```
    cd home/usr/local/opencv-3.2.0  
    mkdir build  
    cd build  
    cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..  
    sudo make -j4  
    j4指用4个 core 进行 make， 以提高编译速度  
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
    echo "export PATH="/home/usr/Qt/5.8/gcc_64/bin:$PATH" >> ~/.bashrc
```

  
  
### Qt Configuration


### Test
