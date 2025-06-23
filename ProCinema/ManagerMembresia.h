#pragma once


class ManagerMembresia {
public:
    void cargarMembresia();
    void listarMembresias();
    void listarMembresias(bool activas);
    void modificarMembresia();
    void cambiarEstadoMembresia();

    void buscarPorId();
    void buscarPorDNI();

    bool validarNumero(int input, int minimo, int maximo);
    bool validarNumero(int input, int minimo);
};
