#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"


class Lagartija : public Animal
{

    public:
        Lagartija(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad);

        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();
};

#endif // LAGARTIJA_H
