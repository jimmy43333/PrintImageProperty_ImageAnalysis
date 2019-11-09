//
//  readRawfile.h
//  PrintImagesProperty_ImagaAnalysis
//
//  Created by 宋題均 on 2017/12/4.
//  Copyright © 2017年 宋題均. All rights reserved.
//

#ifndef readRawfile_h
#define readRawfile_h

using namespace std;
using namespace cv;
Mat readRawfile(const char* filename,int width,int height){
    Mat outputimage;
    //read the raw file
    FILE *fp = NULL;
    char *imagedata = NULL;
    int IMAGE_WIDTH = width;
    int IMAGE_HEIGHT = height;
    int framesize = IMAGE_WIDTH * IMAGE_HEIGHT;
    //Open raw Bayer image.
    fp = fopen(filename, "rb");
    if(!fp){
        cout << "read file failure";
        return outputimage;
    }
    //Memory allocation for bayer image data buffer.
    imagedata = (char*) malloc (sizeof(char) * framesize);
    //Read image data and store in buffer.
    fread(imagedata, sizeof(char), framesize, fp);
    //Create Opencv mat structure for image dimension. For 8 bit bayer, type should be CV_8UC1.
    outputimage.create(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC1);
    memcpy(outputimage.data, imagedata, framesize);
    free(imagedata);
    fclose(fp);
    return outputimage;
}

//Calculate psnr
double calpsnr(Mat& original, Mat& compress){
    double psnr = 0;
    double mse = 0 ;
    int tmp = 0;
    if(original.size() != compress.size()){
        return 0;
    }
    for(int i =0;i<original.rows;i++){
        for(int j = 0;j<original.cols;j++){
            tmp = original.at<uchar>(i,j) - compress.at<uchar>(i,j);
            mse += ( tmp * tmp );
        }
    }
    mse = mse/(original.rows * original.cols);
    psnr = 10 * log10((255*255)/mse);
    return psnr;
}
#endif /* readRawfile_h */

