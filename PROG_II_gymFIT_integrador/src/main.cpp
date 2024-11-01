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

//template <typename T>
//bool darAltaRegistro(IArchivable<T>& archivo, T& reg) {
//	return archivo.guardar(reg);
//}
//template<typename T>
//void mostrarListarRegistros(IArchivable<T>& archivo) {
//	archivo.listarRegistro();
//	system("pause");
//}

///	EXPLICACION	
///		altaClase()
///	
///		Instancias:
///		Clase clase(idActividad, actividadNombre, idLugarDeDesarrollo, idClase, idProfe, cantInscriptos, cantMax, descripcion);
///		DiaHorario diaHorarioClase(idClase, idProfe, dia, horaInicio, horaFin);
/// 
///	!!!	cantInscriptos se inicializa en 0 
///		porque al crear el objeto suponemos 
///		que todavía no tiene alumnos.
/// 
///		Pregunta si desea guardar:
///		
///		1. guarda, muestra.
///		2. termmina la funcion.
void altaClase() {
	ClasesArchivo clasesArchivo(sizeof(Clase));
	DiaHoraArchivo diaHoraClaseArchivo(sizeof(DiaHorario));

	Clase clase;
	DiaHorario diaHorarioClase;

	int idActividad, idClase, idProfe, idLugarDeDesarrollo, cantMax, horaInicio, horaFin, cantInscriptos = 0;
	std::string descripcion, actividadNombre, dia;

	std::cout << " REGISTRAR NUEVA CLASE: " << std::endl;
	std::cout << " --------------------- " << std::endl;
	std::cout << std::endl;

	std::cout << "Id de actividad: " << std::endl;
	std::cin >> idActividad;

	std::cout << "Id de la clase: " << std::endl;
	std::cin >> idClase;

	std::cin.ignore();

	std::cout << "Nombre de la clase: " << std::endl;
	std::getline(std::cin, actividadNombre);
	std::cout << "Descripcion: " << std::endl;
	std::getline(std::cin, descripcion);
	std::cout << "Dia de dictado: " << std::endl;
	std::getline(std::cin, dia);

	std::cout << "hora inicio (ingresar enteros): " << std::endl;
	std::cin >> horaInicio;
	std::cout << "hora fin (ingresar enteros): " << std::endl;
	std::cin >> horaFin;

	std::cout << "Id del Profesor/a: " << std::endl;
	std::cin >> idProfe;
	std::cout << "Id salon: " << std::endl;
	std::cin >> idLugarDeDesarrollo;
	std::cout << "Cantidad maxima alumnos: " << std::endl;
	std::cin >> cantMax;
	
	clase = Clase(idActividad, actividadNombre, idLugarDeDesarrollo, idProfe, idClase, cantInscriptos, cantMax, descripcion);
	//clase = Clase(1, "rpm", 4, 2, 4, 0, 30, "clase divertida de rpm");
	diaHorarioClase = DiaHorario(idClase, idProfe, dia, horaInicio, horaFin);
	//diaHorarioClase = DiaHorario(2, 2, "lunes", 15, 16);
	
	system("cls");
	int guardaRegistro;
	std::cout << "Usted está por guardar el siguiente registro:" << std::endl;	
	clase.mostrarClase();
	std::cout << "Desea guardar?" << std::endl;
	std::cout << "1. SI" << std::endl;
	std::cout << "2. NO" << std::endl;
	std::cin >> guardaRegistro;
	system("pause");

	if (guardaRegistro == 2) {
		return;
	}

	clasesArchivo.guardar(clase);
	diaHoraClaseArchivo.guardar(diaHorarioClase);
	
	clasesArchivo.listarRegistro();
	std::cout << std::endl;
	diaHoraClaseArchivo.listarRegistro();

	/*darAltaRegistro(clasesArchivo, clase);
	darAltaRegistro(diaHoraClaseArchivo, diaHorarioClase);
	mostrarListarRegistros(clasesArchivo);
	mostrarListarRegistros(diaHoraClaseArchivo);*/
}
///	EXPLICACION	
///		altaProfe()
///	
///		Instancias:
/// 
///		Profe profe(nombre, apellido, dni, edad, diaNac, mesNac, anioNac, correoElectronico, diaAlta, mesAlta, anioAlta, horasTrabajadas, CUIT, observaciones, idProfe, salarioHora);
///		clase(idActividad, actividadNombre, idLugarDeDesarrollo, idClase, idProfe, cantInscriptos, cantMax, descripcion);
///		diaHorarioClase(idClase, idProfe, dia, horaInicio, horaFin);
/// 
///		Pregunta si desea guardar
///		
///		1. guarda, luego muestra
///		2. termina
void altaProfe() {
	ProfesArchivo profesArchivo(sizeof(Profe));
	Profe profeNuevo;

	long long dni, CUIT;
	float horasTrabajadas = 0, salarioHora;
	int idProfe, edad, diaNac, mesNac, anioNac, diaAlta, mesAlta, anioAlta;
	std::string nombre, apellido, correoElectronico, observaciones;

	std::cout << " ALTA PROFE: " << std::endl;
	std::cout << " --------------------- " << std::endl;
	std::cout << std::endl;
	
	std::cout << "Nombre: " << std::endl;
	std::cin >> nombre;

	std::cout << "Apellido: " << std::endl;
	std::cin >> apellido;

	std::cin.ignore();
	std::cout << "Observaciones: " << std::endl;
	std::getline(std::cin, observaciones);

	std::cout << "DNI: " << std::endl;
	std::cin >> dni;

	std::cout << "CUIT: " << std::endl;
	std::cin >> CUIT;

	std::cout << "Edad: " << std::endl;
	std::cin >> edad;

	std::cout << "Fecha Nacimiento: " << std::endl;
	std::cout << "dia: " << std::endl;
	std::cin >> diaNac;
	std::cout << "mes: " << std::endl;
	std::cin >> mesNac;
	std::cout << "anio: " << std::endl;
	std::cin >> anioNac;

	std::cout << "Asignar ID: " << std::endl;
	std::cin >> idProfe;

	std::cout << "Fecha Alta: " << std::endl;
	std::cout << "dia: " << std::endl;
	std::cin >> diaAlta;
	std::cout << "mes: " << std::endl;
	std::cin >> mesAlta;
	std::cout << "anio: " << std::endl;
	std::cin >> anioAlta;

	std::cout << "Salario a cobrar por hora: " << std::endl;
	std::cin >> salarioHora;

	profeNuevo = Profe(nombre, apellido, dni, edad, diaNac, mesNac, anioNac, correoElectronico, diaAlta, mesAlta, anioAlta, horasTrabajadas, CUIT, observaciones, idProfe, salarioHora);

	system("cls");
	int guardaRegistro;
	std::cout << "Usted está por guardar el siguiente registro:" << std::endl;
	profeNuevo.mostrar();
	std::cout << "Desea guardar?" << std::endl;
	std::cout << "1. SI" << std::endl;
	std::cout << "2. NO" << std::endl;
	std::cin >> guardaRegistro;
	system("pause");

	if (guardaRegistro == 2) {
		return;
	}

	
	profesArchivo.guardar(profeNuevo);
	profesArchivo.listarRegistro();
}

void filtrarClasesPorProfesor(int idProfe);
void filtrarClasesPorSala(int idSala);
void filtrarClasesPorDia(int idClase);
void verCantidadInscriptosClase(int idClase);
void verListaProfesPorClase(int idClase);
void verListadoTotalProfesores();
void buscarAlumno(int idAlumno);
void buscarProfe(int IdProfe);
void verListadoInscriptosPorClase(int idClase);


int main() {
	//altaClase();
	altaProfe();

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
