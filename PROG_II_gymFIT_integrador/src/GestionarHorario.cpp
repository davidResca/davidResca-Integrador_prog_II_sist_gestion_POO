#include "GestionarHorario.h"
#include "Horario.h"
#include <iostream>
using namespace std;

GestionarHorario::GestionarHorario()
    : archivoHorarios(sizeof(Horario)) 
{}

Horario GestionarHorario::cargarHorario() {
    int idActividad, horaInicio, horaFin;
    string diaSemana;

    cout << "Ingrese el ID de la actividad: ";
    cin >> idActividad;

    cout << "Ingrese el dia de la semana (lunes, martes, ...): ";
    cin >> diaSemana;

    cout << "Ingrese la hora de inicio (en formato 24 horas, sin minutos): ";
    cin >> horaInicio;

    cout << "Ingrese la hora de fin (en formato 24 horas, sin minutos): ";
    cin >> horaFin;

    int idHorario = obtenerIdNuevo();
    Horario nuevoHorario(idHorario, idActividad, diaSemana, horaInicio, horaFin, true);
    return nuevoHorario;
}

void GestionarHorario::altaHorario() {
    Horario nuevoHorario = cargarHorario();

    if (archivoHorarios.guardar(nuevoHorario)) {
        cout << "Horario agregado exitosamente.\n";
    }
    else {
        cout << "Error al guardar el horario.\n";
    }
}

void GestionarHorario::bajaHorario() {
    int id;
    cout << "Ingrese el ID del horario a dar de baja: ";
    cin >> id;

    int pos = archivoHorarios.buscar(id);
    if (pos >= 0) {
        Horario horario = archivoHorarios.leerRegistro(pos);
        horario.setEstado(false);

        if (archivoHorarios.modificarRegistro(horario, pos)) {
            cout << "Horario dado de baja exitosamente.\n";
        }
        else {
            cout << "Error al dar de baja el horario.\n";
        }
    }
    else {
        cout << "Horario no encontrado.\n";
    }
}

void GestionarHorario::listarHorarios() {
    if (!archivoHorarios.listarRegistro()) {
        cout << "No hay horarios registrados o no se pudo leer el archivo.\n";
    }
}

void GestionarHorario::buscarHorario() {
    int id;
    cout << "Ingrese el ID del horario a buscar: ";
    cin >> id;

    int pos = archivoHorarios.buscar(id);
    if (pos >= 0) {
        Horario horario = archivoHorarios.leerRegistro(pos);
        horario.mostrarHorario();
    }
    else {
        cout << "Horario no encontrado.\n";
    }
}

int GestionarHorario::obtenerIdNuevo() {
    return Utilidades::obtenerIdNuevo<HorarioArchivo, Horario>(archivoHorarios);
}
