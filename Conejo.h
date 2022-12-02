#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"


class Conejo : public Animal
{

    public:
    Conejo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad);
        
    //PRE: -    
    //POS: Disminuye higiene dependiendo de su personalidad
    void ensuciar();

    //PRE: -    
    //POS: Aumenta hambre dependiendo de su personalidad
    void gastar_energia();

    void alimentarse();

    void baniarse();
};

#endif // CONEJO_H
