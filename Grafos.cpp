#include <iostream>
#include <string>

using namespace std;

#define numV 8
#define INF 999

/*  INICIAL
  0  1  2  3  4  5  6  7         
  __ __ __ __ __ __ __ __
0|0 |40|in|  |  |  |  |  |  Al siempre partir del (0,0) y solo moverse norte sur este u oeste
1|1 |in|in|in|  |  |  |  |  esos seran los dos valores "fijos" y los demas infinito, el cual la funcion
2|in|in|in|  |  |  |  |  |  camino_minimo se encargara de hallar el valor minimo
3|in|in|  |0 |  |  |  |  |
4|  |  |  |  |0 |  |  |  |
5|  |  |  |  |  |0 |  |  | 
6|  |  |  |  |  |  |0 |  |
7|  |  |  |  |  |  |  |0 | 
*/ 
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