#include "Hora.h"
#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() {
    setDia(1);
    setMes(1);
    setAnio(1900);
    setHora(Hora(0,0));
}
Fecha::Fecha(int dia, int mes, int anio) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(Hora(0,0));
}
Fecha::Fecha(int dia, int mes, int anio, Hora hora) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(hora);
}
Fecha::Fecha(int dia, int mes, int anio, int hora, int minuto) {
    setDia(dia);
    setMes(mes);
    setAnio(anio);
    setHora(Hora(hora, minuto));
}

int Fecha::getDia() {
    return _dia;
}
int Fecha::getMes() {
    return _mes;
}
int Fecha::getAnio() {
    return _anio;
}
Hora Fecha::getHora() {
    return _hora;
}

void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}
void Fecha::setHora(Hora hora) {
    _hora = hora;
}

bool Fecha::validarFecha() {
    bool valido = true;

    if (_anio < 0 || _anio > 9999) valido = false;
    if (_mes < 1 || _mes > 12) valido = false;
    if (_dia < 1) valido = false;
    if (((_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12) && _dia > 31) ||
            ((_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) && _dia > 30) ||
            (_mes == 2 && _dia > 28)) valido = false;
    if (((_anio % 4 == 0 && _anio % 100 != 0) || _anio % 400 == 0) &&
            (_mes == 2) &&
            (_dia == 29)) valido = true;
    if (_hora.getHora() < 0 && _hora.getHora() > 23) valido = false;
    if (_hora.getMinuto() < 0 && _hora.getMinuto() > 59) valido = false;

    return valido;
}



//1: fecha 2: fecha y hora 3: hora
string Fecha::toString(int opcion) {
    string str;
    if (opcion == 1 || opcion == 2) {
        if (getDia() < 10) str += "0";
        str += to_string(getDia()) + "/";
        if (getMes() < 10) str += "0";
        str += to_string(getMes()) + "/" + to_string(getAnio());
    }

    if (opcion == 2) str += " - ";

    if (opcion == 2 || opcion == 3) {
        if (getHora().getHora() < 10) str += "0";
        str += to_string(getHora().getHora()) + ":";
        if (getHora().getMinuto() < 10) str += "0";
        str += to_string(getHora().getMinuto());
    }
    return str;
}

void Fecha::cargar(int opcion) {
    int dia = 1, mes = 1, anio = 1900;
    if (opcion == 1 || opcion == 2) {
        cout << "Ingrese el numero de dia: ";
        cin >> dia;
        cout << "Ingrese el numero de mes: ";
        cin >> mes;
        cout << "Ingrese el año: ";
        cin >> anio;
    }

    int hora = 0, minuto = 0;
    if(opcion == 2 || opcion == 3) {
        cout << "Ingrese la hora: ";
        cin >> hora;
        cout << "Ingrese el minuto: ";
        cin >> minuto;
    }


    if (Fecha(dia, mes, anio, Hora(hora, minuto)).validarFecha()) {
        setDia(dia);
        setMes(mes);
        setAnio(anio);
        setHora(Hora(hora, minuto));
    } else {
        cout << "Fecha de estreno inválida! Se debera modificar mas tarde" << endl;
    }
}
