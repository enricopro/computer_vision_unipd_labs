#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    Mat img;
    img = imread("robocup.jpg");
    if (img.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    struct RGB {
        int r;
        int g;
        int b;
        int threshold;
    };
    
    struct RGB tshirt_rgb = { 168, 119, 24, 45 };

    Mat mask = Mat::zeros(img.rows, img.cols, CV_8UC3);

    for(int i = 0; i < img.rows; i++) {
        for(int j = 0; j < img.cols; j++) {
            if((abs(img.at<Vec3b>(i, j)[0] - tshirt_rgb.b) < tshirt_rgb.threshold && abs(img.at<Vec3b>(i, j)[1] - tshirt_rgb.g) < tshirt_rgb.threshold && abs(img.at<Vec3b>(i, j)[2] - tshirt_rgb.r) < tshirt_rgb.threshold)) {
                mask.at<Vec3b>(i, j)[0] = 255;
                mask.at<Vec3b>(i, j)[1] = 255;
                mask.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }

    imshow("T-shirts", mask);
    waitKey(0);

    return 0;
}