#include "Clase.h"

// constructor
Clase::Clase() : Actividad() {
	_idProfe = -1;
	_idClase = -1;
	_cantidadInscriptos = -1;
}
Clase::Clase(std::string nombreActividad, int idLugarDeDesarrollo, int idProfe, int idClase, int cantidadInscriptos) : Actividad(nombreActividad, idLugarDeDesarrollo) {
	_idProfe = idProfe;
	_idClase = idClase;
	_cantidadInscriptos = cantidadInscriptos;
};

// getters
int Clase::getIdClase() const
{
	return _idClase;
}
int Clase::getCantidadInscriptos() const
{
	return _cantidadInscriptos;
}
int Clase::getIdProfe() const
{
	return _idProfe;
}

// interfaz
void Clase::mostrarClase() const {
	Actividad::mostrarActividad();
	std::cout << std::endl;
	std::cout << "Clase: " << getIdClase() << std::endl;
	std::cout << "Cantidad de inscriptos: " << getCantidadInscriptos() << std::endl;
	std::cout << "Profe: " << getIdProfe() << std::endl;
}

Clase::~Clase() {};

// setters
