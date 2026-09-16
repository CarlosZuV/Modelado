#include"lector_ruta.h"
#include<gtest/gtest.h>



/* ////////////////////////
  TEST NUMERO 1 (NEGATIVO)
*/ ////////////////////////

// Al meter un string vacio ==> Lanzamos Excepcion
TEST(ConstructorTest, ArgumentoVacio_SaleExcepcion) {

  EXPECT_THROW({
      lector_ruta ruta("");
    }, std::invalid_argument);
}

/* ////////////////////////
  TEST NUMERO 2 (POSITIVO)
*/ ////////////////////////

// El test pone a prueba el constructor, ya que hice que recibiera
// un string para poder existir
TEST(ConstructorTest, ArgumentoValido) {
  
  // Creamos el objto de tipo ruta
  lector_ruta ruta("imagen.bmp");

  // Aqui entra en accion la forma en la que vamos a revisar si lo anterior es correcto
  // Hay un metodo en la clase normal que nos dira si lo que escribimos es correcto
  // el cual es el de terminacionCorrecta()

  EXPECT_TRUE(ruta.terminacionCorrecta());  
}


/* ////////////////////////
  TEST NUMERO 3 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ArgumentoInvalido_NoBmp) {
  lector_ruta rutaInvalida("imagen.png");

  EXPECT_FALSE(rutaInvalida.terminacionCorrecta());
}

/* ////////////////////////
  TEST NUMERO 3 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructoTest, ArchivoExiste) {
  
}
