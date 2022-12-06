#include "Jugeton.h"

Jugeton::Jugeton():Personalidad(){
    this -> personalidad = "jugeton";
}

float Jugeton::obtener_multiplicador_hambre() {
    return JUGETON_MULTIPLICADOR;
}