#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image = imread("street_scene.png");
    Mat gray = imread("street_scene.png", IMREAD_GRAYSCALE);
    vector<Vec3f> circles;
    GaussianBlur(gray, gray, Size(7, 7), 1.5, 1.5);
    HoughCircles(gray, circles, HOUGH_GRADIENT, 2, gray.rows/6, 300, 30, 0, 12);
    Point center(circles[0][0], circles[0][1]); //the method reutrn only one circle, the one around the sign
    int radius = circles[0][2];
    circle(image, center, radius, Scalar(0, 0, 255), -1);
    imshow("Sign on the street", image);

    waitKey(0);

    return 0;
}