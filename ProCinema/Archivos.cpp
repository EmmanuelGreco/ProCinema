#include "Pelicula.h"
#include "Archivos.h"

Archivos::Archivos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool Archivos::Guardar(Pelicula pelicula){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&pelicula, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool Archivos::Guardar(Pelicula pelicula, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Pelicula) * posicion, SEEK_SET);
    bool ok = fwrite(&pelicula, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int Archivos::Buscar(int IdPelicula){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Pelicula pelicula;
    int i = 0;
    while(fread(&pelicula, sizeof(Pelicula), 1, pArchivo)){
        if(pelicula.getIdPelicula() == IdPelicula){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int Archivos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Pelicula);
    fclose(pArchivo);
    return cantidadRegistros;
}

Pelicula Archivos::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Pelicula();
    }
    Pelicula pelicula;
    fseek(pArchivo, sizeof(Pelicula) * posicion, SEEK_SET);
    fread(&pelicula, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return pelicula;
}

int Archivos::getUltimoId() {
    FILE *pArchivo;
    Pelicula reg;
    reg = Leer(CantidadRegistros()-1);
    return reg.getIdPelicula();
}


// Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
//void Archivos::Leer(int cantidadRegistros, Pelicula *vector){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return;
//    }
//    for(int i = 0; i < cantidadRegistros; i++){
//        fread(&vector[i], sizeof(Pelicula), 1, pArchivo);
//    }
//    fclose(pArchivo);
//}
