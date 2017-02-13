#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);

    ui->ImageView->addWidget(viewfinder);
    ui->ImageCapture->setScaledContents(true);

    camera->setViewfinder((viewfinder));
    camera->start();

    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)),this,
            SLOT(DisplayImage(int,QImage)));

    connect(ui->buttonCapture,SIGNAL(clicked()),this, SLOT(CaptureImage()));
    connect(ui->buttonSave,SIGNAL(clicked()), this, SLOT(SaveImage()));
    connect(ui->buttonQuit,SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CaptureImage()
{
    ui->statusBar->showMessage(tr("Capturing..."), 1000);
    imageCapture->capture();
}

void MainWindow::DisplayImage(int, QImage image)
{
    ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
    ui->statusBar->showMessage(tr("Caputre Done!"), 5000);
}

void MainWindow::SaveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save image"),QDir::homePath(),
                                                  tr("jpegfile(*.jpg)"));
    if(fileName.isEmpty()){
        ui->statusBar->showMessage(tr("Save cancelled"),5000);
        return;
    }
    const QPixmap* pixmap=ui->ImageCapture->pixmap();
    if(pixmap){
        pixmap->save(fileName);
        ui->statusBar->showMessage(tr("Save Done"),5000);
    }
}
