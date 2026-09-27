#include"../include/cargador_imagen.h"
#include <opencv2/opencv.hpp>
#include<string>
#include <stdexcept>


cargador_imagen::cargador_imagen(const std::string& ruta) {
  
   if (ruta.empty() || ruta.find_first_not_of(' ') == std::string::npos)
    throw  std::invalid_argument("Ni strings vacios, ni strings de puros espacios");
   
  // Creamos la imagen a partir del String
   imagenMatriz = cv::imread(ruta);

   if (estaVacia()) {
     throw std::runtime_error("No se pudo leer el archivo, awas. Puede estar corrupto o no ser una imagen valida.");
   }
}

bool cargador_imagen::estaVacia() const{
  return imagenMatriz.empty();
}

cv::Mat cargador_imagen::getImagen() const {
  return imagenMatriz;
}


