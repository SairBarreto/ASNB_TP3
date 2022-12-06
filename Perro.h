#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Perro : public Animal
{

    public:
        Perro(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);
        
        void alimentarse();
        
        void baniarse();
};

#endif // PERRO_H
