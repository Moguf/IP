#ifndef __IMAGE_HPP
#define __IMAGE_HPP
#include <string>
#include <opencv2/opencv.hpp>
#include "Params.hpp"
class Image{
private:
    std::string filename;
    cv::Mat img;
    unsigned char mat[Y_SIZE][X_SIZE];
public:
    void read(char *file_in);
    void show(void);
    void resize(void);
    void cvimg2mat(void);
    void mat2cvimg(unsigned char mat_in[Y_SIZE][X_SIZE]);
    void threshold(int thresh, int type);
    void histgram(void);
    void threshold_mode(int smt, int type);
    void threshold_discrim(int type);
    void threshold_dynamic(int type);
};
#endif

