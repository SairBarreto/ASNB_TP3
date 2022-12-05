#ifndef JUGETON_H
#define JUGETON_H

#include "Personalidad.h"

const float JUGETON_MULTIPLICADOR = 2;

class Jugeton : public Personalidad {
    public:
        //PRE: Existencia de la personalidad
        //POST: Retorna su MULTIPLICADOR
        float obtener_multiplicador_hambre();

        //CONSTRUCTOR
        Jugeton();

};


#endif //JUGETON_H