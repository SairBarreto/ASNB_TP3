#include <fstream>
#include "animal_handler.h"
#include "ordenamiento.h"

#include "Caballo.h"
#include "Conejo.h"
#include "Erizo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Perro.h"
#include "Roedor.h"

#include "Dormilon.h"
#include "Jugeton.h"
#include "Sociable.h"
#include "Travieso.h"

#include "Diminuto.h"
#include "Pequenio.h"
#include "Mediano.h"
#include "Grande.h"
#include "Gigante.h"

#include "Automovil.h"

#include "menu.h"


void mostrar_gasolina(Automovil autito)
{
    cout<<endl;

    cout<<"El nivel de gasolina actual es de: "<<autito.get_gasolina()<<endl;

    cout<<endl;

}

void cargar_auto_paso_de_tiempo(Automovil autito)
{
    autito.aumentar_nivel_de_gasolina();
}

void cargar_auto(Automovil autito)
{
    int nueva_carga = 0;

    cout<<"El tope de gasolina es de 100, si la gasolina cargada sobrepasa el tope, quedara en 100 de todas maneras \n"<<endl;

    cout<<"Ingrese la cantidad de gasolina que desea cargar: ";
    cin>>nueva_carga;

    autito.cargar_gasolina(nueva_carga);

    mostrar_gasolina(autito);
}

void leer_archivo(ABB<Animal>* arbol_animales) {
    string nombre, edad_str, tamanio_str, especie_str, personalidad_str;
    char delimitador = ',';
    ifstream archivo(PATH_ANIMALES, ios::in);

    if(!archivo.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_ANIMALES << "\", se va a crear el archivo" << endl;
        archivo.open(PATH_ANIMALES, ios::out);
        archivo.close();
        archivo.open(PATH_ANIMALES, ios::in);
    }

    if(archivo.is_open()) {
        while(getline(archivo,nombre, delimitador)) {
            getline(archivo, edad_str, delimitador);
            getline(archivo, tamanio_str, delimitador);
            getline(archivo, especie_str, delimitador);
            getline(archivo, personalidad_str, '\n');

            Tamanio* tamanio;

            switch(string_a_tamanio_t(tamanio_str)) {

                case DIMINUTO:
                    tamanio = new Diminuto();
                    break;
                case PEQUENIO:
                    tamanio = new Pequenio();
                    break;
                case MEDIANO:
                    tamanio = new Mediano();
                    break;
                case GRANDE:
                    tamanio = new Grande();
                    break;
                case GIGANTE:
                    tamanio = new Gigante();
                    break;
                default:
                    {}
            }


            Personalidad* personalidad;

            switch(string_a_personalidad_t(personalidad_str)) {

                case DORMILON:
                    {
                    personalidad = new Dormilon();
                    break;
                    }

                case JUGETON:
                    {
                    personalidad = new Jugeton();
                    break;
                    }
                case SOCIABLE:
                    {
                    personalidad = new Sociable();
                    break;
                    }
                case TRAVIESO:
                    {
                    personalidad = new Travieso();
                    break;
                    }
                default:
                    {}
            }

            switch(string_a_especie_t(especie_str)) {

                case CABALLO:
                    {
                    Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(caballo, caballo -> obtener_nombre());
                    break;
                    }

                case CONEJO:
                    {
                    Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(conejo, conejo -> obtener_nombre());
                    break;
                    }

                case ERIZO:
                    {
                    Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(erizo, erizo -> obtener_nombre());
                    break;
                    }

                case GATO:
                    {
                    Gato* gato = new Gato(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(gato, gato -> obtener_nombre());
                    break;
                    }

                case LAGARTIJA:
                    {
                    Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(lagartija, lagartija -> obtener_nombre());
                    break;
                    }

                case PERRO:
                    {
                    Perro* perro = new Perro(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(perro, perro -> obtener_nombre());
                    break;
                    }

                case ROEDOR:
                    {
                    Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
                    arbol_animales -> insertar(rata, rata -> obtener_nombre());
                    break;
                    }

                default:
                    {}
            }
        }
    }
}

void agregar_animal_a_arbol(string nombre, string edad_str, string tamanio_str, string especie_str, string personalidad_str, ABB<Animal>* arbol_animales) {
    Tamanio* tamanio;

    switch(string_a_tamanio_t(tamanio_str)) {

        case DIMINUTO:
            tamanio = new Diminuto();
            break;
        case PEQUENIO:
            tamanio = new Pequenio();
            break;
        case MEDIANO:
            tamanio = new Mediano();
            break;
        case GRANDE:
            tamanio = new Grande();
            break;
        case GIGANTE:
            tamanio = new Gigante();
            break;
        default:
            {}
    }

    Personalidad* personalidad;

    switch(string_a_personalidad_t(personalidad_str)) {

        case DORMILON:
            {
            personalidad = new Dormilon();
            break;
            }

        case JUGETON:
            {
            personalidad = new Jugeton();
            break;
            }
        case SOCIABLE:
            {
            personalidad = new Sociable();
            break;
            }
        case TRAVIESO:
            {
            personalidad = new Travieso();
            break;
            }
        default:
            {}
    }

    switch(string_a_especie_t(especie_str)) {

        case CABALLO:
            {
            Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(caballo, caballo -> obtener_nombre());
            break;
            }

        case CONEJO:
            {
            Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(conejo, conejo -> obtener_nombre());
            break;
            }

        case ERIZO:
            {
            Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(erizo, erizo -> obtener_nombre());
            break;
            }

        case GATO:
            {
            Gato* gato = new Gato(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(gato, gato -> obtener_nombre());
            break;
            }

        case LAGARTIJA:
            {
            Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(lagartija, lagartija -> obtener_nombre());
            break;
            }

        case PERRO:
            {
            Perro* perro = new Perro(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(perro, perro -> obtener_nombre());
            break;
            }

        case ROEDOR:
            {
            Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio, especie_str, personalidad);
            arbol_animales -> insertar(rata, rata -> obtener_nombre());
            break;
            }

        default:
            {}
    }
}


especie_t string_a_especie_t(string especie) {
    int posicion;
    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(especie == ESPECIES_STR[i])
            posicion = i;
    }
    return (especie_t) posicion;
}


void  imprimir_arbol(ABB<Animal>* arbol_animales) {
    _imprimir_arbol(arbol_animales -> devolver_raiz());
}

void _imprimir_arbol(ABBNodo<Animal>* raiz) {
    if(raiz != nullptr) {
        _imprimir_arbol(raiz -> devolver_nodo_izquierda());
        Animal* animal = raiz -> devolver_dato();
        cout << endl;
        cout << "\t" << animal -> obtener_nombre() << endl;
        cout << "\t-Edad: " << animal -> obtener_edad() << endl;
        cout << "\t-Tamaño: " << animal -> obtener_tamanio() << endl;
        cout << "\t-Especie: " << especie_inicial_a_string(animal -> obtener_especie()) << endl;
        cout << "\t-Personalidad: " << animal -> obtener_personalidad() << endl;
        cout << "\t-Higiene: " << animal -> obtener_higiene() << endl;
        cout << "\t-Hambre: " << animal -> obtener_hambre() << endl;
        _imprimir_arbol(raiz -> devolver_nodo_derecha());
    }
}


void buscar_animales(ABB<Animal>* arbol_animales)
{
    string nombre_ingresado;
    string inicial_especie;

    cin.ignore();
    cout << "Ingrese el nombre del animal que desea buscar" << endl;
    cout << endl;
    getline(cin >> ws, nombre_ingresado);


    Animal* animal = arbol_animales -> buscar(nombre_ingresado);
    if(animal == nullptr) {
        cout << "\nERROR: El nombre ingresado no existe " << endl;
    }
    else {
        cout << endl;
        cout << "\t" << animal -> obtener_nombre() << endl;
        cout << "\t Edad: " << animal -> obtener_edad() << endl;
        cout << "\t Tamaño: " << animal -> obtener_tamanio() << endl;
        cout << "\t Especie: " << especie_inicial_a_string(animal -> obtener_especie())  << endl;
        cout << "\t Personalidad: " << animal -> obtener_personalidad() << endl;
    }

}


void animales_paso_del_tiempo(ABB<Animal>* arbol_animales) {
    _animales_paso_del_tiempo(arbol_animales -> devolver_raiz());
}

void _animales_paso_del_tiempo(ABBNodo<Animal>* raiz) {
    if(raiz != nullptr) {
        _animales_paso_del_tiempo(raiz -> devolver_nodo_izquierda());
        raiz -> devolver_dato() -> ensuciar();
        raiz -> devolver_dato() -> gastar_energia();
        _animales_paso_del_tiempo(raiz -> devolver_nodo_derecha());
    }
}


tamanio_t string_a_tamanio_t(string tamanio) {
    int posicion;
    for(int i = 0; i < CANTIDAD_TAMANIOS; i++){
        if(tamanio == TAMANIOS_STR[i])
            posicion = i;
    }
    return (tamanio_t) posicion;
}


personalidad_t string_a_personalidad_t(string personalidad) {
    int posicion;
    for(int i = 0; i < CANTIDAD_PERSONALIDAD; i++){
        if(personalidad == PERSONALIDAD_STR[i])
            posicion = i;
    }
    return (personalidad_t) posicion;
}

string especie_inicial_a_string(string inicial) {
    int posicion;
    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(inicial == ESPECIES_STR[i])
            posicion = i;
    }
    return  ESPECIES_COMPLETAS[posicion];
}


void elegir_individualmente(ABB<Animal>* arbol_animales)
{
    string nombre_buscado;
    int opcion;

    imprimir_arbol(arbol_animales);

    cout << "Ingrese el nombre del animal que desea buscar" << endl;
    cout << endl;
    getline(cin >> ws, nombre_buscado);

    Animal* animal = arbol_animales -> buscar(nombre_buscado);

    if(animal != nullptr) {
        cout << "Que quiere hacer con " << animal -> obtener_nombre() << endl << endl;
        mostrar_menu_individual();
        opcion = menu_pedir_opcion();
        menu_validar_opcion_individual(opcion);
        procesar_opcion_individual(opcion, animal);
    }

    else {
        cout << endl;
        cout << "El nombre ingresado no se encuentra en la Reserva" << endl;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }

}


void banio_individual(Animal* animal) {
    animal -> baniarse();
}

void alimentar_individual(Animal* animal) {
    animal -> alimentarse();
}


Animal* animal[1000];
int i = 0;
int temporal;

void adoptar_animal(ABB<Animal>* arbol_animales) {
    int metros_cuadrados = 0;
    cout << "Ingrese cantidad de metros cuadrados disponibles: ";
    cin >> metros_cuadrados;

    mostrar_animales_en_adopcion(arbol_animales, metros_cuadrados);

    bool salir = false;
    int contador = 0;
    string nombre_buscado;
    cout << endl;
    cout << "¿Cual desea adoptar? Ingrese su nombre: ";
    cin.ignore();
    getline(cin >> ws, nombre_buscado);

    while(contador < temporal && !salir){
        if(animal[contador]->obtener_nombre() == nombre_buscado){
            Animal* animal = arbol_animales -> buscar(nombre_buscado);

            arbol_animales -> eliminar(animal -> obtener_nombre());
            cout << endl;
            cout << "Felicidades usted adopto a " << nombre_buscado << endl;
            cout << endl << "---------------------------------------------------------" << endl << endl;
            
            salir = true;
        }
        contador++;
    }
    if(salir == false){
        cout << endl;
        cout << nombre_buscado << " no se encuentra en la Reserva o no tiene el espacio suficiente." << endl;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }
}

void mostrar_animales_en_adopcion(ABB<Animal>* arbol_animales, int metros_cuadrados) {
    cout << endl;
    _mostrar_animales_en_adopcion(arbol_animales -> devolver_raiz(), metros_cuadrados);
    cout << endl;

    QuickSort ordenar;

    ordenar.sort(animal, i);

   for(int j = 0; j < i; j++){
        cout << "\tEdad: " << animal[j]->obtener_edad() << endl;
        cout << "\tNombre: " << animal[j]->obtener_nombre() << endl;
        cout << endl;
    }
    temporal = i;
    i = 0; //Reinicio el contador xq esta declarado como una variable global
}

void _mostrar_animales_en_adopcion(ABBNodo<Animal>* nodo, int metros_cuadrados) {

    if(nodo != nullptr) {
        _mostrar_animales_en_adopcion(nodo -> devolver_nodo_izquierda(), metros_cuadrados);
        if( puede_vivir_en_espacio( nodo -> devolver_dato(), metros_cuadrados) ) {
            //cout << "i: " << i <<endl;
            animal[i] = nodo->devolver_dato();
            
            i++;
        }
        _mostrar_animales_en_adopcion(nodo -> devolver_nodo_derecha(), metros_cuadrados);
    }
}

bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados) {
    return animal -> obtener_tipo_tamanio() -> hay_espacio_suficiente(metros_cuadrados);
}


void en_juego(ABB<Animal>* arbol_animales, Vida* vida) {
    _recorrer_animales(arbol_animales, arbol_animales -> devolver_raiz(), vida);
}

void _recorrer_animales(ABB<Animal>* arbol_animales, ABBNodo<Animal>* nodo, Vida* vida) {
    if(nodo != nullptr && nodo -> devolver_dato() != nullptr) {
        _recorrer_animales(arbol_animales, nodo -> devolver_nodo_izquierda(), vida);
        ///Animal* animal = nodo -> devolver_dato();

        if(nodo -> devolver_dato() -> obtener_higiene() <= 0) {
            //cout << animal -> obtener_higiene();
            nodo -> devolver_dato() -> baniarse();
            cout << "Has descuidado un animal, que no vuelva a pasar" << endl;
            vida -> restar_vida();
        }

        if(nodo -> devolver_dato() -> obtener_hambre() >= 100) {
            //cout << animal -> obtener_hambre() << endl;   
            cout << "Has descuidado un animal, que no vuelva a pasar" << endl;
            nodo -> devolver_dato() -> alimentarse();
            vida -> restar_vida();
        }
        _recorrer_animales(arbol_animales, nodo -> devolver_nodo_derecha(), vida);
    }
}



void guardar_y_salir(ABB<Animal>* arbol_animales) {
    ofstream archivo(PATH_ANIMALES, ios::out);

    _guardar_y_salir(arbol_animales -> devolver_raiz(), archivo);

    archivo.close();
}

void _guardar_y_salir(ABBNodo<Animal>* raiz, ofstream &output_file) {
    if(raiz != nullptr) {
        Animal* animal = raiz -> devolver_dato();
        _guardar_y_salir(raiz -> devolver_nodo_izquierda(), output_file);
        output_file << animal -> obtener_nombre() << "," << animal -> obtener_edad() << "," << animal -> obtener_tamanio() << "," << animal -> obtener_especie() << "," << animal -> obtener_personalidad() << endl;
        _guardar_y_salir(raiz -> devolver_nodo_derecha(), output_file);
    }
}