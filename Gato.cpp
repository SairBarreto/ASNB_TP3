#include "Gato.h"

Gato::Gato(string _nombre, int _edad, Tamanio* _tamanio, string _especie, Personalidad* _personalidad): Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Gato::ensuciar() {}

void Gato::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Atun a " << Animal::obtener_nombre() << endl;
}

void Gato::baniarse()
{
    cout << Animal::obtener_nombre() << " NO necesita un baño" << endl;
}