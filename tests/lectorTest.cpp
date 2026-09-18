#include"../include/lector_ruta.h"
#include<fstream>
#include<string>
#include<gtest/gtest.h>


/* ////////////////////////
  TEST NUMERO 1 (POSITIVO)
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
  TEST NUMERO 2 (NEGATIVO)
*/ ////////////////////////

// Al meter un string vacio ==> Lanzamos Excepcion
TEST(ConstructorTest, ArgumentoVacio_SaleExcepcion) {

  EXPECT_THROW({
      lector_ruta ruta("");
    }, std::invalid_argument);
}

/* ////////////////////////
  TEST NUMERO 3 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ArgumentoEspacios_SaleExcepcion) {

  // Un argumento de puros espacios
  EXPECT_THROW({
      lector_ruta ruta("   ");
    }, std::invalid_argument);
}

/* ////////////////////////
  TEST NUMERO 4 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ArgumentoInvalido_NoBmp) {
  lector_ruta rutaInvalida("imagen.png");

  EXPECT_FALSE(rutaInvalida.terminacionCorrecta());
}

/* ////////////////////////
  TEST NUMERO 5 (POSITIVO)
*/ ////////////////////////

// Comprueba si un objeto correcto existe
TEST(ConstructorTest, ObjetoExistente) {

  // el string de la ruta para imitar un .bmp
  std::string ruta_creada = "imagen_falsa.bmp";

  // creamos el archivo temporal que si cumple la extension
  std::ofstream archivoTemporal(ruta_creada);
  // cerramos el archivo, ya que c++ lo abre por defecto
  archivoTemporal.close();

  // Definimos al arhivo como tipo ruta del programa
  lector_ruta ruta(ruta_creada);

  // Debe pasar la prueba de existencia porque el archivo ya existe
  EXPECT_TRUE(ruta.archivoExiste());

  // Borramos el archivo 
  std::filesystem::remove(ruta_creada);
}

/* ////////////////////////
  TEST NUMERO 6 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ObjetoNoExiste) {

  // terminacion correcta
  std::string fantasma = "archivo_inexistente.bmp";

  // se mete la terminacion a un bloque inexistente
  lector_ruta ruta(fantasma);  

  // Dara falso porque el archivo no es real
  EXPECT_FALSE(ruta.archivoExiste());
}


/* ////////////////////////
  TEST NUMERO 7 (POSITIVO)
*/ ////////////////////////

TEST(ConstructorTest, ObjetoCompletitud_Correcta) {

  // crear terminacion correcta
  std::string ruta_util = "imagen_util.bmp";

  // creamos un archivo real
  std::ofstream archivoTem(ruta_util);

  // lo cerramos
  archivoTem.close();

  // metemos la ruta de la terminacion correcta
  lector_ruta ruta(ruta_util);

  // se debe de cumplir las condiciones logicas
  EXPECT_TRUE(ruta.esUsable());

  // quitamos el archivo para no verlo mas
  std::filesystem::remove(ruta_util);
}

/* ////////////////////////
  TEST NUMERO 8 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ObjetoCompletitud_NoExistencia) {

  lector_ruta ruta("fotoCanek.bmp");

  EXPECT_FALSE(ruta.esUsable());
}

/* ////////////////////////
  TEST NUMERO 9 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorTest, ObjetoCompletitud_TerminacionFalla) {

  std::string archivo_mal = "foto_galaviz.jpg";

  std::ofstream archivoTemp(archivo_mal);

  archivoTemp.close();

  lector_ruta ruta(archivo_mal);

  EXPECT_FALSE(ruta.esUsable());

  std::filesystem::remove(archivo_mal);
}
