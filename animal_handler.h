#ifndef ANIMAL_HANDLER_H
#define ANIMAL_HANDLER_H

#include "ABB.h"
#include "Animal.h"

enum tamanio_t {
    DIMINUTO = 0,
    PEQUENIO,
    MEDIANO,
    GRANDE,
    GIGANTE,
    CANTIDAD_TAMANIOS
};

enum personalidad_t {
    DORMILON = 0,
    JUGETON,
    SOCIABLE,
    TRAVIESO,
    CANTIDAD_PERSONALIDAD
};

const string PERSONALIDAD_STR[4] = {
    "dormilon",
    "jugeton",
    "sociable",
    "travieso"
};

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


const string ESPECIES_COMPLETAS[7] = {
    "Caballo",
    "Conejo",
    "Erizo",
    "Gato",
    "Lagartija",
    "Perro",
    "Roedor"

};

const string TAMANIOS_STR[5] =
{
    "diminuto",
    "pequenio",
    "mediano",
    "grande",
    "gigante"
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
personalidad_t string_a_personalidad_t(string personalidad);

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

//PRE:
//POST:
string especie_inicial_a_string(string inicial);

//PRE:
//POST:
void elegir_individualmente(ABB<Animal>* arbol_animales);

//PRE:
//POST:
void banio_individual(Animal* animal);

//PRE:
//POST:
void alimentar_individual(Animal* animal);

void adoptar_animal(ABB<Animal>* arbol_animales);

void mostrar_animales_en_adopcion(ABB<Animal>* arbol_animales, int metros_cuadrados);

void _mostrar_animales_en_adopcion(ABBNodo<Animal>* nodo, int metros_cuadrados);

bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados);

int string_a_tamanio(string tamanio);

tamanio_t string_a_tamanio_t(string tamanio);

void agregar_animal_a_arbol(string nombre, string edad_str, string tamanio_str, string especie_str, string personalidad_str, ABB<Animal>* arbol_animales);

#endif //ANIMAL_HANDLER_H