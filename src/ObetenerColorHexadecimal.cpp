Función obtenerColorHexadecimal(coordenada_X, coordenada_Y):
    // 1. Apuntar al pixel exacto dentro de la figura
    pixel = leer_pixel_en_imagen(coordenada_X, coordenada_Y)
    
    // 2. Extraer los tres canales de color (valores del 0 al 255)
    azul = pixel[0]
    verde = pixel[1]
    rojo = pixel[2]
    
    // 3. Convertir cada número decimal a formato Hexadecimal
    // Ej: 255 se convierte a "FF", 0 se convierte a "00"
    hex_rojo = convertir_a_hex(rojo)
    hex_verde = convertir_a_hex(verde)
    hex_azul = convertir_a_hex(azul)
    
    // 4. Unir todo con el formato estándar
    cadena_final = "#" + hex_rojo + hex_verde + hex_azul
    
    Devolver cadena_final