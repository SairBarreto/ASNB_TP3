#ifndef ERIZO_H
#define ERIZO_H

#include "Animal.h"


class Erizo : public Animal
{

    public:
        Erizo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad);
        
        //PRE: -    
        //POS: Disminuye higiene dependiendo de su personalidad
        void ensuciar();

        //PRE: -    
        //POS: Aumenta su hambre dependiendo de su personalidad
        void gastar_energia();
        
};

#endif // ERIZO_H
