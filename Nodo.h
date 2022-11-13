#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include "Animal.h"
#include <string>

using namespace std;

struct Clave{
    string nombre;
    long Animal;
};

template <typename Dato>
class Nodo 
{
    //Atributos
    private:
        Dato claves_usadas;   // Claves usadas en el nodo
        Clave* clave;           // Array de claves del nodo
        Nodo<Dato>** puntero;    // Array de punteros a bnodo
        Nodo<Dato>* padre;       // Puntero a nodo padre

        //friend class btree;

    //Metodos
    public:
        Nodo(Dato n_claves); // Constructor
        ~Nodo();           // Destructor
};


//Contructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato n_claves)
{
   clavesUsadas = 0;
   clave = new Clave[n_claves];
   puntero = new Nodo<Dato>[n_claves + 1];
   padre = NULL;
}

//Destructor
template <typename Dato>    
Nodo<Dato>::~Nodo()
{
   delete[] clave;
   delete[] puntero;
}

#endif // NODO_H_INCLUDED