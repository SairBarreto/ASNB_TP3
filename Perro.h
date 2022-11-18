#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Perro : public Animal
{

    public:
        Perro(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad);
        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        //PRE: -    
        //POS: Aumenta hambre dependiendo de su personalidad
        void gastar_energia();

};

#endif // PERRO_H
