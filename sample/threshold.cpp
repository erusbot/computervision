#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat image, src_gray, dst;


char window_name[50] = "Threshold Demo";
char trackbar_type [100] = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char trackbar_value[50] = "Value";

void Threshold_Demo( int, void* )
{
  /* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

  threshold(src_gray, dst, threshold_value, max_BINARY_value,threshold_type);

  imshow(window_name, dst);
}


int main( int argc, char** argv )
{
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


  cvtColor(image, src_gray, CV_BGR2GRAY);

  namedWindow(window_name, CV_WINDOW_AUTOSIZE);

  createTrackbar(trackbar_type, window_name, &threshold_type, max_type, Threshold_Demo);

  createTrackbar(trackbar_value, window_name, &threshold_value, max_value, Threshold_Demo);

  Threshold_Demo(0, 0);

  while(true){

    int c;
    c = waitKey( 20 );

    if((char)c == 27){
      break;
    }

   }



  return 0;
}
