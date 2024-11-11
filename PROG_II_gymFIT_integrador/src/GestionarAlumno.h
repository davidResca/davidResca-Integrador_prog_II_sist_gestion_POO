#pragma once
#include "Alumno.h"
#include "AlumnosArchivo.h"


class GestionarAlumno
{
public:
	GestionarAlumno();
	Alumno cargarAlumno();
	void altaAlumno();
	void bajaAlumno();
	void listarAlumnos();
	void buscarAlumno();
	bool esIdMembresiaValido(int idMembresia);

private:
	ArchivoAlumnos archivoAlumnos;
	int obtenerIdNuevo();
};



