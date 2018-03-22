//
//  RGBHistogram.h
//  PrintImagesProperty_ImageAnalysis
//
//  Created by 宋題均 on 2017/12/4.
//  Copyright © 2017年 宋題均. All rights reserved.
//

#ifndef RGBHistogram_h
#define RGBHistogram_h

using namespace std;
using namespace cv;
void RGBHistogram(const String& filename,const String& outputname){
    Mat src, dst;
    //Read image
    src = imread(filename, 1 );    //0< read original; 0 gray ; >0 BGR
    if( !src.data ){
        return;
    }
    //Separate the image in 3 places ( B, G and R )
    vector<Mat> bgr;
    split( src, bgr );
    //Establish the number of bins
    int histSize = 256;
    //Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };
    bool uniform = true;
    bool accumulate = false;

    Mat b_hist, g_hist, r_hist;
    //Compute the histograms
    calcHist( &bgr[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

    // Draw the histograms for B, G and R
    int hist_w = 512; int hist_h = 512;
    int bin_w = cvRound( (double) hist_w/histSize );
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 255,255,255) );
    //Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    //Draw for each channel
    for( int i = 1; i < histSize; i++ ){
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
             Scalar( 255, 0, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
             Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
             Scalar( 0, 0, 255), 2, 8, 0  );
    }
    //Write the images
    imwrite(outputname,histImage);
}
#endif /* RGBHistogram_h */
