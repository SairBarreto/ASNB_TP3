#include <iostream>

#include "animal_handler.h"
#include "menu.h"

using namespace std;



int main() {

    ABB<Animal>* arbol_animales = new ABB<Animal>;
    int opcion = 0;

    leer_archivo(arbol_animales);

    do{
        mostrar_menu();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        procesar_opcion(opcion, arbol_animales);
    }while(opcion != SALIR);

    delete arbol_animales;

    return 0;
}