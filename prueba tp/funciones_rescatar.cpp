#include "funciones_rescatar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_graficar.h"
#include "Automovil.h"
#include "Grafo.h"


#include <string>



void empezar_a_rescatar(string animales_perdidos)
{
    int salir = 1;

    cout<<"Rescata a los animales!!"<<endl;

        cout<<endl;

        imprimir_referencias();

        cout<<"Tablero original"<<endl;

        graficar_tablero(tablero_original);

        cout<<endl;

        Automovil autito;

        int num_casilla_animal = 0;

        int num_casilla_auto = 0;

        int gasolina_necesaria = 0;

        string casilla_animal;

        string casilla_auto;

        string animal_a_rescatar;

        string tablero_random;

        cout<<"Animales perdidos"<<endl;



        tablero_random = generar_tablero_de_animales_perdidos(animales_perdidos);




    while(salir==1){

        graficar_tablero(tablero_random);

        animal_a_rescatar = elegir_animal_a_rescatar(animales_perdidos);

        num_casilla_animal = obtener_ubicacion(animal_a_rescatar,tablero_random) +1;

        num_casilla_auto = obtener_ubicacion("A",tablero_random) + 1;

        casilla_animal = to_string(num_casilla_animal);

        casilla_auto = to_string(num_casilla_auto);


        int cantidad_de_movimientos = 0;

        int movimientos[100];

        buscar_camino_minimo(casilla_auto,casilla_animal);

        cantidad_de_movimientos = obtener_camino(movimientos);

        gasolina_necesaria = calcular_gasolina_necesaria(movimientos,cantidad_de_movimientos);

        cout<<"El costo de gasolina es de "<<gasolina_necesaria<<endl;

        string respuesta;

        cin.ignore();

        cout<<"Desea realizar el viaje? [s/n]";
        getline(cin,respuesta);



        if (autito.se_puede_viajar(gasolina_necesaria) && respuesta =="s")
            {
                cout<<"Costo gasolina = "<<gasolina_necesaria<<endl;

                cout<<"Camino realizado para rescatar animal"<<endl;

                marcar_camino(tablero_original,cantidad_de_movimientos,movimientos);

                autito.descontar_gasolina_viaje(gasolina_necesaria);

                cout<<"Su nivel de gasolina es "<<autito.get_gasolina()<<endl;

                tablero_random = modificar_tablero_aleatorio(tablero_random,num_casilla_animal,num_casilla_auto);

                casilla_auto = casilla_animal;

                graficar_tablero(tablero_random);



            }
            else
            {
                cout<<"No cuenta con la gasolina suficiente"<<endl;
            }



        cout<<"Ingrese : 1. para rescatar otro animal, 2. para salir";
        cin>>salir;
    }














}

string elegir_animal_a_rescatar(string animales_perdidos)
{

    cout<<"Indique el numero del animal que desea rescatar:  "<<endl;

    string inicial;

    int opcion = 0;

    int largo = animales_perdidos.length();

    if(largo != 0){

        for(int i = 0;i<largo;i++)
        {
            cout<<i<<". "<<animales_perdidos[i]<<endl;
        }
        cout<<"Ingrese la opcion elegida: ";
        cin>>opcion;


    }

    inicial = animales_perdidos[opcion];

    return inicial;


}



