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


#endif //MENU_H