#include "Automovil.h"

Automovil::Automovil()
{
    gasolina = 100;
}


bool Automovil::se_puede_viajar(int gasolina_requerida)
{
    bool alcanza = false;

    if(gasolina >= gasolina_requerida)
    {
        alcanza = true;
    }

    return alcanza;
}

int Automovil::get_gasolina()
{
    return gasolina;
}

void Automovil::aumentar_nivel_de_gasolina()
{


    if((gasolina + MODIFICADOR_GASOLINA)<TOPE_GASOLINA)
    {
        gasolina = gasolina + MODIFICADOR_GASOLINA;
    }
    else if((gasolina + MODIFICADOR_GASOLINA)>TOPE_GASOLINA)
    {
        gasolina  = TOPE_GASOLINA;
    }


}


void Automovil::descontar_gasolina_viaje(int gasolina_requerida)
{
    gasolina = gasolina - gasolina_requerida;
}

void Automovil::cargar_gasolina(int gasolina_cargada)
{
    if((gasolina + gasolina_cargada)<TOPE_GASOLINA)
    {
        gasolina = gasolina + gasolina_cargada;
    }
    else if((gasolina + gasolina_cargada)>TOPE_GASOLINA)
    {
        gasolina  = TOPE_GASOLINA;
    }
}



