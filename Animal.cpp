#include "Animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string nombre, int edad, string tamanio, string especie,string personalidad)
{
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = new Personalidad(personalidad);
    this->hambre = 0;
    this->higiene = 100;
}

void Animal::baniarse()
{
    higiene = 100;
}

void Animal::alimentarse()
{
    hambre = 0;
}

void Animal::gastar_energia()
{
    float nuevo_hambre = (float)hambre + 10 * personalidad->obtener_multiplicador();
    if(nuevo_hambre >= 100)
        hambre = 100;
    else
        hambre = (int)nuevo_hambre;
}

void Animal::ensuciar()
{
    float nuevo_higiene = (float)higiene - 10 * personalidad->obtener_multiplicador();
    if(nuevo_higiene <= 0)
        higiene = 0;
    else
        higiene = (int)nuevo_higiene;
}

string Animal::obtener_nombre() {
    return nombre;
}

string Animal::obtener_tamanio() {
    return tamanio;
}

int Animal::obtener_edad() {
    return edad;
}

string Animal::obtener_especie() {
    return especie;
}

Personalidad* Animal::obtener_personalidad() {
    return personalidad;
}

int Animal::obtener_higiene() {
    return higiene;
}

int Animal::obtener_hambre() {
    return hambre;
}
