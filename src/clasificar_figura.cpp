#include "../include/clasificar_figura.h"

char clasificarFigura(const std::vector<cv::Point>& contorno) {

    if (contorno.empty()) {
        return 'X';
    }

    double perimetro = cv::arcLength(contorno, true);

    std::vector<cv::Point> aproximacion;

    cv::approxPolyDP(
        contorno,
        aproximacion,
        0.02 * perimetro,
        true
    );

    int vertices = aproximacion.size();

    if (vertices == 3) {
        return 'T';
    }

    if (vertices == 4) {
        return 'C';
    }

    double area = cv::contourArea(contorno);

    double circularidad =
        4 * CV_PI * area / (perimetro * perimetro);

    cv::Point2f centro;
    float radio;

    cv::minEnclosingCircle(contorno, centro, radio);

    double proporcionArea =
        area / (CV_PI * radio * radio);

    if (circularidad > 0.85 && proporcionArea > 0.90) {
        return 'O';
        }

    return 'X';
}