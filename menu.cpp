#include "menu.h"

void mostrar_menu()
{
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "MENU" << endl;
    cout << "\t 1.Listar animales" << endl;
    cout << "\t 2.Rescatar animal" << endl;
    cout << "\t 3.Buscar animal" << endl;
    cout << "\t 4.Cuidar animales" << endl;
    cout << "\t 5.Adoptar animal" << endl;
    cout << "\t 6.Cargar combustible" << endl;
    cout << "\t 7.Guardar y salir" << endl;
    cout << endl;
}

int menu_pedir_opcion(){
    int opcion;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> opcion;
    cout << endl << "---------------------------------------------------------" << endl << endl;
    return opcion;
}

void menu_validar_opcion(int &opcion)
{
    bool es_opcion_valida = opcion > 0 && opcion <= SALIR;
    string buffer;

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        getline(cin >> ws,buffer);
        opcion = stoi(buffer);
        es_opcion_valida = opcion > 0 && opcion <= SALIR;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }
}


void procesar_opcion(int opcion, ABB<Animal>* arbol_animales)
{
    switch(opcion){
        case LISTAR_ANIMALES:
            imprimir_arbol(arbol_animales);
            break;

        case RESCATAR_ANIMAL:
            break;

        case BUSCAR_ANIMAL:
            break;

        case CUIDAR_ANIMAL:
            break;

        case ADOPTAR_ANIMAL:
            break;

        case CARGAR_COMBUSTIBLE:
            break;

        case SALIR:
            break;
    }
}