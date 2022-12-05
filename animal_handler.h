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

//PRE: Existencia del Archivo a leer
//POST: Lee el archivo y lo va agregando al main
void leer_archivo(ABB<Animal>* arbol_animales);

//PRE: Ingresa un string
//POST: Retorna un numero segun la especie
especie_t string_a_especie_t(string especie);

//PRE: Ingresa un string
//POST: Retorna un numero segun la especie 
personalidad_t string_a_personalidad_t(string personalidad);

//PRE: Existencia del Arbol
//POST: Recorre el Arbol y lo imprime
void  imprimir_arbol(ABB<Animal>* arbol_animales);

//PRE: Ingresa la raiz del Arbol
//POST: Recorre el Arbol y lo imprime
void _imprimir_arbol(ABBNodo<Animal>* raiz);

//PRE: Existencia del Arbol
//POST: Sirve para mostrar los Datos de un ABBNodo si este existe
void buscar_animales(ABB<Animal>* tree);

//PRE: Existencia del Arbol
//POST: Recorre el Arbol y el hambre aumenta e higiene disminuye
void animales_paso_del_tiempo(ABB<Animal>* arbol_animales);

//PRE: Ingresa la raiz del Arbol
//POST: Recorre el Arbol y el hambre aumenta e higiene disminuye
void _animales_paso_del_tiempo(ABBNodo<Animal>* raiz);

//PRE: Ingresa la inicial de la especie
//POST: Devuele el nombre de la especie completo
string especie_inicial_a_string(string inicial);

//PRE: Existencia del Arbol
//POST: Elige a un ABBNodo segun su key para modificarlo
void elegir_individualmente(ABB<Animal>* arbol_animales);

//PRE: Existencia del ABBNodo
//POST: Higiene vuelve al 100 por ciento
void banio_individual(Animal* animal);

//PRE: Existencia del ABBNodo
//POST: Hambre vuelve a 0 por ciento
void alimentar_individual(Animal* animal);

//PRE: Existencia del Arbol
//POST: Busca un ABBNodo del arbol si este existe lo borra del Arbol
void adoptar_animal(ABB<Animal>* arbol_animales);

//PRE: Existencia del Arbol
//POST: Muestra los ABBNodo disponibles segun los mentros_cuadrados ingresados
void mostrar_animales_en_adopcion(ABB<Animal>* arbol_animales, int metros_cuadrados);

//PRE: Existencia del Arbol
//POST: Muestra aquellos que cumplen con la conticion de los metros_cuadrados
void _mostrar_animales_en_adopcion(ABBNodo<Animal>* nodo, int metros_cuadrados);

//PRE: --
//POST: Devuelve TRUE o FALSE si cumple con la condicion de los metros_cuadrados
bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados);

//PRE: --
//POST: 
int string_a_tamanio(string tamanio);

//PRE: --
//POST:  Retorna un numero segun el Tamaño
tamanio_t string_a_tamanio_t(string tamanio);

//PRE: Existencia del Arbol
//POST: Agrega un ABBNodo al Arbol
void agregar_animal_a_arbol(string nombre, string edad_str, string tamanio_str, string especie_str, string personalidad_str, ABB<Animal>* arbol_animales);

#endif //ANIMAL_HANDLER_H