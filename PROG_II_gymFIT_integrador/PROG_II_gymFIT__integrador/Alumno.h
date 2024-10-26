#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"

class Alumno : public Persona
{
private:
	int _idAlumno;
	Fecha _fechaInscripcion;
	bool _esRegular;
	char _carrera[100];
	bool _estado; 
public:
	// constructor
	Alumno();
	Alumno(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idAlumno, int diaInsc, int mesInsc, int anioInsc, bool regular, std::string carrera, bool estado);

	// setters
	void setIdAlumno(int idAlumno);
	void setFechaInscripcion(Fecha fechaInscripcion);
	void setEstadoRegular(bool regular);
	void setCarrera(std::string carrera);
	void setEstadoAlta(bool estado);

	// getters 
	int getIdAlumno() const;
	Fecha getFechaInscripcion() const;
	bool getEstadoRegular() const;
	std::string getCarrera() const;
	bool getEstado() const;

	// interfaz
	Alumno cargar();
	void mostrar();

	// destructor
	~Alumno();
};

