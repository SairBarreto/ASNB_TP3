#ifndef ABB_H
#define ABB_H

#include "ABBNodo.h"


template <typename Dato>
class ABB {
    private:
        ABBNodo<Dato>* raiz;
        ABBNodo<Dato>* cursor;
        
        //PRE: --
        //POST: Inserta el ABBNodo en el Arbol
        ABBNodo<Dato>* _insertar(Dato* dato, string key, ABBNodo<Dato>* nodo);

        //PRE: --
        //POST: Recorre el Arbol y destruye cada ABBNodo que no este vacio
        ABBNodo<Dato>* destruir_arbol(ABBNodo<Dato>* nodo);


        //PRE: Por lo menos que haya un ABBNodo en el arbol
        //POST: Busca el ABBNodo minimo
        ABBNodo<Dato>* nodo_minimo(ABBNodo<Dato>* nodo);

        //PRE: Por lo menos que haya un ABBNodo en el arbol
        //POST: Reccorre el Arbol en busca del ABBNodo asociado al key para eliminarlo
        ABBNodo<Dato>* _eliminar(string key, ABBNodo<Dato>* nodo);

        //PRE: Por lo menos que haya un ABBNodo en el arbol
        //POST: Recorre el Arbol y Retorna el ABBNodo asociado al key ingresado
        ABBNodo<Dato>* _buscar(string key, ABBNodo<Dato>* nodo);


    public:

        //CONSTRUCTOR
        ABB();

        //DESTRUCTOR
        ~ABB();

        //PRE: --
        //POST: Agrega un ABBNodo al arbol con su correspondiente key y dato
        void insertar(Dato* dato, string key);

        //PRE: Por lo menos que haya un ABBNodo en el arbol
        //POST: Recorre el Arbol y devuele el Dato si existe el key
        Dato* buscar(string key);

        //PRE: Por lo menos que haya un ABBNodo en el arbol
        //POST: Recorre el Arbol y si existe el key elimina ese ABBNodo donde pertenece
        void eliminar(string key);

        //PRE: Existencia de la raiz
        //POST: Retorna la raiz
        ABBNodo<Dato>* devolver_raiz();

};

template <typename Dato>
ABB<Dato>::ABB() {
    this -> raiz = nullptr;
    this -> cursor = raiz;
}

template <typename Dato>
ABB<Dato>::~ABB() {
    destruir_arbol(this -> raiz);
}

template <typename Dato>
void ABB<Dato>::insertar(Dato* dato, string key) {
    this -> raiz = _insertar(dato, key, this -> raiz);
}

template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::_insertar(Dato* dato, string key, ABBNodo<Dato>* nodo) {
    
    if(nodo == nullptr) {
        nodo = new ABBNodo<Dato>(dato, key);
        return nodo;
    }

    else if(key < nodo -> devolver_key()) {
        if(nodo != nullptr) {
            ABBNodo<Dato>* nuevo_nodo = _insertar(dato, key, nodo -> devolver_nodo_izquierda());
            nodo -> asignar_nodo_izquierda(nuevo_nodo);
        }
    }

    else {
        if(nodo != nullptr) {
            ABBNodo<Dato>* nuevo_nodo = _insertar(dato, key, nodo -> devolver_nodo_derecha());
            nodo -> asignar_nodo_derecha(nuevo_nodo);
        }
    }

    return nodo;

}


template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::destruir_arbol(ABBNodo<Dato>* nodo) {
    
    if(nodo -> devolver_nodo_derecha() != nullptr) {
        ABBNodo<Dato>* nuevo_nodo = destruir_arbol(nodo -> devolver_nodo_derecha());
        nodo -> asignar_nodo_derecha(nuevo_nodo);
    }

    if(nodo -> devolver_nodo_izquierda() != nullptr) {
        ABBNodo<Dato>* nuevo_nodo = destruir_arbol(nodo -> devolver_nodo_izquierda());
        nodo -> asignar_nodo_izquierda(nuevo_nodo);
    }

    if(nodo -> devolver_nodo_derecha() == nullptr && nodo -> devolver_nodo_izquierda() == nullptr) {
        delete nodo;
        nodo = nullptr;
    }

    return nullptr;

}


template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::nodo_minimo(ABBNodo<Dato>* nodo) {
    ABBNodo<Dato>* actual = nodo -> devolver_nodo_izquierda();
    ABBNodo<Dato>* anterior = nodo;
    while(actual && actual -> devolver_nodo_izquierda() != nullptr) {
        anterior = nodo -> devolver_nodo_izquierda();
        actual = actual -> devolver_nodo_izquierda();
    }
    anterior -> asignar_nodo_izquierda(nullptr);
    return actual;  
}


template <typename Dato>
void ABB<Dato>::eliminar(string key) {
    this -> raiz = _eliminar(key, this -> raiz);
}

template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::_eliminar(string key, ABBNodo<Dato>* nodo) {

    if(nodo == nullptr){
        return nodo;
    }

    if(key < nodo -> devolver_key()) {
        nodo -> asignar_nodo_izquierda(_eliminar(key, nodo -> devolver_nodo_izquierda()));
    }

    else if(key > nodo -> devolver_key()) {
        nodo -> asignar_nodo_derecha(_eliminar(key, nodo -> devolver_nodo_derecha()));
    }

    else if(nodo -> devolver_nodo_derecha() && nodo -> devolver_nodo_izquierda()) {
        cout << "entre aca" << endl;
        ABBNodo<Dato>* temp = nodo_minimo(nodo -> devolver_nodo_derecha());
        nodo -> asignar_dato(temp -> devolver_dato(), temp -> devolver_key());
        nodo -> asignar_nodo_derecha(_eliminar(key, nodo -> devolver_nodo_derecha()));
        delete temp;
        temp = nullptr;
    }

    else {
        cout << "por aca funciona" << endl;
        ABBNodo<Dato>* temp = nodo;
        if(nodo -> devolver_nodo_izquierda() == nullptr) {
            nodo = nodo -> devolver_nodo_derecha();
        }
        else if(nodo -> devolver_nodo_derecha() == nullptr) {
            nodo = nodo -> devolver_nodo_izquierda();
        }
        delete temp;
    }
    return nodo;
}


template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::devolver_raiz() {
    return this -> raiz;
}


template <typename Dato>
Dato* ABB<Dato>::buscar(string key) {
    ABBNodo<Dato>* nodo = _buscar(key, this -> raiz);
    if(nodo == nullptr) {
        return nullptr;
    }
    return nodo -> devolver_dato();
}

template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::_buscar(string key, ABBNodo<Dato>* nodo) {
    if(nodo == nullptr || nodo -> devolver_key() == key) {
        return nodo;
    }

    if(nodo -> devolver_key() < key){
        return _buscar(key, nodo -> devolver_nodo_derecha());
    }

    else {
        return _buscar(key, nodo -> devolver_nodo_izquierda());
    }
}


#endif //ABB_H