#pragma once


class ManagerMembresia {
public:
    void cargarMembresia();
    void listarMembresias();
    void listarMembresiasActivas(bool activas);
    void modificarMembresia();
    void cambiarEstadoMembresia();

    bool validarNumero(int input, int minimo, int maximo);
    bool validarNumero(int input, int minimo);
};
