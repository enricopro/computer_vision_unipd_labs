#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Error: insert the image name! \n";
        return 0;
    }
    cv::Mat img = cv::imread(argv[1]);
    if(img.data == NULL) {
        std::cout << "Error: wrong name! \n";
        return 0;
    }
    cv::Mat img_grayscale(img.rows, img.cols, CV_8U);
    cv::cvtColor(img, img_grayscale, cv::COLOR_BGR2GRAY);

    cv::Mat img_median(img.rows, img.cols, CV_8U);
    cv::medianBlur(img_grayscale, img_median, 5);
    cv::imshow("image median filter", img);
    cv::waitKey(0);

    cv::Mat img_gaussian(img.rows, img.cols, CV_8U);
    cv::GaussianBlur(img_grayscale, img_gaussian, cv::Size(5, 5), 0, 0, cv::BORDER_DEFAULT);
    cv::imshow("image gaussian filter", img_grayscale);
    cv::waitKey(0);
}