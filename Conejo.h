#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"


class Conejo : public Animal
{

    public:
    Conejo(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad);

};

#endif // CONEJO_H
