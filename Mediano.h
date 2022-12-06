#ifndef MEDIANO_H
#define MEDIANO_H

#include "Tamanio.h"

const int MEDIANO_MINIMO = 10;

class Mediano : public Tamanio {
    public:
        //PRE:
        //POST:
        Mediano();

        //PRE:
        //POST:
        bool hay_espacio_suficiente(int metros_cuadrados);
};


#endif// MEDIANO_H