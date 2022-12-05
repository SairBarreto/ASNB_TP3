#include "Animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string nombre, int edad, Tamanio* tamanio, string especie, Personalidad* personalidad)
{
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
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
    hambre += 10 * personalidad -> obtener_multiplicador_hambre();
    if(hambre >= 100)
        hambre = 100;
}

void Animal::ensuciar()
{
    higiene -= 10 * personalidad -> obtener_multiplicador_higiene();
    if(higiene <= 0)
        higiene = 0;
}

string Animal::obtener_nombre() {
    return nombre;
}

string Animal::obtener_tamanio() {
    return tamanio -> obtener_tamanio();
}

int Animal::obtener_edad() {
    return edad;
}

string Animal::obtener_especie() {
    return especie;
}

string Animal::obtener_personalidad() {
    return this -> personalidad -> obtener_personalidad();
}

float Animal::obtener_higiene() {
    return higiene;
}

float Animal::obtener_hambre() {
    return hambre;
}

Tamanio* Animal::obtener_tipo_tamanio() {
    return this -> tamanio;
}
