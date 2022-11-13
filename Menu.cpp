#include <iostream>
#include "menu.h"
#include "animal_handler.h" //Agregue esto para probar la primera opcion

using namespace std;

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

void procesar_opcion(int opcion, Lista<Animal>* lista_animales)
{
    switch(opcion){
        case LISTAR_ANIMALES:
            listar_animales(lista_animales);
            animales_paso_del_tiempo(lista_animales);
            break;
        case RESCATAR_ANIMAL:
            rescatar_animales(lista_animales);
            animales_paso_del_tiempo(lista_animales);
            break;
        case BUSCAR_ANIMAL:
            buscar_animales(lista_animales);
            animales_paso_del_tiempo(lista_animales);
            break;
        case CUIDAR_ANIMAL:
            opcion_4(lista_animales);
            animales_paso_del_tiempo(lista_animales);
            break;
        case ADOPTAR_ANIMAL:
            adoptar_animal(lista_animales);
            animales_paso_del_tiempo(lista_animales);
            break;
        case SALIR:
            guardar_y_salir(lista_animales);
            break;
    }
}

void opcion_4(Lista<Animal>* lista_animales)
{
    int opcion_2;

    do{
        mostrar_menu_2();
        opcion_2 = menu_pedir_opcion();
        menu_validar_opcion_2(opcion_2);
        procesar_opcion_2(opcion_2, lista_animales);
    }while(opcion_2 != REGRESAR_INICIO);
}

void mostrar_menu_2()
{
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "Menu para el Cuidado de los Animales" << endl << endl;
    cout << "\t 1.Elegir individualmente" << endl;
    cout << "\t 2.Alimentar a todos" << endl;
    cout << "\t 3.Bañar a todos" << endl;
    cout << "\t 4.Regresar al inicio" << endl;
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

void procesar_opcion_2(int opcion_2, Lista<Animal>* lista_animales)
{
    switch(opcion_2){
        case ELEGIR_INDIVIDUALMENTE:
            elegir_individualmente(lista_animales);
            break;
        case ALIMENTAR_TODOS:
            alimentar_todos_animales(lista_animales);
            break;
        case BANIO_TODOS:
            banio_todos(lista_animales);
            break;
        case REGRESAR_INICIO:
            break;
    }
}

void mostrar_menu_individual()
{
    cout << "1.Bañarlo" << endl;
    cout << "2.Alimentar" << endl;
    cout << "3.Volver al menu" << endl;
    cout << endl;
}

void menu_validar_opcion_individual(int &opcion)
{
    bool es_opcion_valida = opcion > 0 && opcion <= 3;
    string buffer;

    while(!es_opcion_valida){
        cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
        getline(cin >> ws,buffer);
        opcion = stoi(buffer);
        es_opcion_valida = opcion > 0 && opcion <= 3;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }
}

void procesar_opcion_individual(int &opcion, Lista<Animal>* lista_animales)
{
    switch (opcion){
        case 1:
            banio_individual(lista_animales);
            break;
        case 2:
            comida_individual(lista_animales);
            break;
        case 3:
            break;
    }
}
