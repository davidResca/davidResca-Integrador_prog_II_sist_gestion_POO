#include "GestionarProfe.h"
#include <iostream>
#include "Utilidades.h"
#include "Profe.h"
using namespace std;

GestionarProfesor::GestionarProfesor()
    : archivoProfesores(sizeof(Profe)) // Inicializa el archivo con el tamaño de Profesor
{}

Profe GestionarProfesor::cargarProfesor() {
    string nombre, apellido, correoElectronico, observaciones, direccion;
    long long dni, CUIT, telefono;
    int diaNasc, mesNasc, anioNasc, diaAlta, mesAlta, anioAlta, idProfe;
    float horasTrabajadas, salarioHora;

    cout << "Ingrese el nombre del profesor: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese el apellido del profesor: ";
    getline(cin, apellido);

    cout << "Ingrese el DNI del profesor: ";
    cin >> dni;


    cout << "Ingrese la fecha de nacimiento (dia mes anio): ";
    cin >> diaNasc >> mesNasc >> anioNasc;

    cout << "Ingrese el correo electronico del profesor: ";
    cin.ignore();
    getline(cin, correoElectronico);

    cout << "Ingrese la fecha de alta (dia mes anio): ";
    cin >> diaAlta >> mesAlta >> anioAlta;

    cout << "Ingrese las horas trabajadas: ";
    cin >> horasTrabajadas;

    cout << "Ingrese el CUIT del profesor: ";
    cin >> CUIT;

    cout << "Ingrese cualquier observacion sobre el profesor: ";
    cin.ignore();
    getline(cin, observaciones);

    idProfe = obtenerIdNuevo(); 

    cout << "Ingrese el salario por hora: ";
    cin >> salarioHora;

    cout << "Ingrese la direccion del profesor: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese el telefono del profesor: ";
    cin >> telefono;

    Profe nuevoProfesor(nombre, apellido, dni, diaNasc, mesNasc, anioNasc,
        correoElectronico, diaAlta, mesAlta, anioAlta,
        horasTrabajadas, CUIT, observaciones, idProfe,
        salarioHora, direccion, telefono);
    return nuevoProfesor;
}


void GestionarProfesor::altaProfesor() {
    Profe nuevoProfesor = cargarProfesor();

    if (archivoProfesores.guardar(nuevoProfesor)) {
        cout << "Profesor agregado exitosamente.\n";
    }
    else {
        cout << "Error al guardar el profesor.\n";
    }
}

void GestionarProfesor::bajaProfesor() {
    int id;
    cout << "Ingrese el ID del profesor a dar de baja: ";
    cin >> id;

    int pos = archivoProfesores.buscar(id);
    if (pos >= 0) {
        Profe profesor = archivoProfesores.leerRegistro(pos);
        profesor.setEstado(false); 

        if (archivoProfesores.modificarRegistro(profesor, pos)) {
            cout << "Profesor dado de baja exitosamente.\n";
        }
        else {
            cout << "Error al dar de baja el profesor.\n";
        }
    }
    else {
        cout << "Profesor no encontrado.\n";
    }
}

void GestionarProfesor::listarProfesores() {
    if (!archivoProfesores.listarRegistro()) {
        cout << "No hay profesores registrados o no se pudo leer el archivo.\n";
    }
}

void GestionarProfesor::buscarProfesor() {
    int id;
    cout << "Ingrese el ID del profesor a buscar: ";
    cin >> id;

    int pos = archivoProfesores.buscar(id);
    if (pos >= 0) {
        Profe profesor = archivoProfesores.leerRegistro(pos);
        profesor.mostrar(); // Asume que Profesor tiene un método mostrar() para imprimir sus datos
    }
    else {
        cout << "Profesor no encontrado.\n";
    }
}

int GestionarProfesor::obtenerIdNuevo() {
    return Utilidades::obtenerIdNuevo<ProfesArchivo, Profe>(archivoProfesores);
}
