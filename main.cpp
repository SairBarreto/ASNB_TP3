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


    string animales_perdidos = "PEROCL";//String de prueba para rescatar animales

    string animales_rescatados = "z";

    empezar_a_rescatar(animales_perdidos,animales_rescatados);



    return 0;
}
