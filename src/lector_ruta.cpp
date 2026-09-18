#include"../include/lector_ruta.h"
#include<string>
#include<filesystem>
#include<stdexcept>


namespace fs = std::filesystem;

// Objeto para ser evaludado
lector_ruta::lector_ruta(std::string argumento) {

  if (argumento.empty() || argumento.find_first_not_of(' ') == std::string::npos)
    throw  std::invalid_argument("Ni strings vacios, ni strings de puros espacios");

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

// Combinacion de los dos metodos anteriores
bool lector_ruta::esUsable() {
  return terminacionCorrecta() && archivoExiste();
}
