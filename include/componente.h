#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

struct Componente {
    cv::Vec3b color;
    cv::Rect caja;
    std::vector<cv::Point> contorno;
};