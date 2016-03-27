#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "blend_image.h"

using namespace cv;
using namespace std;

/// Global Variables
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;


/// Matrices to store images
Mat src1;
Mat src2;
Mat dst;

void blend_image(cv::Mat image){
/// Read image ( same size, same type )
src1 = image;

string image2;
cout << "Image 2 path:\n";
cin >> image2;
src2 = imread(image2);

if( !src1.data ) { printf("Error loading src1 \n"); return; }
if( !src2.data ) { printf("Error loading src2 \n"); return; }


/// Initialize values
alpha_slider = 0;

/// Create Windows
namedWindow("Linear Blend", 1);

/// Create Trackbars
char TrackbarName[50];
sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );

/// Show some stuff
on_trackbar( alpha_slider, 0 );

}

void on_trackbar( int, void* )
{
 alpha = (double) alpha_slider/alpha_slider_max ;
 beta = ( 1.0 - alpha );
 //cout << "Beta = " << beta << endl;
 addWeighted( src1, alpha, src2, beta, 0.0, dst);

 imshow( "Linear Blend", dst );
}
