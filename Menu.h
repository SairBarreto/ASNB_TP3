#ifndef MENU_H
#define MENU_H 

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Animal.h"

enum{
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    SALIR,
};

enum{
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_TODOS,
    BANIO_TODOS,
    REGRESAR_INICIO
};

//PRE: -    
//POS: Muestra en texto las opciones del menu
void mostrar_menu();

//PRE: -    
//POS: Solicita el ingreso de opcion de menu
int menu_pedir_opcion();

//PRE: -    
//POS: Solicita el ingreso del nombre del animal a rescatar
string elegir_nombre();

//PRE: -    
//POS: Valida la opcion ingresada
void menu_validar_opcion(int &opcion);

//PRE: Si opcion es valida
//POS: Procesa opcion y determina la accion correspondiente
void procesar_opcion(int opcion, Lista<Animal>* lista_animales);

//PRE: -    
//POS: Muestra el segundo menu (el individual)
void mostrar_menu_2();

//PRE: -    
//POS: Muestra los animales listados
void mostrar_todos_los_animales();

//PRE: Si opcion_2 es valida [0-4]
//POS: Valida la opcion 
void menu_validar_opcion_2(int &opcion_2);

//PRE: Analoga a procesar_opcion pero para el menu 2
//POS: Analoga a procesar_opcion pero para el menu 2
void procesar_opcion_2(int opcion_2, Lista<Animal>* lista_animales);

//PRE: Lista ya cargada
//POS: Si opcion es valida y = 4 regresa al inicio
void opcion_4(Lista<Animal>* lista_animales);

//PRE: -
//POS: Muestra menu individual con 4 opciones
void mostrar_menu_individual();

//PRE: Si opcion [1-3]
//POS: Valida y verificar opcion
void menu_validar_opcion_individual(int &opcion);

//PRE: Opcion valida
//POS: Procesa la opcion y corre funciones correspondietes
void procesar_opcion_individual(int &opcion, Lista<Animal>* lista_animales);

#endif