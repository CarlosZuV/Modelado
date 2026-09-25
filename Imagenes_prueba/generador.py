from PIL import Image, ImageDraw

# Lienzo más ancho para acomodar múltiples figuras sin traslaparse
ANCHO, ALTO = 600, 400
FONDO = (0, 255, 0) # Verde fosforescente

def iniciar_imagen():
    img = Image.new("RGB", (ANCHO, ALTO), FONDO)
    return img, ImageDraw.Draw(img)

def guardar_imagen(img, nombre_archivo):
    img.save(nombre_archivo, format="BMP")
    print(f"Generada: {nombre_archivo}")

# --- IMÁGENES SIMPLES (1 Figura) ---
# 1. Cuadrado azul
img1, draw1 = iniciar_imagen()
draw1.polygon([(200, 100), (400, 100), (400, 300), (200, 300)], fill=(0, 0, 255))
guardar_imagen(img1, "prueba_01_simple_C.bmp")

# 2. Triángulo equilátero amarillo
img2, draw2 = iniciar_imagen()
draw2.polygon([(300, 50), (450, 300), (150, 300)], fill=(255, 255, 0))
guardar_imagen(img2, "prueba_02_simple_T.bmp")

# 3. Círculo magenta
img3, draw3 = iniciar_imagen()
draw3.ellipse([200, 100, 400, 300], fill=(255, 0, 255))
guardar_imagen(img3, "prueba_03_simple_O.bmp")

# 4. Hexágono marrón (Figura X)
img4, draw4 = iniciar_imagen()
draw4.polygon([(300, 50), (450, 125), (450, 275), (300, 350), (150, 275), (150, 125)], fill=(139, 69, 19))
guardar_imagen(img4, "prueba_04_simple_X.bmp")

# --- IMÁGENES DOBLES (2 Figuras) ---
# 5. Rectángulo rojo (Izq) y Círculo cian (Der)
img5, draw5 = iniciar_imagen()
draw5.polygon([(50, 100), (250, 100), (250, 300), (50, 300)], fill=(255, 0, 0))
draw5.ellipse([350, 100, 550, 300], fill=(0, 255, 255))
guardar_imagen(img5, "prueba_05_doble_CO.bmp")

# 6. Dos triángulos distintos (Isósceles rosa y Rectángulo naranja)
img6, draw6 = iniciar_imagen()
draw6.polygon([(150, 100), (250, 300), (50, 300)], fill=(255, 105, 180))
draw6.polygon([(400, 100), (400, 300), (550, 300)], fill=(255, 165, 0))
guardar_imagen(img6, "prueba_06_doble_TT.bmp")

# --- IMÁGENES TRIPLES Y COMPLEJAS ---
# 7. Cuadrado, Círculo y Triángulo
img7, draw7 = iniciar_imagen()
draw7.polygon([(30, 30), (180, 30), (180, 180), (30, 180)], fill=(0, 0, 128))   # Cuadrado azul marino
draw7.ellipse([420, 30, 570, 180], fill=(255, 0, 0))                            # Círculo rojo
draw7.polygon([(300, 200), (400, 350), (200, 350)], fill=(255, 255, 0))         # Triángulo amarillo
guardar_imagen(img7, "prueba_07_triple_COT.bmp")

# 8. Tres Cuadriláteros distintos (Rombo, Rectángulo, Trapecio)
img8, draw8 = iniciar_imagen()
draw8.polygon([(100, 30), (170, 100), (100, 170), (30, 100)], fill=(128, 0, 128)) # Rombo
draw8.polygon([(250, 50), (350, 50), (350, 350), (250, 350)], fill=(0, 128, 0))   # Rectángulo vertical
draw8.polygon([(450, 250), (550, 250), (580, 350), (420, 350)], fill=(0, 0, 0))   # Trapecio negro
guardar_imagen(img8, "prueba_08_triple_CCC.bmp")

# 9. Triángulo escaleno, Pentágono y Círculo pequeño
img9, draw9 = iniciar_imagen()
draw9.polygon([(50, 50), (200, 100), (80, 250)], fill=(0, 100, 255))              # Escaleno
draw9.polygon([(400, 50), (500, 120), (460, 220), (340, 220), (300, 120)], fill=(128, 128, 128)) # Pentágono
draw9.ellipse([250, 280, 350, 380], fill=(255, 255, 255))                         # Círculo blanco
guardar_imagen(img9, "prueba_09_triple_TXO.bmp")

# 10. EL JEFE FINAL (4 Figuras: C, T, O, X dispersas)
img10, draw10 = iniciar_imagen()
draw10.polygon([(20, 20), (120, 20), (120, 120), (20, 120)], fill=(50, 50, 50))       # Cuadrado gris oscuro
draw10.ellipse([480, 20, 580, 120], fill=(200, 0, 0))                                 # Círculo rojo oscuro
draw10.polygon([(50, 250), (150, 350), (20, 350)], fill=(0, 200, 0))                  # Triángulo verde oscuro
draw10.polygon([(450, 250), (550, 250), (580, 320), (500, 380), (420, 320)], fill=(0, 0, 200)) # Pentágono azul
guardar_imagen(img10, "prueba_10_jefe_final.bmp")