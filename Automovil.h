#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

const int TOPE_GASOLINA = 100;

const int MODIFICADOR_GASOLINA = 5;

class Automovil
{
    public:

        Automovil();

        //POST: devuelve nivel de gasolina
        int get_gasolina();

        //POST: Aumenta 5 pts cuando se selecciona una opcion del menu principal
        void aumentar_nivel_de_gasolina();

        //PRE: Recibe la gasolina necesaria para el viaje
        //POST: Devuelve True si se puede viajar
        bool se_puede_viajar(int);

        //PRE: Recibe la cantidad de gasolina a descontar
        //POST: Descuenta la cantidad de gasolina ingresada
        void descontar_gasolina_viaje(int);


    private:

        int gasolina;


};

#endif // AUTOMOVIL_H
