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