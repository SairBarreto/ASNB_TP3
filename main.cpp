#include <iostream>
#include "funciones_rescatar.h"// agregado por mi
#include "animal_handler.h"
#include "menu.h"
#include "Automovil.h"
#include "Vida.h"

using namespace std;



int main() {


    ABB<Animal>* arbol_animales = new ABB<Animal>;
    int opcion = 0;

    Automovil autito;

    leer_archivo(arbol_animales);

    Vida vida = Vida();


    do{ 
        mostrar_menu();
        vida.mostrar_vida();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        procesar_opcion(opcion, arbol_animales,autito);
        en_juego(arbol_animales, &vida);
        sigue_vivo(&vida,&opcion);
    }while(opcion != SALIR);

    delete arbol_animales;



    return 0;
}
