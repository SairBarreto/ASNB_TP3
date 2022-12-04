#include <iostream>

using namespace std;

class QuickSort{
public:
    void sort(vector<int>& vector);

private:  
    void swapElements(int* a, int* b);
    int particion (vector<int>& vector, int bajo, int alto);
    void quickSort(vector<int>& vector, int bajo, int alto);
};