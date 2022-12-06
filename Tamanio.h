#ifndef TAMANIO_H
#define TAMANIO_H

#include <iostream>

using namespace std;


class Tamanio {
    protected:
        string tamanio;
    
    public:

        //PRE:
        //POST:
        Tamanio();

        //PRE:
        //POST:
        string obtener_tamanio();

        //PRE:
        //POST:
        virtual bool hay_espacio_suficiente(int metros_cuadrados);

        //PRE:
        //POST:
        virtual ~Tamanio() {};
};



#endif // TAMANIO_H