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

void permutation(const Mat& a,int *p,int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            *(p+i*512+j)=a.at<uchar>(size-1-i,size-1-j);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    /*
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
    */
    
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
    Mat image1 = readRawfile("/Users/TGsung/Desktop/Frac2018/lenna.raw", 512, 512);
    //Mat image2 = readRawfile("/Users/TGsung/Downloads/Frac2018/output000.raw", 512, 512);
    //Mat image3 = imread("/Users/TGsung/Downloads/Frac2018/04.png",1);
    int Domain[512][512];
    Mat output;
    output.create(512,512,CV_8U);
    permutation(image1,&Domain[0][0],512);
    int i,j;
    for(i=0;i<512;i++){
        for(j=0;j<512;j++){
            output.at<uchar>(i,j) = Domain[i][j];
        }
    }
    
    namedWindow("D", WINDOW_AUTOSIZE);
    imshow("D",output);
    imshow("A",image1);
    //double psnr = calpsnr(image1, image2);
    //cout << psnr;
    waitKey(0);
    return 0;
}
