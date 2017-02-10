#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
//using namespace  cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cv::Mat test1 = cv::imread("/home/usr/Documents/test1.jpg");
    cv::imshow("Test1", test1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
