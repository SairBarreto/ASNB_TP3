#include "funciones_rescatar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_graficar.h"
#include "Automovil.h"
#include "Grafo.h"
#include "animal_handler.h"
#include "ABB.h"
#include "Animal.h"


//#include <ctype.h>
#include <string>



string empezar_a_rescatar(string animales_perdidos,Automovil autito)
{
    int salir = 1;

    string buffer;

    int cantidad_de_animales_rescatados = 0;

    string animales_rescatados;

    animales_rescatados ="z";

    cout<<"Rescata a los animales!!"<<endl;

    cout<<endl;

    imprimir_referencias();

    cout<<"Tablero original"<<endl;

        //graficar_tablero(tablero_original);
    imprimir_emojis(tablero_original);

    cout<<endl;

    //Automovil autito;

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

        //cin.ignore();

        cout<<"Desea realizar el viaje? [s/n]";
        getline(cin >> ws,respuesta);


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

                cantidad_de_animales_rescatados ++;

            }
            else
            {
                cout<<"No cuenta con la gasolina suficiente"<<endl;
            }


        if(cantidad_de_animales_rescatados<5)
        {

            /*cout<<"\n Ingrese : 1. para rescatar otro animal, 2. para salir";
            getline(cin >> ws, buffer);
            salir = stoi(buffer);*/
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

   /* cout<<endl;

    cout<<"Indique el numero del animal que desea rescatar:  "<<endl;

    string inicial;

    string letra;

    string buffer;

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
        cin >> opcion;
        if(!isdigit(opcion)) {
            cout << "Opcion invalida, se elige el 0." << endl;
            opcion = 0;
        }
    }

    inicial = animales_perdidos[opcion];

    return inicial;*/
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

    return especie_str;
}

int generar_edad_rand(){
    srand((unsigned) time(NULL));

    int edad_str = 1 + (rand() % 100);

    return edad_str;

}

void terminar_de_rescatar(ABB<Animal>* arbol_animales,Automovil autito){

    string animales_rescatados;

    string animales_perdidos;

    string nombre_ingresado;

    string animal;

    string edad_str,tamanio_nuevo,personalidad_nueva;

    string especie_nueva;

    int edad_int = 0;

    int largo = 0;

    animales_perdidos = generar_animales_perdidos();

    animales_rescatados = empezar_a_rescatar(animales_perdidos,autito);

    largo = calcular_largo(animales_rescatados);

    string animales_inicial;

    for(int i = 1; i < largo; i++)

        {
            cout<<animales_rescatados<<endl;
            animales_inicial = animales_rescatados[i];

            especie_nueva = especie_inicial_a_string(animales_inicial);

            cout << "Ingrese un nombre para el " << especie_nueva << " que acaba de rescatar: " << endl;
            getline(cin >> ws, nombre_ingresado);

            Animal* animal = arbol_animales -> buscar(nombre_ingresado);

            if(animal != nullptr) {
                cout << "Ese nombre ya esta en la usado" << endl;
                cout << "Ingrese otro nombre: " << endl;
                getline(cin >> ws, nombre_ingresado);
            }

            edad_int = generar_edad_rand();

            edad_str = to_string(edad_int);

            tamanio_nuevo = generar_tamanio_rand();

            personalidad_nueva = generar_personalidades_rand();

            string especie; 
            especie.append(1,especie_nueva[0]);

            agregar_animal_a_arbol(nombre_ingresado,edad_str,tamanio_nuevo,especie,personalidad_nueva,arbol_animales);

    }

    cout<<"Animales rescatados !!";
}


//FUNCION NUEVA SI FUNCIONA LO DE NICO













