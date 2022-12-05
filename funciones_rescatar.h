#ifndef FUNCIONES_RESCATAR_H_INCLUDED
#define FUNCIONES_RESCATAR_H_INCLUDED

#include <iostream>

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

#endif // FUNCIONES_RESCATAR_H_INCLUDED
