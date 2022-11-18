#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include "Arbol_B.h"
#include "Animal.h"

using namespace std;

const int TAMANO = 1000;

struct tamanio_t {
    string tamanio;
    int min;
};

const tamanio_t TAMANIOS[5] = {
    {"diminuto",0},
    {"pequenio",2},
    {"mediano",10},
    {"grande",20},
    {"gigante",50}
};

const int CANTIDAD_TAMANIOS = 6;

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

const int EDAD_MAX = 100;

const int EDAD_MIN = 0;

const string PATH_ANIMALES = "animales.csv";


//PRE: -    
//POS: Lee archivo previamente cargador almacenando datos en Arbol
void leer_archivo_y_agrega_al_arbol(Arbol<Animal>* Arbol_animales);

especie_t string_a_especie_t(string especie);

/*
//PRE: Arbol previamente completada    
//POS: Recorre secuencialmente la Arbol Arbolndo los animales con sus atributos
void listar_animales(Arbol<Animal>* Arbol_animales);


//PRE: Arbol previamente completada, ingreso valido de entero (metros_cuadrados) y string (nombre_buscado) por usuario
//POS: Adopta animal indicado por el usuario siendo eliminado su nodo de la Arbol
void adoptar_animal(Arbol<Animal>* Arbol_animales);

//PRE: metros_cuadrados valido entre 0-100    
//POS: Muestra animales validos para adoptar dependiendo de tus metros cuadrados
void mostrar_animales_en_adopcion(Arbol<Animal>* Arbol_animales, int metros_cuadrados);

//PRE: metros_cuadrados entre 0-100  
//POS: Si metros_cuadrados es mayor al minimo del animal, el mismo puede vivir en el espacio
bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados);

//PRE:-  
//POS: De string a tamanio
int string_a_tamanio(string tamanio);

//PRE: Arbol completa y valida   
//POS: Baja higiene y sube el hambre de cada animal
void animales_paso_del_tiempo(Arbol<Animal>* Arbol_animales);

//PRE: Arbol previamente completada, ingreso valido de entero (metros_cuadrados) y string (nombre_buscado) por usuario
//POS: Adopta animal indicado por el usuario siendo eliminado su nodo de la Arbol
void adoptar_animal(Arbol<Animal>* Arbol_animales);

//PRE: metros_cuadrados valido entre 0-100    
//POS: Muestra animales validos para adoptar dependiendo de tus metros cuadrados
void mostrar_animales_en_adopcion(Arbol<Animal>* Arbol_animales, int metros_cuadrados);

//PRE: metros_cuadrados entre 0-100  
//POS: Si metros_cuadrados es mayor al minimo del animal, el mismo puede vivir en el espacio
bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados);

int string_a_tamanio(string tamanio);

//PRE: Arbol completa y valida
//POS: Se alimenta a todos los animales devolviendo su hambre a 0
void alimentar_todos_animales(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa y valida
//POS: Se baña a todos los animales devolviendo su higiene a 100
void banio_todos(Arbol<Animal>* Arbol_animales);

//PRE: nombre_buscado debe ser valido
//POS: Despliega menu para el animal individual en caso de ser hallado
void elegir_individualmente(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa y valida
//POS: Bania individualmente al animal, en caso de Gato, Roedor y Lagartija higiene jamas baja por ende no lo baña
void banio_individual(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa y valida
//POS: Se alimenta individualmente al animal seleccionado con su respectiva comida
void comida_individual(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa y nombre valido
//POS: Verificar la existencia del nombre ingresado
bool verificar_nombre(Arbol<Animal>* Arbol_animales,string nombre_ingresado);

//PRE: Arbol completa y nombre valido
//POS: Buscar la existencia del nombre ingresado
void buscar_animales(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa y datos valido
//POS: Agrega el nuevo nodo ya completo a la Arbol
void agregar_nodo_a_Arbol(Arbol<Animal>* Arbol_animales, string nombre, string edad_str, string tamanio_str, string especie_str, string personalidad_str);

//PRE: Arbol completa 
//POS: Cargar animales para el rescate
void rescatar_animales(Arbol<Animal>* Arbol_animales);

//PRE: Arbol completa 
//POS: Cargar Arbol reescribiendo el archivo
void guardar_y_salir(Arbol<Animal>* Arbol_animales);

//PRE: Inicial de la especie
//POS: Retorna especie completa
string devolver_especie_palabra_completa(string inicial);

//PRE: -
//POS: Usuario carga especie del animal
string elegir_especie();

//PRE: -
//POS: Usuario carga personalidad del animal
string elegir_personalidad();

//PRE: -
//POS: Usuario carga tamanio del animal
string elegir_tamanio();

//PRE: -
//POS: Usuario carga edad del animal
string ingresar_edad();
*/
#endif