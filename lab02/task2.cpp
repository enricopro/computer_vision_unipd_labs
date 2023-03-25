#include <opencv2/opencv.hpp>
#include <iostream>
#include "max_filter.cpp"
#include "min_filter.cpp"

//use the max filter function importing it from the max_filter.cpp file

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Error: insert the image name! \n";
        return 0;
    }
    cv::Mat img = cv::imread(argv[1], CV_8U);
    if(img.data == NULL) {
        std::cout << "Error: wrong name! \n";
        return 0;
    }

    max_filter(img, 5);
    cv::imshow("image max filter", img);
    cv::waitKey(0);
}