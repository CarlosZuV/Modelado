------------------------------------------------------------------------------------------------
Proyecto 01.
------------------------------------------------------------------------------------------------

 Este proyecto tuvo la finalidad de crear un analizador de imágenes (con especificaciones de
ser imagenes con figuras) capaz de recibir (mediante el uso de la terminal) rutas hacia
archivos ".bmp" con el objeto de, a partir de la imagen, ser capaz de devolver el contenido
de la imagen, dándole los siguientes datos al usuario:
-Cantidad de figuras.
-Qué tipo de figuras hay (Formato: C:Cuadrilatero, O:Círculo, T:Triángulo, X:Cualquier otra).
-Color en formato hexadecimal.

-----------------------------------

 Para el desarrollo del programa y dar solución al planteamiento usamos el lenguaje C++, Python
así como la librería de OpenCV. (INDISPENSABLE OPENCV V. 5.0.0)

 El uso de C++ fue así debido a la manera en la que podemos manejar la memoria, pues esto
nos permite el no hacer un consumo tan desmedido de la misma, más aún por los costos que conlleva
el realizar los análisis de las imagenes, así mismo, por su compatibilidad con la librería de 
OpenCV. La anterior fue usada precisamente porque nos fue capaz de dar las herramientas
necesarias para el procesamiento de imagenes. Python lo consideramos solamente un lenguaje
auxiliar, el cual fue usado para darnos las herramientas para la generación de imagenes.

-----------------------------------

Para el desarrollo del problema asumimos:

- La entrada es una imagen en formato .bmp.
- El fondo de la imagen tiene un único color uniforme.
- Cada figura está compuesta por un único color sólido.
- El color de cada figura es diferente al color del fondo.
- Dos figuras diferentes tienen colores distintos.
- No existen colores intermedios producidos por antialiasing en los bordes.
- Las figuras no se superponen.
- Las figuras pueden tener diferentes tamaños, posiciones y rotaciones.
- Una imagen puede contener una o varias figuras.
- Las figuras pertenecen a las categorías:
  - C: cuadriláteros.
  - T: triángulos.
  - O: círculos.
  - X: cualquier otra figura.

Así como evitar asumir cosas como: el fondo es el área más grande, el píxel (1,1) siempre es fondo, etc

Tomamos en cuenta casos límite como:
•Entrada inválida:
  - Proporcionar una ruta vacía.
  - Proporcionar una ruta que no tenga extensión .bmp.
  - Proporcionar una ruta correspondiente a un archivo inexistente.
  - Proporcionar un archivo que no pueda ser cargado como imagen válida.


-----------------------------------


Requisitos funcionales
|      |                                                                           |
| 0001 | Recibir una ruta de una imagen BMP mediante la línea de comandos.         |
| 0002 | Permitir solicitar una ruta cuando el programa se ejecuta sin argumentos. |
| 0003 | Validar que la ruta tenga extensión ".bmp".                               |
| 0004 | Verificar que el archivo exista y pueda ser cargado.                      |
| 0005 | Identificar todas las figuras presentes en la imagen.                     |
| 0006 | Clasificar cada figura como "C", "T," "O" ó "X".                          |
| 0007 | Obtener el color correspondiente a cada figura.                           |
| 0008 | Mostrar el color de cada figura en formato hexadecimal.                   |
| 0009 | Informar la cantidad de figuras encontradas.                              |
| 0010 | Informar errores de entrada de manera controlada.                         |
------------------------------------------------------------------------------------

Requisinos no funcionales
|      |                                                                                                   |
| 0001 | Rendimiento: el análisis debe realizarse en un tiempo razonable para las imágenes de entrada.     |
| 0002 | Robustez: las entradas inválidas no deben provocar un cierre inesperado del programa.             |
| 0003 | Mantenibilidad: el sistema debe estar organizado en módulos con responsabilidades separadas.      |
| 0004 | Portabilidad: el programa debe poder compilarse y ejecutarse en un entorno con las                |
|      | dependencias especificadas.                                                                       |
| 0005 | Usabilidad: la interacción mediante terminal debe proporcionar mensajes comprensibles al usuario. |
| 0006 | Verificabilidad: las funciones principales deben poder probarse mediante pruebas automatizadas.   |


-----------------------------------


 El algoritmo usado para la identificación de figuras consiste primeramente en la exploración de la imagen
píxel por píxel pues no tenemos otra manera de poder identificar si existe alguna figura en la imagen,
además del uso de máscaras para poder extraer matrices que correspondan al color de x figura con el uso
de la función "cv::inRange()", así mismo, se utiliza la función cv::connectedComponentsWithStats() para
identificar las componentes conexas presentes en cada máscara. Estas componentes son posteriormente
analizadas para determinar cuáles corresponden a figuras, así, podemos extraer el contorno de la figura y
mediante un algoritmo matemático, podemos determinar el número de aristas para, con este, determina de qué
figura se trata.


-----------------------------------

Diagrama de flujo en: "../Modelado/docs/Diagrama de flujo - Como funciona.png"

