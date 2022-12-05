#ifndef GATO_H
#define GATO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Gato : public Animal
{

    public:
        Gato(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);
        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        void alimentarse();
        
        void baniarse();
};

#endif // GATO_H
