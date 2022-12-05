#ifndef PEQUENIO_H
#define PEQUENIO_H

#include "Tamanio.h"

const int PEQUENIO_MINIMO = 2;

class Pequenio : public Tamanio {
    public:
        //CONSTRUCTOR
        Pequenio();

        //PRE: --
        //POST: Retorna TRUE o FALSE
        bool hay_espacio_suficiente(int metros_cuadrados);

};


#endif// PEQUENIO_H