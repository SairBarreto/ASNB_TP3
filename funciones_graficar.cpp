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


    string tablero = "ApPtttttctttppppccccctmmttttctmLmmmtctmRttttcOmmtppCctmmttttcccE";

    /*int posicion_rand = 0;



    string animal;

    for(int i=0; i<5;i++)
    {
        posicion_rand = 2 + rand() % 62;



        animal =  animales_perdidos[i] ;


        tablero.replace(posicion_rand,1,animal);

    }

    //graficar_tablero(tablero);*/


    return tablero;
}




void marcar_camino( string tablero,int cantidad,int vector_camino[])
{



    string nuevo_simbolo = ".";

    int direccion = 0;



    for(int i=0; i<cantidad;i++)
    {
        direccion = vector_camino[i] - 1;

        tablero.replace(direccion,1,nuevo_simbolo);

    }

    imprimir_emojis(tablero);

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

    for(int i = 0;i < 64; i++ )
    {

        if(i == posicion_auto_nueva)
        {

            tablero_rand.replace(i,1,"A");



        }
        if(i == posicion_auto_vieja - 1)
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
    cout<<EMOJIS[8]<<"= Montaña, costo gasolina = 5 pts"<<endl;
    cout<<EMOJIS[9]<<"= Precipicio, costo gasolina = 40 pts"<<endl;
    cout<<EMOJIS[10]<<"= Camino, costo gasolina = 1 pts"<<endl;
    cout<<EMOJIS[11]<<"= Tierra, costo gasolina = 2 pts"<<endl;
    cout<<endl;
    cout<<EMOJIS[7]<<"= auto"<<endl;
    cout<<EMOJIS[13]<<"= en camino"<<endl;
    cout<<endl;
    cout<<EMOJIS[1]<<"= Caballo"<<endl;
    cout<<EMOJIS[2]<<"= Gato"<<endl;
    cout<<EMOJIS[5]<<"= Lagarto"<<endl;
    cout<<EMOJIS[4]<<"= Conejo "<<endl;
    cout<<EMOJIS[0]<<"= Perro"<<endl;
    cout<<EMOJIS[3]<<"= Roedor "<<endl;
    cout<<EMOJIS[6]<<"= Erizo "<<endl;
    cout<<endl;


}

string letra_a_emoji(string letra)
{
    int posicion = 0;

    for(int i = 0; i < 12; i++)
    {
        if(letra == TIPO_CASILLERO[i])
        {
            posicion = i;
        }

    }

    return EMOJIS[posicion];
}


void imprimir_emojis(string tablero_nuevo)
{
    string letra;

    string emoji;

     for(int i=0;i<64;i++)
    {
        letra = tablero_nuevo[i];

        emoji = letra_a_emoji(letra);

        if(i%8==0)
        {
            cout<<endl;
        }

        cout<<" [  "<<emoji<<"  ] ";


    }
}







