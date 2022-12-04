#include "funciones_rescatar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_graficar.h"
#include "Automovil.h"
#include "Grafo.h"


#include <string>



void empezar_a_rescatar(string animales_perdidos, string animales_rescatados)
{
    int salir = 1;

    cout<<"Rescata a los animales!!"<<endl;

        cout<<endl;

        imprimir_referencias();

        cout<<"Tablero original"<<endl;


        imprimir_emojis(tablero_original);

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

        imprimir_emojis(tablero_random);

        animal_a_rescatar = elegir_animal_a_rescatar(animales_perdidos,animales_rescatados);

        num_casilla_animal = obtener_ubicacion(animal_a_rescatar,tablero_random) +1;

        num_casilla_auto = obtener_ubicacion("A",tablero_random) + 1;

        casilla_animal = to_string(num_casilla_animal);

        casilla_auto = to_string(num_casilla_auto);


        int cantidad_de_movimientos = 0;

        int movimientos[100];

        buscar_camino_minimo(casilla_auto,casilla_animal);

        cantidad_de_movimientos = obtener_camino(movimientos);

        gasolina_necesaria = calcular_gasolina_necesaria(movimientos,cantidad_de_movimientos);

        cout<<endl;

        cout<<"\nEl costo de gasolina es de "<<gasolina_necesaria<<endl;

        cout<<"\nSu nivel de gasolina es "<<autito.get_gasolina()<<endl;

        string respuesta;

        cout<<endl;

        cin.ignore();

        cout<<"Desea realizar el viaje? [s/n]";
        getline(cin,respuesta);



        if (autito.se_puede_viajar(gasolina_necesaria) && respuesta =="s")
            {
                cout<<"Costo gasolina = "<<gasolina_necesaria<<endl;

                cout<<"\nCamino realizado para rescatar animal"<<endl;

                marcar_camino(tablero_original,cantidad_de_movimientos,movimientos);

                autito.descontar_gasolina_viaje(gasolina_necesaria);

                cout<<"\nSu nivel de gasolina es "<<autito.get_gasolina()<<endl;

                tablero_random = modificar_tablero_aleatorio(tablero_random,num_casilla_animal-1,num_casilla_auto);

                casilla_auto = casilla_animal;

                imprimir_emojis(tablero_random);

                animales_rescatados = animales_rescatados + animal_a_rescatar;



            }
            else
            {
                cout<<"No cuenta con la gasolina suficiente"<<endl;
            }



        cout<<"\n Ingrese : 1. para rescatar otro animal, 2. para salir";
        cin>>salir;
    }


}

bool estado_animal(string animales_perdido, string animales_rescatados)
{
    bool fue_rescatado = false;

    string animal_rescatado;

    int largo_rescatados = animales_rescatados.length();

    for(int i = 0;i<largo_rescatados;i++)
    {
        animal_rescatado = animales_rescatados[i];

        if (animales_perdido == animal_rescatado)
        {
            fue_rescatado = true;
        }
    }

    return fue_rescatado;

}

string elegir_animal_a_rescatar(string animales_perdidos,string animales_rescatados)
{

    cout<<endl;

    cout<<"Indique el numero del animal que desea rescatar:  "<<endl;

    string inicial;

    string letra;

    int opcion = 0;

    int largo = animales_perdidos.length();

    if(largo != 0){

        for(int i = 0;i<largo;i++)
        {
            letra = animales_perdidos[i];

            if(estado_animal(letra,animales_rescatados) == false)
                cout<<i<<". "<<animales_perdidos[i]<<endl;
        }
        cout<<"Ingrese la opcion elegida: ";
        cin>>opcion;


    }

    inicial = animales_perdidos[opcion];

    return inicial;


}


