#ifndef __THRESHOLD_HPP
#define __THRESHOLD_HPP
#include "Params.hpp"
namespace ch3{
void threshold(unsigned char image_in[Y_SIZE][X_SIZE],
                   unsigned char image_out[Y_SIZE][X_SIZE], int thresh, int type);
}
#endif
