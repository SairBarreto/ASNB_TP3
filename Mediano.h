#ifndef MEDIANO_H
#define MEDIANO_H

#include "Tamanio.h"

const int MEDIANO_MINIMO = 10;

class Mediano : public Tamanio {
    public:
        ////CONSTRUCTOR
        Mediano();

        //PRE: --
        //POST: Retorna TRUE o FALSE
        bool hay_espacio_suficiente(int metros_cuadrados);
};


#endif// MEDIANO_H