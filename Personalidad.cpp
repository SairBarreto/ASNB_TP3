#include "Personalidad.h"

Personalidad::Personalidad(string personalidad)
{
    this->personalidad = personalidad;
}

Personalidad::~Personalidad(){}

string Personalidad::obtener_personalidad()
{
    return personalidad;
}

float Personalidad::obtener_multiplicador()
{
    if(personalidad == "sociable" || personalidad == "dormilon"){
        return multiplicador = 0.5;
    }
    else if(personalidad == "travieso" || personalidad == "jugueton"){
        return multiplicador = 2;
    }
    else{
        return multiplicador = 1;
    }
}