#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>

using namespace std;

template <typename Dato>
class Nodo {

//Atributos
private:
    
    Dato* dato;
    Nodo* siguiente;

//Metodos
public:

    //PRE: -
    //POS: Crea un nodo con dato = d y siguiente = 0; 
    Nodo(Dato* dato);

    //PRE: Nodo existente con Dato 
    //POS: Nodo siguiente cambia de puntero
    void cambiar_siguiente_nodo(Nodo<Dato>* ptr);

    //PRE: -
    //POS: Retorna Dato contenido en el Nodo
    Dato* obtener_dato();

    //PRE: -
    //POS: Retorna el siguiente Nodo al actual
    Nodo* obtener_siguiente_nodo();

    //PRE: nuevo_dato debe ser valido
    //POS: Remplaza Dato con un nuevo_dato
    void cambiar_nuevo_dato(Dato nuevo_dato);

    //PRE: -
    //POS: Devuelve si es o no es nulo el proximo nodo al actual
    bool es_no_nulo_proximo_nulo();

    //PRE: -
    //POS: Destructor
    ~Nodo();

};


//Destructor
template <typename Dato>
Nodo<Dato>::~Nodo() {
    delete dato;
}

//Constructor
template <typename Dato>    
Nodo<Dato>::Nodo(Dato* dato) {
    this->dato = dato;
    this->siguiente = 0;
}

//Cambiar siguiente
template <typename Dato>
void Nodo<Dato>::cambiar_siguiente_nodo(Nodo<Dato>* ptr) {
    this->siguiente = ptr;
}

//Obtener siguiente
template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente_nodo() {
    return siguiente;
}

//Obtener dato
template <typename Dato>
Dato* Nodo<Dato>::obtener_dato() {
    return dato;
}

//Cambia el valor del dato
template <typename Dato>
void Nodo<Dato>::cambiar_nuevo_dato(Dato nuevo_dato) {
    this->dato = nuevo_dato;
}

//Proximo nodo no nulo
template <typename Dato>
bool Nodo<Dato>::es_no_nulo_proximo_nulo() {
    return (siguiente != 0);
}

#endif // NODO_H_INCLUDED