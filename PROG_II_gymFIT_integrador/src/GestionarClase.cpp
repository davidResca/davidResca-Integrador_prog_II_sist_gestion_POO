#include "GestionarClase.h"
#include <iostream>
#include "Utilidades.h"

using namespace std;

GestionarClase::GestionarClase() : clasesArchivo(sizeof(Actividad)) {}

void GestionarClase::cargarClase()
{
	int idClase = obtenerIdNuevo();
	int idActividad,idProfe,cantidadInscriptos,cantMax;
	string nombreActividad, descripcion;
	int idLugarDeDesarrollo;
    bool estado = true;


    cout << "Ingrese el nombre de la actividad: ";
    cin >> nombreActividad;

    cout << "Ingrese el ID de la actividad: ";
    cin >> idActividad;

    cout << "Ingrese el ID del lugar de desarrollo: ";
    cin >> idLugarDeDesarrollo;

    cout << "Ingrese el ID del profesor: ";
    cin >> idProfe;

    cout << "Ingrese la cantidad de inscriptos: ";
    cin >> cantidadInscriptos;

    cout << "Ingrese la cantidad maxima de inscriptos: ";
    cin >> cantMax;

    cout << "Ingrese la descripcion: ";
    cin.ignore();
    getline(cin, descripcion);

    // idActividad, actividadNombre, idLugarDeDesarrollo, idProfe, cantMax, descripcion, estado
    Actividad nuevaClase(idActividad, nombreActividad, idLugarDeDesarrollo, idProfe, cantMax, descripcion, estado);

    if (clasesArchivo.guardar(nuevaClase)) {
        cout << "Clase agregada exitosamente.\n";
    }
    else {
        cout << "Error al guardar la clase.\n";
    }
}

void GestionarClase::bajaClase() {
    int id;
    cout << "Ingrese el ID de la clase a dar de baja: ";
    cin >> id;

    int pos = clasesArchivo.buscar(id);

    if (pos >= 0) {
        Actividad clase = clasesArchivo.leerRegistro(pos);
        clase.setCantMax(0);

        if (clasesArchivo.modificarRegistro(clase, pos)) {
            cout << "Clase dada de baja exitosamente.\n";
        }
        else {
            cout << "Error al dar de baja la clase.\n";
        }
    }
    else {
        cout << "Clase no encontrada.\n";
    }
}

void GestionarClase::buscarClase() {
    int id;
    cout << "Ingrese el ID de la clase a buscar: ";
    cin >> id;

    int pos = clasesArchivo.buscar(id);
    if (pos >= 0) {
        Actividad clase = clasesArchivo.leerRegistro(pos);
        clase.mostrar();
    }
    else {
        cout << "Clase no encontrada.\n";
    }
}

void GestionarClase::listarClases() {
    int totalRegistros = clasesArchivo.contarRegistros();

    if (totalRegistros == 0) {
        cout << "No hay clases registradas.\n";
        return;
    }

    cout << "\n===== LISTA DE CLASES =====\n";

    for (int i = 0; i < totalRegistros; ++i) {
        Actividad clase = clasesArchivo.leerRegistro(i);
        clase.mostrar();
    }
}

int GestionarClase::obtenerIdNuevo() {
    return Utilidades::obtenerIdNuevo<ActividadesArchivo, Actividad>(clasesArchivo);
}
