#include "include/quickSort.h"
#include <iostream>

using namespace std;

void QuickSort::sort(vector<int>& vector) {
    quickSort(vector, 0, (int)vector.size() - 1);
}

void QuickSort::quickSort(vector<int>& vector, int bajo, int alto){
    if (bajo < alto){
        // pi: Indice de particion (cuando el pivote esta en su lugar)
        int pi = particion(vector, bajo, alto);
 
        quickSort(vector, bajo, pi - 1);
        quickSort(vector, pi + 1, alto);
    }
}

int QuickSort::particion(vector<int>& vector, int bajo, int alto)
{
    int pivot = vector[alto] -> animal -> obtener_edad();

    // Indice del elemento mas chico que indica la posicion del pivote por el momento
    int i = (bajo - 1); 
 
    for (int j = bajo; j <= alto - 1; j++)
    {
        // Si el elemento actual es mas chico que el pivote
        if (vector[j] -> animal -> obtener_edad() < pivot)
        {
            // Entonces intercambio el elemento actual por el que esta a la derecha
            // de la posicion actual del pivote
            // (paso el elemento a la mitad izquierda)
            i++;
            swapElements(&vector[i], &vector[j]);
        }
    }
    swapElements(&vector[i + 1], &vector[alto]);
    return (i + 1);
}

void QuickSort::swapElements(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

//void QuickSort::printAlgorithmInfo() const {
  //  cout << "QuickSort" << endl;
  //  cout << "Complexity best case: O(n * log(n))" <<endl;
  //  cout << "Complexity worst case: O(n^2)" << endl;
//}