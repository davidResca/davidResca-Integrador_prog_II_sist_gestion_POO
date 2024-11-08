#pragma once

#include "GestionarAlumno.h"
#include "GestionarClase.h"

class Menu
{
public:
	void mostrarMenu();
	void procesarOpcion(int opcion);

private:
	GestionarAlumno gestorAlumnos;
	GestionarClase gestorClases;

	void gestionarAlumnos();
	void gestionarProfes();
	void gestionarActividades();
	void gestionarClases();
};

