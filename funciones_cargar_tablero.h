#ifndef FUNCIONES_CARGAR_TABLERO_H_INCLUDED
#define FUNCIONES_CARGAR_TABLERO_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;


/*
PRE; recibe el numero de nodo;
POST;segun el tipo de casilla le asigna un peso de camino a derecha
*/
int devolver_peso_der(int numero_nodo);


/*
PRE; recibe el numero de nodo;
POST;segun el tipo de casilla le asigna un peso de camino en dirrecion sur
*/
int devolver_peso_sur(int numero_nodo);


//PRE:Utiliza funcion floyd de camino minimo
//POST: recibe los nodos de origen y de destino y escribe en un archivo el camino realizado;
void buscar_camino_minimo(string origen, string destino);


//PRE: recibe el vector camino y el largo del vector;
//POST: calcula la gasolina necesaria para realizar ese viaje
int calcular_gasolina_necesaria(int camino[],int largo);



#endif // FUNCIONES_CARGAR_TABLERO_H_INCLUDED
