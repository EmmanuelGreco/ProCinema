#pragma once
#include <string>

class Menu {
private:
    int _opcion;
public:
    void setOpcion(int opcion);
    int getOpcion();
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
    void archivosCSV();
    //void configuracionOpciones(std::string queMenuEs);
    void recibirOpcion(int maximo);
    bool opcionValida(int opcion, int maximo);
};
