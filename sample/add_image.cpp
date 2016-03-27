#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "add_image.h"

using namespace cv;
using namespace std;

/// Matrices to store images
Mat src1_add;
Mat src2_add;
Mat src3_add;
void add_image(cv::Mat image){
/// Read image ( same size, same type )
src1_add = image;

string image2;
cout << "Image 2 path:\n";
cin >> image2;
src2_add = imread(image2);

if( !src1_add.data ) { printf("Error loading src1 \n"); return; }
if( !src2_add.data ) { printf("Error loading src2 \n"); return; }

/// Create Windows
namedWindow("Add Image", 1);
src3_add = src1_add + src2_add;
imshow("Add Image", src3_add);
}

