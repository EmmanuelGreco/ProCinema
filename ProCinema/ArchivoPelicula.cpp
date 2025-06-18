#include "ArchivoPelicula.h"
#include "Pelicula.h"

ArchivoPelicula::ArchivoPelicula(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoPelicula::Guardar(Pelicula pelicula){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&pelicula, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoPelicula::Modificar(Pelicula pelicula, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Pelicula) * posicion, SEEK_SET);
    bool ok = fwrite(&pelicula, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoPelicula::Buscar(int IdPelicula){
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

int ArchivoPelicula::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Pelicula);
    fclose(pArchivo);
    return cantidadRegistros;
}

Pelicula ArchivoPelicula::Leer(int posicion){
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

int ArchivoPelicula::getUltimoId() {
    FILE *pArchivo;
    Pelicula registro;
    registro = Leer(CantidadRegistros()-1);
    return registro.getIdPelicula();
}


// Este metodo usa un vector, que no vimos en clase. No creo que necesitemos usar esta funcion tampoco.
// void ArchivoPelicula::Leer(int cantidadRegistros, Pelicula *vector){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return;
//    }
//    for(int i = 0; i < cantidadRegistros; i++){
//        fread(&vector[i], sizeof(Pelicula), 1, pArchivo);
//    }
//    fclose(pArchivo);
// }
