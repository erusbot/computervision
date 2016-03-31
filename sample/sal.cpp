#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;


int main( int argc, char** argv )
{

  Mat image;

  int num;

  if( argc < 2)
  {
   cout << "Tente passar uma imagem como argumento" << endl;
   return -1;
  }

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(! image.data )
  {
      cout <<  "Problemas ao abrir ou ao encontrar a imagem" << endl ;
      return -1;
  }

  namedWindow( "Original", WINDOW_AUTOSIZE );
  imshow( "Original", image );   

  Mat saltpepper_noise = Mat::zeros(image.rows, image.cols,CV_8U);
  randu(saltpepper_noise,0,255);

  Mat black = saltpepper_noise < 30;
  Mat white = saltpepper_noise > 225;

  Mat saltpepper_img;

  cvtColor(image, saltpepper_img, CV_BGR2GRAY);

  saltpepper_img.setTo(255,white);
  saltpepper_img.setTo(0,black);

  namedWindow("Sal e Pimenta", 1);
  imshow("Sal e Pimenta", saltpepper_img);

  waitKey(0);

  return 0;
}
