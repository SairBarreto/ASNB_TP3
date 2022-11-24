#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H


class Automovil
{
    public:
        Automovil();

        int get_gasolina();

        void aumentar_nivel_de_gasolina();

        bool se_puede_viajar(int);

        void descontar_gasolina_viaje(int);


    private:

        int gasolina;


};

#endif // AUTOMOVIL_H
