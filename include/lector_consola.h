#pragma once

#include"../include/lector_ruta.h"
#include<string>


class LectorConsola {
private:
  std::string ruta;

public:
  LectorConsola(int argc, char* argv[]);
  std::string getRuta() const;
  bool sinArgumentos() const;
};

