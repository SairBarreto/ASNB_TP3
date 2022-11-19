/*
#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

enum especie_t {
    CABALLO = 0,
    CONEJO,
    ERIZO,
    GATO,
    LAGARTIJA,
    PERRO,
    ROEDOR,
    CANTIDAD_ESPECIES
};

const string ESPECIES_COMPLETAS[7] = {
    "Caballo",
    "Conejo",
    "Erizo",
    "Gato",
    "Lagartija",
    "Perro",
    "Roedor"
};

const string ESPECIES_STR[7] = {
    "C",
    "O",
    "E",
    "G",
    "L",
    "P",
    "R"
};

especie_t string_a_especie_t(string especie);

//PRE: Inicial de la especie
//POS: Retorna especie completa
string devolver_especie_palabra_completa(string inicial_ingresado);

#endif
*/