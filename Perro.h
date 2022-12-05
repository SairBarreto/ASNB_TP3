#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Perro : public Animal
{

    public:
        //PRE: -    
        //POS: Carga y crea objeto
        Perro(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);

        //PRE: -    
        //POS: Hambre al 0
        void alimentarse();

        //PRE: -    
        //POS: Higiene al 100 si lo necesita
        void baniarse();
};

#endif // PERRO_H
