#pragma once
#include<string>
#include <opencv2/opencv.hpp>

class cargador_imagen {
 private:
  cv::Mat imagenMatriz;

 public:
  cargador_imagen(const std::string& ruta);

  cv::Mat getImagen() const;
  
  bool estaVacia() const;
  
};
