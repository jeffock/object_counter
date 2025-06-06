#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include "tinyfiledialogs.h"

using namespace cv;

Mat showBlueChannelOnly(const Mat& img)
{
    Mat blueOnly = img.clone();

    std::vector<Mat> channels(3);
    split(blueOnly, channels);

    channels[1] = Mat::zeros(channels[1].size(), channels[1].type()); // Zero Green
    channels[2] = Mat::zeros(channels[2].size(), channels[2].type()); // Zero Red

    merge(channels, blueOnly);
    return blueOnly;
}

//TODO
Mat toGrayscale(const Mat& img)
{
    Mat grayscale = img.clone();

    return grayscale;
}

//TODO
Mat gaussianFilter(const Mat& img)
{
    Mat blurredImg = img.clone();

    return blurredImg;
}

//TODO
Mat intensityThreshold(const Mat& img)
{
    Mat pixIntensityThresh = img.clone();

    return pixIntensityThresh;
}

struct WatershedOutput {
    Mat watershedOutImg;
    int count;
};

//TODO
WatershedOutput runWatershed(const Mat& img) 
{
    Mat watershedImg = img.clone();
    int objCount = 0;

    return {watershedImg, objCount};
}

int main()
{
    const char* filetypes[] = { "*.jpg", "*.png", "*.tif", "*.bmp" };
    const char* image_path = tinyfd_openFileDialog(
        "Select an image",
        "",
        4, filetypes,
        "Image files",
        0);

    if (!image_path) {
        std::cout << "No file selected.\n";
        return 1;
    }

    Mat img = imread(image_path, IMREAD_COLOR);

    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    imshow("Display window", img);
    int firstKey = waitKey(0);

    if (firstKey == 'c')
    {
        Mat blueOnly = showBlueChannelOnly(img);
        imshow("Display window", blueOnly);
        waitKey(0);
    }

    //TODO
    // write waitKey & related if statements for all steps

    return 0;
}


