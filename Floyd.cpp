#include "Floyd.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ** Floyd::crearMatrizCaminos(){

    int ** caminos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        caminos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crearMatrizCostos(int ** matrizAdyacencia){

    int ** costos = new int*[cantidadVertices];
    for(int i = 0; i < cantidadVertices; i++){
        costos[i] = new int[cantidadVertices];
    }

    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices; j++){
            costos[i][j] = matrizAdyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::mostrarMatrices(){
    //cout << "Matriz de costos:      ||           Matriz de caminos:" << endl;
    string filaCostos;
    string filaCaminos;
    for(int i = 0; i < cantidadVertices; i++){
        for(int j = 0; j < cantidadVertices * 2; j++) {
            if(j == cantidadVertices * 2 - 1){
                filaCostos += "            ||           ";
                filaCaminos += "\n";
            } else if(j % 2 == 0){
                if(matrizCostos[i][j/2] == INFINITO){
                    filaCostos += "#";
                } else {
                    filaCostos += to_string(matrizCostos[i][j/2]);
                }

                if(matrizCaminos[i][j/2] == POSICION_NO_ENCONTRADA){
                    filaCaminos += "-";
                } else {
                    filaCaminos +=to_string(matrizCaminos[i][j/2]);
                }
            } else{
                filaCaminos += "|";
                filaCostos += "|";
            }
        }
        //cout << filaCostos << filaCaminos;
        filaCostos = "";
        filaCaminos = "";
    }
    //cout << endl;
}

void Floyd::calcularMatrices() {

    cantidadVertices = vertices -> obtenerCantidadDeElementos();
    matrizCostos = crearMatrizCostos(matrizAdyacencia);
    matrizCaminos = crearMatrizCaminos();

    for (int verticeIntermedio = 0; verticeIntermedio < cantidadVertices; verticeIntermedio++) {

        for (int origen = 0; origen < cantidadVertices; origen++){

            for (int destino = 0; destino < cantidadVertices; destino++) {

                int costo = matrizCostos[origen][verticeIntermedio] + matrizCostos[verticeIntermedio][destino];

                if (matrizCostos[origen][destino] > costo) {
                    matrizCostos[origen][destino] = costo;
                    matrizCaminos[origen][destino] = matrizCaminos[origen][verticeIntermedio];
                } else if (matrizCostos[origen][destino] == INFINITO){
                    matrizCaminos[origen][destino] = POSICION_NO_ENCONTRADA;
                }

            }

        }
        //cout << endl << "Iteracion numero: " << verticeIntermedio << endl;
        //mostrarMatrices();

    }

}

void Floyd::caminoMinimo(int origen, int destino) {

    string nombre_archivo = "movimientos.txt";



    ofstream archivo;

                        archivo.open(nombre_archivo.c_str(),fstream::out);

                        if(matrizCaminos[origen][destino] == POSICION_NO_ENCONTRADA){
                           // cout << "No hay un camino que conecte " <<  vertices->obtenerNombre(origen + 1) << " con " << vertices->obtenerNombre(destino + 1);
                        }else{
                                    archivo << vertices->obtenerNombre(origen + 1);//primer punto
                                    archivo << endl;
                            do{
                                origen = matrizCaminos[origen][destino];
                                    archivo << vertices->obtenerNombre(origen + 1);//punto sig

                                    archivo <<endl;

                            }while(origen != destino);
                        }


    archivo.close();

}

void Floyd::liberarMatrices() {
    if(matrizCostos != nullptr && matrizCaminos != nullptr){
        for(int i = 0; i < cantidadVertices; i++){
            delete[] matrizCostos[i];
            delete[] matrizCaminos[i];
        }
        delete[] matrizCostos;
        delete[] matrizCaminos;

        matrizCostos = nullptr;
        matrizCaminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberarMatrices();
}

Floyd::Floyd(Lista<Vertice> *vertices, int ** matrizAdyacencia) : CaminoMinimo(vertices, matrizAdyacencia){
    calcularMatrices();
}







