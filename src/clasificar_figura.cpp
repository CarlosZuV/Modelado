#include "../include/clasificar_figura.h"
#include <opencv2/imgproc.hpp> //para que no haya error al compilar -Zu
#include <opencv2/geometry.hpp>
char clasificarFigura(const std::vector<cv::Point>& contorno) {

    if (contorno.size() < 3) {
        return 'X';
    }

    double perimetro = cv::arcLength(contorno, true);

    if (perimetro <= 0.0){
        return 'X';
    }

    double area = cv::contourArea(contorno);

    if (area <= 0.0) {
        return 'X';
    }

    std::vector<cv::Point> aproximacion;

    cv::approxPolyDP(
        contorno,
        aproximacion,
        0.02 * perimetro, //tolerancia de aproximación
        true
    );

    int vertices = aproximacion.size();

    if (vertices == 3) {
        return 'T';
    }

    if (vertices == 4) {
        return 'C';
    }

    cv::Point2f centro;
    float radio;

    cv::minEnclosingCircle(contorno, centro, radio);

    if (radio <= 0.0) {
        return 'X';
    }

    double circularidad =
        4 * CV_PI * area / (perimetro * perimetro);

    double proporcionArea =
        area / (CV_PI * radio * radio);

    if (circularidad > 0.85 && proporcionArea > 0.90) {
        return 'O';
    }

    return 'X';
}
