#ifndef ERIZO_H
#define ERIZO_H

#include "Animal.h"


class Erizo : public Animal
{

    public:
        Erizo(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad);
        
        void alimentarse();
        
        void baniarse();
};

#endif // ERIZO_H
