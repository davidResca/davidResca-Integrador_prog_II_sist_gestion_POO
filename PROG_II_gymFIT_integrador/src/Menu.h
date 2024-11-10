#pragma 
#include "GestionarAlumno.h"
#include "GestionarProfe.h"
#include "GestionarActividad.h"
#include "GestionarHorario.h"


class Menu
{
public:
	void mostrarMenu();
	void procesarOpcion(int opcion);
private:
	GestionarAlumno gestorAlumnos;
	//GestionarProfe gestorProfe;
	GestionarActividad gestorActividades;
	//GestionarHorario gestorHorarios;

	void gestionarAlumnos();
	//void gestionarProfes();
	void gestionarActividades();
	//void gestionarHorarios();
};

