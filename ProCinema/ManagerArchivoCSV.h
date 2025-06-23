#pragma once


class ManagerArchivoCSV {
public:
    void cargarPeliculasCSV();
    void leerPeliculasCSV();
    void backupPeliculasCSV();
    void restaurarPeliculasCSV();

    void cargarSalasCSV();
    void leerSalasCSV();
    void backupSalasCSV();
    void restaurarSalasCSV();

    void cargarFuncionesCSV();
    void leerFuncionesCSV();
    void backupFuncionesCSV();
    void restaurarFuncionesCSV();

    void cargarMembresiasCSV();
    void leerMembresiasCSV();
    void backupMembresiasCSV();
    void restaurarMembresiasCSV();

    void cargarVentasCSV();
    void leerVentasCSV();
    void backupVentasCSV();
    void restaurarVentasCSV();
};
