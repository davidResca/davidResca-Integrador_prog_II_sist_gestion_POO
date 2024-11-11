#pragma once

#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "GestionarAlumno.h"
#include <iostream>
#include "Utilidades.h"

GestionarAlumno::GestionarAlumno() : archivoAlumnos(sizeof(Alumno)) {}


//Funcion para validar si una cadena contiene solo letras
bool soloLetras(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) return false;
    }
    return true;
}

//Funcion para validar si una cadena contiene solo numeros
bool soloNumeros(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

//Funcion para validar la longitud
bool tienelongitud(const std::string& str, int longitud) {
    return str.length() == longitud;
}


Alumno GestionarAlumno::cargarAlumno()
{
    std::string nombre, apellido, correoElectronico, direccion;
    int dni, diaNasc, mesNasc, anioNasc, diaInsc, mesInsc, anioInsc, idMembresia;
    long long telefono;
    bool estado = true;

    do {
        std::cout << "Ingrese nombre: ";
        std::cin >> nombre;
        if (!soloLetras(nombre)) std::cout << "Nombre Invalido. El nombre debe contener solo letras" << std::endl;
    } while (!soloLetras(nombre));

    do {
        std::cout << "Ingrese apellido: ";
        std::cin >> apellido;
        if (!soloLetras(apellido)) std::cout << "Apellido Invalido. El apellido debe contener solo letras" << std::endl;
    } while (!soloLetras(apellido));


    do {
        std::cout << "Ingrese DNI: ";
        std::cin >> dni;
        std::string dniStr = std::to_string(dni);
        if (!soloNumeros(dniStr) || !tienelongitud(dniStr, 8)) std::cout << "DNI Invalido. Debe ser 8 digitos numericos" << std::endl;
    } while (!soloNumeros(std::to_string(dni)) || !tienelongitud(std::to_string(dni), 8));


    std::cout << "Ingrese fecha de nacimiento (dia - mes - anio): ";
    std::cin >> diaNasc >> mesNasc >> anioNasc;

    std::cout << "Ingrese correo electronico: ";
    std::cin >> correoElectronico;

    std::cout << "Ingrese direccion: ";
    std::cin.ignore();
    std::getline(std::cin, direccion);

    do {
        std::cout << "Ingrese telefono: ";
        std::cin >> telefono;
        std::string telefonoStr = std::to_string(telefono);
        if (!soloNumeros(telefonoStr) || !tienelongitud(telefonoStr, 10)) std::cout << "Telefono Invalido. Debe ser 10 digitos numericos" << std::endl;
    } while (!soloNumeros(std::to_string(telefono)) || !tienelongitud(std::to_string(telefono), 10));


    int idAlumno = obtenerIdNuevo();

    std::cout << "Ingrese fecha de inscripcion (dia mes anio): ";
    std::cin >> diaInsc >> mesInsc >> anioInsc;


    Alumno nuevoAlumno(nombre, apellido, dni, diaNasc, mesNasc, anioNasc, correoElectronico,
        idAlumno, diaInsc, mesInsc, anioInsc, estado, direccion, telefono);

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
