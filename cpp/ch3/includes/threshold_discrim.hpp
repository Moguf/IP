#ifndef __THRESHOLD_DISCRIM_HPP
#define __THRESHOLD_DISCRIM_HPP
#include "Params.hpp"
namespace ch3{
int threshold_discrim(unsigned char image_in[Y_SIZE][X_SIZE],
                      unsigned char image_out[Y_SIZE][X_SIZE], int type);
int threshdiscrim(long hist[256], double disparity);
}
#endif
