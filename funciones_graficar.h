#ifndef FUNCIONES_GRAFICAR_H_INCLUDED
#define FUNCIONES_GRAFICAR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

const string tablero_original = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

const string EMOJIS[12] = {
        "\U0001F436",//PERRO
        "\U0001F434",//caballo
        "\U0001F431",//gato
        "\U0001F400",//rata
        "\U0001F407",//conejo
        "\U0001F98E",//lagarto
        "\U0001F994",//erizo
        "\U0001F697",//auto
        "\U0001F9E1",//montaña
        "\U0001F49B",//precipicio
        "\U0001F49A",//camino
        "\U0001F499"//tierra

 };

 const string TIPO_CASILLERO[12] =
 {
   "P",//perro
   "C",//caballo
   "G",//gato
   "R",//roedor
   "O",//conejo
   "L",//lagarto
   "E",//erizo
   "A",//auto
   "m",//montaña
   "p",//precipicio
   "c",//camino
   "t"
 };



using namespace std;


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
