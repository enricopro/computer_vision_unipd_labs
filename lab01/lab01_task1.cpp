#include <opencv2/highgui.hpp>
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
    cv::namedWindow("Example 1");
    cv::imshow("Example 1", img);
    cv::waitKey(0);

    return 0;    
}