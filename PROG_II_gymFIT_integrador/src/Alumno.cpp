#include "Alumno.h"

// constructores
Alumno::Alumno() : Persona() {
	_idAlumno = -1;
	Fecha fechaInscripcion(1, 1, 1);
	_idMembresia = -1;
	_estado = false;
}
Alumno::Alumno(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idAlumno, int diaInsc, int mesInsc, int anioInsc, int idMembresia, bool estado)
	: Persona(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico)
{
	_idAlumno = idAlumno;
	Fecha _fechaInscripcion(diaInsc, mesInsc, anioInsc);
	_idMembresia = idMembresia;
	_estado = estado;
}

// setters
void Alumno::setIdAlumno(int idAlumno) {
	_idAlumno = idAlumno;
}
void Alumno::setFechaInscripcion(int diaInsc, int mesInsc, int anioInsc) {
	_fechaInscripcion = Fecha(diaInsc, mesInsc, anioInsc);
}
void Alumno::setIdMembresia(int idMembresia) {
	_idMembresia = idMembresia;
}
void Alumno::setEstadoAlta(bool estado) {
	_estado = estado;
}

// getters
Fecha Alumno::getFechaInscripcion() const {
	return _fechaInscripcion;
}
int Alumno::getIdAlumno() const {
	return _idAlumno;
}
int Alumno::getIdMembresia() const {
	return _idMembresia;
}
bool Alumno::getEstado() const {
	return _estado;
}

// interfaz
//Alumno Alumno::cargar() {
//	std::string nombre, apellido, correoElectronico;
//	int dni, edad = 0, diaNasc, mesNasc, anioNasc, idAlumno, diaInsc, mesInsc, anioInsc, idMembresia;
//	bool regular = true, estado = true;
//
//	std::cout << "Nombre: ";
//	std::cin >> nombre;
//	std::cout << "Apellido: ";
//	std::cin >> apellido;
//	std::cout << "DNI: ";
//	std::cin >> dni;
//	std::cout << "Fecha nacimiento: " << std::endl;
//	std::cout << "DIA: ";
//	std::cin >> diaNasc;
//	std::cout << "MES: ";
//	std::cin >> anioNasc;
//	std::cout << "ANIO: ";
//	std::cin >> mesNasc;
//	std::cout << "Correo electronico: ";
//	std::cin >> correoElectronico;
//	std::cout << "Legajo: ";
//	std::cin >> idAlumno;
//	std::cout << "Fecha alta: " << std::endl;
//	std::cout << "DIA: ";
//	std::cin >> diaInsc;
//	std::cout << "MES: ";
//	std::cin >> mesInsc;
//	std::cout << "ANIO: ";
//	std::cin >> anioInsc;
//	std::cout << "Id membresia: ";
//	std::cin >> idMembresia;
//	std::cout << std::endl;
//
//	Alumno alumnoNuevo(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico, idAlumno, diaInsc, mesInsc, anioInsc, true, idMembresia, true);
//
//	return std::move(alumnoNuevo);
//	// Copy Elision - ver también "Return Value Optimization" - RVO
//}
void Alumno::mostrar() {
	if (_estado) {
		std::cout << "------------ " << "ALUMNO: " << getIdAlumno() << " ------------" << std::endl;
		Persona::mostrarPersona();
		std::cout << "ID ALUMNO: " << getIdAlumno() << std::endl;
		std::cout << "FECHA DE INSCRIPCION: " << getFechaInscripcion() << std::endl;
		std::cout << "CARRERA: " << getIdMembresia() << std::endl;

		std::string infoEstado = getEstado() ? "ACTIVO" : "INACTIVO";
		std::cout << "Estado regular: " << infoEstado << std::endl;

		std::cout << std::endl;
	}
}

// destructor
Alumno::~Alumno() {};