#pragma once


class ManagerPelicula {
public:
    void cargarPelicula();
    void listarPeliculas();
    void listarPeliculasActivas(bool activas);
    void modificarPelicula();
    void cambiarEstadoPelicula();

    void buscarPorId();
    void buscarPorTitulo();
    void buscarPorGenero();
    void buscarPorApellidoDirector();
    void buscarPorClasificacion();
    void buscarPorFechaEstreno();

    bool validarNumero(int input, int minimo, int maximo);
    bool validarNumero(int input, int minimo);
};
