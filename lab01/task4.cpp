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
        //channel 1
        cv::Mat img1(img.rows, img.cols, CV_8UC1);
        for (int i = 0; i < img.rows; i++) {
            for (int j = 0; j < img.cols; j++) {
                img1.at<uchar>(i, j) = img.at<cv::Vec3b>(i, j)[0];
            }
        }

        //channel 2
        cv::Mat img2(img.rows, img.cols, CV_8UC1);
        for (int i = 0; i < img.rows; i++) {
            for (int j = 0; j < img.cols; j++) {
                img2.at<uchar>(i, j) = img.at<cv::Vec3b>(i, j)[1];
            }
        }

        //channel 3
        cv::Mat img3(img.rows, img.cols, CV_8UC1);
        for (int i = 0; i < img.rows; i++) {
            for (int j = 0; j < img.cols; j++) {
                img3.at<uchar>(i, j) = img.at<cv::Vec3b>(i, j)[2];
            }
        }
        cv::imshow("Channel 1", img1);
        cv::imshow("Channel 2", img2);
        cv::imshow("Channel 3", img3);
        cv::waitKey(0);
    }

    return 0;
}