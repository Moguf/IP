#include <opencv2/opencv.hpp>
#include "image.hpp"

int main(int argc, char **argv)
{
    Image img1;
    img1.read(argv[1]);
    img1.resize();
    img1.cvimg2mat();
    img1.threshold(100, 1);
    img1.histgram();
    
    return 0;
}
