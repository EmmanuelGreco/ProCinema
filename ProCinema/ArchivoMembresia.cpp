#include "ArchivoMembresia.h"
#include "Membresia.h"

ArchivoMembresia::ArchivoMembresia(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoMembresia::Guardar(Membresia membresia){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&membresia, sizeof(Membresia), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoMembresia::Modificar(Membresia membresia, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Membresia) * posicion, SEEK_SET);
    bool ok = fwrite(&membresia, sizeof(Membresia), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoMembresia::Buscar(int IdMembresia){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Membresia membresia;
    int i = 0;
    while(fread(&membresia, sizeof(Membresia), 1, pArchivo)){
        if(membresia.getIdMembresia() == IdMembresia){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoMembresia::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Membresia);
    fclose(pArchivo);
    return cantidadRegistros;
}

Membresia ArchivoMembresia::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Membresia();
    }
    Membresia membresia;
    fseek(pArchivo, sizeof(Membresia) * posicion, SEEK_SET);
    fread(&membresia, sizeof(Membresia), 1, pArchivo);
    fclose(pArchivo);
    return membresia;
}

int ArchivoMembresia::getUltimoId() {
    FILE *pArchivo;
    Membresia registro;
    registro = Leer(CantidadRegistros()-1);
    return registro.getIdMembresia();
}


// Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
// void ArchivoMembresia::Leer(int cantidadRegistros, Membresia *vector){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return;
//    }
//    for(int i = 0; i < cantidadRegistros; i++){
//        fread(&vector[i], sizeof(Membresia), 1, pArchivo);
//    }
//    fclose(pArchivo);
// }
