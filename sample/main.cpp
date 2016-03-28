#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>    
#include <string> 
#include "crop.h"
#include "threshold.h"
#include "concatenate.h"
#include "blend_image.h"
#include "add_image.h"
#include "scalar_image.h"
#include "gaussian_noise.h"
#include "sp_noise.h"

using namespace cv;
using namespace std;



int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: main <IMAGE PATH>" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	Mat channel[3];
	imshow( "Original Image", image );
	//displayStatusBar("Original Image", "Teste",0);
	// The actual splitting.
	int option;
	cout << "Menu\n0: Exit\n1: Informations\n2: Crop\n3: Isolate Channels(R,G,B)\n4: Concatenate\n5: Threshold\n6: Add Images\n7: Blend Images\n8: Scalar Images\n9: Noise\n";
	cin >> option;
	switch(option){
		case 1:
			cout << "Image width: " << image.cols << '\n';
			cout << "Image height: " << image.rows << '\n';
			cout << "Pixel Depth: " << image.depth() << '\n';
			cout << "Image channels: " << image.channels() << '\n';
			cout << "Image type: " << image.type() << '\n';
		break;
		case 2:
			crop(image);
		break;
		case 3:
			split(image, channel);
			int option2;
			cout << "Isolate Channels Menu:\n1: R\n2: G\n3: B\n";
			cin >> option2;
			switch(option2){
				case 1:
					imshow("Red", channel[2]);
					imwrite( "Red_Image.jpg", channel[2]);
					//channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);
					//channel[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);
				break;
				case 2:
					imshow("Green", channel[1]);
					imwrite( "Green_Image.jpg", channel[1]);
					//channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);
					//channel[2]=Mat::zeros(image.rows, image.cols, CV_8UC1);
				break;
				case 3:
					imshow("Blue", channel[0]);
					imwrite( "Blue_Image.jpg", channel[0]);
					//channel[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);
					//channel[2]=Mat::zeros(image.rows, image.cols, CV_8UC1);
				break;
			}
		break;
		case 4:
			concatenate(image);
		break;
		case 5:
			threshold(image);
		break;
		case 6:
			add_image(image);
		break;
		case 7:
			blend_image(image);
		break;
		case 8:
			scalar_image(image);
		break;
		case 9:
			cout << "Noise Menu:\n1: Gaussian\n2: Salt and Pepper\n3: Impulse\n";
			cin >> option2;
			switch(option2){
				case 1:
					gaussian_noise(image);
				break;
				case 2:
					sp_noise(image);
				break;
				case 3:
				break;
			}
		break;
	}
    // Create Matrices (make sure there is an image in input!)

    //Merging red and green channels
    //merge(channel,1,image);
    //Point org;
    //org.x = 0;
    //org.y = 400;
    //stringstream ss;
    //ss << image.cols;
    //string str = ss.str();
    //putText( image, str, org, 1,
    //         3, 0, 4, 8);
    //imwrite("dest.jpg",image);
	
    waitKey(0);//Wait for a keystroke in the window
    return 0;
}
