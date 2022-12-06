#include "Sociable.h"

Sociable::Sociable():Personalidad(){
    this -> personalidad = "sociable";
}

float Sociable::obtener_multiplicador_higiene() {
    return SOCIABLE_MULTIPLICADOR;
}