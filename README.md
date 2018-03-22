== PrintImagesProperty == 

##Introduction  
This is the file that includes some images analysis function.  

##Header file  
+ CulculateCDF.h  
vector<int> CulculateCDF(Mat& input,int range,const String& outputname)  
return the cdf of images.  
+ RGBHistogram.h  
void RGBHistogram(const String& filename,const String& outputname)  
generate the image that show the rgb histogram of the images.  
+ readRowfile.h  
Mat readRawfile(const char* filename,int width,int height)  
Can read the raw file and convert to Mat format.  


