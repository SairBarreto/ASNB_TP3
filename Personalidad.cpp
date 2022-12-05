#include "Personalidad.h"


Personalidad::Personalidad() {
    this -> personalidad = "basico";
}

float Personalidad::obtener_multiplicador_hambre() {
    return BASIC_MULTIPLICADOR;
}

float Personalidad::obtener_multiplicador_higiene() {
    return BASIC_MULTIPLICADOR;
}

string Personalidad::obtener_personalidad() {
    return this -> personalidad;
}