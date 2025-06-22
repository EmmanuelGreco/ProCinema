#pragma once


class ManagerInformes {
public:
    void topCinco();
    void recaudacionPorPelicula();
    void recaudacionAnual();
    void recaudacionPorSala();
    void porcentajeMiembros();
    //void miembrosMasFrecuentes();
    void ocupacionPromedioSala();

    bool validarNumero(int input, int minimo, int maximo);
};
