#include "Animal.h"
#include <iostream>
using namespace std;


Animal::Animal(string nombre, int edad, string tamanio, string especie,string personalidad)
{
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->hambre = 0;
    this->higiene = 100;
}

void Animal::baniar()
{
    higiene = 100;
}

void Animal::alimentar()
{
    hambre = 0;
}

void Animal::gastar_energia()
{
    int nuevo_hambre = hambre + 10;
    if(nuevo_hambre >= 100)
        hambre = 100;
    else
        hambre = nuevo_hambre;
}

void Animal::ensuciar()
{
    int nuevo_higiene = higiene - 10;
    if(nuevo_higiene <= 0)
        higiene = 0;
    else
        higiene = nuevo_higiene;
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

string Animal::obtener_personalidad() {
    return personalidad;
}

int Animal::obtener_higiene() {
    return higiene;
}

int Animal::obtener_hambre() {
    return hambre;
}
