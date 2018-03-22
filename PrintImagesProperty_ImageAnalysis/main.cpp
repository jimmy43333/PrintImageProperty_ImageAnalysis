//
//  main.cpp
//  PrintImagesProperty_ImageAnalysis
//
//  Created by 宋題均 on 2017/12/4.
//  Copyright © 2017年 宋題均. All rights reserved.
//

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "readRawfile.h"
#include "RGBHistogram.h"
#include "CulculateCDF.h"
using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    Mat input = imread("/Users/TGsung/Desktop/mini.jpg",1);
    for(int i=0;i< input.rows;i++){
        for(int j=0;j<input.cols;j++){
            input.at<Vec3b>(i,j)[1] = i%255;
            input.at<Vec3b>(i,j)[2] = 25;
            input.at<Vec3b>(i,j)[3] = 25;
        }
    }
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", input);
    waitKey(0);
    /*
    Mat face = readRawfile("/Users/TGsung/Desktop/Dataset/880372.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face1.jpg",face);
    vector<int> cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f1.jpg");
    face = readRawfile("/Users/TGsung/Desktop/Dataset/881530.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face2.jpg",face);
    cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f2.jpg");
    face = readRawfile("/Users/TGsung/Desktop/Dataset/882515.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face3.jpg",face);
    cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f3.jpg");
    face = readRawfile("/Users/TGsung/Desktop/Dataset/891538.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face4.jpg",face);
    cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f4.jpg");
    face = readRawfile("/Users/TGsung/Desktop/Dataset/891539.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face5.jpg",face);
    cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f5.jpg");
    face = readRawfile("/Users/TGsung/Desktop/Dataset/892539.raw", 128, 128);
    imwrite("/Users/TGsung/Desktop/face6.jpg",face);
    cdf = CulculateCDF(face,256,"/Users/TGsung/Desktop/f6.jpg");
    
    RGBHistogram("/Users/TGsung/Desktop/Dataset/carriers.jpg", "/Users/TGsung/Desktop/C.jpg");
    RGBHistogram("/Users/TGsung/Desktop/Dataset/Nijubashi.jpg", "/Users/TGsung/Desktop/N.jpg");
    RGBHistogram("/Users/TGsung/Desktop/Dataset/SleepingDog.jpg", "/Users/TGsung/Desktop/S.jpg");
    RGBHistogram("/Users/TGsung/Desktop/Dataset/Daibutsu.jpg", "/Users/TGsung/Desktop/D.jpg");
    */
    return 0;
}
