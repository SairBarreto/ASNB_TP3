#ifndef CREAR_ANIMALES_ALEATORIOS_H_INCLUDED
#define CREAR_ANIMALES_ALEATORIOS_H_INCLUDED

#include <iostream>

#include <string.h>

using namespace std;

const int EDAD_MIN = 0;

const int EDAD_MAX = 100;

const string ESPECIES_COMPLETAS[7] = {
    "Caballo",
    "Conejo",
    "Erizo",
    "Gato",
    "Lagartija",
    "Perro",
    "Roedor"
};

const string INICIALES_ESPECIES_STR[7] = {
    "C",
    "O",
    "E",
    "G",
    "L",
    "P",
    "R"
};

const string PERSONALIDADES[4] = {
    "dormilon",
    "jugueton",
    "sociable",
    "travieso"

};

const string TAMANIOS_STR[5] = {
    "diminuto",
    "pequenio",
    "mediano",
    "grande",
    "gigante"
};

string generar_tamanio_rand();

string generar_personalidades_rand();

string generar_especie_rand();

int generar_edad_rand();

#endif // CREAR_ANIMALES_ALEATORIOS_H_INCLUDED
