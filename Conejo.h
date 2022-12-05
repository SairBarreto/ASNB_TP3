#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"


class Conejo : public Animal
{

    public:
        Conejo(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);

        void alimentarse();
        
        void baniarse();
};

#endif // CONEJO_H
