#ifndef ABB_H
#define ABB_H

#include "ABBNodo.h"


template <typename Dato>
class ABB {
    private:
        ABBNodo<Dato>* raiz;
        ABBNodo<Dato>* cursor;
        
        //PRE:
        //POST:
        ABBNodo<Dato>* _insertar(Dato* dato, string key, ABBNodo<Dato>* nodo);

        //PRE:
        //POST:
        ABBNodo<Dato>* destruir_arbol(ABBNodo<Dato>* nodo);


        //PRE:
        //POST:
        ABBNodo<Dato>* nodo_minimo(ABBNodo<Dato>* nodo);

        //PRE:
        //POST:
        ABBNodo<Dato>* _eliminar(string key, ABBNodo<Dato>* nodo);

        //PRE:
        //POST:
        ABBNodo<Dato>* _buscar(string key, ABBNodo<Dato>* nodo);


    public:

        //PRE:
        //POST:
        ABB();

        //PRE:
        //POST:
        ~ABB();

        //PRE:
        //POST:
        void insertar(Dato* dato, string key);

        //PRE:
        //POST:
        Dato* buscar(string key);

        //PRE:
        //POST:
        void eliminar(string key);

        //PRE:
        //POST:
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
    ABBNodo<Dato>* actual = nodo;
    while(actual && actual -> devolver_nodo_izquierda() != nullptr) {
        actual = actual -> devolver_nodo_izquierda();
    }
    return actual;
}


template <typename Dato>
void ABB<Dato>::eliminar(string key) {
    _eliminar(key, this -> raiz);
}

template <typename Dato>
ABBNodo<Dato>* ABB<Dato>::_eliminar(string key, ABBNodo<Dato>* nodo) {
    if(nodo == nullptr){
        return nodo;
    }

    if(key < nodo -> devolver_key()) {
        nodo -> asignar_nodo_izquierda(_eliminar(key, nodo -> devolver_nodo_izquierda()));
    }

    else if(nodo -> devolver_key() < key) {
        nodo -> asignar_nodo_derecha(_eliminar(key, nodo -> devolver_nodo_derecha()));
    }

    else {
        if(nodo -> devolver_nodo_derecha() == nullptr && nodo-> devolver_nodo_derecha() == nullptr){
            return nullptr;
        }
        else if(nodo -> devolver_nodo_derecha() == nullptr) {
            ABBNodo<Dato>* temp = nodo -> devolver_nodo_izquierda();
            delete nodo;
            return temp;
        }
        else if(nodo -> devolver_nodo_izquierda() == nullptr) {
            ABBNodo<Dato>* temp = nodo -> devolver_nodo_derecha();
            delete nodo;
            return temp;
        }

        ABBNodo<Dato>* temp = nodo_minimo(nodo -> devolver_nodo_derecha());
        nodo -> asignar_dato(temp -> devolver_dato(), temp -> devolver_key());
        nodo -> asignar_nodo_derecha(_eliminar( temp -> devolver_key(), nodo -> devolver_nodo_derecha()));
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