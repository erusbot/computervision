#include <iostream>
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include "crop.h"

using namespace std;
using namespace cv;


Mat src,img,ROI;
Rect cropRect(0,0,0,0);
 Point P1(0,0);
 Point P2(0,0);

const char* winName="Crop Image";
bool clicked=false;
int i=0;
char imgName[15];


void checkBoundary(){
       //check croping rectangle exceed image boundary
       if(cropRect.width>img.cols-cropRect.x)
         cropRect.width=img.cols-cropRect.x;

       if(cropRect.height>img.rows-cropRect.y)
         cropRect.height=img.rows-cropRect.y;

        if(cropRect.x<0)
         cropRect.x=0;

       if(cropRect.y<0)
         cropRect.height=0;
}

void showImage(){
    img=src.clone();
    checkBoundary();
    if(cropRect.width>0&&cropRect.height>0){
        ROI=src(cropRect);
        imshow("cropped",ROI);
    }

    rectangle(img, cropRect, Scalar(0,255,0), 1, 8, 0 );
    imshow(winName,img);
}


void onMouse( int event, int x, int y, int f, void* ){


    switch(event){

        case  CV_EVENT_LBUTTONDOWN  :
                                        clicked=true;

                                        P1.x=x;
                                        P1.y=y;
                                        P2.x=x;
                                        P2.y=y;
                                        break;

        case  CV_EVENT_LBUTTONUP    :
                                        P2.x=x;
                                        P2.y=y;
                                        clicked=false;
                                        break;

        case  CV_EVENT_MOUSEMOVE    :
                                        if(clicked){
                                        P2.x=x;
                                        P2.y=y;
                                        }
                                        break;

        default                     :   break;


    }


    if(clicked){
     if(P1.x>P2.x){ cropRect.x=P2.x;
                       cropRect.width=P1.x-P2.x; }
        else {         cropRect.x=P1.x;
                       cropRect.width=P2.x-P1.x; }

        if(P1.y>P2.y){ cropRect.y=P2.y;
                       cropRect.height=P1.y-P2.y; }
        else {         cropRect.y=P1.y;
                       cropRect.height=P2.y-P1.y; }

    }


showImage();


}
void crop(cv::Mat image)
{

    cout<<"Click and drag for Selection"<<endl<<endl;
    cout<<"------> Press 's' to save"<<endl<<endl;

    cout<<"------> Press '8' to move up"<<endl;
    cout<<"------> Press '2' to move down"<<endl;
    cout<<"------> Press '6' to move right"<<endl;
    cout<<"------> Press '4' to move left"<<endl<<endl;

    cout<<"------> Press 'w' increas top"<<endl;
    cout<<"------> Press 'x' increas bottom"<<endl;
    cout<<"------> Press 'd' increas right"<<endl;
    cout<<"------> Press 'a' increas left"<<endl<<endl;

    cout<<"------> Press 't' decrease top"<<endl;
    cout<<"------> Press 'b' decrease bottom"<<endl;
    cout<<"------> Press 'h' decrease right"<<endl;
    cout<<"------> Press 'f' decrease left"<<endl<<endl;

    cout<<"------> Press 'r' to reset"<<endl;
    cout<<"------> Press 'Esc' to quit"<<endl<<endl;


    src=image;

    namedWindow(winName,WINDOW_AUTOSIZE);
    setMouseCallback(winName,onMouse,NULL );
    imshow(winName,src);

    while(1){
    char c=waitKey();
    if(c=='s'&&ROI.data){
     sprintf(imgName,"%d.jpg",i++);
     imwrite(imgName,ROI);
     cout<<"  Saved "<<imgName<<endl;
    }
    if(c=='6') cropRect.x+=10;
    if(c=='4') cropRect.x-=10;
    if(c=='8') cropRect.y-=10;
    if(c=='2') cropRect.y+=10;

    if(c=='w') { cropRect.y-=10; cropRect.height+=10;}
    if(c=='d') cropRect.width+=10;
    if(c=='x') cropRect.height+=10;
    if(c=='a') { cropRect.x-=10; cropRect.width+=10;}

    if(c=='t') { cropRect.y+=10; cropRect.height-=10;}
    if(c=='h') cropRect.width-=10;
    if(c=='b') cropRect.height-=10;
    if(c=='f') { cropRect.x+=10; cropRect.width-=10;}

    if(c==27) break;
    if(c=='r') {cropRect.x=0;cropRect.y=0;cropRect.width=0;cropRect.height=0;}
    showImage();

    }
}

