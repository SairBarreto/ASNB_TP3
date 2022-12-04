#ifndef NODO_H
#define NODO_H

using namespace std;

const int MAX_VIAS = 3;

enum {
    KEY_IZQUIERDA = 0, // las keys se van "llenando" de izquierda a derecha
    KEY_DERECHA,
    KEY_MAX
};


enum {
    NODO_IZQUIERDA = 0, // los nodos se van "llenando" de izquierda a derecha
    NODO_MEDIO,
    NODO_DERECHA
};


template <typename Dato>
class Nodo {
    private:
        Dato* datos[MAX_VIAS-1]; // datos[0] -> izquierda, datos[1] -> derecha
        Nodo<Dato>* hijos[MAX_VIAS]; // hijos[0] -> izquierda, hijos[1] -> medio, hijos[2] -> derecha
        Nodo<Dato>* padre;
        bool hoja;
        int cantidad_vias;

    public:
        //PRE:
        //POST:
        Nodo(Dato* primer_key);

        //PRE:
        //POST:
        ~Nodo();

        //PRE:
        //POST:
        bool es_hoja();

        //PRE:
        //POST:
        Dato* devolver_dato(int i);

        //PRE:
        //POST:
        Nodo<Dato>* devolver_hijo(int i);

        //PRE:
        //POST:
        int devolver_cantidad_vias();

};

//Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato* primer_key){
    this -> es_hoja = true;
    this -> cantidad_vias = 0;

    Dato** aux_dato = new Dato*[MAX_VIAS-1];
    for(int i = 0; i < MAX_VIAS - 1; i++){
        aux_dato[i] = nullptr;
    }
    this -> datos = aux_dato;
    this -> datos[KEY_IZQUIERDA] = primer_key;

    Nodo<Dato>** aux_hijos = new Nodo<Dato>*[MAX_VIAS];
    for(int i = 0; i < MAX_VIAS; i++) {
        aux_hijos[i] = nullptr;
    }
    this -> hijos = aux_hijos;

    this -> padre = nullptr;
}

//Destructor
template <typename Dato>
Nodo<Dato>::~Nodo() {
    delete[] this -> datos;
    delete[] this -> hijos; 
}


template <typename Dato>
bool Nodo<Dato>::es_hoja() {
    return this -> hoja;
}


template <typename Dato>
Dato* Nodo<Dato>::devolver_dato(int i) {
    return this -> dato[i];
}

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::devolver_hijo(int i) {
    return this -> hijos[i];
}

template <typename Dato>
int Nodo<Dato>::devolver_cantidad_vias() {
    return this -> cantidad_vias;
}



#endif //NODO_H