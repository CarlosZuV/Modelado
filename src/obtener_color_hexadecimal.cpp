#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip> // Necesario para setfill, setw y hex
#include <sstream> // Necesario para construir el string de cadenas de texo complejas
#include <string>

std::string obtenerColorHexadecimal(const cv::Mat& imagen, int x, int y) {
    // 1. Apuntar al pixel exacto en la matriz (fila Y, columna X), ya que open cv para consultar una matriz primero se le pasa la fila (y) y luego la columna (x)
    // cv::Vec3b es un vector de 3 bytes (uno para cada canal de color)
    cv::Vec3b pixel = imagen.at<cv::Vec3b>(y, x);
    
    // 2. Extraer los canales considerando que OpenCV, en esta coasion es diferente ya que su formato no es RGB usa BGR
    int azul  = pixel[0];
    int verde = pixel[1];
    int rojo  = pixel[2];
    
    // 3. Formatear los números a un String Hexadecimal
    // Equivalente a usar String.format("%02X", color) en Java
    std::stringstream hexStream;
    hexStream << "#"
              << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << rojo  // Estos comandos std::hex y std::uppercase trasnforman el numero entero a base 16 en mayuscula
              << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << verde
              << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << azul;
              // std::setfill('0'), y std::setw(2) aseguran que un numero como el 5 se convierta en "05" en lugar de "5", para mantener el formato hexadecimal de 2 dígitos por canal, mateniendo la estructura escrita del color. 
    return hexStream.str();
}