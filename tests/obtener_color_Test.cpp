#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "../include/obtener_color.h" // para que reconozca la funcion que hicimos

// --- PRUEBA 1: EL CASO DE EXITO ---
TEST(ObtenerColorTest, RetornaHexadecimalCorrecto) {
    // 1. Preparamos una imagen falsa de 10x10 pixeles. 
    // CV_8UC3 significa que tiene 3 canales de 8 bits y cv::Scalar le pone el color a toda la matriz.
    // Open Cv, usa BGR, asi que (0, 0, 255) es cero azul, cero verde y todo rojo.
    cv::Vec3b colorRojo(0, 0, 255);    
    // 2. Ejecutamos nuestra funcion pidiendo que revise el pixel de en medio, en las coordenadas x=5, y=5.
    std::string resultado = obtenerColorHexadecimal(colorRojo);    
    // 3. Verificamos que si nos de el color esperado.
    // EXPECT_EQ es literal el equals de Java, compara lo que arrojo nuestra funcion contra el "#FF0000" (Rojo puro).
    EXPECT_EQ(resultado, "#FF0000"); 
}

// --- PRUEBA 2: EL CASO DE FALLO (Coordenadas negativas) ---


// --- PRUEBA 3: EL CASO DE FALLO (Coordenadas excedidas) ---
