#include <iostream>
#include "Animal.h"
#include "Menu.h"

using namespace std;

int main()
{
    //Lista<Animal>* lista_animales = new Lista<Animal>;
    int opcion = 0;

    //leer_archivo(lista_animales);

   do{
        mostrar_menu();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        //procesar_opcion(opcion, lista_animales);
    }while(opcion != SALIR);
    
    //delete lista_animales;

    return 0;
}