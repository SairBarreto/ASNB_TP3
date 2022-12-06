#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include "Grafo.h"
#include "funciones_graficar.h"
#include "funciones_rescatar.h"
#include <time.h>

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

string generar_animales_perdidos()
{
    srand((unsigned int)time(NULL));


    int indice = 0;

    string animales_perdidos;

    string animal;

    srand((unsigned int)time(NULL));

    int n = 0;

    int num[7];

    for(int i=0; i<5; i++)
    {
        do
            n =  rand() % 7 ;

        while(comprobar_repeticion(n, num,7));

        num[i] = n;

        indice = num[i];

        animal = ESPECIES[indice];

        animales_perdidos = animales_perdidos + animal;

    }


    return animales_perdidos;
}

bool comprobar_repeticion(int n, int num[],int ciclo)
{
    bool se_repite = false;

    for(int i=0; i<ciclo; i++)

        if(n == num[i])

            se_repite = true;


    return se_repite ;
}


string generar_tablero_de_animales_perdidos(string animales_perdidos)
{

    string tablero = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    int posicion_rand = 0;

    string animal;

    tablero.replace(0,1,"A");

    srand((unsigned int)time(NULL));
    int n = 0;
    int num[5];
    for(int i=0; i<5; i++)
    {
        animal = animales_perdidos[i];
        do
            n =  1 + rand() % (64-1);
        while(comprobar_repeticion(n, num,5));
        num[i] = n;

        posicion_rand = num[i];
        tablero.replace(posicion_rand,1,animal);
    }

    //graficar_tablero(tablero);


    return tablero;
}




void marcar_camino( string tablero,int cantidad,int vector_camino[])
{



    string nuevo_simbolo = ".";

    int direccion = 0;



    for(int i=0; i<cantidad;i++)
    {
        direccion = vector_camino[i] - 1;

        tablero.replace(direccion,1,"A");

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
    cout << "Referencias: "<<endl;
    cout << endl;
    cout << "⬛" <<" = Monta�a, costo gasolina = 5 pts" << endl;
    cout << "🟫" << " = Precipicio, costo gasolina = 40 pts" << endl;
    cout << "🟩" << " = Camino, costo gasolina = 1 pts" << endl;
    cout << "⬜" << " = Tierra, costo gasolina = 2 pts" << endl;
    cout << endl;
    cout << "🚚" << " = auto" << endl;
    cout << "💨" << " = en camino" << endl;
    cout << endl;
    cout << "🐎" << " = Caballo" << endl;
    cout << "🐱" << " = Gato" << endl;
    cout << "🦎" << " = Lagarto" << endl;
    cout << "🐰" <<" = Conejo " << endl;
    cout << "🐶" << " = Perro" << endl;
    cout << "🐭" << " = Roedor" << endl;
    cout << "🦔" << " = Erizo" << endl;
    cout << endl;


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

        cout << emoji ;


    }
}







