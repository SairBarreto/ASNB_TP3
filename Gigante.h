#ifndef GIGANTE_H
#define GIGANTE_H

#include "Tamanio.h"

const int GIGANTE_MINIMO = 50;

class Gigante : public Tamanio {
    public:
        //PRE:
        //POST:
        Gigante();

        //PRE:
        //POST:
        bool hay_espacio_suficiente(int metros_cuadrados);
};


#endif// GIGANTE_H