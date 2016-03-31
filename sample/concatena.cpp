#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

void ConcatenaImagens(Mat image){
      Mat hcont, vcont;

      hconcat(image,image, hcont);
      vconcat(image,image, vcont);

      namedWindow("Horizontal", CV_WINDOW_AUTOSIZE);
      imshow("Horizontal", hcont);

      namedWindow("Vertical", CV_WINDOW_AUTOSIZE);
      imshow("Vertical", vcont);

}

int main( int argc, char** argv )
{

  Mat image;

  int num;

  if(argc < 1)
  {
   cout << "Tente passar uma imagem como argumento" << endl;
   return -1;
  }

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

  if(!image.data)
  {
      cout <<  "Problemas ao abrir ou ao encontrar a imagem" << endl;
      return -1;
  }

  namedWindow("Original", WINDOW_AUTOSIZE);
  imshow("Original", image);


  ConcatenaImagens(image);

  waitKey(0);

  return 0;
}
