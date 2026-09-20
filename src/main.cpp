#include"../include/lector_ruta.h"
#include<string>
#include<filesystem>
#include<stdexcept>
#include<iostream>

int main() {
  std::string alfa;

  std::cin >> alfa;

  lector_ruta ruta(alfa);

  if(ruta.esUsable()) {
    std::cout << "Si funco esta wea" << '\n' << "La ruta es" << alfa << '\n';
  } else {
    std::cout << "NO funco esta wea" << '\n';
  }
  return 0;
}
