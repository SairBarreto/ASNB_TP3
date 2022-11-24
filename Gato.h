#ifndef GATO_H
#define GATO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Gato : public Animal
{

    public:
        Gato(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad);
        
        //PRE: -    
        //POS: Aumenta hambre dependiendo de su personalidad
        void gastar_energia();
        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();
};

#endif // GATO_H
