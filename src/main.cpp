#include"../include/lector_ruta.h"
#include"../include/lector_consola.h"
#include<string>
#include<filesystem>
#include<stdexcept>
#include<iostream>

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
    std::cout << "Si funco esta wea" << '\n' << "La ruta es" << ruta_final << '\n';
  } else {
    std::cout << "NO funco esta wea" << '\n';
  }
  return 0;
}
