#include"../include/lector_consola.h"
#include <gtest/gtest.h>
#include<string>

/* ////////////////////////
  TEST NUMERO 1 (POSITIVO)
*/ ////////////////////////

TEST(ConstructorTest, EntradaValida_SinArgumento) {
  // simulamos la entrada de un argumento
  int argc = 1;

  // introducimos de manera cosntante el arreglo de
  // caracteres que representa el argumento
  const char* argv[] = {"./ejemplo"};

  // Constructor del Lector Consola (# argumentos, el arreglo de argumentos)
  LectorConsola lectorC(argc, (char**)argv);

  // Metodo que nos dice si no tiene argumentos
  EXPECT_TRUE(lectorC.sinArgumento());
  
}
/* ////////////////////////
  TEST NUMERO 2 (POSITIVO)
*/ ////////////////////////

TEST(ConstructorTest, EntradaValida_ConArgumento) {

  // simulamos los dos argumentos que se reciben 
  int argc = 2;

  // La forma de los dos argumentos
  const char* argv[] = {"./ejemplo", "foto.bmp"};

  // Constructor
  LectorConsola lectorC(argc, (char**)argv);

  // Si tiene un argumento, por lo tanto esto es falso
  EXPECT_FALSE(lectorC.sinArgumento());
  
  // Verificamos que "foto.bmp" si esta en la ruta
  EXPECT_EQ(lectorC.getRuta(), "foto.bmp");
}

/* ////////////////////////
  TEST NUMERO 3 (POSITIVO) PECANDO DEL DRY, PERDON
*/ ////////////////////////

TEST(ConstructorTest, EntradaValida_ConMasArgumentos) {

  // simulamos tres argumentos de entrada 
  int argc = 3;

  // La forma de los dos argumentos
  const char* argv[] = {"./ejemplo", "foto.bmp", "otra_cosa"};

  // Constructor
  LectorConsola lectorC(argc, (char**)argv);

  // Si tiene un argumento, por lo tanto esto es falso
  EXPECT_FALSE(lectorC.sinArgumento());
  
  // Verificamos que "foto.bmp" si esta en la ruta
  EXPECT_EQ(lectorC.getRuta(), "foto.bmp");
}

/* ////////////////////////
  TEST NUMERO 4 (NEGATIVO) 
*/ ////////////////////////

TEST(ConstructorTest, TamanoArgumentos_Invalido) {

  // Un argumento invalido, no pueden ser menores a 1
  int argc = 0;

  // Un arreglo vacio, nada mas pa que no truene el constructor
  char* argv[] = {nullptr};

  // Lanzamos una excepcion pq esto es ilegalisimo
  EXPECT_THROW({
      LectorConsola lectorC(argc, argv);
    }, std::invalid_argument);
}

/* ////////////////////////
  TEST NUMERO 5 (NEGATIVO) 
*/ ////////////////////////

TEST(ConstructorTest, ArregloNulo) {

  // simulamos dos argumentos
  int argc = 2;

  // si el arreglo es nulo, lo mandamos como excepcion
  EXPECT_THROW({
      LectorConsola lectorC(argc, nullptr);
    }, std::invalid_argument);
}





