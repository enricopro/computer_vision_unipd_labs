//dipende molto dalla parte di maglietta selezionata, con 70 si inizia a selezionare anche la palla

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void onMouse(int event, int x, int y, int flags, void* param) {

    Mat img = *(Mat*)param;
    int theshold = 50;
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
        sumB /= 81;
        sumG /= 81;
        sumR /= 81;
        
        cout << "Mean BGR: " << sumB << " " << sumG << " " << sumR << endl; //81 because 9x9

        Mat mask = img.clone();
        
        for(int i = 0; i < img.rows; i++) {
            for(int j = 0; j < img.cols; j++) {
                if(!(abs(img.at<Vec3b>(i, j)[0] - sumB) < theshold && abs(img.at<Vec3b>(i, j)[1] - sumG) < theshold && abs(img.at<Vec3b>(i, j)[2] - sumR) < theshold)) {
                    mask.at<Vec3b>(i, j)[0] = 0;
                    mask.at<Vec3b>(i, j)[1] = 0;
                    mask.at<Vec3b>(i, j)[2] = 0;
                }
            }
        }
        
        /*
        for(int i = 0; i < img.rows; i++) {
            for(int j = 0; j < img.cols; j++) {
                if(!(sqrt(pow(img.at<Vec3b>(i, j)[0] - sumB, 2) + pow(img.at<Vec3b>(i, j)[1] - sumG, 2) + pow(img.at<Vec3b>(i, j)[2] - sumR, 2)) < theshold)) {
                    mask.at<Vec3b>(i, j)[0] = 0;
                    mask.at<Vec3b>(i, j)[1] = 0;
                    mask.at<Vec3b>(i, j)[2] = 0;
                }
            }
        }
        */
        imshow("Mask", mask);
        waitKey(0);
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