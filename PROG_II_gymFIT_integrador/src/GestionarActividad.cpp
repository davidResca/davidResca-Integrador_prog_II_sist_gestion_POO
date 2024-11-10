#include "GestionarActividad.h"
#include <iostream>
using namespace std;

// Inicializa el archivo con el tamaño de Actividad
GestionarActividad::GestionarActividad()
    : archivoActividades(sizeof(Actividad)) 
{}

Actividad GestionarActividad::cargarActividad() {
    int idLugarDeDesarrollo, idProfe, cantMax;
    string nombreActividad, descripcion;

    cout << "Ingrese el nombre de la actividad: ";
    cin.ignore();
    getline(cin, nombreActividad);

    cout << "Ingrese el ID del lugar de desarrollo: ";
    cin >> idLugarDeDesarrollo;

    cout << "Ingrese el ID del profesor: ";
    cin >> idProfe;

    cout << "Ingrese la cantidad maxima de inscriptos: ";
    cin >> cantMax;

    cout << "Ingrese la descripcion de la actividad: ";
    cin.ignore();
    getline(cin, descripcion);

    int idActividad = obtenerIdNuevo();
    Actividad nuevaActividad(idActividad, nombreActividad, idLugarDeDesarrollo, idProfe, cantMax, descripcion, true);
    return nuevaActividad;
}

void GestionarActividad::altaActividad() {
    Actividad nuevaActividad = cargarActividad();

    if (archivoActividades.guardar(nuevaActividad)) {
        cout << "Actividad agregada exitosamente.\n";
    }
    else {
        cout << "Error al guardar la actividad.\n";
    }
}

void GestionarActividad::bajaActividad() {
    int id;
    cout << "Ingrese el ID de la actividad a dar de baja: ";
    cin >> id;

    int pos = archivoActividades.buscar(id);
    if (pos >= 0) {
        Actividad actividad = archivoActividades.leerRegistro(pos);
        actividad.setEstado(false);

        if (archivoActividades.modificarRegistro(actividad, pos)) {
            cout << "Actividad dada de baja exitosamente.\n";
        }
        else {
            cout << "Error al dar de baja la actividad.\n";
        }
    }
    else {
        cout << "Actividad no encontrada.\n";
    }
}

void GestionarActividad::listarActividades() {
    if (!archivoActividades.listarRegistro()) {
        cout << "No hay actividades registradas o no se pudo leer el archivo.\n";
    }
}

void GestionarActividad::buscarActividad() {
    int id;
    cout << "Ingrese el ID de la actividad a buscar: ";
    cin >> id;

    int pos = archivoActividades.buscar(id);
    if (pos >= 0) {
        Actividad actividad = archivoActividades.leerRegistro(pos);
        actividad.mostrar();
    }
    else {
        cout << "Actividad no encontrada.\n";
    }
}

int GestionarActividad::obtenerIdNuevo() {
    return Utilidades::obtenerIdNuevo<ActividadesArchivo, Actividad>(archivoActividades);
}
