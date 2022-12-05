#include "Pequenio.h"

Pequenio::Pequenio():Tamanio(){
    this -> tamanio = "pequenio";
}

bool Pequenio::hay_espacio_suficiente(int metros_cuadrados) {
    if(metros_cuadrados > PEQUENIO_MINIMO)
        return true;
    else   
        return false;
}