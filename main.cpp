#include <iostream>
#include "Funciones.h"
#include "Animal.h"
#include "Menu.h"
#include "Arbol_B.h"

using namespace std;

int main()
{
    Clave clave;

    Arbol arbol_B;
    int i = 0;

    do{
        cout << "Ingrese un nombre del animal: ";
        fflush(stdin);
        getline(cin >> ws, clave.nombre);
        cout << endl;
            
        clave.animal.nombre = clave.nombre;
        cout << "Ingrese la edad: ";
        cin >> clave.animal.edad;
        cout << endl;
        cout << "Ingrese su especie: ";
        fflush(stdin);
        getline(cin >> ws, clave.animal.especie);
        cout << endl;
        cout << "Ingrese su tamaño: ";
        fflush(stdin);
        getline(cin >> ws, clave.animal.tamanio);
        cout << endl;
        cout << "Ingrese su personalidad: ";
        fflush(stdin);
        getline(cin >> ws, clave.animal.personalidad);
        cout << endl;
        clave.registro = i;
        i++;
        
    }while(!arbol_B.insertar(clave) || i < 4);

    arbol_B.mostrar();

    cout << endl << endl;

    string nombre_buscado;
    cout << "Ingrese un nombre para eliminar del arbol: ";
    getline(cin >> ws, nombre_buscado);

    arbol_B.borrar(nombre_buscado);

    cout << endl;
    
    arbol_B.mostrar();

    system("pause");
    return 0;
}