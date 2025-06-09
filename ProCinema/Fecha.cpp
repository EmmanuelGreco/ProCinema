#include "Hora.h"
#include "Fecha.h"
#include <cstring>
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

bool Fecha::validarFecha(int dia, int mes, int anio) {
    bool valido = true;

    if (anio < 0 || anio > 9999) valido = false;
    if (mes < 1 || mes > 12) valido = false;
    if (dia < 1) valido = false;
    if (((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31) ||
            ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) ||
            (mes == 2 && dia > 28)) valido = false;
    if (((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) &&
            (mes == 2) &&
            (dia == 29)) valido = true;

    return valido;
}

void Fecha::AgregarDia() {
    if (validarFecha(getDia()+1,getMes(),getAnio())) {
        setDia(getDia() + 1);
    } else if (validarFecha(1,getMes()+1,getAnio())) {
        setDia(1);
        setMes(getMes()+1);
    } else if (validarFecha(1,1,getAnio()+1)) {
        setDia(1);
        setMes(1);
        setAnio(getAnio()+1);
    }
}

void Fecha::RestarDia() {
    if (validarFecha(getDia()-1,getMes(),getAnio())) {
        setDia(getDia() - 1);
    } else if (validarFecha(31,getMes()-1,getAnio())) {
        setDia(31);
        setMes(getMes()-1);
    } else if (validarFecha(30,getMes()-1,getAnio())) {
        setDia(30);
        setMes(getMes()-1);
    } else if (validarFecha(29,getMes()-1,getAnio())) {
        setDia(29);
        setMes(getMes()-1);
    } else if (validarFecha(28,getMes()-1,getAnio())) {
        setDia(28);
        setMes(getMes()-1);
    } else if (validarFecha(31,12,getAnio()-1)) {
        setDia(31);
        setMes(12);
        setAnio(getAnio()-1);
    }
}

void Fecha::AgregarDias(int cant) {
    if (cant > 0) {
        for (int i = 0; i < cant; i++) {
            AgregarDia();
        }
    } else if (cant < 0) {
        for (int i = 0; i < (cant*-1); i++) {
            RestarDia();
        }
    } else {
        return;
    }
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
