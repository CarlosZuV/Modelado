#include"../include/lector_consola.h"
#include<string>
#include<stdexcept>

// Constructor del lectorConsola
// int argc = tamano del argumento
// char* argv[] = El arreglo de argumentos
LectorConsola::LectorConsola(int argc, char* argv[]){

  if (argv == nullptr)
    throw std::invalid_argument("No se acepta arreglo null");
  
  if (argc < 1)
    throw std::invalid_argument("No se aceptan tamanos menores a 1");

  if (argc > 1) {
    ruta = argv[1];

    if (ruta.empty() || ruta.find_first_not_of(' ') == std::string::npos)
      throw std::invalid_argument("No se aceptan argumentos vacios o sin cuerpo");
  }
}

std::string LectorConsola::getRuta() const {
  return ruta;
}

bool LectorConsola::sinArgumentos() const{
  return ruta.empty();
}




