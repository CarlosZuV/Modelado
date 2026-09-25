# Reporte de Uso de Modelos de Lenguaje (REPORTE_LM)
**Equipo:** Omega Dinamita 3.0

## Caso 1: Generación del Banco de Imágenes de Prueba

*   **Prompt utilizado:** "Me puedes dar un ejemplo de cómo hacerla en BMP y en qué hacerla? Tenía idea de hacerla en Paint... Hay un gran problema y es que el detector de Paint, sus bordes no son exactos. Las esquinas no tienen un vértice y hay difuminación. ¿Mejor haces tú las 10 imágenes mediante un script en Python para garantizar que no haya suavizado?" (Resumido).
*   **¿Por qué decidimos usar esta herramienta?:** Necesitábamos asegurar matemáticamente que las imágenes de prueba cumplieran con los supuestos del proyecto (colores sólidos, formato BMP de 24 bits, sin degradados ni anti-aliasing)[cite: 5]. Hacerlas a mano en software de dibujo estándar estaba generando píxeles difuminados en los contornos que romperían el algoritmo de clasificación geométrica.
*   **Qué parte de la respuesta aceptamos tal cual:** El uso de la librería `Pillow` en Python y la lógica de las funciones `draw.polygon` y `draw.ellipse` para inyectar polígonos sólidos directamente en una matriz de píxeles, forzando el guardado en formato `.bmp`.
*   **Qué parte corregimos o descartamos y por qué:** Se descartó la primera versión del script proporcionado por el modelo. Dicho script generaba únicamente una figura por imagen. Lo corregimos solicitando al modelo que recalculara las coordenadas para incluir 2, 3 y hasta 4 figuras geométricas distintas por imagen (sin traslaparse), ya que el sistema debe ser capaz de procesar múltiples figuras simultáneas de colores distintos[cite: 5].
*   **Error del modelo y cómo lo detectamos:** Inicialmente, el modelo recomendó usar MS Paint o KolourPaint indicando que soportaban BMP nativo, pero omitió advertir que las herramientas de formas aplican suavizado (anti-aliasing) por defecto. Lo detectamos al hacer zoom máximo en una figura de prueba y notar píxeles intermedios (grises/verdosos) en los bordes. El modelo falló al no prever este comportamiento predeterminado del software gráfico, lo que nos obligó a pivotar hacia la generación por código.

## Caso 2: Transición del Paradigma Java a C++ y Arquitectura de Clases

*   **Prompt utilizado:** "Sabemos programar en Java pero somos nuevos en C++. ¿Cómo se divide la estructura de una clase en C++? En Java todo va en un archivo, ¿cuál es el equivalente de una interfaz o cómo se definen los métodos aquí? Por ejemplo, si quisiera migrar la lógica de un método de validación de Java a C++, ¿cómo lo estructuro?"

*   **¿Por qué decidimos usar esta herramienta?:** Necesitábamos mapear nuestro conocimiento previo en programación orientada a objetos hacia la sintaxis y estructura de C++, particularmente para comprender la separación obligatoria del código para este proyecto.

*    **Qué parte de la respuesta aceptamos tal cual:** La explicación estructural sobre cómo usar los archivos de cabecera (.h) para declarar la firma de los métodos (actuando de forma similar a una interfaz) y los archivos de código fuente (.cpp) para desarrollar la lógica interna de nuestras clases.

*    **Qué parte corrigimos o descartamos y por qué:** El modelo nos sugirió utilizar punteros inteligentes (std::unique_ptr) y plantillas avanzadas para el manejo de los objetos. Lo descartamos porque decidimos mantener un manejo de memoria estático y tradicional que nos resultara más familiar y fácil de depurar.

*    **Error del modelo y cómo lo detectamos:** El modelo indicó que en C++ es estrictamente obligatorio que el nombre del archivo coincida exactamente con el nombre de la clase pública, arrastrando una regla que es exclusiva de Java. Detectamos el error al compilar exitosamente archivos con nombres distintos a sus clases internas.

## Caso 3: Exploración de Librerías y Enfoque del Algoritmo

*    **Prompt utilizado:** "Queremos modelar un algoritmo para leer los píxeles de una imagen BMP y detectar las figuras en C++. ¿Qué bibliotecas nos recomiendas usar y cómo podemos estructurar el diagrama de flujo inicial?"

*    **¿Por qué decidimos usar esta herramienta?:** Para realizar una lluvia de ideas técnica que nos permitiera evaluar diferentes opciones de procesamiento de imágenes antes de comprometer el diseño de nuestro código fuente, asegurando cumplir con los requisitos funcionales.   

*    **Qué parte de la respuesta aceptamos tal cual:** La sugerencia de modularizar el problema y agregar un bloque de manejo de excepciones. Además, tomamos la recomendación de implementar pruebas unitarias (con Google Test) para cada módulo, lo cual añadimos a nuestro diseño aunque no fuera un requisito estricto del proyecto.

*    **Qué parte corrigimos o descartamos y por qué:** El modelo sugirió usar librerías nativas de bajo nivel (fstream para lectura binaria) para extraer el código hexadecimal manualmente. Decidimos descartar esa aproximación tan cruda y preferimos apoyarnos en la configuración de OpenCV que ya teníamos, ya que optimiza la lectura de la matriz de píxeles.

*    **Error del modelo y cómo lo detectamos:** Al sugerir el flujo de lectura de píxeles, el modelo asumió que la imagen BMP se lee por defecto en formato RGB. Detectamos el error en las pruebas, ya que el formato BMP almacena los canales de color en orden inverso (BGR), lo cual nos obligó a corregir la lógica de extracción hexadecimal.

## Caso 4: Refactorización y Estructura de Directorios

*    **Prompt utilizado:** "Teníamos esta estructura de carpetas en nuestro repositorio, pero nos pidieron adaptarla a un orden específico con módulos como src/io y src/deteccion. Ya movimos los archivos lector_consola.cpp y lector_ruta.cpp, ¿está correctamente implementada la nueva estructura para cumplir con los estándares?"

*    **¿Por qué decidimos usar esta herramienta?:** Para verificar que nuestra reorganización de archivos en el repositorio de GitHub cumpliera exactamente con la arquitectura modular sugerida por el equipo docente, sin romper las dependencias de compilación.

*    **Qué parte de la respuesta aceptamos tal cual:** La confirmación de que los archivos de lectura de terminal y rutas pertenecían lógicamente al submódulo de Input/Output (src/io/), validando nuestro reordenamiento.

*    **Qué parte corrigimos o descartamos y por qué:** El modelo sugirió crear archivos __init__.py dentro de cada carpeta para convertirlos en módulos. Descartamos esto inmediatamente porque esa es una regla de arquitectura para Python, no aplicable a nuestro entorno de compilación con CMake en C++.
