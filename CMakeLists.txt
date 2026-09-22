cmake_minimum_required(VERSION 3.14)

# Aqui podemos cambiar el nombre del proyecto
project(ProyectoFiguras)

# 1. Configuración general
# Usar C++17 es el estándar recomendado hoy en la industria y la facultad
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Le decimos a CMake dónde encontrar los archivos .h (menú) para todo el proyecto
include_directories(include)

find_package(OpenCV REQUIRED)

# 2. Descargar Google Test de forma segura
# Usamos una versión fija (Tag) para que a todos tus amigos les descargue exactamente la misma
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# ==============================================================================
# 3. EL PROGRAMA PRINCIPAL (Lo que entregan al final)
# ==============================================================================
# Aquí pones el main y toda la lógica de la carpeta src/, pero NO las pruebas

# src/OtraClase.cpp (Agrega aquí los nuevos .cpp que vayan creando)

add_executable(sistema_figuras
	src/main.cpp
	src/lector_ruta.cpp
)

target_link_libraries(sistema_figuras ${OpenCV_LIBS})

# ==============================================================================
# 4. EL PROGRAMA DE PRUEBAS (Su entorno de validación)
# ==============================================================================
# Aquí juntas tu archivo de pruebas unitarias y los .cpp de la lógica que vas a evaluar.
# Nota que NO incluimos src/main.cpp aquí, porque GTest ya tiene su propio main.

add_executable(app_pruebas 
   tests/test.cpp
   src/lector_ruta.cpp
   tests/lectorTest.cpp
)

# Vinculamos el programa de pruebas con la librería de Google Test
target_link_libraries(app_pruebas GTest::gtest_main ${OpenCV_LIBS})

# 5. Habilitar CTest para que escanee y registre las pruebas automáticamente
include(GoogleTest)
gtest_discover_tests(app_pruebas)
