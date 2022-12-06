#ifndef FUNCIONES_RESCATAR_H_INCLUDED
#define FUNCIONES_RESCATAR_H_INCLUDED

#include <iostream>
#include <iostream>
#include <string.h>
#include <cstdlib>


using namespace std;


/*
PRE: Recibe un string con las inciales de los animales en un string;
POST:Imprime tablero y camino minimo realizado
*/
string empezar_a_rescatar(string animales_perdidos);



/*
PRE: -
POST: Pregunta al usuario que animal desea rescatar;
*/
string elegir_animal_a_rescatar(string animales_perdidos,string animales_rescatados);

int calcular_largo(string palabra);
/*
PRE:
*/
bool estado_animal(string animales_perdido, string animales_rescatados);//despues hay que meterla  dentro de la clase animal

void rescatar_animal();


//PARTE NICO
/*



const int EDAD_MIN = 0;

const int EDAD_MAX = 100;

const string ESPECIES_COMPLETAS[7] = {
    "Caballo",
    "Conejo",
    "Erizo",
    "Gato",
    "Lagartija",
    "Perro",
    "Roedor"
};

const string INICIALES_ESPECIES_STR[7] = {
    "C",
    "O",
    "E",
    "G",
    "L",
    "P",
    "R"
};

const string PERSONALIDADES[4] = {
    "dormilon",
    "jugueton",
    "sociable",
    "travieso"

};

const string TAMANIOS_STR[5] = {
    "diminuto",
    "pequenio",
    "mediano",
    "grande",
    "gigante"
};

string generar_tamanio_rand();

string generar_personalidades_rand();

string generar_especie_rand();

int generar_edad_rand();

void crear_animales_aleatorios();

void rescatar(ABB<Animal>* arbol_animales, string animales_perdidos)//FUNCION NUEVA SI FUNCIONA LO NICO

*/








#endif // FUNCIONES_RESCATAR_H_INCLUDED
