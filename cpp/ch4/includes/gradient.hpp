#ifndef __GRADIENT_HPP
#define __GRADIENT_HPP
#include "Params.h"
void gradient(unsigned char image_in[Y_SIZE][X_SIZE],
              unsigned char image_out[Y_SIZE][X_SIZE],
              double amp, int ch[9], int cy[9]);
void gradient_difference(unsigned char image_in[Y_SIZE][X_SIZE],
              unsigned char image_out[Y_SIZE][X_SIZE],
              double amp)
{
    gradient(image_in, image_out, amp, cx_difference, cy_difference);
}
void gradient_roberts(unsigned char image_in[Y_SIZE][X_SIZE],
              unsigned char image_out[Y_SIZE][X_SIZE],
              double amp, int ch[9], int cy[9])
{
    gradient(image_in, image_out, amp, cx_roberts, cy_roberts);
}
void gradient_sobel(unsigned char image_in[Y_SIZE][X_SIZE],
              unsigned char image_out[Y_SIZE][X_SIZE],
              double amp, int ch[9], int cy[9])
{
    gradient(image_in, image_out, amp, cx_sobel, cy_sobel);
}
#endif
