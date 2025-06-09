#pragma once
#include <cstring>
#include "Fecha.h"

class Pelicula {
    private:
        int _idPelicula;
        char _titulo[50];
        char _genero[20];
        char _nombreDirector[50];
        char _apellidoDirector[50];
        int _clasificacion;
        Fecha _fechaEstreno;
        bool _estado;

    public:
        Pelicula();
        Pelicula(int idPelicula, std::string titulo, std::string genero, std::string nombreDirector, std::string apellidoDirector,
                 int clasificacion, Fecha fechaEstreno, bool estado);


        int getIdPelicula();
        std::string getTitulo();
        std::string getGenero();
        std::string getNombreDirector();
        std::string getApellidoDirector();
        int getClasificacion();
        Fecha getFechaEstreno();
        bool getEstado();

        void setIdPelicula(int idPelicula);
        void setTitulo(std::string titulo);
        void setGenero(std::string genero);
        void setNombreDirector(std::string nombreDirector);
        void setApellidoDirector(std::string apellidoDirector);
        void setClasificacion(int clasificacion);
        void setFechaEstreno(Fecha fechaEstreno);
        void setEstado(bool estado);

        std::string mostrar();
};
