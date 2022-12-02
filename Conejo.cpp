#include "Conejo.h"

Conejo::Conejo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Conejo::gastar_energia()
{
    int nuevo_hambre;
    if (personalidad->obtener_personalidad() == "Dormilon")
    {
        nuevo_hambre = hambre + 5;
        if(nuevo_hambre >= 100)
            hambre = 100;
        else
            hambre = nuevo_hambre;
    }
    else if (personalidad->obtener_personalidad() == "Jugueton")
    {
        nuevo_hambre = hambre + 20;
        if(nuevo_hambre >= 100)
            hambre = 100;
        else
            hambre = nuevo_hambre;
    }
    else
    {
        Animal::gastar_energia();
    }
}

void Conejo::ensuciar()
{
    int nuevo_higiene;
    if (personalidad->obtener_personalidad() == "sociable")
    {
        nuevo_higiene = higiene - 5;
        if(nuevo_higiene <= 0)
            higiene = 0;
        else
            higiene = nuevo_higiene;
    }
    else if (personalidad->obtener_personalidad() == "travieso")
    {
        nuevo_higiene = higiene - 20;
        if(nuevo_higiene <= 0)
            higiene = 0;
        else
            higiene = nuevo_higiene;
    }
    else
    {
        Animal::ensuciar();
    }
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