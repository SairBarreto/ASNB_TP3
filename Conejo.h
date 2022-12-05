#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"


class Conejo : public Animal
{

    public:
        //PRE: -    
        //POS: Carga y crea objeto
        Conejo(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);

        //PRE: -    
        //POS: Hambre al 0
        void alimentarse();
        
        //PRE: -    
        //POS: Higiene al 100 si lo necesita
        void baniarse();
};

#endif // CONEJO_H
