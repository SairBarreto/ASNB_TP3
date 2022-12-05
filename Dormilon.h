#ifndef DORMILON_H
#define DORMILON_H

#include "Personalidad.h"

const float DORMILON_MULTIPLICADOR = 0.5;

class Dormilon : public Personalidad {
    public:
        //PRE: Existencia de la personalidad
        //POST: Retorna su MULTIPLICADOR
        float obtener_multiplicador_hambre();

        ////CONSTRUCTOR
        Dormilon();

};


#endif //DORMILON_H