#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include <iostream>

using namespace std;

const float BASIC_MULTIPLICADOR = 1;

class Personalidad {
    protected:
        string personalidad;  

    public:
        
        //PRE:
        //POST:
        Personalidad();


        //PRE:
        //POST:
        virtual float obtener_multiplicador_hambre();

        //PRE:
        //POST:
        virtual float obtener_multiplicador_higiene();

        //PRE:
        //POST:
        string obtener_personalidad();
};




#endif //PERSONALIDAD_H