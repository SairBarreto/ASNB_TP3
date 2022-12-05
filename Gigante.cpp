#include "Gigante.h"

Gigante::Gigante():Tamanio(){
    this -> tamanio = "gigante";
}

bool Gigante::hay_espacio_suficiente(int metros_cuadrados) {
    if(metros_cuadrados > GIGANTE_MINIMO)
        return true;
    else   
        return false;
}