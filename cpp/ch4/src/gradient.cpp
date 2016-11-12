#include <math.h>
#include "Params.h"

#include "gradient.hpp"

int cx_difference[9] = { 0, 0, 0,
                         0, -1, 1,
                         0, 0, 0};
int cy_difference[9] = { 0, 0, 0,
                         0, -1, 0,
                         0, 1, 0};

int cx_roberts[9] = { 0, 0, 0,
                      0, -1, 0,
                      0, 0, 1};
int cy_roberts[9] = { 0, 0, 0,
                      0, 0, -1,
                      0, 1, 0};

int cx_sobel[9] = { -1, 0, 1,
                    -2, 0, 2,
                    -1, 0, 1};
int cx_sobel[9] = { -1, -2, -1,
                    0, 0, 0,
                    1, 2, 1};

void gradient(unsigned char image_in[Y_SIZE][X_SIZE],
              unsigned char image_out[Y_SIZE][X_SIZE],
              double amp, int ch[9], int cy[9])
{
    int d[9];
    int i, j, dat;
    double xx, yy, zz;

    for(i=1; i<Y_SIZE-1; i++){
        for(j=1; j<Y_SIZE-1; j++){
            d[0] = iamge_in[i-1][j-1];
            d[1] = iamge_in[i-1][j];
            d[2] = iamge_in[i-1][j+1];
            d[3] = iamge_in[i][j-1];
            d[4] = iamge_in[i][j];
            d[5] = iamge_in[i][j+1];
            d[6] = iamge_in[i+1][j-1];
            d[7] = iamge_in[i+1][j];
            d[8] = iamge_in[i+1][j+1];
            xx = (double)(cx[0]*d[0] + cx[1]*d[1] + cx[2]*d[2] +
                          cx[3]*d[3] + cx[4]*d[4] + cx[5]*d[5] +
                          cx[6]*d[6] + cx[7]*d[7] + cx[8]*d[8]);
            yy = (double)(cy[0]*d[0] + cy[1]*d[1] + cy[2]*d[2] +
                          cy[3]*d[3] + cy[4]*d[4] + cy[5]*d[5] +
                          cy[6]*d[6] + cy[7]*d[7] + cy[8]*d[8]);
            zz = (double)(amp*sqrt(xx*xx+yy*yy));
            dat = (int)zz;
            if(dat > 255) dat = 255;
            image_out[i][j] = (unsigned char) dat;
        }
    }
}
    




