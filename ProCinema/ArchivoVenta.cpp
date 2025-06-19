#include "ArchivoVenta.h"
#include "Venta.h"

ArchivoVenta::ArchivoVenta(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoVenta::Guardar(Venta venta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoVenta::Modificar(Venta venta, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    bool ok = fwrite(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoVenta::Buscar(int IdVenta){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Venta venta;
    int i = 0;
    while(fread(&venta, sizeof(Venta), 1, pArchivo)){
        if(venta.getIdVenta() == IdVenta){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoVenta::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Venta);
    fclose(pArchivo);
    return cantidadRegistros;
}

Venta ArchivoVenta::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Venta();
    }
    Venta venta;
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    fread(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return venta;
}

int ArchivoVenta::getUltimoId() {
    FILE *pArchivo;
    Venta registro;
    registro = Leer(CantidadRegistros()-1);
    return registro.getIdVenta();
}
