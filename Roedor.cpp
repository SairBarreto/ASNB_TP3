#include "Roedor.h"

Roedor::Roedor(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Roedor::gastar_energia()
{
    Animal::gastar_energia();
}

void Roedor::ensuciar(){}

void Roedor::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Queso a " << Animal::obtener_nombre() << endl;
}

void Roedor::baniarse()
{
    cout << Animal::obtener_nombre() << " NO necesita un baño" << endl;
}