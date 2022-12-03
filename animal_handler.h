#ifndef ANIMAL_HANDLER_H
#define ANIMAL_HANDLER_H

#include "ABB.h"
#include "Animal.h"


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


const string ESPECIES_STR[7] = {
    "C",
    "O",
    "E",
    "G",
    "L",
    "P",
    "R"
};


const string PATH_ANIMALES = "animales.csv";

//PRE:
//POST:
void leer_archivo(ABB<Animal>* arbol_animales);


//PRE:
//POST:
especie_t string_a_especie_t(string especie);

//PRE:
//POST:
void  imprimir_arbol(ABB<Animal>* arbol_animales);

//PRE:
//POST:
void _imprimir_arbol(ABBNodo<Animal>* raiz);

//PRE:
//POST:
void buscar_animales(ABB<Animal>* tree);

//PRE:
//POST:
void animales_paso_del_tiempo(ABB<Animal>* arbol_animales);

//PRE:
//POST:
void _animales_paso_del_tiempo(ABBNodo<Animal>* raiz);

#endif //ANIMAL_HANDLER_H