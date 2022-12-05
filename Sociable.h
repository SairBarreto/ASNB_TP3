#ifndef SOCIABLE_H
#define SOCIABLE_H

#include "Personalidad.h"

const float SOCIABLE_MULTIPLICADOR = 0.5;

class Sociable : public Personalidad {
    public:
        //PRE: Existencia de la personalidad
        //POST: Retorna su MULTIPLICADOR
        float obtener_multiplicador_higiene();

        //CONSTRUCTOR
        Sociable();

};


#endif //SOCIABLE_H