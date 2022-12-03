#include "Erizo.h"

Erizo::Erizo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Erizo::ensuciar()
{
    Animal::ensuciar();
}

void Erizo::gastar_energia()
{
    Animal::gastar_energia();
}

void Erizo::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Insectos a " << Animal::obtener_nombre() << endl;
}

void Erizo::baniarse()
{
    Animal::baniarse();
    cout << "Se baño a " << Animal::obtener_nombre() << endl;
}