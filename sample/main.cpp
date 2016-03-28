#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;

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
  waitKey(0);

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

  waitKey(0);

}

void ConcatenaImagens(Mat image){
      Mat cont;

      hconcat(image,image, cont);

      namedWindow("Cont", CV_WINDOW_AUTOSIZE);
      imshow("Cont", cont);
      waitKey(0);
}

void Threshold(Mat image){



}

void ImagemCinza(Mat image){

  Mat cinza;
  cvtColor(image, cinza, CV_BGR2GRAY);

  namedWindow( "Cinza", CV_WINDOW_AUTOSIZE );
  imshow( "Cinza", cinza);
  waitKey(0);
}

int main( int argc, char** argv )
{

    int num;

    if( argc != 2)
    {
     cout << "Tente passar uma imagem como argumento" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Ler imagem

    if(! image.data )                              // Checar se realmente se trata de uma imagem
    {
        cout <<  "Problemas ao abrir ou ao encontrar a imagem" << endl ;
        return -1;
    }

    namedWindow( "Original", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Original", image );   // Show our image inside it.
    waitKey(0);

    while(1){
      cout << "Escolha uma operacao:" << endl;

      cout << "1. Exibir informacoes da image" << endl;

      cout << "2. Recortar uma parte da imagem" << endl;

      cout << "3. Selecionar canais da imagem" << endl;

      cout << "4. Concatenar duas imagens" << endl;

      cout << "5. Imagem Cinza" << endl;

      cout << "6. Threshold" << endl;

      cout << "0. Sair" << endl;

      cin >> num;

      if(num == 0)
        break;

      switch(num){

        case 1:
          ExibeInformacao(image);
          break;

        case 2:
          CortaImagem(image);
          break;

        case 3:
          SelecionaCanais(image);
          break;

        case 4:
          ConcatenaImagens(image);
          break;

        case 5:
          ImagemCinza(image);
          break;

        case 6:

          Threshold(image);

      }

  }
    waitKey(0);                                      // Wait for a keystroke in the window
    return 0;
}
