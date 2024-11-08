#pragma once
#include <iostream>

class Inscripciones
{
private:
	int _idHorario;
	int _idAlumno;
public:
	Inscripciones();
	Inscripciones(int idHorario, int idAlumno);

	// getters
	int getIdAlumno();
	int getIdHorario();
	
	// setters
	void setIdAlumno(int idAlumno);
	void setIdHorario(int idHorario);

	// interfaz
	void mostrar();
};

















