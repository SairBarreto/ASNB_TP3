#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include "Animal.h"
#include <string>

using namespace std;
/*
struct animal 
{
    string nombre;
    int edad;
    string tamanio;
    string personalidad;
    string especie;
};
*/
struct Clave 
{
    string nombre;
    Animal* animal;
    long registro; // número índice correspondiente a la clave "nombre"
};


template <typename Dato>
class Nodo 
{
    public:
        int clavesUsadas;   // Claves usadas en el nodo
        Clave* clave;     // Array de claves del nodo
        Nodo<Dato>** puntero;    // Array de punteros a Nodo
        Nodo<Dato>* padre;       // Puntero a nodo padre
        
        //friend class Arbol;

    
        Nodo(int nClaves); // Constructor
        ~Nodo();           // Destructor
};
/* template con typedef no van
template <typename Dato>
typedef Nodo<Dato>* pNodo;
*/
template <typename Dato>
Nodo<Dato>::Nodo(int nClaves)
{
   clavesUsadas = 0;
   clave = new Clave[nClaves];
   puntero = new Nodo<Dato>*[nClaves+1];
   padre = NULL;
}

template <typename Dato>
Nodo<Dato>::~Nodo()
{
   delete[] clave;
   delete[] puntero;
}

#endif