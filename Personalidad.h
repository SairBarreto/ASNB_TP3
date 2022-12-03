#ifndef PERSONALIDAD_H
#define PERSONALIDAD_H

#include <string>

using namespace std;

class Personalidad{
    protected:
        string personalidad;
        float multiplicador;
    public:
        Personalidad(string personalidad);

        ~Personalidad();

        string obtener_personalidad();

        float obtener_multiplicador();
};

#endif