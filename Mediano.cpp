#include "Mediano.h"

Mediano::Mediano():Tamanio(){
    this -> tamanio = "mediano";
}

bool Mediano::hay_espacio_suficiente(int metros_cuadrados) {
    if(metros_cuadrados > MEDIANO_MINIMO)
        return true;
    else   
        return false;
}