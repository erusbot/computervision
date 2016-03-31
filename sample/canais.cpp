#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

void SelecionaCanais(Mat image){

  vector<Mat> channels(3);

  Mat canal1, canal2, canal3;

  split (image, channels);

  canal1 = channels[0];
  canal2 = channels[1];
  canal3 = channels[2];

  namedWindow("Azul", CV_WINDOW_AUTOSIZE);
  imshow("Azul", canal1);

  namedWindow("Verde", CV_WINDOW_AUTOSIZE);
  imshow("Verde", canal2);

  namedWindow("Vermelho", CV_WINDOW_AUTOSIZE);
  imshow("Vermelho", canal3);

}

int main( int argc, char** argv )
{

  Mat image;

  int num;

  if( argc < 1)
  {
   cout << "Tente passar uma imagem como argumento" << endl;
   return -1;
  }

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(!image.data)
  {
      cout <<  "Problemas ao abrir ou ao encontrar a imagem" << endl ;
      return -1;
  }

  namedWindow( "Original", WINDOW_AUTOSIZE );
  imshow( "Original", image );

  SelecionaCanais(image);

  waitKey(0);

  return 0;
}
