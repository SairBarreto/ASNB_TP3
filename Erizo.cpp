#include "Erizo.h"

Erizo::Erizo(string _nombre, int _edad, string _tamanio, string _especie, string _personalidad):Animal(_nombre,_edad,_tamanio,_especie,_personalidad)
{

}

void Erizo::ensuciar()
{
    int nuevo_higiene;
    if (personalidad=="sociable")
    {
        nuevo_higiene = higiene - 5;
        if(nuevo_higiene <= 0)
            higiene = 0;
        else
            higiene = nuevo_higiene;
    }
    else if (personalidad == "travieso")
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

void Erizo::gastar_energia()
{
    int nuevo_hambre;
    if (personalidad == "dormilon")
    {
        nuevo_hambre = hambre + 5;
        if(nuevo_hambre >= 100)
            hambre = 100;
        else
            hambre = nuevo_hambre;
    }
    else if (personalidad == "jugueton")
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