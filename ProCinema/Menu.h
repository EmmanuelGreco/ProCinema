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
    void BuscarVentasPor();
    void peliculas();
    void listarPeliculasPor();
    void BuscarPeliculasPor();
    void funciones();
    void ListarFuncionPor();
    void BuscarFuncionPor();
    void informes();
    void RecaudacionTotalPor();
    void configuracion();
    void configuracionSalas();
    void listarSalasPor();
    void configuracionMembresias();
    void listarMembresiasPor();
    void configuracionOpciones(std::string queMenuEs);
    void recibirOpcion(int maximo);
    bool opcionValida(int opcion, int maximo);
};
