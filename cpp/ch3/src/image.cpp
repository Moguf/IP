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
#include "threshold_mode.hpp"
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
            mat[i][j] = img.at<uchar>(i,j);
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
    ch3::threshold(mat, image_out, thresh, type);
    mat2cvimg(image_out);
    cv::imwrite("threshfold.png", img);
}

void Image::histgram(void)
{
    unsigned char image_out[Y_SIZE][X_SIZE];
    long hist[256], smooth_hist[256];

    //ヒストグラムを求める
    ch3::histgram(mat, hist);
    
    //ヒストグラムを標準出力で表現する
    ch3::histprint(hist);

    //ヒストグラムの画像化
    ch3::histimage(hist, image_out);
    mat2cvimg(image_out);
    cv::imwrite("histgram_image.png", img);

    //ヒストグラムの平滑化
    ch3::histsmooth(hist, smooth_hist);
    //平滑化したヒストグラムの画像化
    ch3::histimage(smooth_hist, image_out);
    mat2cvimg(image_out);
    cv::imwrite("smooth_histgram_image.png", img);
}

void Image::threshold_mode(int smt, int type)
{
    unsigned char image_out[Y_SIZE][X_SIZE];

    std::cout << "thresh(mode)::" << ch3::threshold_mode(mat, image_out, smt, type) << std::endl;; 
    mat2cvimg(image_out);
    cv::imwrite("threshold_mode.png", img);    
}

void Image::threshold_discrim(int type)
{
    unsigned char image_out[Y_SIZE][X_SIZE];
    std::cout << "thresh(discrim)::" << ch3::threshold_discrim(mat, image_out, type) << std::endl;; 
    mat2cvimg(image_out);
    cv::imwrite("threshold_discrim.png", img);    
}

void Image::threshold_dynamic(int type)
{
    unsigned char image_out[Y_SIZE][X_SIZE];
    ch3::threshold_dynamic(mat, image_out, type);
    mat2cvimg(image_out);
    cv::imwrite("threshold_dynamic.png", img);    
}
