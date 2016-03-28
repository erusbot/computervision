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

  threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );

  imshow( window_name, dst );
}


void ExibeInformacao(Mat image){

  cout << "Largura: " << image.cols << endl;
  cout << "Altura: " << image.rows << endl;
  cout << "Canais: " << image.channels() << endl;

}

void CortaImagem(Mat image){

  Rect region = Rect(50, 50, 50, 50);
  Mat corte = image(region);

  namedWindow( "Corte", CV_WINDOW_AUTOSIZE );
  imshow( "Corte", corte);


}

void SelecionaCanais(Mat image){

  vector<Mat> channels(3);

  Mat canal1, canal2, canal3;

  split (image, channels);

  canal1 = channels[0];
  canal2 = channels[1];
  canal3 = channels[2];

  namedWindow("Canal1", CV_WINDOW_AUTOSIZE);
  imshow("Canal1", canal1);

  namedWindow("Canal2", CV_WINDOW_AUTOSIZE);
  imshow("Canal2", canal2);

  namedWindow("Canal3", CV_WINDOW_AUTOSIZE);
  imshow("Canal3", canal3);



}

void ConcatenaImagens(Mat image){
      Mat cont;

      hconcat(image,image, cont);

      namedWindow("Cont", CV_WINDOW_AUTOSIZE);
      imshow("Cont", cont);

}


void ImagemCinza(Mat image){

  Mat cinza;
  cvtColor(image, cinza, CV_BGR2GRAY);

  namedWindow( "Cinza", CV_WINDOW_AUTOSIZE );
  imshow( "Cinza", cinza);

}

int main( int argc, char** argv )
{
  int num;

  if( argc < 2)
  {
   cout << "Tente passar uma imagem como argumento" << endl;
   return -1;
  }

  image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Ler imagem

  if(! image.data )                              // Checar se realmente se trata de uma imagem
  {
      cout <<  "Problemas ao abrir ou ao encontrar a imagem" << endl ;
      return -1;
  }

  namedWindow( "Original", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Original", image );   // Show our image inside it.

///////////////////////////////////////////////////////////////////////////////
  ExibeInformacao(image);
  CortaImagem(image);
  SelecionaCanais(image);
  ConcatenaImagens(image);
///////////////////////////////////////////////////////////////////////////////
  Mat imagem2,res;

  imagem2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);

  res = imagem2 + image;

  namedWindow( "Soma", WINDOW_AUTOSIZE );// Create a window for display.
  imshow( "Soma", res);

/////////////////////////////////////////////////////////////////////////
  double alpha = 0.5; double beta;

  Mat blend;

  namedWindow("Blende Efeito", 1);

  beta = ( 1.0 - alpha );
  addWeighted( image, alpha, imagem2, beta, 0.0, blend);

  imshow( "Blende Efeito", blend);
//////////////////////////////////////////////////////////////////////////
  Mat mult;

  mult = image*0.3;

  namedWindow("Multiplicação", 1);

  imshow("Multiplicação", mult);
/////////////////////////////////////////////////////////////////////////////////

  Mat gaus;

  gaus = image.clone();

  randn(gaus, 30, 128);

  namedWindow("Gaus", 1);
  imshow("Gaus",gaus);

////////////////////////////////////////////////////////////////////////////////

  Mat desfocar;

  blur(image, desfocar, Size(120,30));

  namedWindow("Desfocar", 1);
  imshow("Desfocar", desfocar);

  ///////////////////////////////////////////////////////////////////////////////

  Mat saltpepper_noise = Mat::zeros(image.rows, image.cols,CV_8U);
  randu(saltpepper_noise,0,255);

  Mat black = saltpepper_noise < 30;
  Mat white = saltpepper_noise > 225;

  Mat saltpepper_img;

  cvtColor(image, saltpepper_img,  CV_BGR2GRAY);

  saltpepper_img.setTo(255,white);
  saltpepper_img.setTo(0,black);

  namedWindow("Sal e Pimenta", 1);
  imshow("Sal e Pimenta", saltpepper_img);

/////////////////////////////////////////////////////////////////////////////////

Mat sruido;


fastNlMeansDenoising();


/////////////////////////////////////////////////////////////////////////////////

  cvtColor( image, src_gray, CV_BGR2GRAY );

  namedWindow( window_name, CV_WINDOW_AUTOSIZE );

  createTrackbar( trackbar_type,
                  window_name, &threshold_type,
                  max_type, Threshold_Demo );

  createTrackbar( trackbar_value,
                  window_name, &threshold_value,
                  max_value, Threshold_Demo );

  Threshold_Demo( 0, 0 );

  while(true)
  {
    int c;
    c = waitKey( 20 );
    if( (char)c == 27 )
      { break; }
   }

////////////////////////////////////////////////////////////////////////////////

  return 0;
}
