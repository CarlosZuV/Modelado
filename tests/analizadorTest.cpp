#include <gtest/gtest.h>
#include "../include/analizador_imagen.h"
#include "../include/cargador_imagen.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

struct CasoFigura {
    std::string archivo;
    std::vector<std::pair<char, std::string>> figuras;
};

class AnalizadorTest : public ::testing::TestWithParam<CasoFigura> {
};

TEST_P(AnalizadorTest, AnalizaFiguras) {
    CasoFigura caso = GetParam();

    cargador_imagen imagen("../Imagenes_prueba/" + caso.archivo);

    std::vector<ResultadoFigura> resultados =
        analizarImagen(imagen.getImagen());

    std::vector<std::pair<char, std::string>> obtenidas;

    for (const ResultadoFigura& resultado : resultados) {
        obtenidas.push_back({resultado.tipo, resultado.color});
    }

    std::sort(obtenidas.begin(), obtenidas.end());
    std::sort(caso.figuras.begin(), caso.figuras.end());

    ASSERT_EQ(obtenidas.size(), caso.figuras.size());
    EXPECT_EQ(obtenidas, caso.figuras);
}

INSTANTIATE_TEST_SUITE_P(
    Imagenes,
    AnalizadorTest,
    ::testing::Values(

        CasoFigura{
            "prueba_01_simple_C.bmp",
            {{'C', "#0000FF"}}
        },

        CasoFigura{
            "prueba_02_simple_T.bmp",
            {{'T', "#FFFF00"}}
        },

        CasoFigura{
            "prueba_03_simple_O.bmp",
            {{'O', "#FF00FF"}}
        },

        CasoFigura{
            "prueba_04_simple_X.bmp",
            {{'X', "#8B4513"}}
        },

        CasoFigura{
            "prueba_05_doble_CO.bmp",
            {
                {'O', "#00FFFF"},
                {'C', "#FF0000"}
            }
        },

        CasoFigura{
            "prueba_06_doble_TT.bmp",
            {
                {'T', "#FFA500"},
                {'T', "#FF69B4"}
            }
        },

        CasoFigura{
            "prueba_07_triple_COT.bmp",
            {
                {'T', "#FFFF00"},
                {'O', "#FF0000"},
                {'C', "#000080"}
            }
        },

        CasoFigura{
            "prueba_08_triple_CCC.bmp",
            {
                {'C', "#000000"},
                {'C', "#008000"},
                {'C', "#800080"}
            }
        },

        CasoFigura{
            "prueba_09_triple_TXO.bmp",
            {
                {'O', "#FFFFFF"},
                {'X', "#808080"},
                {'T', "#0064FF"}
            }
        },

        CasoFigura{
            "prueba_10_jefe_final.bmp",
            {
                {'X', "#0000C8"},
                {'T', "#00C800"},
                {'O', "#C80000"},
                {'C', "#323232"}
            }
        }
    )
);