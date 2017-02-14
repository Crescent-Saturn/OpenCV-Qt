#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    cam = NULL;
    timer = new QTimer(this);
    ui->label->setScaledContents(true); // Fit the video to label area
    ui->label_2->setScaledContents(true); //


    connect(timer,      SIGNAL(timeout()),this,SLOT(readFrame()));
    connect(ui->openCam, SIGNAL(clicked()), this, SLOT(openCamera()));
    connect(ui->takePic, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closeCamera()));
    connect(ui->buttonQuit,SIGNAL(clicked()),qApp, SLOT(quit()));   // QApplication Quit Slot fct

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openCamera()
{
    if(cam.isOpened())
        cam.release(); // If the camera is opened, close it
    cam.open(0);
    timer->start(33);

}


void MainWindow::readFrame()
{
    cam >> frame;
    QImage img1 = QImage((const unsigned char*)frame.data,
                         frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    ui->label->setPixmap(QPixmap::fromImage(img1));
}

void MainWindow::takingPictures()
{
    cam >> frame;
    QImage img2 = QImage((const unsigned char*)frame.data,
                         frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();
    ui->label_2->setPixmap(QPixmap::fromImage(img2));

}

void MainWindow::closeCamera()
{
    timer->stop();
    cam.release();

}

