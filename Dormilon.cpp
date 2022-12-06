#include "Dormilon.h"

Dormilon::Dormilon():Personalidad(){
    this -> personalidad = "dormilon";
}

float Dormilon::obtener_multiplicador_hambre() {
    return DORMILON_MULTIPLICADOR;
}