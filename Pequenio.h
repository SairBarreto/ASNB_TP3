#ifndef PEQUENIO_H
#define PEQUENIO_H

#include "Tamanio.h"

const int PEQUENIO_MINIMO = 2;

class Pequenio : public Tamanio {
    public:
        //PRE:
        //POST:
        Pequenio();

        //PRE:
        //POST:
        bool hay_espacio_suficiente(int metros_cuadrados);

};


#endif// PEQUENIO_H