// Menu.cpp
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mostrarMenu() {
    cout << "===== MENU PRINCIPAL =====\n";
    cout << "1. Gestionar Alumnos\n";
    cout << "2. Gestionar Profesores\n";
    cout << "3. Gestionar Actividades\n";
    cout << "4. Gestionar Horarios\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

void Menu::procesarOpcion(int opcion) {
    switch (opcion) {
    case 1:
        gestionarAlumnos();
        break;
    case 2:
        //gestionarProfes();
        break;
    case 3:
        gestionarActividades();
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

//void Menu::gestionarProfes() {
//    int opcion;
//    do {
//        cout << "\n===== GESTION DE PROFESORES =====\n";
//        cout << "1. Alta de Profesor\n";
//        cout << "2. Baja de Profesor\n";
//        cout << "3. Modificar Profesor\n";
//        cout << "4. Buscar Profesor\n";
//        cout << "5. Listar Profesores\n";
//        cout << "0. Volver al Menu Principal\n";
//        cout << "Seleccione una opcion: ";
//        cin >> opcion;
//
//        switch (opcion) {
//        case 1:
//            gestorProfe.altaProfesor();
//            break;
//        case 2:
//            gestorProfe.bajaProfesor();
//            break;
//        case 3:
//            //gestorProfesores.modificarProfesor();
//            break;
//        case 4:
//            gestorProfesores.buscarProfesor();
//            break;
//        case 5:
//            gestorProfesores.listarProfesores();
//            break;
//        case 0:
//            cout << "Volviendo al menu principal...\n";
//            break;
//        default:
//            cout << "Opcion no valida, intente nuevamente.\n";
//        }
//    } while (opcion != 0);
//}


void Menu::gestionarActividades() {
    int opcion;
    do {
        cout << "\n===== GESTION DE ACTIVIDADES =====\n";
        cout << "1. Alta de Actividad\n";
        cout << "2. Baja de Actividad\n";
        cout << "3. Modificar Actividad\n";
        cout << "4. Buscar Actividad\n";
        cout << "5. Listar Actividades\n";
        cout << "0. Volver al Menu Principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestorActividades.altaActividad();
            break;
        case 2:
            gestorActividades.bajaActividad();
            break;
        case 3:
            //gestorActividades.modificarActividad();
            break;
        case 4:
            gestorActividades.buscarActividad();
            break;
        case 5:
            gestorActividades.listarActividades();
            break;
        case 0:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opcion no valida, intente nuevamente.\n";
        }
    } while (opcion != 0);
}


//
//void Menu::gestionarHorarios() {
//    int opcion;
//    do {
//        cout << "\n===== GESTION DE HORARIOS =====\n";
//        cout << "1. Alta de Horario\n";
//        cout << "2. Baja de Horario\n";
//        cout << "3. Modificar Horario\n";
//        cout << "4. Buscar Horario\n";
//        cout << "5. Listar Horarios\n";
//        cout << "0. Volver al Menu Principal\n";
//        cout << "Seleccione una opcion: ";
//        cin >> opcion;
//
//        switch (opcion) {
//        case 1:
//            gestorHorarios.altaHorario();
//            break;
//        case 2:
//            gestorHorarios.bajaHorario();
//            break;
//        case 3:
//            //gestorHorarios.modificarHorario();
//            break;
//        case 4:
//            gestorHorarios.buscarHorario();
//            break;
//        case 5:
//            gestorHorarios.listarHorarios();
//            break;
//        case 0:
//            cout << "Volviendo al menu principal...\n";
//            break;
//        default:
//            cout << "Opcion no valida, intente nuevamente.\n";
//        }
//    } while (opcion != 0);
//}
