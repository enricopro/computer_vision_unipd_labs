#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) {

    Mat img = *(Mat*)param;
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "BGR: " << img.at<Vec3b>(y, x) << endl;
    }
}

int main(int argc, char** argv) {

    Mat img;
    img = imread("robocup.jpg");

    imshow("Robocup", img);
    setMouseCallback("Robocup", onMouse, (void*)&img);
    waitKey(0);

    return 0;
}