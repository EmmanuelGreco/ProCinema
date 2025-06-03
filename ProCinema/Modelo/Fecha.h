#pragma once
#include "Hora.h"


class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
        Hora _hora;

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes, int anio, Hora hora);

        int getDia();
        int getMes();
        int getAnio();
        Hora getAnio();

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void setAnio(Hora hora);
};
