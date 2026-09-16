#pragma once
#include<string>
#include<filesystem>

namespace fs = std::filesystem;

class lector_ruta {

private:
  fs::path ruta;
  
public:
  lector_ruta(std::string argumento);
  bool esUsable();

};
