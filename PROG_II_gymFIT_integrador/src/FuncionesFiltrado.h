#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Profe.h"
#include "Actividad.h"
#include "ActividadesArchivo.h"
#include "ProfesArchivo.h"
#include "AlumnosArchivo.h"
#include "DiaHoraArchivo.h"


//Gestión de clases
void filtrarClasesPorProfesor(int idProfe);
void verListaProfesPorClase(int idClase);
void verListadoTotalProfesores();

//Gestión de profesores
void buscarProfe(int idProfe);
void altaProfe();
void altaClase();

//Gestión de alumnos
void buscarAlumno(int idAlumno);

/*
void verCantidadInscriptosClase(int idClase);
void filtrarClasesPorSala(int idSala);
void filtrarClasesPorDia(const std::string& dia);
*/

/*

	- crear class InscripcionesArchivo.
	- crear una class Menu, o varias, tener en cuenta los datos que deben ingresar en el registro de profes, clases, diahorario, alumnos.

	- Pensar cómo trabajar estas funciones o similares:

		void filtrarClasesPorProfesor(int idProfe);
		void filtrarClasesPorSala(int idSala);
		void filtrarClasesPorDia(int idClase);
		void verCantidadInscriptosClase(int idClase);
		void verListaProfesPorClase(int idClase);
		void verListadoTotalProfesores();
		void buscarAlumno(int idAlumno);
		void buscarProfe(int IdProfe);

	- Validaciones de datos.


*/