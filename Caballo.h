#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"


class Caballo : public Animal
{

    public:
        //PRE: -    
        //POS: Carga y crea objeto
        Caballo(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad*_personalidad);

        //PRE: -    
        //POS: Hambre al 0
        void alimentarse();

        //PRE: -    
        //POS: Higiene al 100 si lo necesita
        void baniarse();
};

#endif // CABALLO_H
