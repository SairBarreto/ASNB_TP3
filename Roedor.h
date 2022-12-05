#ifndef ROEDOR_H
#define ROEDOR_H

#include "Animal.h"


class Roedor : public Animal
{

    public:
        //PRE: -    
        //POS: Carga y crea objeto
        Roedor(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad);

        
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

#endif // ROEDOR_H
