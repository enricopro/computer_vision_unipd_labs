#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img;
    img = imread("robocup.jpg");

    namedWindow("robocup");
    imshow("Robocup", img);
    waitKey(0);

    return 0;
}