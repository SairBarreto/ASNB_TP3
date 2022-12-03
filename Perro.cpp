#include "Perro.h"

Perro:: Perro(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad) : Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Perro::ensuciar()
{
    Animal::ensuciar();
}

void Perro ::gastar_energia()
{
    Animal::gastar_energia();
}

void Perro::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Huesos a " << Animal::obtener_nombre() << endl;
}

void Perro::baniarse()
{
    Animal::baniarse();
    cout << "Se baño a " << Animal::obtener_nombre() << endl;
}