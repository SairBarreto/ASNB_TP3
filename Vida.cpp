#include "Vida.h"

#include <iostream>

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
    if(vida > 0)
        return true;
    else 
        return false;
}

void Vida::mostrar_vida(){
    cout << "VIDAS: ";
    for(int i = 0; i < vida; i++) {
        cout << "❤️ ";
    }
    cout << endl;
}