#include "funciones_cargar_tablero.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "Grafo.h"
#include "funciones_graficar.h"

using namespace std;


int devolver_peso_nodo(int numero_nodo)
{
    string tablero = "ccpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";



    string tipo_casilla;

    int peso = 0;

    for(int i=1;i<65;i++)
    {
        tipo_casilla = tablero[i];

        if(tipo_casilla == "m" && i == numero_nodo )
        {
            peso = 5;
        }
        else if(tipo_casilla == "p" && i == numero_nodo )
        {
            peso = 40;
        }
        else if (tipo_casilla == "c" && i == numero_nodo )
        {
            peso = 1;
        }
        else if(tipo_casilla == "t" && i == numero_nodo )
        {
            peso = 2;
        }

    }

    return peso;
}


void buscar_camino_minimo(string origen, string destino)
{
    Grafo grafo;

    int num_nodo=0;

    int numero_nodo = 0;

    int peso_total_der = 0;

    int peso_total_sur = 0;

    int peso_der = 0;

    int peso_sur = 0;

    int peso_nodo = 0;


    for(int i=0;i<65;i++)
    {
        num_nodo = i;

        string str_nodo(to_string(num_nodo));

        grafo.agregarVertice(str_nodo);

    }



    for(int i=0;i<64;i++)
    {
        numero_nodo = i;

        string str_nodo(to_string(numero_nodo));
        string str_nodo_der(to_string(numero_nodo + 1));
        string str_nodo_sur(to_string(numero_nodo + 8));

        peso_nodo = devolver_peso_nodo(numero_nodo);

        peso_der = devolver_peso_nodo(numero_nodo + 1);

        peso_sur = devolver_peso_nodo(numero_nodo + 8);

        if(numero_nodo % 8 != 0 && numero_nodo<57)
        {

            peso_total_der = peso_nodo + peso_der;

            peso_total_sur = peso_nodo + peso_sur;

            grafo.agregarCamino(str_nodo,str_nodo_der,peso_total_der);
            grafo.agregarCamino(str_nodo,str_nodo_sur, peso_total_sur);

        }
        else if(numero_nodo<57)
        {

            peso_total_sur = peso_nodo + peso_sur;

            grafo.agregarCamino(str_nodo,str_nodo_sur, peso_total_sur);


        }
        else
        {
            peso_total_der = peso_nodo + peso_der;

            grafo.agregarCamino(str_nodo,str_nodo_der,peso_der);
        }



    }


    grafo.usarFloyd();

    grafo.caminoMinimo(origen,destino);
}


int calcular_gasolina_necesaria(int camino[], int largo)
{

    int gasolina_necesaria = 0;

    int  nro_casillero = 0;

    string tipo_de_casillero ;

    for(int i = 1;i<=largo-1;i++)
    {
        nro_casillero = camino[i] - 1;

        tipo_de_casillero = tablero_original[nro_casillero];


        if (tipo_de_casillero == "m")
        {
            gasolina_necesaria += 5;
        }
        else if(tipo_de_casillero == "p")
        {
            gasolina_necesaria += 40;
        }
        else if(tipo_de_casillero == "c")
        {
            gasolina_necesaria += 1 ;
        }
        else if(tipo_de_casillero == "t")
        {
            gasolina_necesaria += 2;
        }
    }

    return gasolina_necesaria;
}

