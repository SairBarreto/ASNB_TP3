#ifndef DORMILON_H
#define DORMILON_H

#include "Personalidad.h"

const float DORMILON_MULTIPLICADOR = 0.5;

class Dormilon : public Personalidad {
    public:
        //PRE:
        //POST:
        float obtener_multiplicador_hambre();

        //PRE:
        //POST:
        Dormilon();

};


#endif //DORMILON_H