#include <fstream>
#include "animal_handler.h"
#include "Caballo.h"
#include "Conejo.h"
#include "Erizo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Perro.h"
#include "Roedor.h"

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


            switch(string_a_especie_t(especie_str)) {

                case CABALLO:
                    {
                    Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(caballo, caballo -> obtener_nombre());
                    break;
                    }

                case CONEJO:
                    {
                    Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(conejo, conejo -> obtener_nombre());
                    break;
                    }

                case ERIZO:
                    {
                    Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(erizo, erizo -> obtener_nombre());
                    break;
                    }

                case GATO:
                    {
                    Gato* gato = new Gato(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(gato, gato -> obtener_nombre());
                    break;
                    }

                case LAGARTIJA:
                    {
                    Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(lagartija, lagartija -> obtener_nombre());
                    break;
                    }

                case PERRO:
                    {
                    Perro* perro = new Perro(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    arbol_animales -> insertar(perro, perro -> obtener_nombre());
                    break;
                    }

                case ROEDOR:
                    {
                    Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
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
        cout << raiz -> devolver_key() << endl;
        _imprimir_arbol(raiz -> devolver_nodo_derecha());
    }
}