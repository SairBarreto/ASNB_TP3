#ifndef FUNCIONES_RESCATAR_H_INCLUDED
#define FUNCIONES_RESCATAR_H_INCLUDED

#include <iostream>

using namespace std;


/*
PRE: Recibe un string con las inciales de los animales en un string;
POST:Imprime tablero y camino minimo realizado
*/
void empezar_a_rescatar(string animales_perdidos);

/*
PRE: -
POST: Pregunta al usuario que animal desea rescatar;
*/
string elegir_animal_a_rescatar(string animales_perdidos);



#endif // FUNCIONES_RESCATAR_H_INCLUDED
