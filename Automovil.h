#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include <iostream>

using namespace std;

class Automovil
{
    public:
        Automovil();

        void gastar_combustible(int);

        void cargar_combustible();

        int obtener_nivel_de_combustible();


    private:

        int combustible;
};

#endif // AUTOMOVIL_H
