#include "include\crear_animales_aleatorios.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


string generar_tamanio_rand()
{
    string tamanio_nuevo;

    srand((unsigned) time(NULL));

    int random =  (rand() % 5);

    tamanio_nuevo = TAMANIOS_STR[random];

    return tamanio_nuevo;
}

string generar_personalidades_rand()
{
    string personalidad_nuevo;

    srand((unsigned) time(NULL));

    int random =  (rand() % 4);

    personalidad_nuevo = PERSONALIDADES[random];

    return personalidad_nuevo;


}

string generar_especie_rand()
{
    string especie_nuevo;

    srand((unsigned) time(NULL));

    int random =  (rand() % 7);

    especie_nuevo = INICIALES_ESPECIES_STR[random];

    return especie_nuevo;
}

int generar_edad_rand()
{
    srand((unsigned) time(NULL));

    int edad = 1 + (rand() % 100);

    return edad;

}
