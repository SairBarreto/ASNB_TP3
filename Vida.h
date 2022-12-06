#ifndef VIDA_H
#define VIDA_H

using namespace std;


class Vida{
private:
    int vida;

public:  

    Vida();

    int obtener_vida();

    void restar_vida();

    bool esta_vivo();

    void mostrar_vida();
};


#endif // VIDA_H