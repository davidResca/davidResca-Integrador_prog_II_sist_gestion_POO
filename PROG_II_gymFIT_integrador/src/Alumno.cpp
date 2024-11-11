#include "Alumno.h"

// constructores
Alumno::Alumno() : Persona() {
	_idAlumno = -1;
	Fecha fechaInscripcion(1, 1, 1);
	_idMembresia = -1;
	_estado = false;
}
Alumno::Alumno(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idAlumno, int diaInsc, int mesInsc, int anioInsc, int idMembresia, bool estado, std::string direccion, long long telefono)
	: Persona(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico, direccion, telefono)
{
	_idAlumno = idAlumno;
	Fecha _fechaInscripcion(diaInsc, mesInsc, anioInsc);
	_idMembresia = idMembresia;
	_estado = estado;
}

// setters
void Alumno::setIdAlumno(int idAlumno) {
	if (idAlumno <= 0) throw std::invalid_argument("El ID del Alumno debe ser un numero positivo");
	_idAlumno = idAlumno;
}
void Alumno::setFechaInscripcion(int diaInsc, int mesInsc, int anioInsc) {
	_fechaInscripcion = Fecha(diaInsc, mesInsc, anioInsc);
}
void Alumno::setIdMembresia(int idMembresia) {
	if (idMembresia <= 0) throw std::invalid_argument("El ID de la Membresia debe ser un numero positivo");
	_idMembresia = idMembresia;
}
void Alumno::setEstadoAlta(bool estado) {
	_estado = estado;
}

// getters
Fecha Alumno::getFechaInscripcion() const {
	return _fechaInscripcion;
}
int Alumno::getId() const {
	return _idAlumno;
}
int Alumno::getIdMembresia() const {
	return _idMembresia;
}
bool Alumno::getEstado() const {
	return _estado;
}

void Alumno::mostrar() {
	if (_estado) {
		std::cout << "------------ " << "ALUMNO: " << getId () << " ------------" << std::endl;
		Persona::mostrarPersona();
		std::cout << "ID ALUMNO: " << getId () << std::endl;
		std::cout << "FECHA DE INSCRIPCION: " << getFechaInscripcion() << std::endl;
		std::cout << "CARRERA: " << getIdMembresia() << std::endl;

		std::string infoEstado = getEstado() ? "ACTIVO" : "INACTIVO";
		std::cout << "Estado regular: " << infoEstado << std::endl;

		std::cout << std::endl;
	}
}

// destructor
Alumno::~Alumno() {};