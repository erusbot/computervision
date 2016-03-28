#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace cv;
using namespace std;

/// Global Variables
const int alpha_slider_max_g = 100;
int alpha_slider_g;
double alpha_g;
Mat frame;
void on_trackbar_gaussian( int, void* );

int main(int, char**)
{

/// Initialize values
alpha_slider_g = 0;
/// Create Trackbars
char TrackbarName[50];



    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
	//sprintf( TrackbarName, "Alpha x %d", alpha_slider_max_g );

	//createTrackbar( TrackbarName, "edges", &alpha_slider_g, alpha_slider_max_g, on_trackbar_gaussian );
/// Show some stuff
//on_trackbar_gaussian( alpha_slider_g, 0 );
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}

void on_trackbar_gaussian( int, void* )
{
 alpha_g = (double) alpha_slider_g ;
 Mat gaussian_noise = frame.clone();
 randn(gaussian_noise,128,alpha_g);
 Mat image_gaussian = gaussian_noise + frame;
 imshow("edges",image_gaussian);
}
