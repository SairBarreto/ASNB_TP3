#include "Travieso.h"

Travieso::Travieso():Personalidad(){
    this -> personalidad = "Travieso";
}

float Travieso::obtener_multiplicador_higiene() {
    return TRAVIESO_MULTIPLICADOR;
}