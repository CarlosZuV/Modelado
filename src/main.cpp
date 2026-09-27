#include"../include/lector_ruta.h"
#include"../include/lector_consola.h"
#include "../include/cargador_imagen.h"
#include<string>
#include<filesystem>
#include<stdexcept>
#include<iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) {

  LectorConsola lectorC(argc, argv);

  std::string ruta_final;

  if (lectorC.sinArgumentos()) {
    
    std::cout << "No tenia argumentos, los pedimos al usuario";
    std::getline(std::cin, ruta_final);
    
  } else {

    std::cout << "Si tenia argumentos, tomamos el primer argumento";
    ruta_final = lectorC.getRuta();
    
  }
  
  lector_ruta ruta(ruta_final);

  if(ruta.esUsable()) {
    std::cout <<  "La ruta es" << ruta_final << '\n';

    cargador_imagen cargador(ruta_final);

    cv::Mat imagen = cargador.getImagen();
    
    std::cout << "\n Se logro \n";
    std::cout << "Resolución leída: " << imagen.cols << "x" << imagen.rows << " pixeles.\n";
    std::cout << "Color: " << imagen.channels() << "\n";
    
  } else {
    std::cout << "NO funco esta wea" << '\n';
  }
  return 0;
}
