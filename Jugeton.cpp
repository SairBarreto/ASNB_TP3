#include "Jugeton.h"

Jugeton::Jugeton():Personalidad(){
    this -> personalidad = "Jugeton";
}

float Jugeton::obtener_multiplicador_hambre() {
    return JUGETON_MULTIPLICADOR;
}