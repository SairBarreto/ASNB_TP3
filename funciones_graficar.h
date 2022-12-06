#ifndef FUNCIONES_GRAFICAR_H_INCLUDED
#define FUNCIONES_GRAFICAR_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

const string tablero_original = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";



 const string EMOJIS[13] = {
        "🐶",//PERRO
        "🐎",//caballo
        "🐱",//gato
        "🐭",//rata
        "🐰",//conejo
        "🦎",//lagarto
        "🦔",//erizo
        "🚚",//auto
        "🟫",//monta�a
        "⬛",//precipicio
        "⬜",//camino
        "🟩",//tierra
        "❤️"//corazon rojo

 };


 const string TIPO_CASILLERO[13] =
 {
   "P",//perro
   "C",//caballo
   "G",//gato
   "R",//roedor
   "O",//conejo
   "L",//lagarto
   "E",//erizo
   "A",//auto
   "m",//monta�a
   "p",//precipicio
   "c",//camino
   "t",//tierra
   "."//yendo en camino
 };

const string ESPECIES[7] =
{
    "P",//perro 0
    "C",//caballo 1
    "G",//gato 2
    "R",//roedor 3
    "O",//conejo 4
    "L",//lagarto 5
    "E"//erizo 6
};






using namespace std;


bool comprobar_repeticion(int n, int num[],int ciclo);

string generar_animales_perdidos();

//PRE: recibe una letra del tablero
//POST: devuelve el emoji correspondiente a esa letra
string letra_a_emoji(string letra);

//PRE: recibe el tablero en formato iniciales
//POST: imprime el tablero como matriz en formato emoji
void imprimir_emojis(string tablero_nuevo);

//PRE: recibe el tablero, cantidad_de_ movimientos, y el vector con los movimientos
//POST:reemplaza en el tablero el camino por '.'
void marcar_camino( string tablero,int cantidad,int vector_camino[]);


//PRE: recibe un string con las inciales de los animales perdidos
//POST: coloca de forma aleatoria en el tablero los animales perdidos y el auto
string generar_tablero_de_animales_perdidos(string animales_perdidos);

//pre: recibe un vector vacio
//post: lee el archivo de movimientos y va llenando el vector con movientos
int obtener_camino(int vector_movimientos[]);

//pre: recibe un string con un tablero
//post: imprime el tablero en forma de matriz
void graficar_tablero(string nuevo_tablero);


//pre: recibe el animal del que se desea saber la ubicacion
//post: devuelve el numero del casillero donde se encuentra ese animal
int obtener_ubicacion(string inicial_animal, string tablero_nuevo);


//pre:recibe el tablero viejo
//post:modifica la posicion del auto
string modificar_tablero_aleatorio(string tablero_rand, int posicion_auto_nueva, int posicion_auto_vieja);

//post: imprime instrucciones para el usuario
void imprimir_referencias();





#endif // FUNCIONES_GRAFICAR_H_INCLUDED
