#pragma once

#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "GestionarAlumno.h"
#include <iostream>
#include "Utilidades.h"

GestionarAlumno::GestionarAlumno() : archivoAlumnos(sizeof(Alumno)) {}

Alumno GestionarAlumno::cargarAlumno()
{
    std::string nombre, apellido, correoElectronico, direccion;
    int dni, edad, diaNasc, mesNasc, anioNasc, diaInsc, mesInsc, anioInsc, idMembresia;
    long long telefono;
    bool estado;

    std::cout << "Ingrese nombre: ";
    std::cin >> nombre;

    std::cout << "Ingrese apellido: ";
    std::cin >> apellido;

    std::cout << "Ingrese DNI: ";
    std::cin >> dni;

    std::cout << "Ingrese edad: ";
    std::cin >> edad;

    std::cout << "Ingrese fecha de nacimiento (dia - mes - anio): ";
    std::cin >> diaNasc >> mesNasc >> anioNasc;

    std::cout << "Ingrese correo electronico: ";
    std::cin >> correoElectronico;

    std::cout << "Ingrese direccion: ";
    std::cin.ignore();
    std::getline(std::cin, direccion);

    std::cout << "Ingrese telefono: ";
    std::cin >> telefono;

    int idAlumno = obtenerIdNuevo();

    std::cout << "Ingrese fecha de inscripcion (dia mes anio): ";
    std::cin >> diaInsc >> mesInsc >> anioInsc;

    std::cout << "Ingrese ID de membresia: ";
    std::cin >> idMembresia;

    std::cout << "El alumno esta activo? (1 = Si, 0 = No): ";
    std::cin >> estado;

    Alumno nuevoAlumno(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico,
        idAlumno, diaInsc, mesInsc, anioInsc, idMembresia, estado, direccion, telefono);

    return nuevoAlumno;
}

void GestionarAlumno::altaAlumno() {
    Alumno nuevoAlumno = cargarAlumno(); // Llama a cargarAlumno para obtener un Alumno con datos

    if (archivoAlumnos.guardar(nuevoAlumno)) {
        std::cout << "Alumno agregado exitosamente.\n";
    }
    else {
        std::cout << "Error al guardar el alumno.\n";
    }
}

void GestionarAlumno::bajaAlumno() {
    int id;
    std::cout << "Ingrese el ID del alumno a dar de baja: ";
    std::cin >> id;

    int pos = archivoAlumnos.buscar(id);
    if (pos >= 0) {
        Alumno alumno = archivoAlumnos.leerRegistro(pos);
        alumno.setEstadoAlta(false);
        if (archivoAlumnos.modificarRegistro(alumno, pos)) {
            std::cout << "Alumno dado de baja exitosamente.\n";
        }
        else {
            std::cout << "Error al dar de baja al alumno.\n";
        }
    }
    else {
        std::cout << "Alumno no encontrado.\n";
    }
}

void GestionarAlumno::listarAlumnos() {
    int totalRegistros = archivoAlumnos.contarRegistros();

    if (totalRegistros == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }

    std::cout << "\n===== LISTA DE ALUMNOS ACTIVOS =====\n";

    for (int i = 0; i < totalRegistros; ++i) {
        Alumno alumno = archivoAlumnos.leerRegistro(i);

        if (alumno.getEstado()) {
            alumno.mostrar();
        }
    }
}

void GestionarAlumno::buscarAlumno() {
    int id;
    std::cout << "Ingrese el ID del alumno a buscar: ";
    std::cin >> id;

    int pos = archivoAlumnos.buscar(id);
    if (pos >= 0) {
        Alumno alumno = archivoAlumnos.leerRegistro(pos);
        alumno.mostrar();
    }
    else {
        std::cout << "Alumno no encontrado.\n";
    }
}

int GestionarAlumno::obtenerIdNuevo() {
    return Utilidades::obtenerIdNuevo<ArchivoAlumnos, Alumno>(archivoAlumnos);
}
