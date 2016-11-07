#ifndef __THRESH_MODE_HPP
#define __THRESH_MODE_HPP
#include "Params.hpp"
namespace ch3{
void thresh_mode(unsigned char image_in[Y_SIZE][X_SIZE],
                 unsigned char image_out[Y_SIZE][X_SIZE], int smt, int type);
int threshmode(long hist[256]);
}
#endif
