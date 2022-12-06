#include "Travieso.h"

Travieso::Travieso():Personalidad(){
    this -> personalidad = "travieso";
}

float Travieso::obtener_multiplicador_higiene() {
    return TRAVIESO_MULTIPLICADOR;
}