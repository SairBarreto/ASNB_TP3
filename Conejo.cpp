#include "Conejo.h"

Conejo::Conejo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Conejo::gastar_energia()
{
    Animal::gastar_energia();
}

void Conejo::ensuciar()
{
    Animal::ensuciar();
}

void Conejo::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Lechuga a " << Animal::obtener_nombre() << endl;
}

void Conejo::baniarse()
{
    Animal::baniarse();
    cout << "Se baño a " << Animal::obtener_nombre() << endl;
}