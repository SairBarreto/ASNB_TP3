#include "include\crear_animales_aleatorios.h"
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

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
/*
void crear_animales_aleatorios(){
    string especie_str;
    string nombre;
    int edad_str;
    int i;
    string personalidad_str;
    string tamanio_str;

    string animales_perdidos[5];

    for(i = 0; i < 5; i++){ 

        nombre = "NULL"; //pedirle al usuario al adoptarlo que cargue el nombre que desee

        especie_str = generar_especie_rand();
        edad_str = generar_edad_rand();
        tamanio_str = generar_tamanio_rand();
        personalidad_str = generar_personalidades_rand();

        string animales_perdidos[i] = especie_str;

            switch(especie_str){

                    case 'C':
                        {
                        Caballo* caballo = new Caballo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(caballo);
                        break;
                        }

                    case 'O':
                        {
                        Conejo* conejo = new Conejo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(conejo);
                        break;
                        }

                    case 'E':
                        {
                        Erizo* erizo = new Erizo(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(erizo);
                        break;
                        }

                    case 'G':
                        {
                        Gato* gato = new Gato(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(gato);
                        break;
                        }

                    case 'L':
                        {
                        Lagartija* lagartija = new Lagartija(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(lagartija);
                        break;
                        }

                    case 'P':
                        {
                        Perro* perro = new Perro(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(perro);
                        break;
                        }

                    case 'R':
                        {
                        Roedor* rata = new Roedor(nombre, stoi(edad_str), tamanio_str, especie_str, personalidad_str);
                        lista_animales_a_rescatar->agregar_nodo(rata);
                        }

                    default:
                        break;
            }
           
     }
} 
 */ 

