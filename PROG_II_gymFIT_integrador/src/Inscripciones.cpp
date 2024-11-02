#include "Inscripciones.h"

Inscripciones::Inscripciones() {
	_idClase = -1;
	_idAlumno = -1;
}

Inscripciones::Inscripciones(int idClase, int idAlumno) {
	_idClase = idClase;
	_idAlumno = idAlumno;
}

// getters
int Inscripciones::getIdAlumno() {
	return _idAlumno;
};
int Inscripciones::getIdClase() {
	return _idClase; 
};

// setters
void Inscripciones::setIdAlumno(int idAlumno) {
	_idAlumno = idAlumno;
}
void Inscripciones::setIdClase(int idClase) {
	_idClase = idClase;
}