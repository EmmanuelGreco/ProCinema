#include "ArchivoFuncion.h"
#include "Funcion.h"

ArchivoFuncion::ArchivoFuncion(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoFuncion::Guardar(Funcion funcion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&funcion, sizeof(Funcion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoFuncion::Modificar(Funcion funcion, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Funcion) * posicion, SEEK_SET);
    bool ok = fwrite(&funcion, sizeof(Funcion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoFuncion::Buscar(int IdFuncion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Funcion funcion;
    int i = 0;
    while(fread(&funcion, sizeof(Funcion), 1, pArchivo)){
        if(funcion.getIdFuncion() == IdFuncion){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoFuncion::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Funcion);
    fclose(pArchivo);
    return cantidadRegistros;
}

Funcion ArchivoFuncion::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Funcion();
    }
    Funcion funcion;
    fseek(pArchivo, sizeof(Funcion) * posicion, SEEK_SET);
    fread(&funcion, sizeof(Funcion), 1, pArchivo);
    fclose(pArchivo);
    return funcion;
}

int ArchivoFuncion::getUltimoId() {
    FILE *pArchivo;
    Funcion registro;
    registro = Leer(CantidadRegistros()-1);
    return registro.getIdFuncion();
}


// Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
// void ArchivoFuncion::Leer(int cantidadRegistros, Funcion *vector){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return;
//    }
//    for(int i = 0; i < cantidadRegistros; i++){
//        fread(&vector[i], sizeof(Funcion), 1, pArchivo);
//    }
//    fclose(pArchivo);
// }
