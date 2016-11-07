#include <stdio.h>
#include "Params.hpp"
#include "histprint.hpp"

/*--- histprint
 hist: ヒストグラム
 buf: メッセージ用バッファ
---*/
namespace ch3{
void histprint(long hist[256])
{
    char buf[TEXT_BUF_LEN];
    int i, j, k;
    double p, q, max;
    int posi, m;

    posi = 0;
    p = X_SIZE * Y_SIZE;
    max = 0;

    for(i=0; i<256; i++)
        if(hist[i] > max)
            max = hist[i];

    for(i=0; i<256; i++){
        q = hist[i] / p * 100.0;
        m = sprintf(&buf[posi], "%3d:%5.1f%%|", i, q);
        posi += m;

        k = (int)(hist[i] / max * 60.0);
        for(j=0; j<k; j++){
            m = sprintf(&buf[posi], "*");
            posi += m;            
        }
        m = sprintf(&buf[posi], "\n");
        posi += m;

    }
    puts(buf);
}
}
