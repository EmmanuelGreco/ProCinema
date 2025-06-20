#pragma once


class ManagerPelicula {
public:
    void cargarPelicula();
    void listarPeliculas();
    void modificarPelicula();
    void cambiarEstadoPelicula();


    void buscarPorId();
    void buscarPorTitulo();
    void buscarPorGenero();
    void buscarPorApellidoDirector();
    void buscarPorClasificacion();
    void buscarPorFechaEstreno();
};
