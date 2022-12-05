#include "Tamanio.h"

Tamanio::Tamanio() {
    this -> tamanio = "cero";
}

string Tamanio::obtener_tamanio() {
    return this -> tamanio;
}

bool Tamanio::hay_espacio_suficiente(int metros_cuadrados) {
    return true;
}
