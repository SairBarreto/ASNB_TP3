#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include <string>

using namespace std;

class Personalidad{
    protected:
        string personalidad;
    public:
        Personalidad(string personalidad);

        ~Personalidad();

        string obtener_personalidad();
};

#endif