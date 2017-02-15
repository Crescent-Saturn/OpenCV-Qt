#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore/QTimer>
#include <QtGui/QPixmap>
#include <QtGui/QImage>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    cv::Mat frame;
    cv::VideoCapture cam;
//    QImage  image;
    QTimer *timer;
//    double rate; //FPS
//    cv::VideoWriter writer;   //make a video record

private slots:
//    void openCamera();
    void readFrame();
//    void closeCamera();
//    void takingPictures();

};
#endif // MAINWINDOW_H
