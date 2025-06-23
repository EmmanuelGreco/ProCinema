#include <iostream>
#include <string>
#include <iomanip>

#include "ManagerInformes.h"

#include "ArchivoPelicula.h"
#include "Pelicula.h"
#include "ArchivoVenta.h"
#include "Venta.h"
#include "ArchivoFuncion.h"
#include "Funcion.h"
#include "ArchivoSala.h"
#include "Sala.h"
#include "ArchivoMembresia.h"
#include "Membresia.h"


using namespace std;


void ManagerInformes::topCinco() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    if (cantidadPeliculas == 0 || cantidadVentas == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }

    ///No se puede hacer un array bidimensional con new. Se harán dos vectores.
    ///En el primero se guarda el id de la pelicula, en el otro su recaudacion.
    float *totalesPeliculas = nullptr;
    int *idsPeliculas = nullptr;
    totalesPeliculas = new float[cantidadPeliculas] {0.0};
    idsPeliculas = new int[cantidadPeliculas] {0};
    if(totalesPeliculas == nullptr || idsPeliculas == nullptr) {
        cout << "No pudo solicitar memoria" << endl;
        exit(-1);
    }


    ///para cada película
    for (int i = 0; i < cantidadPeliculas; i++) {
        Pelicula pelicula = archivoPeliculas.Leer(i);
        idsPeliculas[i] = pelicula.getIdPelicula();
        ///encontrar ventas asociadas y sumar
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);
            Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

            if (idsPeliculas[i] == funcion.getIdPelicula() && venta.getEstado()) totalesPeliculas[i] += venta.getImporteTotal();
        }
    }

    ///ORDENAMIENTO DE VECTORES (BUBBLE)
    for (int i = 0; i < cantidadPeliculas - 1; i++) {
        for (int j = 0; j < cantidadPeliculas - i - 1; j++) {
            if (totalesPeliculas[j] < totalesPeliculas[j + 1]) {
                float temporalTotales = totalesPeliculas[j];
                int temporalIds = idsPeliculas[j];

                totalesPeliculas[j] = totalesPeliculas[j + 1];
                idsPeliculas[j] = idsPeliculas[j + 1];

                totalesPeliculas[j + 1] = temporalTotales;
                idsPeliculas[j + 1] = temporalIds;
            }
        }
    }


    cout << "Top 5 peliculas mas taquilleras de la historia:" << endl << endl;
    if (cantidadPeliculas < 5) {
        for (int i = 0; i < cantidadPeliculas; i++) {
            cout << i + 1 << ". ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
        for (int i = cantidadPeliculas; i < 5; i++) {
            cout << i + 1 << ". --- " << endl;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " - ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
    }

    delete []totalesPeliculas;
    delete []idsPeliculas;
}

void ManagerInformes::topCincoAnual() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    if (cantidadPeliculas == 0 || cantidadVentas == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }


    ///No se puede hacer un array bidimensional con new. Se harán dos vectores.
    ///En el primero se guarda el id de la pelicula, en el otro su recaudacion.
    float *totalesPeliculas = nullptr;
    int *idsPeliculas = nullptr;
    totalesPeliculas = new float[cantidadPeliculas] {0.0};
    idsPeliculas = new int[cantidadPeliculas] {0};
    if(totalesPeliculas == nullptr || idsPeliculas == nullptr) {
        cout << "No pudo solicitar memoria" << endl;
        exit(-1);
    }

    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while (!validarNumero(anioAConsultar, 0, 9999)) {
        cout << "Ingrese un año válido: ";
        cin >> anioAConsultar;
    }
    cout << endl;

    ///para cada película
    for (int i = 0; i < cantidadPeliculas; i++) {
        Pelicula pelicula = archivoPeliculas.Leer(i);
        idsPeliculas[i] = pelicula.getIdPelicula();
        ///encontrar ventas asociadas y sumar
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);

            if (venta.getFechaVenta().getAnio() == anioAConsultar) {
                Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

                if (idsPeliculas[i] == funcion.getIdPelicula() && venta.getEstado()) totalesPeliculas[i] += venta.getImporteTotal();
            }
        }
    }

    ///ORDENAMIENTO DE VECTORES (BUBBLE)
    for (int i = 0; i < cantidadPeliculas - 1; i++) {
        for (int j = 0; j < cantidadPeliculas - i - 1; j++) {
            if (totalesPeliculas[j] < totalesPeliculas[j + 1]) {
                float temporalTotales = totalesPeliculas[j];
                int temporalIds = idsPeliculas[j];

                totalesPeliculas[j] = totalesPeliculas[j + 1];
                idsPeliculas[j] = idsPeliculas[j + 1];

                totalesPeliculas[j + 1] = temporalTotales;
                idsPeliculas[j + 1] = temporalIds;
            }
        }
    }


    cout << "Top 5 peliculas mas taquilleras de la historia:" << endl << endl;
    if (cantidadPeliculas < 5) {
        for (int i = 0; i < cantidadPeliculas; i++) {
            cout << i + 1 << ". ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
        for (int i = cantidadPeliculas; i < 5; i++) {
            cout << i + 1 << ". --- " << endl;
        }
    } else {
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " - ";
            cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
            cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
        }
    }

    delete []totalesPeliculas;
    delete []idsPeliculas;
}

void ManagerInformes::recaudacionPorPelicula() {
    ArchivoPelicula archivoPeliculas("peliculas.dat");
    int cantidadPeliculas = archivoPeliculas.CantidadRegistros();
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    if (cantidadPeliculas == 0 || cantidadVentas == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }

    ///igual que la funcion anterior.
    float *totalesPeliculas = nullptr;
    int *idsPeliculas = nullptr;
    totalesPeliculas = new float[cantidadPeliculas] {0.0};
    idsPeliculas = new int[cantidadPeliculas] {0};
    if(totalesPeliculas == nullptr || idsPeliculas == nullptr) {
        cout << "No pudo solicitar memoria" << endl;
        exit(-1);
    }

    ///para cada película
    for (int i = 0; i < cantidadPeliculas; i++) {
        Pelicula pelicula = archivoPeliculas.Leer(i);
        idsPeliculas[i] = pelicula.getIdPelicula();
        ///encontrar ventas asociadas y sumar
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);
            Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

            if (idsPeliculas[i] == funcion.getIdPelicula() && venta.getEstado()) totalesPeliculas[i] += venta.getImporteTotal();
        }
    }

    cout << "Recaudacion por pelicula:" << endl << endl;
    for (int i = 0; i < cantidadPeliculas; i++) {
        cout << "ID: " << i + 1 << " - ";
        cout << archivoPeliculas.Leer(idsPeliculas[i]).getTitulo() << " - ";
        cout << "$" << fixed << setprecision(2) << totalesPeliculas[i] << endl;
    }

    delete []totalesPeliculas;
    delete []idsPeliculas;
}

void ManagerInformes::recaudacionAnual() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    if (cantidadVentas == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }


    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while (!validarNumero(anioAConsultar, 0, 9999)) {
        cout << "Ingrese un año válido: ";
        cin >> anioAConsultar;
    }
    cout << endl;

    int cantidadEncontrados = 0;
    float totales[13] {}; //en [0] se guarda el total anual, en los otros los de cada mes.
    string meses[12] = {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

    for (int i = 0; i < cantidadVentas; i++) {
        Venta venta = archivoVentas.Leer(i);
        if (venta.getFechaVenta().getAnio() == anioAConsultar && venta.getEstado()) {
            totales[0] += venta.getImporteTotal();
            totales[venta.getFechaVenta().getMes()] += venta.getImporteTotal();
            cantidadEncontrados++;
        }
    }
    if (cantidadEncontrados == 0) {
        cout << "No se encontraron ventas para el año " << anioAConsultar << "!" << endl;
    } else {
        for (int i = 0; i < 13; i++) {
            if (i==0) cout << "Ventas del año " << anioAConsultar << ":" << endl << endl;
            else cout << meses[i-1] << ": $" << fixed << setprecision(2) << totales[i] << endl;
        }
        cout << "Total: $" << totales[0] << endl;
    }
}

void ManagerInformes::recaudacionPorSala() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoSala archivoSalas("salas.dat");
    int cantidadSalas = archivoSalas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    if (cantidadVentas == 0 || cantidadSalas == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }

    float *totalesSalas = nullptr;
    int *idsSalas = nullptr;
    totalesSalas = new float[cantidadSalas] {0.0};
    idsSalas = new int[cantidadSalas] {0};
    if(totalesSalas == nullptr || idsSalas == nullptr) {
        cout << "No se pudo solicitar memoria" << endl;
        exit(-1);
    }

    for (int i = 0; i < cantidadSalas; i++) {
        Sala sala = archivoSalas.Leer(i);
        idsSalas[i] = sala.getIdSala();
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);
            Funcion funcion = archivoFunciones.Leer(venta.getIdFuncion());

            if (idsSalas[i] == funcion.getIdSala()&& venta.getEstado()) totalesSalas[i] += venta.getImporteTotal();
        }
    }



    cout << "Recaudacion por sala:" << endl;
    cout << endl;
    for (int i = 0; i < cantidadSalas; i++) {
        int tipoSala = archivoSalas.Leer(idsSalas[i]).getTipoSala();
        string nombreSala;
        ///mas compacto que un switch
        if (tipoSala == 1) nombreSala = "Standard";
        else if (tipoSala == 2) nombreSala = "Premium";
        else if (tipoSala == 3) nombreSala = "3D";
        else if (tipoSala == 4) nombreSala = "4D";
        else if (tipoSala == 5) nombreSala = "IMAX";

        cout << "Sala N°" << i + 1 << " - ";
        cout << nombreSala << " - ";
        cout << "$" << fixed << setprecision(2) << totalesSalas[i] << endl;
    }

    delete []totalesSalas;
    delete []idsSalas;
}

void ManagerInformes::porcentajeMembresias() {
    ArchivoVenta archivoVentas("ventas.dat");
    int cantidadVentas = archivoVentas.CantidadRegistros();
    ArchivoMembresia archivoMembresias("membresias.dat");
    int cantidadMembresias = archivoMembresias.CantidadRegistros();
    if (cantidadVentas == 0 || cantidadMembresias == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }
    // Hardcodeado
    const int CANT_TIPO_MEMBRESIAS = 4;

    int totalesButacas[CANT_TIPO_MEMBRESIAS] {0};
    float totalesRecaudacion[CANT_TIPO_MEMBRESIAS] {0};
    int idsMembresias[CANT_TIPO_MEMBRESIAS] {0};
    int totalButacas = 0;
    float totalRecaudacion = 0;



    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while (!validarNumero(anioAConsultar, 0, 9999)) {
        cout << "Ingrese un año válido: ";
        cin >> anioAConsultar;
    }
    cout << endl;

    for (int i = 0; i < CANT_TIPO_MEMBRESIAS; i++) {
        idsMembresias[i] = i;
        for (int j = 0; j < cantidadVentas; j++) {
            Venta venta = archivoVentas.Leer(j);

            int tipoAComparar;
            if (venta.getIdMembresia() == 0) tipoAComparar = 0;
            else tipoAComparar = archivoMembresias.Leer(venta.getIdMembresia() - 1).getTipoMembresia();

            if(i == tipoAComparar && venta.getFechaVenta().getAnio() == anioAConsultar && venta.getEstado()) {
                totalesButacas[i] += venta.getCantidadEntradas();
                totalesRecaudacion[i] += venta.getImporteTotal();
            }
        }
    }


    for (int i = 0; i < CANT_TIPO_MEMBRESIAS; i++) {
        totalButacas += totalesButacas[i];
        totalRecaudacion += totalesRecaudacion[i];
    }

    for (int i = 0; i < CANT_TIPO_MEMBRESIAS; i++) {
        string miembro = "";
        if (i==0) miembro = "0. Clientes no registrados";
        else if (i==1) miembro = "1. Plus";
        else if (i==2) miembro = "2. Premium";
        else if (i==3) miembro = "3. VIP";


        float porcentajeRecaudacion, porcentajeButacas;
        porcentajeRecaudacion = (totalesRecaudacion[i] * 100) / totalRecaudacion;
        porcentajeButacas = ((float)totalesButacas[i] * 100) / totalButacas;
        if (totalRecaudacion == 0) porcentajeRecaudacion = 0;
        if (totalButacas == 0) porcentajeButacas = 0;                               ///NO DIVIDAS POR CERO!!!

        cout << miembro << ": " << endl
             << fixed << setprecision(2) << "$" << totalesRecaudacion[i] << " ("
             << fixed << setprecision(2) << porcentajeRecaudacion << "%) - "
             << totalesButacas[i] << " butacas ("
             << fixed << setprecision(2) << porcentajeButacas << "%)"
             << endl << endl;
    }
    cout << "Total vendido en el año " << anioAConsultar << ": $"
         << fixed << setprecision(2) << totalRecaudacion << " - "
         << totalButacas << " butacas" << endl;
}

void ManagerInformes::ocupacionPromedioSala() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadSalas = archivoSalas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadFunciones = archivoFunciones.CantidadRegistros();
    if (cantidadSalas == 0 || cantidadFunciones == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }

    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while (!validarNumero(anioAConsultar, 0, 9999)) {
        cout << "Ingrese un año válido: ";
        cin >> anioAConsultar;
    }
    cout << endl;


    for (int i = 0; i < cantidadSalas; i++) {
        Sala sala = archivoSalas.Leer(i);
        int idSala = sala.getIdSala();
        int butacasTotales = sala.getButacasTotales();

        int totalButacasOcupadas = 0;
        int cantidadFuncionesSala = 0;

        for (int j = 0; j < cantidadFunciones; j++) {
            Funcion funcion = archivoFunciones.Leer(j);

            if (funcion.getIdSala() == idSala && funcion.getFechaFuncion().getAnio() == anioAConsultar) {

                totalButacasOcupadas += (butacasTotales - funcion.getButacasDisponibles());
                cantidadFuncionesSala++;
            }
        }

        if (cantidadFuncionesSala > 0) {
            float porcentajeOcupacionSala = ((float)totalButacasOcupadas * 100) /
                                            (cantidadFuncionesSala * butacasTotales);
            cout << "Sala " << idSala+1 << ": " << fixed << setprecision(2) << porcentajeOcupacionSala << "%" << endl;
        } else {
            cout << "Sala " << idSala+1 << ": Sin funciones en el año " << anioAConsultar << endl;
        }
    }
}

void ManagerInformes::ocupacionMenorFunciones() {
    ArchivoSala archivoSalas("salas.dat");
    int cantidadSalas = archivoSalas.CantidadRegistros();
    ArchivoFuncion archivoFunciones("funciones.dat");
    int cantidadFunciones = archivoFunciones.CantidadRegistros();
    if (cantidadSalas == 0 || cantidadFunciones == 0) {
        cout << "No hay suficiente información para completar la solicitud." << endl;
        return;
    }

    cout << "Ingrese un año para consultar: ";
    int anioAConsultar;
    cin >> anioAConsultar;
    while (!validarNumero(anioAConsultar, 0, 9999)) {
        cout << "Ingrese un año válido: ";
        cin >> anioAConsultar;
    }
    cout << endl;

    int *idFunMenorOcupacion = nullptr;
    float *porcenFunMenorOcupacion = nullptr;
    idFunMenorOcupacion = new int[cantidadFunciones] {0};
    porcenFunMenorOcupacion = new float[cantidadFunciones] {0.0};

    if(idFunMenorOcupacion == nullptr || porcenFunMenorOcupacion == nullptr) {
        cout << "No se pudo solicitar memoria!" << endl;
        exit(-1);
    }

    int cantFunMenorOcupacion = 0;

    for (int i = 0; i < cantidadFunciones; i++) {
        Funcion funcion = archivoFunciones.Leer(i);
        int anioFuncion = funcion.getFechaFuncion().getAnio();

        if (anioFuncion == anioAConsultar) {
            int idSala = funcion.getIdSala();
            Sala sala = archivoSalas.Leer(idSala);

            int butacasTotales = sala.getButacasTotales();
            int butacasDisponibles = funcion.getButacasDisponibles();

            if (butacasTotales > 0) {
                float porcentajeOcupacion = ((float)(butacasTotales - butacasDisponibles) *100) / butacasTotales;

                if (porcentajeOcupacion < 50) {
                    idFunMenorOcupacion[cantFunMenorOcupacion] = funcion.getIdFuncion();
                    porcenFunMenorOcupacion[cantFunMenorOcupacion] = porcentajeOcupacion;
                    cantFunMenorOcupacion++;
                }
            }
        }
    }


    if (cantFunMenorOcupacion == 0) {
        cout << "No hay Funciones con Ocupación menor al 50%, en el año " << anioAConsultar << endl;
    } else {
        for (int i = 0; i < cantFunMenorOcupacion; i++) {
            Funcion funcion = archivoFunciones.Leer(idFunMenorOcupacion[i]);

            cout << " ID Función: " << funcion.getIdFuncion() + 1
                 << " - ID Sala: " << funcion.getIdSala() + 1
                 << " - Porcentaje Ocupación: " << fixed << setprecision(2) << porcenFunMenorOcupacion[i] << "%" << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }

    delete []idFunMenorOcupacion;
    delete []porcenFunMenorOcupacion;
}

bool ManagerInformes::validarNumero(int input, int minimo, int maximo) {
    if (cin.fail()) {
        cin.clear();
        while (cin.get() != '\n');
        return false;
    } else {
        return (input >= minimo && input <= maximo);
    }
}

