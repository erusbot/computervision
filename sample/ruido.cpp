#include <opencv2/imgproc/imgproc.hpp>
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


  if( argc < 1)
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

  Mat rui;

  fastNlMeansDenoising(image,rui, 3,7,21);

  namedWindow( "Sem Ruido", WINDOW_AUTOSIZE );
  imshow( "Sem Ruido", rui);

  waitKey(0);

  return 0;
}
