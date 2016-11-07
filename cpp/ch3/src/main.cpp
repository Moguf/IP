#include <opencv2/opencv.hpp>
#include "image.hpp"

int main(int argc, char **argv)
{
    Image img1;
    img1.read(argv[1]);
    img1.resize();
    // 256x256に画像をリサイズする

    img1.cvimg2mat();
    // サンプルプログラムを使用するためopencvのcv::Matから行列に要素を渡す。
    
    //img1.threshold(100, 1);
    // 適当に閾値を決め、画像がどうなるか確認する。
    
    //img1.histgram();
    // サンプルの画像のヒストグラムを出力する。

    //img1.threshold_mode(10, 1);
    // モード法による閾値処理
    
    //img1.threshold_discrim(1);
    // 判別分析法による閾値処理
    
    img1.threshold_dynamic(1);    
    // 動的閾値法
    
    
    return 0;
}
