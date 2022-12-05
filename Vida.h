#include <iostream>

using namespace std;


class Vida{
public:
    int vida;

private:  
    int obtener_vida();

    void restar_vida();

    bool esta_vivo();

    void mostrar_vida();
};