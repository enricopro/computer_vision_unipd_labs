#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

struct MyValues {
    Mat image;
    int threshold;
    int max_threshold;
    int ratio;
    int kernel_size;
};

void cannyAlgorithm(int pos, void* vals) {
    MyValues* myValues = (MyValues*)vals;
    myValues->threshold = pos;
    Mat canny_output = myValues->image.clone();
    GaussianBlur(canny_output, canny_output, Size(5, 5), 0, 0);
    Canny(canny_output, canny_output, myValues->threshold, myValues->threshold * myValues->ratio, myValues->kernel_size);
    imshow("Canny Image", canny_output); 
    return;
}

int main(int argc, char** argv)
{
    Mat image = imread("street_scene.png");

    namedWindow("Canny Image");

    MyValues* myValues = new MyValues();
    cvtColor(image, myValues->image, COLOR_BGR2GRAY);
    myValues->threshold = 0;
    myValues->max_threshold = 500;
    myValues->ratio = 3;
    myValues->kernel_size = 5;

    createTrackbar("Threshold for the hysteresis procedure:", "Canny Image", nullptr, myValues->max_threshold, cannyAlgorithm, myValues);
    setTrackbarPos("Threshold for the hysteresis procedure:", "Canny Image", myValues->threshold);

    imshow("Canny Image", image);

    waitKey(0);

    return 0;
}