#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;


void ExibeInformacao(Mat image){

  cout << "Largura: " << image.cols << endl;
  cout << "Altura: " << image.rows << endl;
  cout << "Canais: " << image.channels() << endl;

}

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


  ExibeInformacao(image);

  Mat imagem2,res;

  imagem2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);

  res = imagem2 + image;

  namedWindow( "Soma", WINDOW_AUTOSIZE );
  imshow( "Soma", res);


  double alpha = 0.5; double beta;

  Mat blend;

  namedWindow("Blende Efeito", 1);

  beta = ( 1.0 - alpha );
  addWeighted( image, alpha, imagem2, beta, 0.0, blend);

  imshow( "Blende Efeito", blend);

  Mat mult;

  mult = image*0.3;

  namedWindow("Multiplicação", 1);

  imshow("Multiplicação", mult);


  Mat gaus;

  gaus = image.clone();

  randn(gaus, 30, 128);

  namedWindow("Gaus", 1);
  imshow("Gaus",gaus);


  Mat desfocar;

  blur(image, desfocar, Size(120,30));

  namedWindow("Desfocar", 1);
  imshow("Desfocar", desfocar);

  waitKey(0);

  return 0;
}
