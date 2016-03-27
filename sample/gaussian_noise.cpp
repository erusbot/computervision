#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gaussian_noise.h"

using namespace cv;
using namespace std;

/// Global Variables
const int alpha_slider_max_g = 100;
int alpha_slider_g;
double alpha_g;


/// Matrices to store images
Mat src1_g;

void gaussian_noise(cv::Mat image){
/// Read image ( same size, same type )
src1_g = image;

if( !src1_g.data ) { printf("Error loading src1 \n"); return; }


/// Initialize values
alpha_slider_g = 0;

/// Create Windows
namedWindow("Gaussian", 1);

/// Create Trackbars
char TrackbarName[50];
sprintf( TrackbarName, "Alpha x %d", alpha_slider_max_g );

createTrackbar( TrackbarName, "Gaussian", &alpha_slider_g, alpha_slider_max_g, on_trackbar_gaussian );

/// Show some stuff
on_trackbar_gaussian( alpha_slider_g, 0 );

}

void on_trackbar_gaussian( int, void* )
{
 alpha_g = (double) alpha_slider_g ;
 Mat gaussian_noise = src1_g.clone();
 randn(gaussian_noise,128,alpha_g);
 Mat image_gaussian = gaussian_noise + src1_g;
 imshow("Gaussian",image_gaussian);
}
