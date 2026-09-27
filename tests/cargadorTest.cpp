#include"../include/cargador_imagen.h"
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include<string>


/* ////////////////////////
  TEST NUMERO 1 (POSITIVO)
*/ ////////////////////////


TEST(ConstructorCargador, ObjetoValidoCargador) {

  // ruta relativa
  cargador_imagen imagen("../tests/imagenes_prueba/cuadrado.bmp");

  // checamos que la imagen no este vacia
  EXPECT_FALSE(imagen.estaVacia());

  // obtenemos los datos de la imagen
  // ancho, alto y los colores, en RGB 
  cv::Mat matriz = imagen.getImagen();

  // Los datos de la imagen son estos, lo saque de jspaint
  EXPECT_EQ(matriz.cols, 683);       
  EXPECT_EQ(matriz.rows, 384);       
  EXPECT_EQ(matriz.channels(), 3);
}

/* ////////////////////////
  TEST NUMERO 2 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorCargador, ObjetoNoValidoCargador) {

  //En el caso en que no exista la imagen
  EXPECT_THROW({
        cargador_imagen imagen("../tests/imagenes_prueba/juan.bmp");
    }, std::runtime_error);
}

/* ////////////////////////
  TEST NUMERO 2 (NEGATIVO)
*/ ////////////////////////

TEST(ConstructorCargador, ObjetoVacioCargador) {

  //En el caso en que no exista la imagen
  EXPECT_THROW({
      cargador_imagen imagen("");
    }, std::invalid_argument);
}


