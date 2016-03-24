#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }


    cout << "Largura: " << image.cols << std::endl;
    cout << "Altura: " << image.rows << std::endl;
    cout << "Canais: " << image.channels() << std::endl;

    namedWindow( "Original", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Original", image );   // Show our image inside it.


    Mat cinza;
    cvtColor(image, cinza, CV_BGR2GRAY);

    namedWindow( "Cinza", CV_WINDOW_AUTOSIZE );
    imshow( "Cinza", cinza);

    Rect region = Rect(50, 50, 50, 50);
    Mat corte = image(region);

    namedWindow( "Corte", CV_WINDOW_AUTOSIZE );
    imshow( "Corte", corte);

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
