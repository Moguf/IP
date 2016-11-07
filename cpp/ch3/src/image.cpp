#include <iostream>
#include <string>
#include <stdlib.h>
#include <opencv2/opencv.hpp>

#include "Params.hpp"
#include "image.hpp"
#include "threshold.hpp"
#include "histgram.hpp"
#include "histimage.hpp"
#include "histprint.hpp"
#include "histsmooth.hpp"
#include "thresh_mode.hpp"
#include "threshold_discrim.hpp"
#include "threshold_dynamic.hpp"

void Image::read(char *file_in)
{
    // 画像を読み込み、グレースケールをする。
    cv::Mat gray_img;
    std::cout << "Open::" << file_in << std::endl;
    filename = file_in;
    img = cv::imread(file_in);
    cvtColor(img, gray_img,CV_RGB2GRAY);
    img = gray_img;
    if(img.empty())
        exit(1);
    std::cout << img.size() << std::endl;
}
    
void Image::show(void)
{
    // img に保存されている画像をウィンドウに表示する。
    cv::namedWindow("sample", cv::WINDOW_AUTOSIZE);
    cv::imshow("show", img);
    cv::waitKey(0);
}

void Image::resize(void)
{
    // 画像のサイズを256x256にする。
    cv::Mat dst_img(X_SIZE, Y_SIZE, img.type());
    cv::resize(img, dst_img, dst_img.size(), cv::INTER_CUBIC);
    img = dst_img;
}

void Image::cvimg2mat(void)
{
    // サンプルプログラム用に、opencvのCV::Matのデータを行列に渡す。
    for(int i=0 ;i<Y_SIZE ; i++){
        for(int j=0 ;j<X_SIZE ; j++){
            imgmat[i][j] = img.at<uchar>(i,j);
        }
    }
}

void Image::mat2cvimg(unsigned char mat_in[Y_SIZE][X_SIZE])
{
    // サンプルプログラム用に、行列のデータをopencvのCV::Matに渡す。
    for(int i=0 ;i<Y_SIZE ; i++){
        for(int j=0 ;j<X_SIZE ; j++){
            img.at<uchar>(i,j) = mat_in[i][j];
        }
    }
}

void Image::threshold(int thresh, int type)
{
    // サンプルプログラムのthresholdを呼び出し、結果を画像として保存する。
    unsigned char image_out[Y_SIZE][X_SIZE];
    ch3::threshold(imgmat, image_out, thresh, type);
    mat2cvimg(image_out);
    cv::imwrite("threshfold.png", img);
    //Image::mat2cvimg(
}

void Image::histgram(void)
{
    unsigned char image_out[Y_SIZE][X_SIZE];
    long hist[256];
    ch3::histgram(imgmat, hist);
    //ch3::histprint(hist);
    ch3::histimage(hist, image_out);
    mat2cvimg(image_out);
    cv::imwrite("histgram_image.png", img);
}

//void Image
