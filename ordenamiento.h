#include <iostream>
#include "Animal.h"

using namespace std;

class QuickSort{
public:
    void sort(Animal* vector[], int max);

private:  
    void swapElements(Animal* a[], Animal* b[]);
    int particion (Animal* vector[], int bajo, int alto);
    void quickSort(Animal* vector[], int bajo, int alto);
};