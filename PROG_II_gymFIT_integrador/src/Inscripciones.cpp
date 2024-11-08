#include "Inscripciones.h"

Inscripciones::Inscripciones() {
	_idHorario = -1;
	_idAlumno = -1;
}

Inscripciones::Inscripciones(int idHorario, int idAlumno) {
	_idHorario = idHorario;
	_idAlumno = idAlumno;
}

// getters
int Inscripciones::getIdAlumno() {
	return _idAlumno;
};
int Inscripciones::getIdHorario() {
	return _idHorario;
};

// setters
void Inscripciones::setIdAlumno(int idAlumno) {
	_idAlumno = idAlumno;
}
void Inscripciones::setIdHorario(int idHorario) {
	_idHorario = idHorario;
}

// interfaz
void Inscripciones::mostrar()
{
	std::cout << "Horario: " << getIdHorario() << std::endl;
	std::cout << "Alumno: " << getIdAlumno() << std::endl;
}
