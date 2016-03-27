#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scalar_image.h"

using namespace cv;
using namespace std;

/// Global Variables
const int alpha_slide_max_scalar = 100;
int alpha_slide_scalar;
double  alpha_scalar;


/// Matrices to store images
Mat src1_scalar;
Mat src2_scalar;

void scalar_image(cv::Mat image){
/// Read image ( same size, same type )
src1_scalar = image;

if( !src1_scalar.data ) { printf("Error loading src1 \n"); return; }


/// Initialize values
alpha_slide_scalar = 0;

/// Create Windows
namedWindow("Scalar", 1);

/// Create Trackbars
char TrackbarName[50];
sprintf( TrackbarName, "Alpha x %d", alpha_slide_max_scalar );

createTrackbar( TrackbarName, "Scalar", &alpha_slide_scalar, alpha_slide_max_scalar, on_trackbar_scalar );

/// Show some stuff
on_trackbar_scalar( alpha_slide_scalar, 0 );

}

void on_trackbar_scalar( int, void* )
{
 alpha_scalar = (double) alpha_slide_scalar/alpha_slide_max_scalar ;
 src2_scalar = src1_scalar * alpha_scalar;

 imshow( "Scalar", src2_scalar );
}

