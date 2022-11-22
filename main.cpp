#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include "Grafo.h"

using namespace std;


//PARTE GRAFICA
//tendria que recibir una string con las iniciales de los animales random
//imprime tablero con los animales en la posicion que le toco
void generar_tablero()
{
    string animales_perdidos[6] = {"PIROC"};

    string tablero = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    int posicion_rand = 0;

    int posiciones_animales_perdidos[5];

    string animal;

    for(int i=0; i<5;i++)
    {
        posicion_rand = 2 + rand() % 62;

        cout << posicion_rand<<endl;

        animal =  animales_perdidos[0][i] ;

        cout << animal<<endl;

        tablero.replace(posicion_rand,1,animal);

    }



    for(int i=0;i<64;i++)
    {
        if(i%8==0)
        {
            cout<<"\n";
        }

        cout<<"[ "<<tablero[i]<<" ] ";
    }

}
//PARTE GRAFICA - no terminada
// marca con un # el camino
//tendria que recibir los nodos
int marcar_camino(int vector_camino[], string tablero,int cantidad)
{



    //string tablero = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    string nuevo_simbolo = "#";



    for(int i=0; i<cantidad;i++)
    {



        tablero.replace(vector_camino[i],1,nuevo_simbolo);

    }

    for(int i=0;i<64;i++)
    {
        if(i%8==0)
        {
            cout<<"\n";
        }

        cout<<"[ "<<tablero[i]<<" ] ";
    }







}


//GRAFO
//calcula el peso segun la casilla que hay a la derecha( o sea lo que cuesta llegar a esa)
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

    string camino_completo_prueba;


    int num_nodo=0;



    for(int i=1;i<65;i++)
    {
        num_nodo = i;

        string str_nodo(to_string(num_nodo));

        grafo.agregarVertice(str_nodo);



    }

    int numero_nodo = 0;



    for(int i=1;i<65;i++)
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




    grafo.mostrarGrafo();

    grafo.usarFloyd();

    grafo.caminoMinimo(origen, destino);
}

int main() {


    string tablero = "cpttttttctttppppccccctmmttttctmmmmmtctmmttttctmmtpppctmmttttcccc";

    int camino[15] = {1,9,17,18,19,20,21,29,37,45,53,61,62,63};

    marcar_camino(camino, tablero, 13);

    buscar_camino_minimo("1","3");



    //leer_archivo(lista_animales);

   do{
        mostrar_menu();
        opcion = menu_pedir_opcion();
        menu_validar_opcion(opcion);
        //procesar_opcion(opcion, lista_animales);
    }while(opcion != SALIR);
    
    //delete lista_animales;

    system("pause");
    return 0;
}
