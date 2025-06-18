#include "Hora.h"






Hora::Hora() {
    setHora(0);
    setMinuto(0);
}

Hora::Hora(int hora, int minuto) {
    setHora(hora);
    setMinuto(minuto);
}

int Hora::getMinuto() {
    return _minuto;
}
int Hora::getHora() {
    return _hora;
}

void Hora::setMinuto(int minuto) {
    if (minuto >= 0 && minuto <= 59) _minuto = minuto;
    else _minuto = 0;
}
void Hora::setHora(int hora) {
    if (hora >= 0 && hora <= 23) _hora = hora;
    else hora = 0;
}
