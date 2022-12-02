/*
#ifndef ARBOL_B_H_INCLUDED
#define ARBOL_B_H_INCLUDED
#include "Nodo.h"
//#include "Funciones.h" esto me lo rompe
#include <iostream>

using namespace std;

template <typename Dato>
class Arbol 
{
    private:
        Clave* lista;               // Auxiliar para insertar claves
        Nodo<Dato>** listapunt;            // Auxiliar para insertar claves

        // Funciones auxiliares internas de la clase:
        void inserta(Clave clave, Nodo<Dato>* nodo, Nodo<Dato>* hijo1, Nodo<Dato>* hijo2);

        void borrar_clave(Nodo<Dato>* nodo, string clave);

        void borrar_nodo(Nodo<Dato>* nodo);

        void pasar_clave_derecha(Nodo<Dato>* derecha, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre);

        void pasar_clave_izquierda(Nodo<Dato>* izquierda, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre);

        void fundir_nodo(Nodo<Dato>* izquierda, Nodo<Dato>* &padre, Nodo<Dato>* derecha, int posicion_clave_padre);

        void ver(Nodo<Dato>* nodo);
        
        int nClaves;                  // Número de claves por nodo
        int nodosMinimos;             // Número de punteros mínimos para cada nodo que no sea hoja
        Nodo<Dato>* Entrada;               // Puntero a nodo de entrada en el árbol

    public:
        // Constructor
        Arbol(); 

        // Destructor        
        ~Arbol();                    

        // buscar un valor de clave, devuelve la posición en el array
        long buscar(string clave);  

        // insertar una clave
        bool insertar(Clave clave); 

        // borrar la clave correspondiente a un valor
        void borrar(string clave);    

        // (Depuración) mostrar el árbol por pantalla   
        void mostrar();               
};

template <typename Dato>
Arbol<Dato>::Arbol()
{
    nClaves = 3; //Crea un arbol de 3 vias
    lista = new Clave[nClaves+1];
    listapunt = new Nodo<Dato>*[nClaves+2];
    nodosMinimos = nClaves/2; // ((nClaves+1)/2)-1;
    Entrada = NULL;
}

template <typename Dato>
Arbol<Dato>::~Arbol()
{
    delete[] lista;
    delete[] listapunt;
    // Destruir arbol, algoritmo recursivo:
    borrar_nodo(Entrada);
}

template <typename Dato>
void Arbol<Dato>::borrar_nodo(Nodo<Dato>* nodo)
{
    int i;

    if(!nodo) 
        return;

    for(i = 0; i <= nodo->clavesUsadas; i++) 
        borrar_nodo(nodo->puntero[i]);
        
    delete nodo;
}

template <typename Dato>
void Arbol<Dato>::mostrar()
{
    cout << "-------------------------------------------" << endl;
    cout << "Los animales en la Reserva son: " << endl << endl;
    ver(Entrada);
    cout << "-------------------------------------------" << endl;
    system("pause");
}

template <typename Dato>
void Arbol<Dato>::ver(Nodo<Dato>* nodo)
{
    int i;
    string inicial_especie;
    if(!nodo) 
        return;

    for(i = 0; i < nodo->clavesUsadas; i++){ 

        if(nodo->clave[i].nombre[0] != '\0'){
            cout << "\t" << nodo->clave[i].nombre << "," << nodo->clave[i].animal->obtener_edad() << "," << nodo->clave[i].animal->obtener_tamanio() << "," << nodo->clave[i].animal->obtener_especie() << "," << nodo->clave[i].animal->obtener_personalidad() << "," << nodo->clave[i].animal->obtener_hambre() << "," << nodo->clave[i].animal->obtener_higiene() << endl;
        }
    }
    
    for(i = 0; i <= nodo->clavesUsadas; i++) 
        ver(nodo->puntero[i]);
}

template <typename Dato>
long Arbol<Dato>::buscar(string clave)
{
    Nodo<Dato>* nodo = Entrada;
    int i;

    while(nodo) {
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].nombre < clave)) 
            i++;
        
        if(nodo->clave[i].nombre == clave) 
            return nodo->clave[i].registro;
        else 
            nodo = nodo->puntero[i];
    }
    return -1L;
}

template <typename Dato>
bool Arbol<Dato>::insertar(Clave clave)
{
    Nodo<Dato>* nodo;
    Nodo<Dato>* padre;
    int i;

    // Asegurarse de que la clave no este en el arbol
    padre = nodo = Entrada;
    while(nodo) {
        padre = nodo;
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].nombre < clave.nombre)) 
            i++;
        
        if(nodo->clave[i].nombre == clave.nombre && i < nodo->clavesUsadas) 
            return false;
        else 
            nodo = nodo->puntero[i];
    }
    nodo = padre;
    inserta(clave, nodo, NULL, NULL);
    return true;
}

template <typename Dato>
void Arbol<Dato>::inserta(Clave clave, Nodo<Dato>* nodo, Nodo<Dato>* hijo1, Nodo<Dato>* hijo2)
{
    Nodo<Dato>* padre;
    Nodo<Dato>* nuevo;
    int i, j;
    bool salir = false;

    // insertar nueva clave en nodo:
    do {
        if(!nodo)
        {
            nodo = new Nodo<Dato>(nClaves);
            nodo->clavesUsadas = 0;
            nodo->padre = NULL;
            Entrada = nodo;
        }
        padre = nodo->padre;
        if(nodo->clavesUsadas == nClaves) // overflow
        {
            // Nodo derecho
            nuevo = new Nodo<Dato>(nClaves);
            // Construye lista ordenada:
            i = 0;
            while(nodo->clave[i].nombre < clave.nombre && i < nClaves){
                lista[i] = nodo->clave[i];
                listapunt[i] = nodo->puntero[i];
                i++;
            }
            lista[i] = clave;
            listapunt[i] = hijo1;
            listapunt[i+1] = hijo2;

            while(i < nClaves){
                lista[i+1] = nodo->clave[i];
                listapunt[i+2] = nodo->puntero[i+1];
                i++;
            }
            // Dividir nodos:
            // Nodo izquierdo:
            nodo->clavesUsadas = nClaves/2;

            for(j = 0; j < nodo->clavesUsadas; j++){
                nodo->clave[j] = lista[j];
                nodo->puntero[j] = listapunt[j];
            }
            nodo->puntero[nodo->clavesUsadas] = listapunt[nodo->clavesUsadas];

            // Nodo derecho:
            nuevo->clavesUsadas = nClaves - nodo->clavesUsadas;

            for(j = 0; j < nuevo->clavesUsadas; j++){
                nuevo->clave[j] = lista[j+(nClaves/2)+1];
                nuevo->puntero[j] = listapunt[j+(nClaves/2)+1];
            }
            nuevo->puntero[nuevo->clavesUsadas] = listapunt[nClaves+1];

            for(j = 0; j <= nodo->clavesUsadas; j++){
                if(nodo->puntero[j]) 
                    (nodo->puntero[j])->padre = nodo;
            }
            for(j = 0; j <= nuevo->clavesUsadas; j++){
                if(nuevo->puntero[j]) 
                    (nuevo->puntero[j])->padre = nuevo;
            }

            clave = lista[nClaves/2];
            hijo1 = nodo;
            hijo2 = nuevo;
            nodo = padre;
        }
        else
        {
            // Inserta nueva clave en su lugar:
            i = 0;
            if(nodo->clavesUsadas > 0){
                while(nodo->clave[i].nombre < clave.nombre && i < nodo->clavesUsadas) 
                    i++;
                
                for(j = nodo->clavesUsadas; j > i; j--)
                    nodo->clave[j] = nodo->clave[j-1];
                
                for(j = nodo->clavesUsadas+1; j > i; j--)
                    nodo->puntero[j] = nodo->puntero[j-1];
            }
            nodo->clavesUsadas++;
            nodo->clave[i] = clave;
            nodo->puntero[i] = hijo1;
            nodo->puntero[i+1] = hijo2;

            if(hijo1) 
                hijo1->padre = nodo;
            if(hijo2) 
                hijo2->padre = nodo;
            salir = true;
        }
    } while(!salir);
}

template <typename Dato>
void Arbol<Dato>::borrar(string clave)
{
    Nodo<Dato>* nodo;
    bool encontrado = false;
    int i;

    // Busca el nodo que contiene la clave, si existe
    nodo = Entrada;
    while(nodo && !encontrado) {
        i = 0;
        while(i < nodo->clavesUsadas && (nodo->clave[i].nombre < clave)) 
            i++;
        
        if(nodo->clave[i].nombre == clave && i < nodo->clavesUsadas) 
            encontrado = true;
        else 
            nodo = nodo->puntero[i];
    }

    if(encontrado) 
        borrar_clave(nodo, clave);
}

template <typename Dato>
void Arbol<Dato>::borrar_clave(Nodo<Dato>* nodo, string clave)
{
    Nodo<Dato>* actual;
    Nodo<Dato>* derecha;
    Nodo<Dato>* izquierda;
    Nodo<Dato>* padre;
    int posicion_clave_padre, pos, i;

    // buscar posicion dentro de lista de claves:
    pos = 0;
    while(nodo->clave[pos].nombre < clave) 
        pos++;

    // Esta la clave en un nodo hoja?
    if(nodo->puntero[0]) { // No, se trata de un nodo intermedio
        // buscar actual del valor siguiente:
        actual = nodo->puntero[pos+1];
        while(actual->puntero[0]) 
            actual = actual->puntero[0];
        // Intercambiar con el valor siguiente:
        nodo->clave[pos] = actual->clave[0];
        // La posicion de la clave a borrar en ahora la 0:
        pos = 0;
    } 
    else 
        actual = nodo;

    // borrar clave
    for(i = pos; i < actual->clavesUsadas; i++)
        actual->clave[i] = actual->clave[i+1];
    actual->clavesUsadas--;

    if(actual == Entrada && actual->clavesUsadas == 0) {
        delete actual;
        Entrada = NULL;
        return;
    }

    // Es el numero de claves mayor que el minimo para el nodo?
    if(actual == Entrada || actual->clavesUsadas >= nodosMinimos) 
        return;

    do {
        // El numero de claves es menor que el minimo:
        // buscar nodos a derecha e izquierda:
        padre = actual->padre;
        for(posicion_clave_padre = 0; padre->puntero[posicion_clave_padre] != actual; posicion_clave_padre++);
        
        if(posicion_clave_padre > 0)
            izquierda = padre->puntero[posicion_clave_padre-1];
        else 
            izquierda = NULL;
        
        if(posicion_clave_padre < padre->clavesUsadas)
            derecha = padre->puntero[posicion_clave_padre+1];
        else 
            derecha = NULL;

        // Intentar pasar una clave de un nodo cercano:
        if(derecha && derecha->clavesUsadas > nodosMinimos)
            pasar_clave_derecha(derecha, padre, actual, posicion_clave_padre);
        else if(izquierda && izquierda->clavesUsadas > nodosMinimos)
            pasar_clave_izquierda(izquierda, padre, actual, posicion_clave_padre-1);
        // Si no fue posible, fundir con un nodo cercano y una clave de padre:
        else if(derecha) // Usar nodo derecho
            fundir_nodo(actual, padre, derecha, posicion_clave_padre);
        else             // Usar el nodo izquierdo
            fundir_nodo(izquierda, padre, actual, posicion_clave_padre-1);
        // Vuelta a empezar:
        actual = padre;
    } while(actual && actual != Entrada && actual->clavesUsadas < nodosMinimos);
}

template <typename Dato>
void Arbol<Dato>::pasar_clave_derecha(Nodo<Dato>* derecha, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre)
{
    int i;

    nodo->clave[nodo->clavesUsadas] = padre->clave[posicion_clave_padre];
    nodo->clavesUsadas++;
    padre->clave[posicion_clave_padre] = derecha->clave[0];
    nodo->puntero[nodo->clavesUsadas] = derecha->puntero[0];
    
    if(derecha->puntero[0]) 
        derecha->puntero[0]->padre = nodo;
    
    for(i = 0; i < derecha->clavesUsadas; i++) 
        derecha->clave[i] = derecha->clave[i+1];
    
    for(i = 0; i <= derecha->clavesUsadas; i++) 
        derecha->puntero[i] = derecha->puntero[i+1];
    derecha->clavesUsadas--;
}

template <typename Dato>
void Arbol<Dato>::pasar_clave_izquierda(Nodo<Dato>* izquierda, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre)
{
    int i;

    for(i = nodo->clavesUsadas; i > 0; i--) 
        nodo->clave[i] = nodo->clave[i-1];
    
    for(i = nodo->clavesUsadas+1; i > 0; i--) 
        nodo->puntero[i] = nodo->puntero[i-1];
    
    nodo->clavesUsadas++;
    nodo->clave[0] = padre->clave[posicion_clave_padre];
    padre->clave[posicion_clave_padre] = izquierda->clave[izquierda->clavesUsadas-1];
    nodo->puntero[0] = izquierda->puntero[izquierda->clavesUsadas];
    
    if(nodo->puntero[0]) 
        nodo->puntero[0]->padre = nodo;
    izquierda->clavesUsadas--;
}

template <typename Dato>
void Arbol<Dato>::fundir_nodo(Nodo<Dato>* izquierda, Nodo<Dato>* &padre, Nodo<Dato>* derecha, int posicion_clave_padre)
{
    int i;

    izquierda->clave[izquierda->clavesUsadas] = padre->clave[posicion_clave_padre];
    padre->clavesUsadas--;

    for(i = posicion_clave_padre; i < padre->clavesUsadas; i++) {
        padre->clave[i] = padre->clave[i+1];
        padre->puntero[i+1] = padre->puntero[i+2];
    }
    izquierda->clavesUsadas++;

    for(i = 0; i < derecha->clavesUsadas; i++)
        izquierda->clave[izquierda->clavesUsadas+i] = derecha->clave[i];

    for(i = 0; i <= derecha->clavesUsadas; i++) {
        izquierda->puntero[izquierda->clavesUsadas+i] = derecha->puntero[i];
        if(derecha->puntero[i]) derecha->puntero[i]->padre = izquierda;
    }
    izquierda->clavesUsadas += derecha->clavesUsadas;

    if(padre == Entrada && padre->clavesUsadas == 0) { // Cambio de entrada
        Entrada = izquierda;
        Entrada->padre = NULL;
        delete padre;
        padre = NULL;
    }
    delete derecha;
}

#endif
*/