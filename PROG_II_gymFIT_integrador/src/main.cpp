#include <iostream>
#include "Inscripciones.h"
#include "InscripcionesArchivo.h"
#include "Fecha.h"
#include "Actividad.h"
#include "ActividadesArchivo.h"
#include "Empleado.h"
#include "IArchivable.h"
#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "Profe.h"
#include "ProfesArchivo.h"
#include "DiaHorario.h"
#include "DiaHoraArchivo.h"
#include "FuncionesFiltrado.h"
#include "Menu.h"   

using namespace std;


int main() {
	
    Menu menu;
    int opcion;

    do {
        menu.mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        menu.procesarOpcion(opcion);
    } while (opcion != 0);

    return 0;

}
//void mostrarMenuPrincipal() {
//	bool salir = false;
//	while (!salir) {
//		int opcion;
//		bool salir = false;
//		while (!salir) {
//			std::cout << "SITEMA GymFist" << std::endl;
//			std::cout << std::endl;
//			std::cout << "OPCIONES" << std::endl;
//			std::cout << "1) GESTION EMPLEADOS" << std::endl;
//			std::cout << "2) GESTION CLASES" << std::endl;
//			std::cout << std::endl;
//			std::cout << "0) Salir" << std::endl;
//			std::cout << std::endl;
//			std::cout << "Elija una opcion: ";
//			std::cin >> opcion;
//
//			switch (opcion) {
//			case 1:
//				
//				break;
//			case 2:
//				break;
//			case 3:
//
//				break;
//			case 4:
//
//				break;
//			case 0:
//				salir = true;
//				break;
//			default:
//				std::cout << "OPCION INCORRECTA." << std::endl;
//				system("pause");
//				break;
//			}
//			system("cls");
//		}
//	}
//}
//
//

























