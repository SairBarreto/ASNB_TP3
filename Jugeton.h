#ifndef JUGETON_H
#define JUGETON_H

#include "Personalidad.h"

const float JUGETON_MULTIPLICADOR = 2;

class Jugeton : public Personalidad {
    public:
        //PRE:
        //POST:
        float obtener_multiplicador_hambre();

        //PRE:
        //POST:
        Jugeton();

};


#endif //JUGETON_H