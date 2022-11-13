#ifndef ARBOL_B_H_INCLUDED
#define ARBOL_B_H_INCLUDED
#include "Nodo.h"
#include <iostream>

using namespace std;

template <typename Dato>
class Arbol
{
//Atributos
    private:
        Clave* lista;
        Nodo<Dato>** listapunt;
        Dato n_claves; 
        Dato nodos_minimos;
        Nodo<Dato>* entrada;

        void inserta(Clave clave, Nodo<Dato>* nodo, Nodo<Dato>* hijo1, Nodo<Dato>* hijo2);

        void borrar_clave(Nodo<Dato>* nodo, Dato nombre);

        void borrar_nodo(Nodo<Dato>* nodo);

        void pasar_clave_derecha(Nodo<Dato>* derecha, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre);

        void pasar_clave_izquierda(Nodo<Dato>* izquierda, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre);

        void fundir_nodo(Nodo<Dato>* izquierda, Nodo<Dato>* &padre, Nodo<Dato>* derecha, int posicion_clave_padre);

        void ver(Nodo<Dato>* nodo);

    //Metodos
    public:
        Arbol(Dato n_claves);

        ~Arbol();

        long buscar(Dato clave);

        bool insertar(Clave clave);

        void borrar(Dato clave);

        void mostrar();
};

//Contructor
template <typename Dato>
Arbol<Dato>::Arbol(Dato n_claves) : n_claves(n_claves)
{
    lista = new Clave[n_claves+1];
    listapunt = new Nodo<Dato>*[n_claves + 2];
    nodos_minimos = n_claves / 2; // ((n_claves+1)/2)-1;
    entrada = NULL;
}

//Destructor
template <typename Dato>
Arbol<Dato>::~Arbol()
{
    delete[] lista;
    delete[] listapunt;
    // Destruir �rbol, algoritmo recursivo:
    borrarNodo(entrada);
}

//borrar nodo
template <typename Dato>
void Arbol<Dato>::borrar_nodo(Nodo<Dato>* nodo)
{
    if(!nodo) 
        return;

    for(int i = 0; i <= nodo->claves_usadas; i++) 
        borrarNodo(nodo->puntero[i]);
    delete nodo;
}

//Mostrar
template <typename Dato>
void Arbol<Dato>::mostrar()
{
    cout << "arbol" << endl;
    ver(entrada);
    cout << "-----" << endl;
    system("pause");
}

//Ver
template <typename Dato>
void Arbol<Dato>::ver(Nodo<Dato>* nodo)
{
    if(!nodo) 
        return;
    
    for(i = 0; i < nodo->claves_usadas-1; i++) 
        cout << nodo->clave[i].nombre << "-";

    if(nodo->claves_usadas) 
        cout << nodo->clave[i].nombre << " [";

    if(nodo->padre) 
        cout << (nodo->padre)->clave[0].nombre; 
    else 
        cout << "*";
    
    cout << "]" << endl;
    
    for(i = 0; i <= nodo->claves_usadas; i++) 
        ver(nodo->puntero[i]);
}

//buscar
template <typename Dato>
long Arbol<Dato>::buscar(Dato clave)
{
    Nodo<Dato>* nodo = entrada;
    int i;

    while(nodo) {
        i = 0;
        while((i < nodo->claves_usadas) && (nodo->clave[i].nombre < clave)) 
            i++;
        
        if(nodo->clave[i].nombre == clave) 
            return nodo->clave[i].Animal;
        else 
            nodo = nodo->puntero[i];
    }
    return -1L;
}

//insertar
template <typename Dato>
bool Arbol<Dato>::insertar(Clave clave)
{
    Nodo<Dato>* nodo; 
    Nodo<Dato>* padre;
    int i;

    // Asegurarse de que la clave no est� en el �rbol
    padre = entrada;
    nodo = entrada;
    while(nodo) {
        padre = nodo;
        i = 0;

        while((i < nodo->claves_usadas) && (nodo->clave[i].nombre < clave.nombre)) 
            i++;

        if((nodo->clave[i].nombre == clave.nombre) && (i < nodo->claves_usadas)) 
            return false;
        else 
            nodo = nodo->puntero[i];
    }
    nodo = padre;
    inserta(clave, nodo, NULL, NULL);
    return true;
}

//Inserta
template <typename Dato>
void Arbol<Dato>::inserta(Clave clave, Nodo<Dato>* nodo, Nodo<Dato>* hijo1, Nodo<Dato>* hijo2)
{
    Nodo<Dato>* padre;
    Nodo<Dato>* nuevo;
    int i, j;
    bool salir = false;

    // insertar nueva clave en nodo:
    do {
        if(!nodo){
            nodo = new Nodo<Dato>(n_claves);
            nodo->claves_usadas = 0;
            nodo->padre = NULL;
            entrada = nodo;
        }
        padre = nodo->padre;

        if(nodo->claves_usadas == n_claves){
            // Nodo derecho
            nuevo = new Nodo<Dato>(n_claves);
            // Construye lista ordenada:
            i = 0;
            while(nodo->clave[i].nombre < clave.nombre && i < n_claves){
                lista[i] = nodo->clave[i];
                listapunt[i] = nodo->puntero[i];
                i++;
            }
            lista[i] = clave;
            listapunt[i] = hijo1;
            listapunt[i + 1] = hijo2;

            while(i < n_claves) {
                lista[i + 1] = nodo->clave[i];
                listapunt[i + 2] = nodo->puntero[i + 1];
                i++;
            }

            // Dividir nodos:
            // Nodo izquierdo:
            nodo->claves_usadas = n_claves / 2;
            for(j = 0; j < nodo->claves_usadas; j++) {
                nodo->clave[j] = lista[j];
                nodo->puntero[j] = listapunt[j];
            }
            nodo->puntero[nodo->claves_usadas] = listapunt[nodo->claves_usadas];

            // Nodo derecho:
            nuevo->claves_usadas = n_claves - nodo->claves_usadas;
            for(j = 0; j < nuevo->claves_usadas; j++) {
                nuevo->clave[j] = lista[j + (n_claves / 2) + 1];
                nuevo->puntero[j] = listapunt[j + (n_claves / 2) + 1];
            }
            nuevo->puntero[nuevo->claves_usadas] = listapunt[n_claves + 1];

            for(j = 0; j <= nodo->claves_usadas; j++){
                if(nodo->puntero[j]) 
                    (nodo->puntero[j])->padre = nodo;
            }

            for(j = 0; j <= nuevo->claves_usadas; j++){
                if(nuevo->puntero[j]) 
                    (nuevo->puntero[j])->padre = nuevo;
            }

            clave = lista[n_claves / 2];
            hijo1 = nodo;
            hijo2 = nuevo;
            nodo = padre;
        }
        else
        {
            // Inserta nueva clave en su lugar:
            i = 0;
            if(nodo->claves_usadas > 0) {
                while((nodo->clave[i].nombre < clave.nombre) && (i < nodo->claves_usadas)) 
                    i++;

                for(j = nodo->claves_usadas; j > i; j--)
                    nodo->clave[j] = nodo->clave[j - 1];

                for(j = nodo->claves_usadas+1; j > i; j--)
                    nodo->puntero[j] = nodo->puntero[j - 1];
            }
            nodo->claves_usadas++;
            nodo->clave[i] = clave;
            nodo->puntero[i] = hijo1;
            nodo->puntero[i + 1] = hijo2;

            if(hijo1) 
                hijo1->padre = nodo;
            if(hijo2) 
                hijo2->padre = nodo;
            
            salir = true;
        }
    } while(!salir);
}

//Borrar
template <typename Dato>
void Arbol<Dato>::borrar(Dato nombre)
{
    Nodo<Dato>* nodo;
    bool encontrado = false;
    int i;

    // Busca el nodo que contiene la clave, si existe
    nodo = entrada;
    while(nodo && !encontrado) {
        i = 0;
        while((i < nodo->claves_usadas) && (nodo->clave[i].nombre < nombre)) 
            i++;
        
        if((nodo->clave[i].nombre == nombre) && (i < nodo->claves_usadas)) 
            encontrado = true;
        else 
            nodo = nodo->puntero[i];
    }

    if(encontrado) 
        borrar_clave(nodo, nombre);
}

//borrar Clave
template <typename Dato>
void Arbol<Dato>::borrar_clave(Nodo<Dato>* nodo, Dato nombre)
{
    Nodo<Dato>* actual, derecha, izquierda, padre;
    int posicion_clave_padre, pos, i;

    // buscar posicion dentro de lista de claves:
    pos = 0;
    while(nodo->clave[pos].nombre < nombre) 
        pos++;

    // Esta la clave en un nodo hoja?
    if(nodo->puntero[0]){ // No, se trata de un nodo Datoermedio
        // buscar actual del nombre siguiente:
        actual = nodo->puntero[pos+1];

        while(actual->puntero[0]) 
            actual = actual->puntero[0];

        // Dato a intercambiar con el nombre siguiente:
        nodo->clave[pos] = actual->clave[0];
        // La posicion de la clave a borrar en ahora la 0:
        pos = 0;
    } 
    else 
        actual = nodo;

    // borrar clave
    for(i = pos; i < actual->claves_usadas; i++)
        actual->clave[i] = actual->clave[i + 1];

    actual->claves_usadas--;

    if(actual == entrada && (actual->claves_usadas == 0)) {
        delete actual;
        entrada = NULL;
        return;
    }

    // Es el numero de claves mayor que el minimo para el nodo?
    if(actual == entrada || (actual->claves_usadas >= nodos_minimos)) 
        return;

    do {
        // El numero de claves es menor que el m�nimo:
        // buscar nodos a derecha e izquierda:
        padre = actual->padre;
        
        for(posicion_clave_padre = 0; padre->puntero[posicion_clave_padre] != actual; posicion_clave_padre++);

        if(posicion_clave_padre > 0)
            izquierda = padre->puntero[posicion_clave_padre-1];
        else 
            izquierda = NULL;
        
        if(posicion_clave_padre < padre->claves_usadas)
            derecha = padre->puntero[posicion_clave_padre+1];
        else 
            derecha = NULL;

        // Datoentar pasar una clave de un nodo cercano:
        if(derecha && (derecha->claves_usadas > nodos_minimos))
            pasar_clave_derecha(derecha, padre, actual, posicion_clave_padre);
        else if(izquierda && izquierda->claves_usadas > nodos_minimos)
            pasar_clave_izquierda(izquierda, padre, actual, posicion_clave_padre-1);
        // Si no fue posible, fundir con un nodo cercano y una clave de padre:
        else if(derecha) // Usar nodo derecho
            fundir_nodo(actual, padre, derecha, posicion_clave_padre);
        else             // Usar el nodo izquierdo
            fundir_nodo(izquierda, padre, actual, posicion_clave_padre-1);
        // Vuelta a empezar:
        actual = padre;
    } while(actual && (actual != entrada) && (actual->claves_usadas < nodos_minimos));
}

//Pasar clave a la derecha
template <typename Dato>
void Arbol<Dato>::pasar_clave_derecha(Nodo<Dato>* derecha, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre)
{
    nodo->clave[nodo->claves_usadas] = padre->clave[posicion_clave_padre];
    nodo->claves_usadas++;
    padre->clave[posicion_clave_padre] = derecha->clave[0];
    nodo->puntero[nodo->claves_usadas] = derecha->puntero[0];

    if(derecha->puntero[0]) 
        derecha->puntero[0]->padre = nodo;

    for(int i = 0; i < derecha->claves_usadas; i++){
        derecha->clave[i] = derecha->clave[i+1];
    }
    for(int i = 0; i <= derecha->claves_usadas; i++){
        derecha->puntero[i] = derecha->puntero[i+1];
    }
    derecha->claves_usadas--;
}

//Pasar clave a la izquierda
template <typename Dato>
void Arbol<Dato>::pasar_clave_izquierda(Nodo<Dato>* izquierda, Nodo<Dato>* padre, Nodo<Dato>* nodo, int posicion_clave_padre)
{
    for(int i = nodo->claves_usadas; i > 0; i--){
        nodo->clave[i] = nodo->clave[i-1];
    }
    for(int i = nodo->claves_usadas+1; i > 0; i--){
        nodo->puntero[i] = nodo->puntero[i-1];
    }
    nodo->claves_usadas++;
    nodo->clave[0] = padre->clave[posicion_clave_padre];
    padre->clave[posicion_clave_padre] = izquierda->clave[izquierda->claves_usadas - 1];
    nodo->puntero[0] = izquierda->puntero[izquierda->claves_usadas];

    if(nodo->puntero[0]){
        nodo->puntero[0]->padre = nodo;
    }
    izquierda->claves_usadas--;
}

//Fundir Nodo
template <typename Dato>
void Arbol<Dato>::fundir_nodo(Nodo<Dato>* izquierda, Nodo<Dato>* &padre, Nodo<Dato>* derecha, int posicion_clave_padre)
{
    izquierda->clave[izquierda->claves_usadas] = padre->clave[posicion_clave_padre];
    padre->claves_usadas--;

    for(int i = posicion_clave_padre; i < padre->claves_usadas; i++) {
        padre->clave[i] = padre->clave[i + 1];
        padre->puntero[i + 1] = padre->puntero[i + 2];
    }
    izquierda->claves_usadas++;

    for(int i = 0; i < derecha->claves_usadas; i++){
        izquierda->clave[izquierda->claves_usadas+i] = derecha->clave[i];
    }

    for(int i = 0; i <= derecha->claves_usadas; i++){
        izquierda->puntero[izquierda->claves_usadas+i] = derecha->puntero[i];
        if(derecha->puntero[i]) derecha->puntero[i]->padre = izquierda;
    }
    izquierda->claves_usadas += derecha->claves_usadas;
    
    if(padre == entrada && padre->claves_usadas == 0) { // Cambio de entrada
        entrada = izquierda;
        entrada->padre = NULL;
        delete padre;
        padre = NULL;
    }
    delete derecha;
}

#endif