#pragma once
class Inscripciones
{
private:
	int _idClase;
	int _idAlumno;
public:
	Inscripciones();
	Inscripciones(int idClase, int idAlumno);

	// getters
	int getIdAlumno();
	int getIdClase();
	
	// setters
	void setIdAlumno(int idAlumno);
	void setIdClase(int idClase);
};

















