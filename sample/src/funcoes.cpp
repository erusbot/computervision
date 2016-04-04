#include "funcoes.hpp"

//////// GLOBAL VARIABLES ///////////////////////////////////////
Mat img_gray, img_dst;
const string window_name = "Threshold Demo";
const string trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const string trackbar_value = "Value";

int threshold_value = 0;
int threshold_type = 3;
int const MAX_VALUE = 255;
int const MAX_TYPE = 4;
int const MAX_BINARY_VALUE = 255;


void getMetaInfo(const Mat image)
{
    cout << "Tamanho: " << image.size() << endl;
    cout << "Canais: " << image.channels() << endl;
}

void isolateChannels(const Mat image)
{
    vector<Mat> channels(3);
    split (image, channels);

    namedWindow("Channel B", CV_WINDOW_AUTOSIZE);
    imshow("Channel B", channels[0]);
    namedWindow("Channel G", CV_WINDOW_AUTOSIZE);
    imshow("Channel G", channels[1]);
    namedWindow("Channel R", CV_WINDOW_AUTOSIZE);
    imshow("Channel R", channels[2]);
    waitKey(0);

}

Mat imageROI(const Mat image, const Rect roi)
{
    Mat image_roi = image(roi);
    return image_roi;
}

Mat concatMat(const Mat img1, const Mat img2, bool flag)
{
    Mat output;

    if(flag)
    {
        hconcat(img1,img2,output);
        namedWindow("Horizontaly Concat", CV_WINDOW_AUTOSIZE);
        imshow("Horizontaly Concat", output);
        waitKey(0);
    }else
    {
        vconcat(img1,img2,output);
        namedWindow("Verticaly Concat", CV_WINDOW_AUTOSIZE);
        imshow("Verticaly Concat", output);
        waitKey(0);
    }

    return output;
}

Mat conv2Gray(const Mat img)
{
    Mat output;
    cvtColor(img, output, CV_BGR2GRAY);

    return output;
}

Mat add2Images(const Mat img1, const Mat img2)
{
    Mat output;
    add(img1,img2,output);

    return output;
}

Mat blendImages(const Mat img1, const double alpha, const Mat img2)
{
    Mat output;
    double beta = 1 - alpha;
    addWeighted(img1, alpha, img2, beta, 0.0, output);

    return output;
}

Mat escalarProduct(const Mat img, const double value)
{
    Mat out = img.clone();
    return out*value;
}

Mat noiseGaussian(const Mat img)
{
    Mat noised = img.clone();

    randn(noised, 30, 128);

    return noised;
}

Mat unfocus(const Mat img)
{
    Mat out;

    blur(img, out, Size(120,30));

    return out;
}

Mat noise_Salt(const Mat img)
{
    Mat saltPepper_Noise = Mat::zeros(img.rows, img.cols,CV_8U);
    randu(saltPepper_Noise,0,255);
    Mat black = saltPepper_Noise < 30;
    Mat white = saltPepper_Noise > 225;

    Mat out_SaltPepper;

    cvtColor(img, out_SaltPepper, CV_BGR2GRAY);

    out_SaltPepper.setTo(255,white);
    out_SaltPepper.setTo(0,black);

    return out_SaltPepper;
}

// Mat noise_Remove(const Mat img)
// {
//     Mat out;
//     fastNlMeansDenoising(img,out, 3, 7, 21);
//
//     return out;
// }

void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

  threshold(img_gray, img_dst, threshold_value, MAX_BINARY_VALUE, threshold_type);
  imshow(window_name, img_dst);
}

void thresHold(Mat img)
{
    /// Convert the image to Gray
    cvtColor( img, img_gray, CV_BGR2GRAY);

    /// Create a window to display results
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );

    /// Create Trackbar to choose type of Threshold
    createTrackbar( trackbar_type, window_name, &threshold_value, MAX_TYPE, Threshold_Demo);

    createTrackbar( trackbar_value, window_name, &threshold_value, MAX_VALUE, Threshold_Demo );

    /// Call the function to initialize
    Threshold_Demo(0, NULL);

    /// Wait until user finishes program
    while(true)
      {
        int c;
        c = waitKey(20);
        if ( (char)c == 27 )
        {
            break;
        }
      }
}

int menu(void)
{
    int opc;

    cout << "##########################################################" << endl;
    cout << "##########################################################" << endl;
    cout << "#################### ComputerVision ######################" << endl;
    cout << "#######                                             ######" << endl;
    cout << "####### Escolha a opção:                            ######" << endl;
    cout << "#######                                             ######" << endl;
    cout << "####### 1) Exibir Metainformações da Imagem         ######" << endl;
    cout << "####### 2) Crop Image                               ######" << endl;
    cout << "####### 3) Isolar Canais                            ######" << endl;
    cout << "####### 4) Concatenar duas imagens                  ######" << endl;
    cout << "####### 5) TreshHold                                ######" << endl;
    cout << "####### 6) Adicao de Duas Imagens                   ######" << endl;
    cout << "####### 7) Blend de Duas Imagens                    ######" << endl;
    cout << "####### 8) Multiplicação por Escalar                ######" << endl;
    cout << "####### 9) Adicao de Ruidos                         ######" << endl;
    cout << "####### 10) Remocao de Ruidos                       ######" << endl;
    cout << "#######                                             ######" << endl;
    cout << "##########################################################" << endl;
    cout << "##########################################################" << endl;
    cout << "##########################################################" << endl;

    cin >> opc;

    return opc;
}
