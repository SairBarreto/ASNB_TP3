#include "include/Vida.h"
#include <iostream>

using namespace std;

Vida::Vida(){
    vida = 3;
}

int Vida::obtener_vida(){
    return vida;
}

void Vida::restar_vida(){
    if(vida > 0)
        vida = vida - 1;
}

bool Vida::esta_vivo(){
    if(vida != 0)
        return true;
}

void Vida::mostrar_vida(){
    cout << "Te quedan " << obtener_vida() << "vidas" << endl;
}
