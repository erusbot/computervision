//Autor : rhuancaetano@gmail.com

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//lib para usar cvtColor
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
// iniciando
using namespace cv;
using namespace std;

//Crop Image (ROI) 
void createCropImage(Mat image){
	Rect roiRec = Rect(120,20,280,280);
	Mat roi(image, roiRec);
  namedWindow( "ROI Region of Interest", WINDOW_AUTOSIZE );
  imshow( "ROI Region of Interest",  roi ); 
}

void isolateChannelsImage(Mat image){
	Mat channel[3], redChannel, blueChannel, greenChannel;
    
  //Isolate Channel
  split(image,channel);
	namedWindow( "Isolate Channel", WINDOW_AUTOSIZE );
  imshow( "Isolate Channel",  channel[0]);
    
  //BLUE
  split(image,channel);
	channel[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	channel[2]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	merge(channel, 3, blueChannel);
	namedWindow( "BLUE Channel", WINDOW_AUTOSIZE );
  imshow( "BLUE Channel",  blueChannel );
    
  //GREEN
  split(image,channel);
	channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	channel[2]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	merge(channel, 3, greenChannel);
	namedWindow( "GREEN Channel", WINDOW_AUTOSIZE );
  imshow( "GREEN Channel",  greenChannel );
    
  //RED
  split(image,channel);
	channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	channel[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);
	merge(channel, 3, redChannel);
	namedWindow( "RED Channel", WINDOW_AUTOSIZE );
  imshow( "RED Channel",  redChannel );
}

void concatenateImage(Mat im1, Mat im2){
  Size sz1 = im1.size();
  Size sz2 = im2.size();
  Mat im3(sz1.height, sz1.width+sz2.width, CV_8UC3);
  // Move right boundary to the left.
  im3.adjustROI(0, 0, 0, -sz2.width);
  im1.copyTo(im3);
  // Move the left boundary to the right, right boundary to the right.
  im3.adjustROI(0, 0, -sz1.width, sz2.width);
  im2.copyTo(im3);
  // restore original ROI.
  im3.adjustROI(0, 0, sz1.width, 0);
  namedWindow( "Concatenated Image", WINDOW_AUTOSIZE );
  imshow("Concatenated Image", im3);
}


	// Threshold Function variables
	char trackbar_type[200] = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
	char trackbar_value[10] = "Value";
	char window_name[20] = "Adjust Image";
	int threshold_value = 0;
	int threshold_type = 3;
	int const max_value = 255;
	int const max_type = 4;
	int const max_BINARY_value = 255;
	Mat grayImageThreshold;

void Threshold_Function( int, void*){
	/* 0: Binary
     1: Binary Inverted
     2: Threshold Truncated
     3: Threshold to Zero
     4: Threshold to Zero Inverted
   */

	Mat newImage;
  threshold( grayImageThreshold, newImage, threshold_value, max_BINARY_value,threshold_type );

  imshow( window_name, newImage );
}

void adjustImage(Mat image){
	cvtColor(image, grayImageThreshold, CV_BGR2GRAY);
	namedWindow( window_name, WINDOW_AUTOSIZE );
	
	/// Create Trackbar to choose type of Threshold
  createTrackbar( trackbar_type, window_name, &threshold_type, max_type, Threshold_Function );
  createTrackbar( trackbar_value, window_name, &threshold_value, max_value, Threshold_Function );

	/// Call the function to initialize
  Threshold_Function( 0, 0);
}


int main( int argc, char** argv ){
	if( argc < 2)
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
    
    cout << "Number of channels: " << image.channels() << endl;
	Size s = image.size();
	cout << "Width: " << s.width << endl;
	cout << "Height: " << s.height << endl;
	
        //adjustImage(image);
	//concatenateImage(image, image);
	//createCropImage(image);
	//isolateChannelsImage(image);    
    
    namedWindow( "Original Image", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Original Image", image );              // Show our image inside it.

    waitKey(0);                                   // Wait for a keystroke in the window
    return 0;
}

