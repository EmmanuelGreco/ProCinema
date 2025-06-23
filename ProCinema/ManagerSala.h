#pragma once


class ManagerSala {
public:
    void cargarSala();
    void listarSalas();
    void listarSalas(bool activas);
    void modificarSala();
    void cambiarEstadoSala();

    bool validarNumero(int input, int minimo, int maximo);
    bool validarNumero(int input, int minimo);


};
