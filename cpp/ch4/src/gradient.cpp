#include <math.h>
#include "Params.h"

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

//void gradient(unsigned char image_in




