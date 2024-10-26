#include "Clase.h"


// constructor
Clase::Clase() {
	_idProfe = -1;
	_idClase = -1;
	_cantidadInscriptos = -1;
}
Clase::Clase(int idProfe, int idClase, int cantidadInscriptos) {
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

Clase::~Clase()
{
}

// setters
