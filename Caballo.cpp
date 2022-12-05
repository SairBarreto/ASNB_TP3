#include "Caballo.h"

Caballo::Caballo(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad): Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Caballo::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Manzanas a " << Animal::obtener_nombre() << endl;
}

void Caballo::baniarse()
{
    Animal::baniarse();
    cout << "Se baño a " << Animal::obtener_nombre() << endl;
}