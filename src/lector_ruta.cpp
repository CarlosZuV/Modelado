#include"lector_ruta.h"
#include<string>
#include<filesystem>
#include <stdexcept>


namespace fs = std::filesystem;

// Objeto para ser evaludado
lector_ruta::lector_ruta(std::string argumento) {

  if (argumento.empty())
    throw  std::invalid_argument("El string debe contener cuerpo");

  ruta = argumento;
}

// Si la ruta termina con .bmp, return true
bool lector_ruta::terminacionCorrecta() {
  return ruta.extension() == ".bmp";
}

// Si el archivo existe, return true
bool lector_ruta::archivoExiste() {
  return fs::exists(ruta);
}

bool lector_ruta::esUsable() {
  return terminacionCorrecta() && archivoExiste();
}
