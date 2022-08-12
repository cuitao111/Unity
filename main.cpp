#include<opencv2/opencv.hpp>
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

int otsu(int gray[256], int tol){
    int ans_T = 256;
    double var, best_var = 0;
    for (int T = 0; T < 256; ++T) {
        int sum0 = 0, sum1 = 0;
        int num0 = 0, num1 = 0;
        for (int i = 0; i < T; ++i) {
            num0 += gray[i];
            sum0 += i * gray[i];
        }
        for (int i = T; i < 256; ++i) {
            num1 += gray[i];
            sum1 += i * gray[i];
        }
        double u0 = (double)sum0 / num0;
        double w0 = (double)num0 / tol;
        double u1 = (double)sum1 / num1;
        double w1 = (double)num1 / tol;
        double u = (double)(sum0 + sum1) / tol;
        var = w0 * (u0 - u) * (u0 - u) + w1 * (u1 - u) * (u1 - u);
        if (var > best_var){
            best_var = var;
            ans_T = T;
        }
    }
    return ans_T;
}

cv::Mat get_gray(cv::Mat src, cv::Mat mask){
    cv::Mat tmp = cv::Mat::zeros(src.rows, src.cols, CV_8UC1);
    for (int i = 0; i < mask.rows; i += 100) {
        for (int j = 0; j < mask.cols; j += 100) {
            int gray[256] = { 0 }, num = 0, sum = 0;
            for (int x = 0; x < 100; ++x) {
                for (int y = 0; y < 100; ++y) {
                    int nx = i + x, ny = j + y;
                    if (nx >= mask.rows || ny >= mask.cols) continue;
                    num++;
                    if (!mask.at<uchar>(nx, ny)) continue;
                    int val = src.at<uchar>(nx, ny);
                    gray[val]++;
                    sum++;
                }
            }
            if (sum < 50) continue;
            int T = otsu(gray, num);
            //printf("%d %d\n", sum, T);
            for (int x = 0; x < 100; ++x) {
                for (int y = 0; y < 100; ++y) {
                    int nx = i + x, ny = j + y;
                    if (nx >= mask.rows || ny >= mask.cols) continue;
                    int val = src.at<uchar>(nx, ny);
                    if (val >= T) tmp.at<uchar>(nx, ny) = 255;
                }
            }
        }
    }
    return tmp;
}

cv::Mat dilate_progress(cv::Mat src, cv::Mat mask){
    for (int i = 0; i < mask.rows; ++i) {
        for (int j = 0; j < mask.cols; ++j) {
            src.at<uchar>(i, j) = src.at<uchar>(i, j) & mask.at<uchar>(i, j);
        }
    }
    return src;
}


int main(){
    string img_path = "/home/aichikaodigua/study/jiqing/0250.png";
    string mask_path = "/home/aichikaodigua/study/jiqing/0.png";

    cv::Mat image_RGB = cv::imread(img_path);
    cv::Mat image_Gray = cv::imread(img_path, IMREAD_GRAYSCALE);
    cv::imwrite("/home/aichikaodigua/study/jiqing/image_Gray.png", image_Gray);
    cv::Mat mask = cv::imread(mask_path, IMREAD_GRAYSCALE);

    cv::Mat str = cv::getStructuringElement(0, cv::Size(12, 12));
    cv::Mat erodeSrc;
    cv::dilate(mask, erodeSrc, str);

    cv::Mat image_Blur;
    //cv::medianBlur(image_Gray, image_Blur, 5);
    //cv::GaussianBlur(image_Gray, image_Blur, cv::Size(7, 7), 0, 0);
    //cv::blur(image_Gray, image_Blur, cv::Size(5, 5));
    //cv::imwrite("/home/aichikaodigua/study/jiqing/image_Blur.png", image_Blur);


    cv::Mat result = get_gray(image_Gray, mask);
    cv::imwrite("/home/aichikaodigua/study/jiqing/result.png", result);

    cv::Mat result2 = dilate_progress(result, erodeSrc);
    cv::imwrite("/home/aichikaodigua/study/jiqing/result2.png", result2);
    cv::Mat str1 = cv::getStructuringElement(0, cv::Size(5, 5));
    cv::Mat result3;
    cv::dilate(result2, result3, str1);
    cv::Mat result4;
    cv::erode(result3, result4, str1);
    cv::imwrite("/home/aichikaodigua/study/jiqing/result4.png", result4);
    for (int i = 0; i < result4.rows; ++i) {
        for (int j = 0; j < result4.cols; ++j) {
            if (result4.at<uchar>(i, j) == 0) continue;
            image_RGB.at<cv::Vec3b>(i, j)[0] = 0;
            image_RGB.at<cv::Vec3b>(i, j)[1] = 0;
            image_RGB.at<cv::Vec3b>(i, j)[2] = 255;
        }
    }
    cv::imwrite("/home/aichikaodigua/study/jiqing/oooo.png", image_RGB);

    //waitKey(0);
    return 0;
}
