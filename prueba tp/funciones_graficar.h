#ifndef FUNCIONES_GRAFICAR_H_INCLUDED
#define FUNCIONES_GRAFICAR_H_INCLUDED

#include <iostream>
#include <string>

const string tablero_original = "ccpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttccccc";

using namespace std;




void marcar_camino( string tablero,int cantidad,int vector_camino[]);

string generar_tablero_de_animales_perdidos(string animales_perdidos);

int obtener_camino(int vector_movimientos[]);

void graficar_tablero(string nuevo_tablero);

int obtener_ubicacion(string inicial_animal, string tablero_nuevo);

string modificar_tablero_aleatorio(string tablero_rand, int posicion_auto_nueva, int posicion_auto_vieja);

void imprimir_referencias();





#endif // FUNCIONES_GRAFICAR_H_INCLUDED
