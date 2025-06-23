#pragma once
#include <string>

class Menu {
private:
    int _opcion;
public:
    //void menuPrincipal();
    void menuVentas();
    void menuPeliculas();
    void menuFunciones();
    void menuMembresia();
    void menuInformes();
    void menuConfiguracion();
    void menuCreditos();


    void setOpcion(int opcion);
    int getOpcion();
    void recibirOpcion(int maximo);
    bool opcionValida(int opcion, int maximo);
    void menuBienvendidaImprimir();
    void principal();
    void ventas();
    void buscarVentasPor();
    void peliculas();
    void listarPeliculasPor();
    void buscarPeliculasPor();
    void funciones();
    void listarFuncionPor();
    void buscarFuncionPor();
    void membresias();
    void listarMembresiasPor();
    void buscarMembresiasPor();
    void informes();
    void recaudacionTotalPor();
    void configuracion();
    void configuracionSalas();
    void listarSalasPor();
    void configuracionCSV();
    void archivosCSVLeer();
    void archivosCSVCargar();
    void imprimirOpcionesCSV();
    void creditosImprimir();
    bool verificarContrasena(const std::string &contrasenaIngresada);
};
