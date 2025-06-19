#pragma once
#include <cstring>
#include <string>


class Membresia {
    private:
        int _idMembresia;
        int _tipoMembresia;
        int _descuentoMembresia;
        char _nombreMembresia[15];
        char _nombreMiembro[50];
        char _apellidoMiembro[50];
        int _dniMiembro;
        char _emailMiembro[50];
        bool _estado;

    public:
        Membresia();
        Membresia(int idMembresia, int tipoMembresia, int descuentoMembresia, std::string nombreMembresia, std::string nombreMiembro,
                  std::string apellidoMiembro, int dniMiembro, std::string emailMiembro, bool estado);

        int getIdMembresia();
        int getTipoMembresia();
        int getDescuentoMembresia();
        std::string getNombreMembresia();
        std::string getNombreMiembro();
        std::string getApellidoMiembro();
        int getDniMiembro();
        std::string getEmailMiembro();
        bool getEstado();

        void setIdMembresia(int idMembresia);
        void setTipoMembresia(int tipoMembresia);
        void setDescuentoMembresia(int descuentoMembresia);
        void setNombreMembresia(std::string nombreMembresia);
        void setNombreMiembro(std::string nombreMiembro);
        void setApellidoMiembro(std::string apellidoMiembro);
        void setDniMiembro(int dniMiembro);
        void setEmailMiembro(std::string emailMiembro);
        void setEstado(bool estado);

        std::string mostrar();
};
