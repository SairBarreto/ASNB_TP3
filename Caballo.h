#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"


class Caballo : public Animal
{

    public:
        Caballo(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad*_personalidad);

        void alimentarse();
        
        void baniarse();
};

#endif // CABALLO_H
