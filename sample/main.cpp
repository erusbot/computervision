#include "funcoes.hpp"

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    int opc = -1;
    Rect pedaco;

    if( argc != 2)
    {
     cout <<" Usage: main <IMAGE PATH>" << endl;
     return -1;
    }

    Mat gaussian, salt, focus;
    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    opc = menu();

    switch(opc)
    {
        case 1:
            getMetaInfo(image);
            namedWindow("Imagem", WINDOW_AUTOSIZE );// Create a window for display.
            imshow("Imagem", image);                   // Show our image inside it.
            waitKey(0);                                          // Wait for a keystroke in the window
            break;

        case 2:
            pedaco = Rect(50,50,100,100);
            image = imageROI(image,pedaco);
            namedWindow("Cropped Image", WINDOW_AUTOSIZE );
            imshow("Cropped Image", image);                   // Show our image inside it.
            waitKey(0);                                          // Wait for a keys
            break;

        case 3:
            isolateChannels(image);
            break;

        case 4:
            concatMat(image, image, true);
            break;

        case 5:
            thresHold(image);
            break;

        case 6:
            image = add2Images(image,image);
            namedWindow("Added Images", WINDOW_AUTOSIZE );
            imshow("Added Images", image);
            waitKey(0);
            break;

        case 7:
            image = blendImages(image, 0.5, image);
            namedWindow("Blended Images", WINDOW_AUTOSIZE );
            imshow("Blended Images", image);
            waitKey(0);
            break;

        case 8:
            image = escalarProduct(image,25.0);
            namedWindow("Escalar Product", WINDOW_AUTOSIZE );
            imshow("Escalar Product", image);
            waitKey(0);
            break;

        case 9:
            gaussian = image.clone();
            salt = image.clone();
            focus = image.clone();

            gaussian = noiseGaussian(image);
            salt = noise_Salt(salt);
            focus = unfocus(focus);
            namedWindow("Gaussian Noise", WINDOW_AUTOSIZE );
            imshow("Gaussian Noise", gaussian);
            namedWindow("Salt Noise", WINDOW_AUTOSIZE );
            imshow("Salt Noise", salt);
            namedWindow("Focus Noise", WINDOW_AUTOSIZE );
            imshow("Focus Noise", focus);
            waitKey(0);
            break;

        case 10:
            break;

    }

    return EXIT_SUCCESS;
}
