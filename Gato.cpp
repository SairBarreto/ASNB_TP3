#include "Gato.h"

Gato::Gato(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad): Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Gato::gastar_energia()
{
    int nuevo_hambre;
    if (personalidad->obtener_personalidad() == "dormilon")
    {
        nuevo_hambre = hambre + 5;
        if(nuevo_hambre >= 100)
            hambre = 100;
        else
            hambre = nuevo_hambre;
    }
    else if (personalidad->obtener_personalidad() == "jugueton")
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

void Gato::ensuciar(){}

void Gato::alimentarse()
{
    Animal::alimentarse();
    cout << "Se dio de comer Atun a " << Animal::obtener_nombre() << endl;
}

void Gato::baniarse()
{
    cout << Animal::obtener_nombre() << " NO necesita un baño" << endl;
}