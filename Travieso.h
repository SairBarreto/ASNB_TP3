#ifndef TRAVIESO_H
#define TRAVIESO_H

#include "Personalidad.h"

const float TRAVIESO_MULTIPLICADOR = 2.0;

class Travieso : public Personalidad {
    public:
        //PRE: Existencia de la personalidad
        //POST: Retorna su MULTIPLICADOR
        float obtener_multiplicador_higiene();

        //CONSTRUCTOR
        Travieso();

};


#endif //TRAVIESO_H