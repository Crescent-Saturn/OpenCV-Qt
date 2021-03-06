#-------------------------------------------------
#
# Project created by QtCreator 2017-02-10T09:41:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Hello_Qt_OpenCV
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
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
#        -lopencv_viz\
        -lopencv_objdetect

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


