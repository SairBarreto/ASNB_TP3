#ifndef ABBNODO_H
#define ABBNODO_H

#include <iostream>

using namespace std;

template <typename Dato>
class ABBNodo {
    private:
        ABBNodo<Dato>* nodo_izquierda;
        ABBNodo<Dato>* nodo_derecha;
        Dato* dato;
        string key;

    public:
        //PRE:
        //POST:
        ABBNodo(Dato* dato, string key);


        //PRE:
        //POST:
        ~ABBNodo();

        //PRE:
        //POST:
        Dato* devolver_dato();

        //PRE:
        //POST:
        ABBNodo<Dato>* devolver_nodo_izquierda();

        //PRE:
        //POST:
        ABBNodo<Dato>* devolver_nodo_derecha();

        //PRE:
        //POST:
        void asignar_nodo_derecha(ABBNodo<Dato>* nodo);

        //PRE:
        //POST:
        void asignar_nodo_izquierda(ABBNodo<Dato>* nodo);

        //PRE:
        //POST:
        void asignar_dato(Dato* dato, string key);

        //PRE:
        //POST:
        string devolver_key();
};


template <typename Dato>
ABBNodo<Dato>::ABBNodo(Dato* dato, string key) {
    this -> dato = dato;
    this -> key = key;
    this -> nodo_derecha = nullptr;
    this -> nodo_izquierda = nullptr;
}

template <typename Dato>
ABBNodo<Dato>::~ABBNodo() {
    delete this -> dato;
}

template <typename Dato>
Dato* ABBNodo<Dato>::devolver_dato() {
    return this -> dato;
}

template <typename Dato>
ABBNodo<Dato>* ABBNodo<Dato>::devolver_nodo_derecha() {
    return this -> nodo_derecha;
}

template <typename Dato>
ABBNodo<Dato>* ABBNodo<Dato>::devolver_nodo_izquierda() {
    return this -> nodo_izquierda;
}

template <typename Dato>
void ABBNodo<Dato>::asignar_nodo_derecha(ABBNodo<Dato>* nodo) {
    this -> nodo_derecha = nodo;
    this -> nodo_derecha -> key = nodo -> key;
}


template <typename Dato>
void ABBNodo<Dato>::asignar_nodo_izquierda(ABBNodo<Dato>* nodo) {
    this -> nodo_izquierda = nodo;
    this -> nodo_izquierda -> key = nodo -> key;
}

template <typename Dato>
void ABBNodo<Dato>::asignar_dato(Dato* dato, string key) {
    this -> dato = dato;
    this -> key = key;
}

template <typename Dato>
string ABBNodo<Dato>::devolver_key() {
    return this -> key;
}

#endif //ABBNODO_H