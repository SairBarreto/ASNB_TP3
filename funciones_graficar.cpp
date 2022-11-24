#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include "Grafo.h"
#include "funciones_graficar.h"

using namespace std;

void graficar_tablero(string nuevo_tablero)
{

    for(int i=0;i<64;i++)
    {
        if(i%8==0)
        {
            cout<<"\n";
        }

        cout<<"["<<nuevo_tablero[i]<<"]";
    }

    cout<<endl;
}
//PARTE GRAFICA
//tendria que recibir una string con las iniciales de los animales random
//imprime tablero con los animales en la posicion que le toco
string generar_tablero_de_animales_perdidos(string animales_perdidos)
{


    string tablero = "Apttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    int posicion_rand = 0;



    string animal;

    for(int i=0; i<5;i++)
    {
        posicion_rand = 2 + rand() % 62;



        animal =  animales_perdidos[i] ;


        tablero.replace(posicion_rand,1,animal);

    }

    //graficar_tablero(tablero);


    return tablero;
}



//PARTE GRAFICA - no terminada
// marca con un # el camino
//tendria que recibir los nodos
void marcar_camino( string tablero,int cantidad,int vector_camino[])
{



    //string tablero = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    string nuevo_simbolo = ".";



    for(int i=0; i<cantidad;i++)
    {



        tablero.replace(vector_camino[i]-1,1,nuevo_simbolo);

    }

    graficar_tablero(tablero);





}
int obtener_camino(int vector_movimientos[])
{
    string nombre_archivo = "movimientos.txt";

    ifstream archivo(nombre_archivo.c_str());

    string linea;

    int num = 0;

    int contador = 0;

    while(getline(archivo,linea))
    {
        num = stoi(linea);

        vector_movimientos[contador] = num;

        contador++;
    }

    return contador;
}

int obtener_ubicacion(string inicial_animal, string tablero_nuevo)
{
    string letra;

    int posicion = 0;

    for(int i=0;i<64;i++)
    {
        letra = tablero_nuevo[i];

        if (letra == inicial_animal)
        {
            posicion = i;
        }
    }

    return posicion;
}

string modificar_tablero_aleatorio(string tablero_rand, int posicion_auto_nueva, int posicion_auto_vieja)
{
    string casillero;

    tablero_rand[0] = tablero_original[0];

    for(int i = 1;i < 64; i++ )
    {
        if(i == posicion_auto_nueva)
        {
             tablero_rand.replace(i,1,"A");

        }
        if(i == posicion_auto_vieja)
        {
            casillero = tablero_original[i];

            tablero_rand.replace(i,1,casillero);
        }

    }

    return tablero_rand;
}

void imprimir_referencias()
{
    cout<<"Referencias: "<<endl;
    cout<<endl;
    cout<<"'m' = Montaña, costo gasolina = 5 pts"<<endl;
    cout<<"'p' = Precipicio, costo gasolina = 40 pts"<<endl;
    cout<<"'c' = Camino, costo gasolina = 1 pts"<<endl;
    cout<<"'t' = Tierra, costo gasolina = 2 pts"<<endl;
    cout<<endl;
    cout<<"'A' = auto"<<endl;
    cout<<endl;
    cout<<"'C' = Caballo"<<endl;
    cout<<"'G' = Gato"<<endl;
    cout<<"'I' = Iguana"<<endl;
    cout<<"'O' = Conejo "<<endl;
    cout<<"'P' = Perro"<<endl;
    cout<<"'R' = Roedor "<<endl;
    cout<<endl;


}







