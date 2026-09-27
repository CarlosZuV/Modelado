#include "../include/clasificar_figura.h"
#include <gtest/gtest.h>

TEST(ClasificadorTest, DetectaTriangulo) {
    std::vector<cv::Point> triangulo = {
        cv::Point(0, 0),
        cv::Point(100, 0),
        cv::Point(50, 100)
    };

    EXPECT_EQ(clasificarFigura(triangulo), 'T');
}

TEST(ClasificadorTest, DetectaCuadrilatero) {
    std::vector<cv::Point> cuadrado = {
        cv::Point(0, 0),
        cv::Point(100, 0),
        cv::Point(100, 100),
        cv::Point(0, 100)
    };

    EXPECT_EQ(clasificarFigura(cuadrado), 'C');
}

TEST(ClasificadorTest, DetectaCirculo) {

    std::vector<cv::Point> circulo;

    cv::ellipse2Poly(
        cv::Point(50, 50),
        cv::Size(40, 40),
        0,
        0,
        360,
        10,
        circulo
    );

    EXPECT_EQ(clasificarFigura(circulo), 'O');
}

TEST(ClasificadorTest, DetectaOtro) {

    std::vector<cv::Point> pentagono = {
        cv::Point(50, 0),
        cv::Point(100, 40),
        cv::Point(80, 100),
        cv::Point(20, 100),
        cv::Point(0, 40)
    };

    EXPECT_EQ(clasificarFigura(pentagono), 'X');
}