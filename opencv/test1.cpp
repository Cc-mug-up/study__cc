#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 创建一个简单的图像
    cv::Mat image = cv::Mat::zeros(300, 500, CV_8UC3);

    // 绘制文字
    cv::putText(image, "Hello OpenCV!", cv::Point(100, 150),
                cv::FONT_HERSHEY_SIMPLEX, 1.5, cv::Scalar(0, 200, 255), 2);

    // 绘制一个矩形
    cv::rectangle(image, cv::Rect(50, 50, 400, 200),
                  cv::Scalar(255, 0, 0), 3);

    // 显示OpenCV版本
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    std::cout << "Build timestamp: " << cv::getBuildInformation() << std::endl;

    // 显示图像
    cv::imshow("Compiled OpenCV Works!", image);
    cv::waitKey(0);

    return 0;
}