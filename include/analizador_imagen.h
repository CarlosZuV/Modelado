#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

struct ResultadoFigura {
    char tipo;
    std::string color;
};

std::vector<ResultadoFigura> analizarImagen(const cv::Mat& imagen);