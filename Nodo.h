#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
//#include "Animal.h"
#include <string>

using namespace std;

struct animal 
{
    string nombre;
    int edad;
    string tamanio;
    string personalidad;
    string especie;
};

struct Clave 
{
    string nombre;
    animal animal;
    long registro; // número índice correspondiente a la clave "nombre"
};

class Nodo 
{
    private:
        int clavesUsadas;   // Claves usadas en el nodo
        Clave *clave;     // Array de claves del nodo
        Nodo **puntero;    // Array de punteros a Nodo
        Nodo *padre;       // Puntero a nodo padre
        
        friend class Arbol;

    public:
        Nodo(int nClaves); // Constructor
        ~Nodo();           // Destructor
};

typedef Nodo* pNodo;

Nodo::Nodo(int nClaves)
{
   clavesUsadas = 0;
   clave = new Clave[nClaves];
   puntero = new pNodo[nClaves+1];
   padre = NULL;
}

Nodo::~Nodo()
{
   delete[] clave;
   delete[] puntero;
}

#endif