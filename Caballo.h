#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"


class Caballo : public Animal
{

    public:
        Caballo(string _nombre, int _edad, string _tamanio, string _especie, Personalidad*_personalidad);

};

#endif // CABALLO_H
