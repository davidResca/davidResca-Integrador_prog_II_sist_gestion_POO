// Menu.cpp
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mostrarMenu() {
    cout << "===== MENU PRINCIPAL =====\n";
    cout << "1. Gestionar Alumnos\n";
    cout << "2. Gestionar Profesores\n";
    cout << "3. Gestionar Actividades\n";
    cout << "4. Gestionar Clases\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

void Menu::procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        gestionarAlumnos();
        break;
    case 2:
        gestionarProfes();
        break;
    case 3:
        gestionarActividades();
        break;
    case 4:
        gestionarClases();
        break;
    case 0:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
    }
}

void Menu::gestionarAlumnos() {
    int opcion;
    do {
        cout << "\n===== GESTION DE ALUMNOS =====\n";
        cout << "1. Alta de Alumno\n";
        cout << "2. Baja de Alumno\n";
        cout << "3. Modificar Alumno\n";
        cout << "4. Buscar Alumno\n";
        cout << "5. Listar Alumnos\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestorAlumnos.altaAlumno();
            break;
        case 2:
            gestorAlumnos.bajaAlumno();
            break;
        case 3:
            //gestorAlumnos.modificarAlumno();
            break;
        case 4:
            gestorAlumnos.buscarAlumno();
            break;
        case 5:
            gestorAlumnos.listarAlumnos();
            break;
        case 0:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion no valida, intente nuevamente.\n";
        }
    } while (opcion != 0);
}

void Menu::gestionarProfes() {
    // Logica para gestionar profesores
    cout << "Gestion de Profesores" << endl;
}

void Menu::gestionarClases() {
    int opcion;
    do {
        cout << "\n===== GESTION DE CLASES =====\n";
        cout << "1. Alta de Clase\n";
        cout << "2. Baja de Clase\n";
        cout << "3. Modificar Clase\n";
        cout << "4. Buscar Clase\n";
        cout << "5. Listar Clases\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestorClases.cargarClase();
            break;
        case 2:
            gestorClases.bajaClase();
            break;
        case 3:
            //gestorClases.modificarClase();
            break;
        case 4:
            gestorClases.buscarClase();
            break;
        case 5:
            gestorClases.listarClases();
            break;
        case 0:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion no valida, intente nuevamente.\n";
        }
    } while (opcion != 0);
}

void Menu::gestionarActividades() {
    // Logica para gestionar actividades
    cout << "Gestion de Actividades" << endl;
}
