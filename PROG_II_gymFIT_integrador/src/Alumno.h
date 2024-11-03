#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"

class Alumno : public Persona
{
private:
	int _idAlumno;
	Fecha _fechaInscripcion;
	int _idMembresia;
	bool _estado; 
public:
	// constructor
	Alumno();
	Alumno(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idAlumno, int diaInsc, int mesInsc, int anioInsc, int idMembresia, bool estado, std::string direccion, long long telefono);

	// setters
	void setIdAlumno(int idAlumno);
	void setFechaInscripcion(int diaInsc, int mesInsc, int anioInsc);
	void setIdMembresia(int id);
	void setEstadoAlta(bool estado);

	// getters 
	Fecha getFechaInscripcion() const;
	int getIdAlumno() const;
	int getIdMembresia () const;
	bool getEstado() const;

	// interfaz
	//Alumno cargar();
	void mostrar();

	// destructor
	~Alumno();
};

