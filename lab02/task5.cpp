#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv){
   cv::Mat img = cv::imread("image_grayscale.jpg");
   cv::Mat gray = cv::Mat();
   cv::cvtColor(img, gray, cv::COLOR_RGB2GRAY, 0);
   cv::namedWindow("Example 1");
   cv::imshow("Example 1", gray);
   cv::waitKey();
   std::vector<cv::Mat> gray_planes;
   cv::split( gray, gray_planes );
   int n = 256;
   float range[] = { 0, (float)n }; //the upper boundary is exclusive
   const float* histRange[] = { range };
   bool uniform = true, accumulate = false;
   cv::Mat hist;
   cv::calcHist( &gray_planes[0], 1, 0, cv::Mat(), hist, 1, &n, histRange, uniform, accumulate );

   int w = 512, h = 400;
   int bin_w = cvRound( (double) w/n );
   cv::Mat histImage( h, w, CV_8UC1);
   cv::normalize(hist, hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
   for( int i = 1; i < n; i++ ){
      cv::line( histImage, cv::Point( bin_w*(i-1), h - cvRound(hist.at<float>(i-1)) ) ,
                     cv::Point( bin_w*(i), h - cvRound(hist.at<float>(i)) ),
                     cv::Scalar(255), 2, 8, 0  );
   }
   cv::namedWindow("Histogram");
   cv::imshow("Histogram", histImage );
   cv::waitKey();

   cv::Mat equalized;
   cv::equalizeHist( gray, equalized );
   cv::namedWindow("Equalized");
   cv::imshow("Equalized", equalized );
   cv::waitKey();

   return 0;   
}
