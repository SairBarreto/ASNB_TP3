#ifndef TAMANIO_H
#define TAMANIO_H

#include <iostream>

using namespace std;


class Tamanio {
    protected:
        string tamanio;
    
    public:

        //CONSTRUCTOR
        Tamanio();

        //PRE: Existencia del tamanio
        //POST: Retorna el Tamanio
        string obtener_tamanio();

        //PRE: --
        //POST: Retorna TRUE o FALSE
        virtual bool hay_espacio_suficiente(int metros_cuadrados);

        //DESTRUCTOR
        virtual ~Tamanio() {};
};



#endif // TAMANIO_H