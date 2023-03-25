#include <iostream>
#include <opencv2/opencv.hpp>

void min_filter(cv::Mat& img, int kernel_size) {
    if(kernel_size % 2 == 0) {
        throw std::invalid_argument("The kernel size must be odd!");
    }
    cv::Mat img_copy = img.clone();
    int half_kernel = kernel_size / 2;
    for(int i = half_kernel; i < img.rows - half_kernel; i++) {
        for(int j = half_kernel; j < img.cols - half_kernel; j++) {
            int min = 255;
            for(int k = -half_kernel; k <= half_kernel; k++) {
                for(int l = -half_kernel; l <= half_kernel; l++) {
                    if(img_copy.at<uchar>(i + k, j + l) < min) {
                        min = img_copy.at<uchar>(i + k, j + l);
                    }
                }
            }
            img.at<uchar>(i, j) = min;
        }
    }
}