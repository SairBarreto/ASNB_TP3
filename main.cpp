#include "Grafo.h"
#include <iostream>
#include <conio.h>

#include <cstdlib>

#include "funciones_graficar.h"
#include "funciones_cargar_tablero.h"
#include "funciones_rescatar.h"
#include "colors.h"
//#include "Automovil.h"

using namespace std;

int main() {


    string animales_perdidos;//String de prueba para rescatar animales

    string animales_rescatados;

    //(animales_perdidos,animales_rescatados);

    animales_perdidos = generar_animales_perdidos();



    animales_rescatados = empezar_a_rescatar(animales_perdidos);


    //cout<<"RESCATADOS"<<animales_rescatados;








    return 0;
}
