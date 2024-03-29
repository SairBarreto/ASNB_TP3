#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"


class Lagartija : public Animal
{

    public:
        Lagartija(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);

        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        void alimentarse();
        
        void baniarse();
};

#endif // LAGARTIJA_H
