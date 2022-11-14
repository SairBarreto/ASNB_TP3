#include <iostream>
#include <fstream>
#include "Animal.h"
#include "Menu.h"
#include "Arbol_B.h"

using namespace std;

const int TAMANO = 1000;

const string PATH_ANIMALES = "animales.csv";

int main()
{
    Arbol<Animal>* arbol_animales = new Arbol<Animal>(3);
    //int opcion = 0;

    //ifstream archivo(PATH_ANIMALES, ios::out);
    

    /*/leer_archivo(lista_animales);

   do{
        mostrar_menu();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        //procesar_opcion(opcion, lista_animales);
    }while(opcion != SALIR);
    */

    return 0;
}