#pragma once


class ManagerInformes {
public:
    void topCinco();
    void topCincoAnual();
    void recaudacionPorPelicula();
    void recaudacionAnual();
    void recaudacionPorSala();
    void porcentajeMembresias();
    //void miembrosMasFrecuentes();
    void ocupacionPromedioSala();
    void ocupacionMenorFunciones();

    bool validarNumero(int input, int minimo, int maximo);
};
