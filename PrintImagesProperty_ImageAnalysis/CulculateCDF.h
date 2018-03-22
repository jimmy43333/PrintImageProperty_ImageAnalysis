//
//  CulculateCDF.h
//  PrintImagesProperty_ImageAnalysis
//
//  Created by 宋題均 on 2017/12/4.
//  Copyright © 2017年 宋題均. All rights reserved.
//

#ifndef CulculateCDF_h
#define CulculateCDF_h
#include <vector>
using namespace std;
using namespace cv;

vector<int> CulculateCDF(Mat& input,int range,const String& outputname){
    vector<int> pdf(range,0);
    vector<int> cdf(range,0);
    Mat src = input;
    double total = src.rows * src.cols ;
    //calculate pdf
    for(int i =0;i<src.rows;i++){
        for(int j =0;j<src.cols;j++){
            if(src.at<uchar>(i,j) < range){
                pdf[(int)src.at<uchar>(i,j)]++;
            }
        }
    }
    //calculate cdf
    for(int i =0;i< cdf.size();i++){
        for(int j=0;j <= i;j++){
            cdf[i] += pdf[j];
        }
    }
    
    //Show the cdf result
    int r_h = 512;
    int r_w = 512;
    int bin_w = r_w/cdf.size();
    Mat result(r_h,r_w,CV_8UC3,Scalar( 255,255,255) );
    for(int i =1;i<cdf.size();i++){
        line(result,Point(bin_w *(i-1), cvRound(r_h*(1-(cdf[i-1]/total)))),Point(bin_w *(i),cvRound(r_h*(1-(cdf[i]/total)))),Scalar(255,0,0),2,8,0);
    }
    imwrite(outputname,result);
    return cdf;
}

#endif /* CulculateCDF_h */
