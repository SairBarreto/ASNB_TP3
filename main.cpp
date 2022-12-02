#include <iostream>

#include "animal_handler.h"

using namespace std;



int main() {

    ABB<Animal>* arbol_animales = new ABB<Animal>;

    leer_archivo(arbol_animales);

    imprimir_arbol(arbol_animales);

    delete arbol_animales;

    return 0;
}