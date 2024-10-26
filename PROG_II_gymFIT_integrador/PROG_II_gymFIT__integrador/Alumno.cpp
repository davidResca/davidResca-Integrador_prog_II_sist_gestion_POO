#include "Alumno.h"

// constructores
Alumno::Alumno() : Persona() {
	setIdAlumno(0);
	Fecha fechaInscripcion(1, 1, 1);
	setEstadoRegular(0);
	setCarrera("no hay datos");
}
Alumno::Alumno(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idAlumno, int diaInsc, int mesInsc, int anioInsc, bool regular, std::string carrera, bool estado)
	: Persona(nombre, apellido, dni, diaNasc, mesNasc, anioNasc, dni, correoElectronico)
{
	_idAlumno = idAlumno;
	Fecha _fechaInscripcion(diaInsc, mesInsc, anioInsc);
	strcpy_s(_carrera, sizeof(_carrera), carrera.c_str());
	_esRegular = regular;
	_estado = estado;
}

// setters
void Alumno::setIdAlumno(int legajo) {
	_idAlumno = legajo;
}
void Alumno::setFechaInscripcion(Fecha fechaInscripcion) {
	_fechaInscripcion = fechaInscripcion;
}
void Alumno::setEstadoRegular(bool regular) {
	_esRegular = regular;
}
void Alumno::setCarrera(std::string carrera) {
	strcpy_s(_carrera, sizeof(_carrera), carrera.c_str());
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
bool Alumno::getEstadoRegular() const {
	return _esRegular;
}
std::string Alumno::getCarrera() const {
	return _carrera;
}
bool Alumno::getEstado() const {
	return _estado;
}

// interfaz
Alumno Alumno::cargar() {
	std::string nombre, apellido, correoElectronico, carrera;
	int dni, edad = 0, diaNasc, mesNasc, anioNasc, idAlumno, diaInsc, mesInsc, anioInsc;
	bool regular = true, estado = true;

	std::cout << "Nombre: ";
	std::cin >> nombre;
	std::cout << "Apellido: ";
	std::cin >> apellido;
	std::cout << "DNI: ";
	std::cin >> dni;
	std::cout << "Fecha nacimiento: " << std::endl;
	std::cout << "DIA: ";
	std::cin >> diaNasc;
	std::cout << "MES: ";
	std::cin >> anioNasc;
	std::cout << "ANIO: ";
	std::cin >> mesNasc;
	std::cout << "Correo electronico: ";
	std::cin >> correoElectronico;
	std::cout << "Legajo: ";
	std::cin >> idAlumno;
	std::cout << "Fecha alta: " << std::endl;
	std::cout << "DIA: ";
	std::cin >> diaInsc;
	std::cout << "MES: ";
	std::cin >> mesInsc;
	std::cout << "ANIO: ";
	std::cin >> anioInsc;
	std::cout << "Carrera: ";
	std::cin >> carrera;
	std::cout << std::endl;

	Alumno alumnoNuevo(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico, idAlumno, diaInsc, mesInsc, anioInsc, true, carrera, true);

	return std::move(alumnoNuevo);
	// Copy Elision - ver también "Return Value Optimization" - RVO
}
void Alumno::mostrar() {
	if (_estado) {
		std::cout << "------------ " << "ALUMNO: " << getIdAlumno() << " ------------" << std::endl;
		Persona::mostrarPersona();
		std::cout << "ID ALUMNO: " << getIdAlumno() << std::endl;
		std::cout << "FECHA DE INSCRIPCION: " << getFechaInscripcion() << std::endl;
		std::cout << "CARRERA: " << getCarrera() << std::endl;

		std::string infoRegularidad = getEstadoRegular() ? "REGULAR" : "NO REGULAR";
		std::cout << "Estado regular: " << infoRegularidad << std::endl;

		std::cout << std::endl;
	}
}

// destructor
Alumno::~Alumno() {}