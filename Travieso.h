#ifndef TRAVIESO_H
#define TRAVIESO_H

#include "Personalidad.h"

const float TRAVIESO_MULTIPLICADOR = 2.0;

class Travieso : public Personalidad {
    public:
        //PRE:
        //POST:
        float obtener_multiplicador_higiene();

        //PRE:
        //POST:
        Travieso();

};


#endif //TRAVIESO_H