#include <iostream>
#include "Fecha.h"
#include "Actividad.h"
#include "Empleado.h"
#include "IArchivable.h"
#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "Profe.h"
#include "ProfesArchivo.h"
#include "Clase.h"
#include "ClasesArchivo.h"
#include "DiaHorario.h"
#include "DiaHoraArchivo.h"
//#include "ClasesGestion.h"


template <typename T>
bool darAltaRegistro(IArchivable<T>& archivo, T& reg) {
	return archivo.guardar(reg);
}

template<typename T>
void mostrarListarRegistros(IArchivable<T>& archivo) {
	archivo.listarRegistro();
	system("pause");
}


//template<typename T>
//T buscarRegistro(int ubi)

int main() {
	bool exito;
	
	//nombre, apellido, dni,    edad, fecha nac   ,  correoElectronico , fecha  Alta, hTrab, CUIT,  observaciones,idProfe, salarioHora
	Profe laura("laura", "pavese", 35450984, 35, 20, 12, 1989, "lau@profesgym.com", 4, 4, 2023, 345, 14354509849, "Excelente", 2, 9500);
	ProfesArchivo archivo(sizeof(Profe));
	exito = darAltaRegistro(archivo, laura);
	mostrarListarRegistros(archivo);
	std::cout << exito << std::endl;

	//std::cout << "-----------------------------------------------" << std::endl;
	DiaHoraArchivo archivoDiaHorario(sizeof(DiaHorario));
	//				   (idClase, idProfe,diaSemana, horaInicio, horaFin)
	DiaHorario rpmLunes(2, 2, "lunes", 15, 16);
	darAltaRegistro(archivoDiaHorario, rpmLunes);
	mostrarListarRegistros(archivoDiaHorario);
	//std::cout << "-----------------------------------------------" << std::endl;


	std::cout << "-----------------------------------------------" << std::endl;
	ArchivoAlumnos archivoAlumnos(sizeof(Alumno));
	//				nombre, apellido,   dni,   edad, Fecha Nac, correoElectronico, id , FechaInsc, idMembresia, estado
	Alumno alumno1("matias", "peretti", 39882345, 26, 4, 4, 1996, "mati@matias.com", 234, 6, 8, 2024, 5, true);
	exito = darAltaRegistro(archivoAlumnos, alumno1);
	mostrarListarRegistros(archivoAlumnos);
	std::cout << "-----------------------------------------------" << std::endl;

	



	return 0;
}

//
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






//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA ACTIVIDAD" << std::endl;
//Actividad fiesta("fiesta en el bunker (SUM 4)", 4);
//fiesta.mostrarActividad();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA CLASE" << std::endl;
//// nombreActividad, idLugarDeDesarrollo, idProfe, idClase, cantidadInscriptos
//Clase rpm("rpm", 6, 2, 6500, 10);
//rpm.mostrarClase();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA PERSONA" << std::endl;
//Persona javier("javier", "montiel", 17634972, 55, 10, 3, 1978, "javi@javi.com");
//javier.mostrarPersona();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA EMPLEADO" << std::endl;
//Empleado franco("franco", "servini", 39882349, 30, 2, 9, 1996, "francoservini@mantenimientogim.com", 9, 9, 2024, 300, 20398823492, "Excelente trabajo, no descuidar los espejos");
//franco.mostrar();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA PROFE" << std::endl;
//Profe laura("laura", "pavese", 35450984, 35, 20, 12, 1989, "lau@profesgym.com", 4, 4, 2023, 345, 14354509849, "Excelente", 2, 9500);
//laura.mostrarProfe();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA DIA HORARIO" << std::endl;
//DiaHorario rpmLunes(2, 2, "lunes", 15, 16);
//rpmLunes.mostrarDiaHorario();
//std::cout << "-----------------------------------------------" << std::endl;