#ifndef ANIMAL_H
#define ANIMAL_H

#include "Personalidad.h"

#include <iostream>
using namespace std;
//nombre,edad,tama�o,especie,personalidad
class Animal
{
    protected:
        string nombre;
        int edad;
        string tamanio;
        string especie;
        Personalidad* personalidad;
        float hambre;
        float higiene;

    public:
        
        //PRE: -    
        //POS: Carga y crea objeto Animal
        Animal(string nombre, int edad, string tamanio, string especie,Personalidad* personalidad);

        //PRE: -
        //POS: Disminuye en -10 la higiene, si ya esta menor de 0 la deja en 0
        virtual void ensuciar();

        //PRE: -    
        //POS: Aumenta el hambre en +10, si ya tiene mas hambre que 100 la deja en 100
        virtual void gastar_energia();//aumenta niveles de hambre
        
        //PRE: -    
        //POS: Higiene al 100
        void baniar();

        //PRE: -    
        //POS: Hambre al 0
        void alimentar();

        //PRE: -    
        //POS: Retorna el nombre del animal
        string obtener_nombre();

        //PRE: -    
        //POS: Retorna la higiene del animal
        float obtener_higiene();  

        //PRE: -    
        //POS: Retorna el hambre del animal
        float obtener_hambre(); 

        //PRE: -    
        //POS: Destructor
        virtual ~Animal(){};

        //PRE: -    
        //POS: Retorna tamanio de animal
        string obtener_tamanio();

        //PRE: -    
        //POS: Retorna edad del animal
        int obtener_edad();

        //PRE: -    
        //POS: Retorna especie del animal
        string obtener_especie();

        //PRE: -    
        //POS: Retorna personalidad del animal
        string obtener_personalidad();
};

#endif // ANIMAL_H
