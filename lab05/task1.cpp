#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    vector<string> imagePaths = {"Asphalt-1.png", "Asphalt-2.png", "Asphalt-3.png"};

    for (const auto& imagePath : imagePaths) {
        Mat image = imread(imagePath, IMREAD_GRAYSCALE);
        Mat binaryImage(image.rows, image.cols, CV_8UC1, Scalar(0));

        //blur image
        GaussianBlur(image, image, Size(3, 3), 0);
        GaussianBlur(image, image, Size(3, 3), 0);

        //log transform method
        Mat logImage(image.rows, image.cols, CV_8UC1, Scalar(0));
        for (int i = 0; i < image.rows; i++) {
            for (int j = 0; j < image.cols; j++) {
                logImage.at<uchar>(i, j) = (uchar)(255 * log(1 + image.at<uchar>(i, j)) / log(256));
            }
        }

        //normalize image
        normalize(logImage, logImage, 0, 255, NORM_MINMAX, CV_8UC1);

        //bilateral filter
        Mat bilateralImage(image.rows, image.cols, CV_8UC1, Scalar(0));
        bilateralFilter(logImage, bilateralImage, 7, 75, 75);

        //canny edge detection
        Canny(bilateralImage, binaryImage, 60, 150, 3);
        imshow("Binary Image", binaryImage);
        waitKey(0);

    }

    return 0;
}
