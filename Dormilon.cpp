#include "Dormilon.h"

Dormilon::Dormilon():Personalidad(){
    this -> personalidad = "Dormilon";
}

float Dormilon::obtener_multiplicador_hambre() {
    return DORMILON_MULTIPLICADOR;
}