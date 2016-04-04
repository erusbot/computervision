#ifndef __FUNCOES
    #define __FUNCOES

    #include <opencv2/imgproc/imgproc.hpp>
    #include <opencv2/core/core.hpp>
    #include <opencv2/highgui/highgui.hpp>
    #include <cv.h>
    #include <iostream>

    using namespace std;
    using namespace cv;

    void getMetaInfo(const Mat image);
    void isolateChannels(const Mat image);
    Mat imageROI(const Mat image, const Rect roi);
    Mat concatMat(const Mat img1, const Mat img2, const bool flag);
    Mat conv2Gray(const Mat img);
    Mat add2Images(const Mat img1,const  Mat img2);
    Mat blendImages(const Mat img1, const double alpha, const Mat img2);
    Mat escalarProduct(const Mat img, const double value);
    Mat noiseGaussian(const Mat img);
    Mat unfocus(const Mat img);
    Mat noise_Salt(const Mat img);
    // Mat noise_Remove(const Mat img); //Tem q consertar
    void Threshold_Demo( int, void* );
    void thresHold(Mat img);
    int menu(void);

#endif //END_FUNCOES
