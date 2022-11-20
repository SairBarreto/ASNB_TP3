#include <iostream>
#include <string>

using namespace std;

#define numV 8
#define INF 999

void camino_minimo(int matriz_mapa[numV][numV]){ //matriz_mapa ya cargada con costo de cada celda
    int i, j, k;
    int matriz_1[numV][numV];

    for (i = 0; i < numV; i++){ 
        for (j = 0; j < numV; j++){ 
            matriz_1[i][j] = matriz_mapa[i][j];
        }
    }

    for (k = 0; k < nV; k++) { // se pone vertice en vertice comparando camino minimo
        for (i = 0; i < nV; i++) {
            for (j = 0; j < nV; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}