#include "Automovil.h"
#include <iostream>

using namespace std;

Automovil::Automovil()
{
    combustible = 100;
}

void Automovil::gastar_combustible(int peso){
    
    combustible = combustible - peso;
    
}
void Automovil::cargar_combustible()
{
    combustible = combustible + 5;
}
int Automovil::obtener_nivel_de_combustible()
{
    return combustible;
}
