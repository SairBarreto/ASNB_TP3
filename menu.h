#ifndef MENU_H
#define MENU_H

#include "animal_handler.h"
#include "funciones_graficar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_rescatar.h"


enum{
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    CARGAR_COMBUSTIBLE,
    SALIR,
};

enum{
    ELEGIR_INDIVIDUALMENTE = 1,
    REGRESAR_INICIO
};


//PRE: -    
//POS: Muestra en texto las opciones del menu
void mostrar_menu();

//PRE: -    
//POS: Solicita el ingreso de opcion de menu
int menu_pedir_opcion();

//PRE: -    
//POS: Valida la opcion ingresada
void menu_validar_opcion(int &opcion);

//PRE: Si opcion es valida
//POS: Procesa opcion y determina la accion correspondiente
void procesar_opcion(int opcion, ABB<Animal>* arbol_animales);

//PRE:
//POST:
void opcion_cuidar_animal(ABB<Animal>* arbol_animales);

//PRE:
//POST:
void mostrar_menu_cuidar_animal();

//PRE:
//POST:
void menu_validar_opcion_cuidar_animal(int &opcion_2);


//PRE:
//POST:
void procesar_opcion_cuidar_animal(int opcion_2, ABB<Animal>* arbol_animales);

//PRE:
//POST:
void mostrar_menu_individual();

void menu_validar_opcion_individual(int &opcion);

void procesar_opcion_individual(int &opcion, Animal* animal);

void rescatar_animales_al_arbol(ABB<Animal>* arbol_animales);


#endif //MENU_H