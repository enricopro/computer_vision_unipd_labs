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
    cv::imwrite("image_grayscale.jpg", img_grayscale);
}