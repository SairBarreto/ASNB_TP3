/*
#include "Funciones2.h"
#include <iostream>

especie_t string_a_especie_t(string especie)
{
    int posicion;
    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(especie == ESPECIES_STR[i])
            posicion = i;
    }
    return (especie_t) posicion;
}

string devolver_especie_palabra_completa(string inicial_ingresado)
{
    string inicial;
    string palabra;
    string especie_nombre_completo;

    for(int i = 0; i < 7; i++){
        palabra = ESPECIES_COMPLETAS[i];
        inicial = palabra[0];

        if (inicial_ingresado == inicial && palabra != "Conejo" ){
            especie_nombre_completo = palabra;
        }
        else if (inicial_ingresado == "O" && palabra =="Conejo"){
            especie_nombre_completo = palabra;
        }
    }

    return especie_nombre_completo;
}
*/