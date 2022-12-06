#include "funciones_rescatar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_graficar.h"
#include "Automovil.h"
#include "Grafo.h"

#include <ctype.h>
#include <string>



string empezar_a_rescatar(string animales_perdidos)
{
    int salir = 1;

    int cantidad_de_animales_rescatados = 0;

    string animales_rescatados;

    cout<<"Rescata a los animales!!"<<endl;

        cout<<endl;

        imprimir_referencias();

        cout<<"Tablero original"<<endl;

        //graficar_tablero(tablero_original);
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


    while(salir==1 && cantidad_de_animales_rescatados<5){

        //graficar_tablero(tablero_random);

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

                //graficar_tablero(tablero_random);

                imprimir_emojis(tablero_random);

                animales_rescatados = animales_rescatados + animal_a_rescatar;

                cantidad_de_animales_rescatados ++;





            }
            else
            {
                cout<<"No cuenta con la gasolina suficiente"<<endl;
            }


        if(cantidad_de_animales_rescatados<5)
        {

            cout<<"\n Ingrese : 1. para rescatar otro animal, 2. para salir";
            cin>>salir;

        }
    }

    return animales_rescatados;

}

int calcular_largo(string palabra)
{
    int contador = 0;
    while(palabra[contador] !='\0')
    {
        contador++;
    }
    return contador;
}


bool estado_animal(string animales_perdido, string animales_rescatados)
{
    bool fue_rescatado = false;

    string animal_rescatado;

    int largo_rescatados = calcular_largo(animales_rescatados);

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

    int largo = calcular_largo(animales_perdidos);

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

//FUNCIONES NICO

/*

string generar_tamanio_rand(){
    string tamanio_str;

    srand((unsigned) time(NULL));

    int random =  (rand() % 5);

    tamanio_str = TAMANIOS_STR[random];

    return tamanio_str;
}

string generar_personalidades_rand(){
    string personalidad_str;

    srand((unsigned) time(NULL));

    int random =  (rand() % 4);

    personalidad_str = PERSONALIDADES[random];

    return personalidad_str;


}

string generar_especie_rand(){
    string especie_str;

    srand((unsigned) time(NULL));

    int random =  (rand() % 7);

    especie_str = INICIALES_ESPECIES_STR[random];

    return especie_nuevo;
}

int generar_edad_rand(){
    srand((unsigned) time(NULL));

    int edad_str = 1 + (rand() % 100);

    return edad_str;

}

void terminar_de_rescatar(ABB<Animal>* arbol_animales, string animales_rescatados){
    string nombre_ingresado;
    Animal* animal;

    for(i = 0; i < animales_rescatados.size(); i++){
        cout << "Ingrese el nombre del " << string_a_especie_t(animales_rescatados[i]) << "que desea rescatar" << endl;
        getline(cin >> ws, nombre_ingresado);

        animal -> nombre = nombre_ingresado;
        animal -> especie = generar_especie_rand();
        animal -> edad = generar_edad_rand();
        animal -> tamanio = generar_tamanio_rand();
        animal -> personalidad = generar_personalidades_rand();

        arbol_animales -> insertar(animal, nombre_ingresado);
    }
}
//FUNCION NUEVA SI FUNCIONA LO DE NICO

/*




void rescatar(ABB<Animal>* arbol_animales, string animales_perdidos)
{

    string animales_rescatados;

    animales_rescatados =  empezar_a_rescatar(animales_perdidos);

    terminar_de_rescatar(arbol_animales,animales_rescatados);


}



*/






