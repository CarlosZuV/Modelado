#include "../include/iniciar.h"
#include "../include/lector_consola.h"
#include "iostream"
#include "string"
#include "../include/lector_ruta.h"
#include "../include/cargador_imagen.h"
#include "../include/analizador_imagen.h"

int iniciar(int argc, char* argv[]) {
        LectorConsola lectorC(argc, argv);

        std::string ruta_final;

        if (lectorC.sinArgumentos()) {
            while (true) {
            std::cout << "Ingrese una ruta válida (o escriba 'salir' para terminar): ";
            std::getline(std::cin, ruta_final);

            if (ruta_final == "salir") {
                return 0;
            }

        try {
            lector_ruta ruta(ruta_final);
            ruta.esUsable();
            cargador_imagen imagen(ruta_final);
            std::vector<ResultadoFigura> resultados = analizarImagen(imagen.getImagen());
            std::cout << "Figuras encontradas: " << resultados.size() << '\n';
            for (const ResultadoFigura& resultado : resultados) {
                std::cout << resultado.tipo << " " << resultado.color << '\n';
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
        }

        }
        } else {
            ruta_final = lectorC.getRuta();
            lector_ruta ruta(ruta_final);
            ruta.esUsable();
            cargador_imagen imagen(ruta_final);
            std::vector<ResultadoFigura> resultados = analizarImagen(imagen.getImagen());
            std::cout << "Figuras encontradas: " << resultados.size() << '\n';
            for (const ResultadoFigura& resultado : resultados) {
                std::cout << resultado.tipo << " " << resultado.color << '\n';
            }
        }

        return 0;

}