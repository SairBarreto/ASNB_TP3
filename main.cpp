#include <iostream>
#include "funciones_rescatar.h"// agregado por mi
#include "animal_handler.h"
#include "menu.h"
#include "Automovil.h"

using namespace std;



int main() {


    ABB<Animal>* arbol_animales = new ABB<Animal>;
    int opcion = 0;

    Automovil autito;

    leer_archivo(arbol_animales);



    do{
        mostrar_menu();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        procesar_opcion(opcion, arbol_animales,autito);
    }while(opcion != SALIR);

    delete arbol_animales;



    return 0;
}
