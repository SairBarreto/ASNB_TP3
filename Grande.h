#ifndef GRANDE_H
#define GRANDE_H

#include "Tamanio.h"

const int GRANDE_MINIMO = 20;

class Grande : public Tamanio {
    public:
        //PRE:
        //POST:
        Grande();

        //PRE:
        //POST:
        bool hay_espacio_suficiente(int metros_cuadrados);
};


#endif// GRANDE_H