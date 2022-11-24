#include "funciones_cargar_tablero.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "Grafo.h"
#include "funciones_graficar.h"

using namespace std;

int devolver_peso_der(int numero_nodo)
{
    string tablero[1] = {"acpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc"};
    string tipo_casilla;

    int peso =0;

    for(int i=1;i<65;i++)
    {
        tipo_casilla = tablero[0][i];

        if(tipo_casilla == "m" && i == numero_nodo)
        {
            peso = 5;
        }
        else if(tipo_casilla == "p" && i == numero_nodo)
        {
            peso = 40;
        }
        else if (tipo_casilla == "c" && i == numero_nodo)
        {
            peso = 1;
        }
        else if(tipo_casilla == "t" && i == numero_nodo)
        {
            peso = 2;
        }

    }

    return peso;

}

//GRAFO
//calcula el peso de lo que cuesta bajar en la casilla

int devolver_peso_sur(int numero_nodo)
{
    string tablero[1] = {"acpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc"};

    string tipo_casilla;

    int peso = 0;

    for(int i=1;i<65;i++)
    {
        tipo_casilla = tablero[0][i];

        if(tipo_casilla == "m" && i == numero_nodo + 8)
        {
            peso = 5;
        }
        else if(tipo_casilla == "p" && i == numero_nodo + 8)
        {
            peso = 40;
        }
        else if (tipo_casilla == "c" && i == numero_nodo + 8)
        {
            peso = 1;
        }
        else if(tipo_casilla == "t" && i == numero_nodo + 8)
        {
            peso = 2;
        }

    }

    return peso;
}


void buscar_camino_minimo(string origen, string destino)
{
    Grafo grafo;

    //string camino_completo_prueba;


    int num_nodo=0;



    for(int i=1;i<65;i++)
    {
        num_nodo = i;

        string str_nodo(to_string(num_nodo));

        grafo.agregarVertice(str_nodo);



    }

    int numero_nodo = 0;



    for(int i=1;i<64;i++)
    {
        numero_nodo = i;

        int peso_der = 0;

        int peso_sur = 0;

       string str_nodo(to_string(numero_nodo));
       string str_nodo_der(to_string(numero_nodo + 1));
       string str_nodo_sur(to_string(numero_nodo + 8));

       peso_der = devolver_peso_der(numero_nodo + 1);

       peso_sur = devolver_peso_sur(numero_nodo);

       if(numero_nodo % 8 != 0 && numero_nodo<57)
       {


            grafo.agregarCamino(str_nodo,str_nodo_der,peso_der);
            grafo.agregarCamino(str_nodo,str_nodo_sur, peso_sur);

       }
       else if(numero_nodo<57)
       {


              grafo.agregarCamino(str_nodo,str_nodo_sur, peso_sur);


        }
        else
        {
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

    for(int i = 0;i<largo;i++)
    {
        nro_casillero = camino[i];



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

