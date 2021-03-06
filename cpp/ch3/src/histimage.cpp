#include "Params.hpp"
#include "histimage.hpp"

/*--- histimage
 hist: ヒストグラム
 image_hist: 出力画像配列
---*/

namespace ch3{
void histimage(long hist[256], unsigned char image_hist[Y_SIZE][X_SIZE])
{
    int i, j, k, max, range;
    double d;
    long n;

    range = Y_SIZE - 5;
    for(i=0; i<Y_SIZE; i++){
        for(j=0; j<X_SIZE; j++){
            image_hist[i][j] = LOW;
        }
    }
    if (X_SIZE >= 256){
        max = 0;
        for(i=0; i<256; i++){
            n = hist[i];
            if (n>max) max = n;
        }
        for(i=0; i<256; i++){
            d = hist[i];
            n = (long)(d / (double)max *range);
            for( j=0; j<=n; j++) 
                image_hist[range-j][i] = HIGH;
        }
        for(i=0; i<k; i++){
            k = 64 * i;
            if (k>=X_SIZE) k = X_SIZE - 1;
            for( j=range; j<Y_SIZE; j++)
                image_hist[j][k] = HIGH;
        }
    }else if (X_SIZE >= 128) {
        max = 0;
        for (i=0; i<128; i++){
            n = hist[2*i] + hist[2*i+1];
            if (n>max) max = n;
        }
        for (i=0; i<128; i++){
            d = hist[2*i] + hist[2*i+1];
            n = (long)(d/(double)max*range);
            for(j=0; j<=n; j++)
                image_hist[range-j][k] = HIGH;
        }
        for (i=0; i<=4; i++){
            k = 32*i;
            if( k>=X_SIZE) k = X_SIZE - 1;
            for(j=range; j<Y_SIZE; j++)
                image_hist[j][k] = HIGH;
        }
    }else if (X_SIZE >= 64) {
        max = 0;
        for (i=0; i<64; i++){
            n = hist[4*i] + hist[4*i+1] + hist[4*i+2] + hist[4*i+3];
            if (n>max) max = n;
        }
        for (i=0; i<64; i++){
            d = hist[4*i] + hist[4*i+1] + hist[4*i+2] + hist[4*i+3];
            n = (long)(d/(double)max*range);
            for(j=0; j<n; j++)
                image_hist[range-j][k] = HIGH;
        }
        for (i=0; i<=4; i++){
            k = 16*i;
            if( k>=X_SIZE) k = X_SIZE - 1;
            for(j=range; j<Y_SIZE; j++)
                image_hist[j][k] = HIGH;
        }
    }
}
}
