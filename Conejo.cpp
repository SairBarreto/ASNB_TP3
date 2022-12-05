#include "Conejo.h"

Conejo::Conejo(string _nombre, int _edad, string _tamanio, string _especie, Personalidad* _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

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