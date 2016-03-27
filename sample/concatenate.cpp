#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "concatenate.h"

using namespace cv;
using namespace std;
		
void concatenate(cv::Mat image){

	Mat im1 = image;
	cout << "Image 2 path:\n";
	string image2;
	cin >> image2;
	Mat im2 = imread(image2);
if( !im1.data ) { printf("Error loading im1 \n"); return; }
if( !im2.data ) { printf("Error loading im2 \n"); return; }
	Size sz1 = im1.size();
	Size sz2 = im2.size();
	Mat im3(sz1.height, sz1.width+sz2.width, CV_8UC3);
	Mat left(im3, Rect(0, 0, sz1.width, sz1.height));
	im1.copyTo(left);
	Mat right(im3, Rect(sz1.width, 0, sz2.width, sz2.height));
	im2.copyTo(right);
	imshow("Concatenated Images", im3);
}
