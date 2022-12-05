#include "Lagartija.h"

Lagartija::Lagartija(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad) : Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Lagartija::ensuciar() {}

void Lagartija::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Insectos a " << Animal::obtener_nombre() << endl;
}

void Lagartija::baniarse()
{
    cout << Animal::obtener_nombre() << " NO necesita un baño" << endl;
}