#ifndef GATO_H
#define GATO_H

#include "Animal.h"

#include <iostream>

using namespace std;

class Gato : public Animal
{

    public:
        //PRE: -    
        //POS: Carga y crea objeto
        Gato(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);
        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        //PRE: -    
        //POS: Hambre al 0
        void alimentarse();

        //PRE: -    
        //POS: Higiene al 100 si lo necesita
        void baniarse();
};

#endif // GATO_H
