#include "Perro.h"

Perro:: Perro(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad) : Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

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