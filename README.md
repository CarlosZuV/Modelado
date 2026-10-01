-------------------------------------
-Repositorio Modelado y Programación 2027-1
-------------------------------------

Equipo Omega Dinamita 3.0

-------------------------------------
Integrantes
-------------------------------------

-Bárcenas Lejarazo Karen\
-Cantero Zavaleta Héctor\
-Miranda Vieyra Francisco Cuahutémoc\
-Zúñiga Vilchis Carlos Uriel

--------------------------------------
## Requisitos de compilación y ejecución

Para compilar y ejecutar correctamente **ProyectoFiguras**, el sistema debe contar con las siguientes herramientas y dependencias:

### 1. Compilador de C++

Se requiere un compilador compatible con **C++17**.

El proyecto está configurado para utilizar el estándar **C++17**, por lo que el compilador debe proporcionar soporte para dicho estándar.

### 2. CMake

Se requiere **CMake versión 3.14 o superior**.

El proyecto utiliza CMake como sistema de configuración y generación de la compilación:

"cmake
cmake_minimum_required(VERSION 3.14)
"

### 3. OpenCV

Se requiere **OpenCV versión 5.0.0**.

El proyecto utiliza OpenCV para el procesamiento y análisis de las imágenes, incluyendo operaciones como lectura de imágenes, procesamiento de contornos, cálculo de áreas, perímetros y detección geométrica de las figuras.

La versión requerida está especificada directamente en la configuración de CMake:

"cmake
find_package(OpenCV 5.0.0 REQUIRED COMPONENTS core imgproc highgui)
"

Los módulos utilizados son:

- **core** — estructuras y operaciones fundamentales de OpenCV.
- **imgproc** — procesamiento de imágenes y análisis geométrico.
- **highgui** — funcionalidades de manejo de imágenes proporcionadas por OpenCV.

### 4. GoogleTest

El proyecto utiliza **GoogleTest 1.12.1** para las pruebas unitarias.

No es necesario instalar GoogleTest manualmente. CMake lo descarga automáticamente mediante `FetchContent`, utilizando una versión fija para garantizar que todos los integrantes del proyecto trabajen con la misma versión:

"cmake
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
"

### 5. Git

Se requiere **Git** durante la configuración del proyecto para que CMake pueda descargar GoogleTest desde su repositorio.

No es necesario que el usuario instale GoogleTest de forma independiente.

---

## Resumen de requisitos

| Herramienta           | Versión requerida                   |
|                       |                                     |
| **CMake**             | 3.14 o superior                     |
| **Compilador de C++** | Compatible con C++17                |
| **Estándar de C++**   | C++17                               |
| **OpenCV**            | **5.0.0**                           |
| **GoogleTest**        | 1.12.1                              |
| **Git**               | Necesario para descargar GoogleTest |

### Requisitos de entrada

El programa recibe imágenes en formato **BMP (`.bmp`)**.

Las imágenes deben cumplir con las condiciones establecidas para el proyecto: las figuras deben presentar colores sólidos, distinguirse del fondo y no utilizar gradientes ni bordes suavizados mediante antialiasing.

---

## Compilación

Una vez instalados los requisitos, el proyecto puede configurarse y compilarse mediante CMake en el firectorio raiz "../Modelado/":

"
cmake -S . -B build
cmake --build build
"

Esto genera los ejecutables del proyecto, incluyendo:

- `sistema_figuras` — programa principal.
- `app_pruebas` — conjunto de pruebas unitarias.

Las pruebas pueden ejecutarse mediante:

```bash
ctest --test-dir build
```

## Ejecución

Tras la compilación, dentro de la carpeta "../Modelado/build/" Ejecutamos:

./sistema_figuras

Para que el programa empiece a ejecutarse

