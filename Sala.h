#pragma once


class Sala {
    private:
        int _idSala;
        int _tipoSala;
        int _butacasTotales;
        bool _estado;

    public:
        Sala();
        Sala(int idSala, int tipoSala, int butacasTotales, bool estado);

        int getIdSala();
        int getTipoSala();
        int getButacasTotales();
        bool getEstado();

        void setIdPelicula(int idSala);
        void setTipoSala(int tipoSala);
        void setButacasTotales(int butacasTotales);
        void setEstado(bool estado);
};
