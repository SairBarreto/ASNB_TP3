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
            animales_paso_del_tiempo(arbol_animales);
            break;

        case RESCATAR_ANIMAL:
            rescatar_animales_al_arbol(arbol_animales);
            animales_paso_del_tiempo(arbol_animales);
            break;

        case BUSCAR_ANIMAL:
            buscar_animales(arbol_animales);
            animales_paso_del_tiempo(arbol_animales);
            break;

        case CUIDAR_ANIMAL:
            opcion_cuidar_animal(arbol_animales);
            animales_paso_del_tiempo(arbol_animales);
            break;

        case ADOPTAR_ANIMAL:
            adoptar_animal(arbol_animales);
            animales_paso_del_tiempo(arbol_animales);
            break;

        case CARGAR_COMBUSTIBLE:
            break;

        case SALIR:
            {}
    }
}

void opcion_cuidar_animal(ABB<Animal>* arbol_animales) {
    int opcion_2;

    do{
        mostrar_menu_cuidar_animal();
        opcion_2 = menu_pedir_opcion();
        menu_validar_opcion_cuidar_animal(opcion_2);
        procesar_opcion_cuidar_animal(opcion_2, arbol_animales);
    }while(opcion_2 != REGRESAR_INICIO);
}

void mostrar_menu_cuidar_animal()
{
    cout << endl;
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "Menu para el Cuidado de los Animales" << endl << endl;
    cout << "\t 1.Elegir individualmente" << endl;
    cout << "\t 2.Regresar al inicio" << endl;
    cout << endl;
}

void menu_validar_opcion_cuidar_animal(int &opcion_2) {
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

void procesar_opcion_cuidar_animal(int opcion_2, ABB<Animal>* arbol_animales)
{
    switch(opcion_2){
        case ELEGIR_INDIVIDUALMENTE:
            elegir_individualmente(arbol_animales);
            break;
        case REGRESAR_INICIO:
            {}
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

void procesar_opcion_individual(int &opcion, Animal* animal)
{
    switch (opcion){
        case 1:
            banio_individual(animal);
            break;
        case 2:
            alimentar_individual(animal);
            break;
        case 3:
            {}
    }
}

void rescatar_animales_al_arbol(ABB<Animal>* arbol_animales) {
    string animales_perdidos;
    string animales_rescatados;

    animales_perdidos = generar_animales_perdidos();
    animales_rescatados = empezar_a_rescatar(animales_perdidos);
}