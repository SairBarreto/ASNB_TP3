#include <iostream>
#include "Funciones.h"
#include "Animal.h"
#include "Menu.h"
#include "Arbol_B.h"

using namespace std;

int main()
{
    Clave clave;

    Arbol<Animal>* arbol_B = new Arbol<Animal>;

    leer_archivo_y_agrega_al_arbol(arbol_B);

    arbol_B->mostrar();

    cout << endl << endl;

    string nombre_buscado;
    cout << "Ingrese un nombre para eliminar del arbol: ";
    getline(cin >> ws, nombre_buscado);

    arbol_B->borrar(nombre_buscado);

    cout << endl;
    
    arbol_B->mostrar();

    system("pause");
    return 0;
}