#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    Mat img;
    img = imread("street_scene.png");
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
    
    struct RGB sky_rgb = { 130, 212, 255, 70 };
    struct RGB asphalt_rgb = { 118, 121, 122, 40 };
    struct RGB stripes_rgb = { 254, 254, 254, 40 };

    Mat sky_mask = img.clone();
    Mat asphalt_mask = img.clone();
    Mat stripes_mask = img.clone();

    //creation of the sky mask
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (!(abs(img.at<Vec3b>(i, j)[0] - sky_rgb.b) < sky_rgb.threshold && abs(img.at<Vec3b>(i, j)[1] - sky_rgb.g) < sky_rgb.threshold && abs(img.at<Vec3b>(i, j)[2] - sky_rgb.r) < sky_rgb.threshold)) {
                sky_mask.at<Vec3b>(i, j)[0] = 0;
                sky_mask.at<Vec3b>(i, j)[1] = 0;
                sky_mask.at<Vec3b>(i, j)[2] = 0;
            }
        }
    }

    //creation of the asphalt mask
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (!(abs(img.at<Vec3b>(i, j)[0] - asphalt_rgb.b) < asphalt_rgb.threshold && abs(img.at<Vec3b>(i, j)[1] - asphalt_rgb.g) < asphalt_rgb.threshold && abs(img.at<Vec3b>(i, j)[2] - asphalt_rgb.r) < asphalt_rgb.threshold)) {
                asphalt_mask.at<Vec3b>(i, j)[0] = 0;
                asphalt_mask.at<Vec3b>(i, j)[1] = 0;
                asphalt_mask.at<Vec3b>(i, j)[2] = 0;
            }
        }
    }

    //creation of the stripes mask
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (!(abs(img.at<Vec3b>(i, j)[0] - stripes_rgb.b) < stripes_rgb.threshold && abs(img.at<Vec3b>(i, j)[1] - stripes_rgb.g) < stripes_rgb.threshold && abs(img.at<Vec3b>(i, j)[2] - stripes_rgb.r) < stripes_rgb.threshold)) {
                stripes_mask.at<Vec3b>(i, j)[0] = 0;
                stripes_mask.at<Vec3b>(i, j)[1] = 0;
                stripes_mask.at<Vec3b>(i, j)[2] = 0;
            }
        }
    }

    Mat layered = Mat::zeros(img.size(), CV_8UC3);
    
    //sky mask coloring
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (sky_mask.at<Vec3b>(i, j)[0] != 0 && sky_mask.at<Vec3b>(i, j)[1] != 0 && sky_mask.at<Vec3b>(i, j)[2] != 0) {
                layered.at<Vec3b>(i, j)[0] = 255;
                layered.at<Vec3b>(i, j)[1] = 212;
                layered.at<Vec3b>(i, j)[2] = 130;
            }
        }
    }

    //asphalt mask coloring
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (asphalt_mask.at<Vec3b>(i, j)[0] != 0 && asphalt_mask.at<Vec3b>(i, j)[1] != 0 && asphalt_mask.at<Vec3b>(i, j)[2] != 0) {
                layered.at<Vec3b>(i, j)[0] = 0;
                layered.at<Vec3b>(i, j)[1] = 0;
                layered.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }
    
    //stripes mask coloring
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (stripes_mask.at<Vec3b>(i, j)[0] != 0 && stripes_mask.at<Vec3b>(i, j)[1] != 0 && stripes_mask.at<Vec3b>(i, j)[2] != 0) {
                layered.at<Vec3b>(i, j)[0] = 0;
                layered.at<Vec3b>(i, j)[1] = 0;
                layered.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }

    imshow("Layered", layered);
    waitKey(0);

    return 0;
}