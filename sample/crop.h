#ifndef CROP_H_
#define CROP_H_


void checkBoundary();
void showImage();
void onMouse( int event, int x, int y, int f, void* );
void crop(cv::Mat image);


#endif
