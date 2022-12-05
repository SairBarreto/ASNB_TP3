#ifndef SOCIABLE_H
#define SOCIABLE_H

#include "Personalidad.h"

const float SOCIABLE_MULTIPLICADOR = 0.5;

class Sociable : public Personalidad {
    public:
        //PRE:
        //POST:
        float obtener_multiplicador_higiene();

        //PRE:
        //POST:
        Sociable();

};


#endif //SOCIABLE_H