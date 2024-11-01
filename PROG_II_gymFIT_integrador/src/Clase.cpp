#include "Clase.h"

const std::string Clase::defaultValue = "no hay datos";

// constructor
Clase::Clase() : Actividad() {
	_idProfe = -1;
	_idClase = -1;
	_cantidadInscriptos = -1;
	_cantMax = -1;
	strcpy_s(_descripcion, sizeof(_descripcion), defaultValue.c_str());
}
Clase::Clase(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo, int idProfe, int idClase, int cantidadInscriptos, int cantMax, std::string descripcion) : Actividad(idActividad, nombreActividad, idLugarDeDesarrollo) {
	_idProfe = idProfe;
	_idClase = idClase;
	_cantidadInscriptos = cantidadInscriptos;
	_cantMax = cantMax;
	strcpy_s(_descripcion, sizeof(_descripcion), descripcion.c_str());
};

// getters
int Clase::getIdClase() const{return _idClase;}
int Clase::getIdProfe() const{return _idProfe;}
int Clase::getCantidadInscriptos() const { return _cantidadInscriptos; }
int Clase::getCantMax() const {	return _cantMax;}
std::string Clase::getDescripcion() const {	return _descripcion; }


// setters
void Clase::setIdClase(int idClase) { _idClase = idClase; }
void Clase::setIdProfe(int idProfe) {_idProfe = idProfe;}
void Clase::setCantidadInscriptos(int cantidadInscriptos) {_cantidadInscriptos = cantidadInscriptos;}
void Clase::setCantMax(int cantMax) {_cantMax = cantMax;}
void Clase::setDescripcion(std::string descripcion) 
{
	strcpy_s(_descripcion, sizeof(_descripcion), descripcion.c_str());
}

// interfaz
void Clase::mostrarClase() const {
	Actividad::mostrarActividad();
	std::cout << "Profe: " << getIdProfe() << std::endl;
	std::cout << "Clase: " << getIdClase() << std::endl;
	std::cout << "Cantidad de inscriptos: " << getCantidadInscriptos() << std::endl;
	std::cout << "Cant Maxima alumnos: " << getCantMax() << std::endl;
	std::cout << "Descripcion: " << getDescripcion() << std::endl;
}

Clase::~Clase() {};

