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
	if (idAlumno < 0) throw std::invalid_argument("El ID del Alumno debe ser un numero positivo");
	_idAlumno = idAlumno;
}
void Inscripciones::setIdHorario(int idHorario) {
	if (idHorario < 0) throw std::invalid_argument("El ID del Horario debe ser un numero positivo");
	_idHorario = idHorario;
}

// interfaz
void Inscripciones::mostrar()
{
	std::cout << "Horario: " << getIdHorario() << std::endl;
	std::cout << "Alumno: " << getIdAlumno() << std::endl;
}
