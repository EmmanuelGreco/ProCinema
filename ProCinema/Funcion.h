#pragma once
#include <cstring>
#include <string>
#include "Fecha.h"

class Funcion {
    private:
        int _idFuncion;
        int _idPelicula;
        int _idSala;
        int _butacasDisponibles;
        int _idiomaFuncion;
        Fecha _fechaFuncion;
        float _importeFuncion;
        bool _estado;

    public:
        Funcion();
        Funcion(int idFuncion, int idPelicula, int idSala, int butacasDisponibles, int idiomaFuncion,
                Fecha fechaFuncion, float importeFuncion, bool estado);

        int getIdFuncion();
        int getIdPelicula();
        int getIdSala();
        int getButacasDisponibles();
        int getIdiomaFuncion();
        Fecha getFechaFuncion();
        float getImporteFuncion();
        bool getEstado();

        void setIdFuncion(int idFuncion);
        void setIdPelicula(int idPelicula);
        void setIdSala(int idSala);
        void setButacasDisponibles(int butacasDisponibles);
        void setIdiomaFuncion(int idiomaFuncion);
        void setFechaFuncion(Fecha fechaFuncion);
        void setImporteFuncion(float importeFuncion);
        void setEstado(bool estado);

        Funcion operator +=(int cantidadButacas);
        Funcion operator -=(int cantidadButacas);

        std::string mostrar();
};
