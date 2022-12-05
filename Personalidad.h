#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include <iostream>

using namespace std;

const float BASIC_MULTIPLICADOR = 1;

class Personalidad {
    protected:
        string personalidad;  

    public:
        
        //CONSTRUCTOR
        Personalidad();


        //PRE: Existencia de personalidad
        //POST: Retorna un Float segun la personalidad
        virtual float obtener_multiplicador_hambre();

        //PRE: Existencia de personalidad
        //POST: Retorna un Float segun la personalidad
        virtual float obtener_multiplicador_higiene();

        //PRE: Existencia de personalidad
        //POST: Retorna la personalidad
        string obtener_personalidad();

        //DESTRUCTOR
        virtual ~Personalidad() {};
};




#endif //PERSONALIDAD_H