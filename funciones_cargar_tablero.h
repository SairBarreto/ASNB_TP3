#ifndef FUNCIONES_CARGAR_TABLERO_H_INCLUDED
#define FUNCIONES_CARGAR_TABLERO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

const int PESOS[4] ={
    5,
    40,
    1,
    2

};

const string CASILLERO[4] ={

    "m",
    "p",
    "c",
    "t"

};




//PRE; recibe el numero de nodo;
//POST;segun el tipo de casilla le asigna un peso de camino a derecha o camino en direccion sur
int devolver_peso_nodo(int numero_nodo);


//PRE:Utiliza funcion floyd de camino minimo
//POST: recibe los nodos de origen y de destino y escribe en un archivo el camino realizado;
void buscar_camino_minimo(string origen, string destino);


//PRE: recibe el vector camino y el largo del vector;
//POST: calcula la gasolina necesaria para realizar ese viaje
int calcular_gasolina_necesaria(int camino[],int largo);



#endif // FUNCIONES_CARGAR_TABLERO_H_INCLUDED
