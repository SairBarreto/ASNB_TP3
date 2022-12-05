#ifndef MENU_H
#define MENU_H

#include "animal_handler.h"


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

//PRE: Existencia del Arbol
//POST: 
void opcion_cuidar_animal(ABB<Animal>* arbol_animales);

//PRE: --
//POST: Muestra en texto las opciones del menu para el cuidado de animales
void mostrar_menu_cuidar_animal();

//PRE: -    
//POS: Valida la opcion ingresada
void menu_validar_opcion_cuidar_animal(int &opcion_2);

//PRE: Si opcion es valida
//POS: Procesa opcion y determina la accion correspondiente
void procesar_opcion_cuidar_animal(int opcion_2, ABB<Animal>* arbol_animales);

//PRE: --
//POST: Muestra en texto las opciones del menu para el cuidado individual del animal
void mostrar_menu_individual();

//PRE: -    
//POS: Valida la opcion ingresada
void menu_validar_opcion_individual(int &opcion);

//PRE: Si opcion es valida
//POS: Procesa opcion y determina la accion correspondiente
void procesar_opcion_individual(int &opcion, Animal* animal);

#endif //MENU_H