#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) {

    Mat img = *(Mat*)param;
    if (event == EVENT_LBUTTONDOWN)
    {
        int sumB = 0;
        int sumG = 0;
        int sumR = 0;
        for (int i = -4; i < 5; i++) {
            for (int j = -4; j < 5; j++) {
                sumB += img.at<Vec3b>(y + i, x + j)[0];
                sumG += img.at<Vec3b>(y + i, x + j)[1];
                sumR += img.at<Vec3b>(y + i, x + j)[2];
            }
        }
        cout << "Mean BGR: " << sumB / 81 << " " << sumG / 81 << " " << sumR / 81 << endl; //81 because 9x9
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