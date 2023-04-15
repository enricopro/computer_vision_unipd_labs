#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image = imread("street_scene.png");
    Mat image_canny(image.rows, image.cols, CV_8UC1);
    Canny(image, image_canny, 50, 300, 3);
    namedWindow("Hough Image");
    vector<Vec2f> lines;
    HoughLines(image_canny, lines, 1, CV_PI / 180, 130);

    float min_rho_index = 0, max_rho_index = 0;

    for(size_t i = 0; i < lines.size(); i++){
        if(lines[i][0] < lines[min_rho_index][0]){
            min_rho_index = i;
        }
        if(lines[i][0] > lines[max_rho_index][0]){
            max_rho_index = i;
        }
    }

    //we compute m and q of the line with the minimum rho
    float m1 = -cos(lines[min_rho_index][1]) / sin(lines[min_rho_index][1]);
    float q1 = lines[min_rho_index][0] / sin(lines[min_rho_index][1]);

    //we compute m and q of the line with the maximum rho
    float m2 = -cos(lines[max_rho_index][1]) / sin(lines[max_rho_index][1]);
    float q2 = lines[max_rho_index][0] / sin(lines[max_rho_index][1]);

    //we color all the pixels between the two lines
    for(int i = 0; i < image.rows; i++){
        for(int j = 0; j < image.cols; j++){
            if(i > m1 * j + q1 && i > m2 * j + q2){
                image.at<Vec3b>(i, j)[0] = 0;
                image.at<Vec3b>(i, j)[1] = 0;
                image.at<Vec3b>(i, j)[2] = 255;
            }
        }
    }

    imshow("Hough Image", image);

    waitKey(0);

    return 0;
}