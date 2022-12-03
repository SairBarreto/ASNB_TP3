#ifndef ROEDOR_H
#define ROEDOR_H

#include "Animal.h"


class Roedor : public Animal
{

    public:
        Roedor(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad);

        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad 
        void ensuciar();


};

#endif // ROEDOR_H
