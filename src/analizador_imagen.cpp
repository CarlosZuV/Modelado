#include "../include/analizador_imagen.h"

#include <cstdint>
#include <unordered_set>
#include "../include/componente.h"
#include "../include/clasificar_figura.h"
#include "../include/obtener_color.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/geometry.hpp>

uint32_t codificarColor(const cv::Vec3b& color) {          //Esta funcion sirve para darle un id unico a cada color, para no hacer repetidos al momento de hacer las máscaras
    return (static_cast<uint32_t>(color[0]) << 16) |
            (static_cast<uint32_t>(color[1]) << 8)  |
            static_cast<uint32_t>(color[2]);
}

cv::Vec3b decodificarColor(uint32_t codigo) { //reversa de la de arriba xd
    return cv::Vec3b(
        (codigo >> 16) & 0xFF,
        (codigo >> 8) & 0xFF,
        codigo & 0xFF
    );
}

std::unordered_set<uint32_t> obtenerColoresUnicos(const cv::Mat& imagen) { 
    std::unordered_set<uint32_t> colores;

    for (int y = 0; y < imagen.rows; y++) {
        for (int x = 0; x < imagen.cols; x++) {
            cv::Vec3b pixel = imagen.at<cv::Vec3b>(y, x);
            colores.insert(codificarColor(pixel));
        }
    }

    return colores;
}
//funcion para crear una mascara binaria para al final extraer componentes conexas y analizarlas
cv::Mat crearMascaraColor(const cv::Mat& imagen, const cv::Vec3b& color) {
    cv::Mat mascara;
    cv::inRange(imagen, color, color, mascara);
    return mascara;
}

int encontrarComponentes( //retorno de la cantidad de componentes
    const cv::Mat& mascara, 
    cv::Mat& etiquetas, //matriz para indicar a que cc pertenece
    cv::Mat& estadisticas, //info
    cv::Mat& centroides //centro
) {
    return cv::connectedComponentsWithStats(
        mascara,
        etiquetas,
        estadisticas,
        centroides,
        8, //nuestra conectidad, es decir, todo el circulito que está  alrededor del pixel
        CV_32S //tipo de dato de la matriz de etiquetas
    );
}

    int cantidadComponentes(int totalComponentes) {
        return totalComponentes - 1;
    }


    bool cajaContiene(const cv::Rect& exterior, const cv::Rect& interior) {
    return exterior.contains(interior.tl()) && exterior.contains(interior.br());
    }

    bool contornoContiene(
        const std::vector<cv::Point>& exterior,
        const std::vector<cv::Point>& interior
)        {
        for (const cv::Point& punto : interior) {
            if (cv::pointPolygonTest(exterior, punto, false) < 0) {
                return false;
            }
        }

    return true;
}

std::vector<ResultadoFigura> analizarImagen(const cv::Mat& imagen) {
    std::vector<ResultadoFigura> resultados;
    std::vector<Componente> componentes;
    std::unordered_set<uint32_t> coloresFondo;

    std::unordered_set<uint32_t> colores = obtenerColoresUnicos(imagen);

    for (uint32_t codigo : colores) {
        cv::Vec3b color = decodificarColor(codigo);
        cv::Mat mascara = crearMascaraColor(imagen, color);
        cv::Mat etiquetas;
        cv::Mat estadisticas;
        cv::Mat centroides;

        int totalComponentes = encontrarComponentes(
            mascara,
            etiquetas,
            estadisticas,
            centroides
        );

        for (int i = 1; i < totalComponentes; i++) { //esta parte hace una caja que delimita la componente, nos sirve para determinar si una componente está dentro de otra, haciendo que tomemos la más grande como fondo
            cv::Rect caja(
            estadisticas.at<int>(i, cv::CC_STAT_LEFT),
            estadisticas.at<int>(i, cv::CC_STAT_TOP),
            estadisticas.at<int>(i, cv::CC_STAT_WIDTH),
            estadisticas.at<int>(i, cv::CC_STAT_HEIGHT)
        );

        Componente componente;
        componente.color = color;
        componente.caja = caja;

        cv::Mat mascaraComponente = (etiquetas == i);

        std::vector<std::vector<cv::Point>> contornos; //omfg ya podemos sacar el contorno

        cv::findContours(
            mascaraComponente,
            contornos,
            cv::RETR_EXTERNAL,
            cv::CHAIN_APPROX_SIMPLE
        );

        if (contornos.empty()) {
            continue;
        }

        componente.contorno = contornos[0];
        componentes.push_back(componente);

        }
    }

        for (size_t i = 0; i < componentes.size(); i++) {
            for (size_t j = 0; j < componentes.size(); j++) {

            if (i == j) {
                continue;
            }

            if (!cajaContiene(componentes[i].caja, componentes[j].caja)) {
                continue;
            }

            if (contornoContiene(componentes[i].contorno, componentes[j].contorno)) {
                coloresFondo.insert(
                codificarColor(componentes[i].color)
            );
        }
    }
}

        for (const Componente& componente : componentes) {
            if (coloresFondo.find(codificarColor(componente.color)) != coloresFondo.end()) {continue;}

            char tipo = clasificarFigura(componente.contorno);
            std::string colorHex = obtenerColorHexadecimal(componente.color);

            ResultadoFigura resultado;
            resultado.tipo = tipo;
            resultado.color = colorHex;

            resultados.push_back(resultado);

        }

    return resultados;
}
