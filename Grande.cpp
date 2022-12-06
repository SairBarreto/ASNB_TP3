#include "Grande.h"

Grande::Grande():Tamanio(){
    this -> tamanio = "grande";
}

bool Grande::hay_espacio_suficiente(int metros_cuadrados) {
    if(metros_cuadrados > GRANDE_MINIMO)
        return true;
    else   
        return false;
}