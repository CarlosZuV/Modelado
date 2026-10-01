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

    // Descarta polígonos de 5 a 8 vértices antes de evaluar si son ovalados.
    if (vertices >= 5 && vertices <= 8) {
        return 'X';
    }

    //tanto círculos como ovalos son clasificados como 'O'
    if (contorno.size() >= 5) { //La función fitElipse requiere al menos 5 puntos

        cv::RotatedRect elipse = cv::fitEllipse(contorno);

        double radioX = elipse.size.width / 2.0; //nos da semieje horizontal
        double radioY = elipse.size.height / 2.0;  //nos da semieje vertical

        if (radioX > 0.0 && radioY > 0.0) {

            double areaElipse = CV_PI * radioX * radioY; //CV_PI es PI

            double proporcionElipse = area / areaElipse;

            if (proporcionElipse > 0.85 && proporcionElipse < 1.15) {

            return 'O';
        }
    }
}

return 'X';

}
