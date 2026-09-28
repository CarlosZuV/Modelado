#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "../include/obtener_color.h" // para que reconozca la funcion que hicimos

// --- PRUEBA 1: EL CASO DE EXITO ---
TEST(ObtenerColorTest, RetornaHexadecimalCorrecto) {
    // 1. Preparamos una imagen falsa de 10x10 pixeles. 
    // CV_8UC3 significa que tiene 3 canales de 8 bits y cv::Scalar le pone el color a toda la matriz.
    // Open Cv, usa BGR, asi que (0, 0, 255) es cero azul, cero verde y todo rojo.
    cv::Mat imagen_roja(10, 10, CV_8UC3, cv::Scalar(0, 0, 255));
    
    // 2. Ejecutamos nuestra funcion pidiendo que revise el pixel de en medio, en las coordenadas x=5, y=5.
    std::string resultado = obtenerColorHexadecimal(imagen_roja, 5, 5);
    
    // 3. Verificamos que si nos de el color esperado.
    // EXPECT_EQ es literal el equals de Java, compara lo que arrojo nuestra funcion contra el "#FF0000" (Rojo puro).
    EXPECT_EQ(resultado, "#FF0000"); 
}

// --- PRUEBA 2: EL CASO DE FALLO (Coordenadas negativas) ---
TEST(ObtenerColorTest, FallaConCoordenadasNegativas) {
    // 1. Creamos una imagen cualquiera de 10x10, color negro.
    cv::Mat imagen_negra(10, 10, CV_8UC3, cv::Scalar(0, 0, 0));
    
    // Usamos EXPECT_THROW para asegurar que atrape el error.
    // Le pasamos a proposito una coordenada negativa (-1) que no existe. 
    // Si el if funciona bien, la prueba va a pasar porque detecto el error out_of_range.
    EXPECT_THROW(obtenerColorHexadecimal(imagen_negra, -1, 5), std::out_of_range);
}

// --- PRUEBA 3: EL CASO DE FALLO (Coordenadas excedidas) ---
TEST(ObtenerColorTest, FallaConCoordenadasExcedidas) {
    // 1. Creamos otra imagen de 10x10. Como las coordenadas empiezan en 0, el limite es 9.
    cv::Mat imagen_negra(10, 10, CV_8UC3, cv::Scalar(0, 0, 0));
    
    // Le pedimos el pixel en la coordenada 15, 15, la cual se sale de la matriz.
    // Igual que arriba, verificamos que nuestro escudo mande la excepcion para que el programa no explote de la nada.
    EXPECT_THROW(obtenerColorHexadecimal(imagen_negra, 15, 15), std::out_of_range);
}