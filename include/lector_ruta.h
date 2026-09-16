#pragma once
#include<string>
#include<filesystem>
#include <stdexcept>


class lector_ruta {

private:
  std::filesystem::path ruta;
  
public:
  lector_ruta(std::string argumento);
  bool esUsable();
  bool terminacionCorrecta();
  bool archivoExiste();

};
