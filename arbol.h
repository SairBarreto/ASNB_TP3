#ifndef ARBOL_H
#define ARBOL_H

#include "nodoB.h"


template <typename Dato>
class ArbolB {

    private:
        NodoB<Dato>* raiz;

        //PRE: private?
        //POST:
        bool _buscar_dato(NodoB<Dato>* nodo, Dato dato);

        //PRE:
        //POST:
        bool agregar_dato_a_nodo(NodoB<Dato>* nodo, Dato dato);

        //PRE:
        //POST:
        void add(NodoB<Dato> *nodo);
    
    public:
        //POST:
        //PRE:
        ArbolB(bool (*compare)(Dato,Dato), void (*imprimir)(Dato)); //operator overfloading 

        //PRE:
        //POST:
        bool buscar_dato(Dato dato);

        //PRE:
        //POST:
        bool insertar_nodo(Dato* dato);
        
};

template <typename Dato>
ArbolB<Dato>::ArbolB(bool (*compare)(Dato,Dato), void (*imprimir)(Dato)) {
    this -> raiz = nullptr;
}



template <typename Dato>
bool ArbolB<Dato>::buscar_dato(Dato dato) {
    bool el_dato_esta;
    if( this -> raiz == NULL)
        el_dato_esta = false;
    el_dato_esta = _buscar_dato(this -> raiz, dato); //recursive
    return el_dato_esta;
}

template <typename Dato>
bool ArbolB<Dato>::_buscar_dato(NodoB<Dato>* nodo, Dato dato) {
    bool el_dato_esta = false;
    if(nodo != nullptr) {
        if(nodo -> cantidad_vias == 2) { //una sola key
            if(dato == nodo->devolver_dato(KEY_IZQUIERDA)) {
                el_dato_esta = true; 
            }
            else if( dato < nodo->devolver_dato(KEY_IZQUIERDA)) {
                el_dato_esta = _buscar_dato( nodo -> devolver_hijo(NODO_IZQUIERDA), dato);
            }
            else {
                el_dato_esta = _buscar_dato( nodo -> devolver_hijo(NODO_DERECHA), dato);
            }
        }
        else  {             // dos keys
            for(int i = 0; i < KEY_MAX; i++) {
                if( dato == nodo -> devolver_dato(i))
                    el_dato_esta = true;
            }
            if(dato < nodo -> devolver_dato(KEY_IZQUIERDA)) {
                el_dato_esta = _buscar_dato( nodo -> devolver_hijo(NODO_IZQUIERDA), dato);
            }
            else if( dato < nodo -> devolver_dato(KEY_DERECHA)) {
                el_dato_esta = _buscar_dato( nodo -> devolver_hijo(NODO_MEDIO), dato);
            }
            else if( dato > nodo -> devolver_dato(KEY_DERECHA)) {
                el_dato_esta = _buscar_dato( nodo -> devolver_hijo(NODO_MEDIO), dato);
            }
        }
    }
    
    return el_dato_esta;
}

template <typename Dato>
bool ArbolB<Dato>::insertar_nodo(Dato* dato) {

    // Caso 0: El dato ya esta en el arbol
    if(!this -> buscar_dato(dato))
        return false;

    NodoB<Dato>* nodo_nuevo = new NodoB<Dato>(dato);

    // Caso 1: El arbol esta vacio
    if(this -> raiz == NULL) {
        this -> raiz == nodo_nuevo;
    }

    // Caso 2: raiz es una hoja
    if( this -> raiz -> es_hoja()) 
        //return raiz->agregar(dato);
    



    return true;
}






/*
template <typename Dato>
bool ArbolB<Dato>::agregar_dato_a_nodo(Nodo<Dato>* nodo, Dato dato) {

    if(nodo -> devolver_dato(KEY_DERECHA) == nullptr)
        nodo -> agregar_dato(dato, KEY_IZQUIERDA);

    return true;
}
*/


#endif //ARBOL_H