#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sp_noise.h"

using namespace cv;
using namespace std;

/// Global Variables
const int alpha_slider_max_sp = 255;
int alpha_slider_sp;
double alpha_sp;
double beta_sp;

/// Matrices to store images
Mat src1_sp;

void sp_noise(cv::Mat image){
/// Read image ( same size, same type )
src1_sp = image;

if( !src1_sp.data ) { printf("Error loading src1 \n"); return; }


/// Initialize values
alpha_slider_sp = 0;

/// Create Windows
namedWindow("SP", 1);

/// Create Trackbars
char TrackbarName[50];
sprintf( TrackbarName, "Alpha x %d", alpha_slider_max_sp );

createTrackbar( TrackbarName, "SP", &alpha_slider_sp, alpha_slider_max_sp, on_trackbar_sp );

/// Show some stuff
on_trackbar_sp( alpha_slider_sp, 0 );

}

void on_trackbar_sp( int, void* )
{
 alpha_sp = (double) alpha_slider_sp ;
 beta_sp = (255 - alpha_sp);
 Mat sp_noise = Mat::zeros(src1_sp.rows, src1_sp.cols,CV_8U);
 randu(sp_noise,0,255);
 Mat black = sp_noise < alpha_sp;
 Mat white = sp_noise > beta_sp;
 Mat sp_img = src1_sp.clone();
 sp_img.setTo(255,white);
 sp_img.setTo(0,black);
 //Mat image_sp = sp_noise + sp_img;
 imshow("SP",sp_img);
}
