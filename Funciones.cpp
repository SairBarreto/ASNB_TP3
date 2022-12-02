/*
#include <iostream>
#include <fstream>
#include "Funciones.h"
#include "Caballo.h"
#include "Conejo.h"
#include "Erizo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Perro.h"
#include "Roedor.h"
#include "Menu.h"

void leer_archivo_y_agrega_al_arbol(Arbol<Animal>* Arbol_animales)
{
string nombre, edad_str, tamanio_str, especie_str, personalidad_str;
    char delimitador = ','; //El delimitador tiene que ser de tipo char con string no funciona
    ifstream archivo(PATH_ANIMALES, ios::in);

    if(!archivo.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_ANIMALES << "\", se va a crear el archivo" << endl;
        archivo.open(PATH_ANIMALES, ios::out);
        archivo.close();
        archivo.open(PATH_ANIMALES, ios::in);
    }

    if(archivo.is_open()){
        int i = 0;
        Clave clave;

        do{
            getline(archivo,nombre, delimitador);
            getline(archivo, edad_str, delimitador);
            getline(archivo, tamanio_str, delimitador);
            getline(archivo, especie_str, delimitador);
            getline(archivo, personalidad_str, '\n');

            switch(string_a_especie_t(especie_str)) {

                case CABALLO:
                    {
                    Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = caballo;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case CONEJO:
                    {
                    Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = conejo;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case ERIZO:
                    {
                    Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = erizo;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case GATO:
                    {
                    Gato* gato = new Gato(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = gato;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case LAGARTIJA:
                    {
                    Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = lagartija;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case PERRO:
                    {
                    Perro* perro = new Perro(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = perro;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                case ROEDOR:
                    {
                    Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                    clave.nombre = nombre;
                    clave.animal = rata;
                    clave.registro = i;
                    Arbol_animales->insertar(clave);
                    i++;
                    break;
                    }

                default:
                    break;
            
            }
        }while(!archivo.eof() && i < TAMANO);
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }

    archivo.close();
}

especie_t string_a_especie_t(string especie)
{
    int posicion;
    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(especie == ESPECIES_STR[i])
            posicion = i;
    }
    return (especie_t) posicion;
}

string devolver_especie_palabra_completa(string inicial_ingresado)
{
    string inicial;
    string palabra;
    string especie_nombre_completo;

    for(int i = 0; i < 7; i++){
        palabra = ESPECIES_COMPLETAS[i];
        inicial = palabra[0];

        if (inicial_ingresado == inicial && palabra != "Conejo" ){
            especie_nombre_completo = palabra;
        }
        else if (inicial_ingresado == "O" && palabra =="Conejo"){
            especie_nombre_completo = palabra;
        }
    }

    return especie_nombre_completo;
}
*/