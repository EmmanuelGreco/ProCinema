#pragma once

class Hora{
    private:
        int _minuto;
        int _hora;

    public:
        Hora();
        Hora(int hora, int minuto);

        int getMinuto();
        int getHora();

        void setMinuto(int minuto);
        void setHora(int hora);
};
