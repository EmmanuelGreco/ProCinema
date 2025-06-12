#include "ArchivoSala.h"
#include "Sala.h"

ArchivoSala::ArchivoSala(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoSala::Guardar(Sala sala){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&sala, sizeof(Sala), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoSala::Modificar(Sala sala, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Sala) * posicion, SEEK_SET);
    bool ok = fwrite(&sala, sizeof(Sala), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoSala::Buscar(int IdSala){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Sala sala;
    int i = 0;
    while(fread(&sala, sizeof(Sala), 1, pArchivo)){
        if(sala.getIdSala() == IdSala){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoSala::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Sala);
    fclose(pArchivo);
    return cantidadRegistros;
}

Sala ArchivoSala::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Sala();
    }
    Sala sala;
    fseek(pArchivo, sizeof(Sala) * posicion, SEEK_SET);
    fread(&sala, sizeof(Sala), 1, pArchivo);
    fclose(pArchivo);
    return sala;
}

int ArchivoSala::getUltimoId() {
    FILE *pArchivo;
    Sala reg;
    reg = Leer(CantidadRegistros()-1);
    return reg.getIdSala();
}


// Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
// void ArchivoSala::Leer(int cantidadRegistros, Sala *vector){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return;
//    }
//    for(int i = 0; i < cantidadRegistros; i++){
//        fread(&vector[i], sizeof(Sala), 1, pArchivo);
//    }
//    fclose(pArchivo);
//}
