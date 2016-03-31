#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;


void CortaImagem(Mat image){

  int xc,yc,x1,y1;

   cout << "Digite o centro (X,Y) e depois o tamnho do Retangulo X Y:" << endl;
  scanf("%d %d %d %d", &xc, &yc, &x1, &y1);

  Rect region = Rect(xc, yc, x1, y1);
  Mat corte = image(region);

  namedWindow( "Corte", CV_WINDOW_AUTOSIZE );
  imshow( "Corte", corte);

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


  CortaImagem(image);

  waitKey(0);

  return 0;
}
