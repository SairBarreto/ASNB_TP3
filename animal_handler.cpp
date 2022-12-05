#include <fstream>
#include "animal_handler.h"
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

#include "menu.h"




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
                    break;
            }

            switch(string_a_especie_t(especie_str)) {

                case CABALLO:
                    {
                    Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(caballo, caballo -> obtener_nombre());
                    break;
                    }

                case CONEJO:
                    {
                    Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(conejo, conejo -> obtener_nombre());
                    break;
                    }

                case ERIZO:
                    {
                    Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(erizo, erizo -> obtener_nombre());
                    break;
                    }

                case GATO:
                    {
                    Gato* gato = new Gato(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(gato, gato -> obtener_nombre());
                    break;
                    }

                case LAGARTIJA:
                    {
                    Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(lagartija, lagartija -> obtener_nombre());
                    break;
                    }

                case PERRO:
                    {
                    Perro* perro = new Perro(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(perro, perro -> obtener_nombre());
                    break;
                    }

                case ROEDOR:
                    {
                    Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad);
                    arbol_animales -> insertar(rata, rata -> obtener_nombre());
                    break;
                    }
                
                default:
                    break;
            }
        }
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
    //nombre_ingresado = elegir_nombre();

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

void adoptar_animal(Arbol<Animal>* arbol_animales){
    int metros_cuadrados = 0;
    string nombre_buscado;
    cout << "Ingrese cantidad de metros cuadrados disponibles: ";
    cin >> metros_cuadrados;

    mostrar_animales_en_adopcion(arbol_animales, metros_cuadrados);

    cout << "¿Cual desea adoptar? Ingrese su nombre: ";
    getline(cin >> ws, nombre_buscado);
    
    bool existe_nombre = false;
    int i = 0;

    while(i < arbol_animales->obtener_cantidad() && !existe_nombre){
        if(nombre_buscado == arbol_animales->devolver_dato()->obtener_nombre() && puede_vivir_en_espacio(arbol_animales->devolver_dato(), metros_cuadrados)){
            //  lista_animales->borrar_nodo_actual();  // en el tp dice que no es necesario borrarlo
            cout << endl;
            cout << "Felicidades usted adopto a " << nombre_buscado << endl;
            cout << endl << "---------------------------------------------------------" << endl << endl;
            existe_nombre = true;
        }
        i++;
        // arbol_animales->pasar_nodo();  ¿uso arbol_animales->_eliminar?
    }
 
    if(existe_nombre == false){
        cout << endl;
        cout << nombre_buscado << " no se encuentra en la Reserva" << endl;
        cout << endl << "---------------------------------------------------------" << endl << endl;
    }

    // lista_animales->iniciar_nodo_actual();
}

void mostrar_animales_en_adopcion(ABB<Animal>* arbol_animales, int metros_cuadrados) {
    cout << endl;
    _mostrar_animales_en_adopcion(arbol_animales -> devolver_raiz(), metros_cuadrados);
    cout << endl;

}

void _mostrar_animales_en_adopcion(ABBNodo<Animal>* nodo, int metros_cuadrados) {
   
    if(nodo != nullptr) {
         _mostrar_animales_en_adopcion(nodo -> devolver_nodo_izquierda(), metros_cuadrados);
        if( puede_vivir_en_espacio( nodo -> devolver_dato(), metros_cuadrados) ) {
          // falta definir la funcion
        }
         _mostrar_animales_en_adopcion(nodo -> devolver_nodo_derecha(), metros_cuadrados);
    }
   
}

void ordenar_vector(Animal* animales_adopcion[]){
    QuickSort quicksort;

    quicksort.sort(animales_adopcion);
    
    cout << "ordenado" << endl;
}


bool puede_vivir_en_espacio(Animal* animal, int metros_cuadrados) {
    int minimo = string_a_tamanio(animal->obtener_tamanio());
    if(metros_cuadrados >= minimo)
        return true;
    return false;
}

int string_a_tamanio(string tamanio) {
    int espacio_minimo = 100;
    for(int i = 0; i < CANTIDAD_TAMANIOS; i++){

        if(tamanio == TAMANIOS[i].tamanio)
            espacio_minimo = TAMANIOS[i].min;
    }
    return espacio_minimo;
}
