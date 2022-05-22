#define _USE_MATH_DEFINES
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include "header.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "C:\C++\eigen-3.4.0\Eigen\Dense"
#include "C:\C++\eigen-3.4.0\Eigen\Geometry"
#include "C:\C++\eigen-3.4.0\unsupported\Eigen\CXX11\Tensor"
#include <opencv2/core/eigen.hpp>
#include <cmath>
using namespace cv;
using namespace Eigen;



int main()
{

    /*std::string image_path = "C:/Users/Domi/Desktop/cppTrials/OpenCv/opencvReuseTest/opencvReuseTest/Lea.PNG";
    Mat img = imread(image_path, IMREAD_GRAYSCALE);
    img = img -16;
    img = img+2;
    convertScaleAbs(img, img, 0.8, 0);
    MatrixXd imgEigen;
    cv2eigen(img, imgEigen);
    
    imgEigen = imgEigen / 255.0;
    AsciH testObj;
  
    testObj.printMatrix(imgEigen,70);
    system("pause");*/
    

    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if (!cap.open(0))
        return 0;
    for (;;)
    {
        Mat frame;
        cap >> frame;
        cvtColor(frame,frame, COLOR_BGR2GRAY);
        MatrixXd imgEigen;
        cv2eigen(frame, imgEigen);

        imgEigen = imgEigen / 255.0;
        AsciH testObj;
        system("cls");
        testObj.printMatrix(imgEigen, 130);
        if (waitKey(10) == 27) break; // stop capturing by pressing ESC 
    }
    
    return 0;
}