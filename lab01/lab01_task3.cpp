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
    std::cout << "Number of channels: " << img.channels() << std::endl;
    if (img.channels() == 3) {
        cv::Mat_<cv::Vec3b> _img = img;
        for (int i = 0; i < _img.rows; i++) {
            for (int j = 0; j < _img.cols; j++) {
                _img(i, j)[0] = 0;
            }
        }
        img = _img;
    }
    cv::namedWindow("Example 1");   
    cv::imshow("Example 1", img);
    cv::waitKey(0);

    return 0;
}