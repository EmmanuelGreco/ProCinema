#pragma once
#include "Hora.h"
#include <string>


class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;
    Hora _hora;

    bool validarFecha(int dia, int mes, int anio);
    void AgregarDia();
    void RestarDia();

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha(int dia, int mes, int anio, Hora hora);
    Fecha(int dia, int mes, int anio, int hora, int minuto);

    int getDia();
    int getMes();
    int getAnio();
    Hora getHora();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setHora(Hora hora);

    void AgregarDias(int cant);
    //1: fecha 2: fecha y hora 3: hora
    std::string toString(int opcion);
};

