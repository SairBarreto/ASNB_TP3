#include <iostream>
#include "Menu.h"
#include "Funciones.h" 


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
    cout << "\t 6.Guardar y salir" << endl;
    cout << endl;
}

int menu_pedir_opcion(){
    int opcion;
    cout << "Ingrese el número de su acción elegida : ";
    cin >> opcion;
    cout << endl << "---------------------------------------------------------" << endl << endl;
    return opcion;
}

string elegir_nombre()
{
    string nombre;
    cout << "Ingrese el nombre del animal: ";
    getline(cin >> ws, nombre);

    return nombre;
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

void procesar_opcion(int opcion, Arbol<Animal>* Arbol_animales)
{
    switch(opcion){
        case LISTAR_ANIMALES:
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

void opcion_4(Arbol<Animal>* Arbol_animales)
{
    int opcion_2;

    do{
        mostrar_menu_2();
        opcion_2 = menu_pedir_opcion();
        menu_validar_opcion_2(opcion_2);
        procesar_opcion_2(opcion_2, Arbol_animales);
    }while(opcion_2 != REGRESAR_INICIO);
}

void mostrar_menu_2()
{
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "Menu para el Cuidado de los Animales" << endl << endl;
    cout << "\t 1.Elegir individualmente" << endl;
    cout << "\t 2.Regresar al inicio" << endl;
    cout << endl;
}

void menu_validar_opcion_2(int &opcion_2){
    bool es_opcion_valida = opcion_2 > 0 && opcion_2 <= REGRESAR_INICIO;
    string buffer;

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        getline(cin >> ws,buffer);
        opcion_2 = stoi(buffer);
        es_opcion_valida = opcion_2 > 0 && opcion_2 <= REGRESAR_INICIO;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }
}

void procesar_opcion_2(int opcion_2, Arbol<Animal>* Arbol_animales)
{
    switch(opcion_2){
        case ELEGIR_INDIVIDUALMENTE:
            break;
        case REGRESAR_INICIO:
            break;
    }
}

void mostrar_menu_individual()
{
    cout << "1.Bañarlo" << endl;
    cout << "2.Alimentar" << endl;
    cout << "3.Saltear" << endl;
    cout << "4.Volver al inicio" << endl;
    cout << endl;
}

void menu_validar_opcion_individual(int &opcion)
{
    bool es_opcion_valida = opcion > BANIO && opcion <= REGRESAR;
    string buffer;

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        getline(cin >> ws,buffer);
        opcion = stoi(buffer);
        es_opcion_valida = opcion > BANIO && opcion <= REGRESAR;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }
}

void procesar_opcion_individual(int &opcion, Arbol<Animal>* Arbol_animales)
{
    switch (opcion){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}