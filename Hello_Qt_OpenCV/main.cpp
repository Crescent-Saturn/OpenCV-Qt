#include "mainwindow.h"
#include <iostream>
#include <cstdlib>
#include <QApplication>
#include <opencv2/opencv.hpp>

void show(const cv::String & name, cv::InputArray _src);


int main(int argc, char *argv[])
{

    // CV_8U -> uchar
    // CV_8S -> char (also signed char -> schar).
    // CV_16U -> ushort.
    // CV_16S -> short.
    // CV_32S -> int.
    // CV_32F -> float.
    // CV_64F -> double.

    // CV_8UC2
    // CV_8SC2
    // CV_16UC2
    // CV_16SC2
    // CV_32SC2
    // CV_32FC2
    // CV_64FC2

    // CV_8UC3
    // CV_8SC3
    // CV_16UC3
    // CV_16SC3
    // CV_32SC3
    // CV_32FC3
    // CV_64FC3

    // CV_8UC4
    // CV_8SC4
    // CV_16UC4
    // CV_16SC4
    // CV_32SC4
    // CV_32FC4
    // CV_64FC4

    // Matx
    // Mat
    // Mat_
    // Vec
    // Scalar



    cv::Mat a = (cv::Mat3f(3,3)<<cv::Vec3f(1.f, 1.f, 1.f),cv::Vec3f(2.f, 2.f, 2.f),cv::Vec3f(3.f, 3.f, 3.f),
                                 cv::Vec3f(4.f,4.f,4.f), cv::Vec3f(5.f,5.f,5.f), cv::Vec3f(6.f,6.f,6.f),
                                 cv::Vec3f(7.f,7.f,7.f),cv::Vec3f(8.f,8.f,8.f),cv::Vec3f(9.f,9.f,9.f) );

    cv::Mat b;

    a.convertTo(b, CV_8U);


    b.at<cv::Vec3b>(1,1) = cv::Vec3b(18.f, 18.f, 18.f);

    cv::extractChannel(a,a,0);
    cv::extractChannel(b,b,1);

    a.convertTo(a, CV_32F);
    b.convertTo(b, CV_32F);

    cv::Mat c = a/b;

//    cv::multiply(a,b,c);

    c = a.inv();

    c = c.t();

    c.release();

    std::cout<<c<<std::endl;

    cv::Mat test1 = cv::imread("/home/leilei/Documents/test1.jpg");
    show("nihao", test1);
    cv::waitKey(-1);

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    cv::Mat test1 = cv::imread("/home/leilei/Documents/test1.jpg");
//    cv::imshow("Test1", test1);
//    cv::waitKey(-1);
//    return a.exec();
    return EXIT_SUCCESS;
}

void show(const cv::String & name, cv::InputArray _src)
{

    if(_src.empty())
        return;

    if(_src.isVector() && _src.kind() == cv::_InputArray::STD_VECTOR_MAT )
    {
        std::vector<cv::Mat> src;

        _src.copyTo(src);
        // typename std::vecor<cv::Mat>::const_iterator
        for(auto it = src.begin(); it != src.end(); ++it)
        {
            cv::Mat tmp = *it;

            if( (tmp.channels() != 1) || (tmp.channels() != 3) )
            {
                tmp.convertTo(tmp, CV_32F);

                std::vector<cv::Mat> cns;

                // splint int channel (tmp == 3 channels image -> cns is 3 times one channel).
                cv::split(tmp, cns);

                tmp = std::accumulate(cns.begin(), cns.end(), cv::Mat1f::zeros(tmp.size()));
                tmp /= cns.size();
            }



            if(tmp.depth() != CV_8U)
                cv::normalize(tmp, tmp, 255., 0., cv::NORM_MINMAX);



            for(int i=0; i<src.size();++i)
            {
                std::string name_tmp = name;
                name_tmp += std::to_string(i);

                cv::imshow(name_tmp, src.at(i));
            }
        }
    }

    if(_src.isMat())
    {
        cv::Mat tmp = _src.getMat();

        if( ( (tmp.channels() != 1) && (tmp.channels() != 3)) )
        {
            tmp.convertTo(tmp, CV_32F);

            std::vector<cv::Mat> cns;

            // splint int channel (tmp == 3 channels image -> cns is 3 times one channel).
            cv::split(tmp, cns);

            tmp = std::accumulate(cns.begin(), cns.end(), cv::Mat1f::zeros(tmp.size()));
            tmp /= cns.size();
        }

        if(tmp.depth() != CV_8U)
            cv::normalize(tmp, tmp, 255., 0., cv::NORM_MINMAX);

        tmp.convertTo(tmp, CV_8U);

        std::cout<<"CHECK "<<tmp.size()<<" "<<tmp.depth()<<std::endl;

        cv::imshow(name, tmp);
    }
}
