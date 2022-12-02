#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"


class Lagartija : public Animal
{

    public:
        Lagartija(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad);
        
        //PRE: -    
        //POS: Aumenta hambre dependiendo de su personalidad
        void gastar_energia();

        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        void alimentarse();

        void baniarse();
};

#endif // LAGARTIJA_H
