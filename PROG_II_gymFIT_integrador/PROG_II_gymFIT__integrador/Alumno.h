#pragma once
#include <cstring>
#include "Persona.h"
#include "Fecha.h"

class Alumno : public Persona
{
private:
	int _legajo;
	Fecha _fechaInscripcion;
	bool _esRegular;
	char _carrera[100];
	bool _estado;
public:
	Alumno();
	Alumno(
		std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int legajo, int diaInsc, int mesInsc, int anioInsc, bool regular, std::string carrera, bool estado);

	Alumno cargar();
	void mostrar();

	void setLegajo(int legajo);
	void setFechaInscripcion(Fecha fechaInscripcion);
	void setEstadoRegular(bool regular);
	void setCarrera(std::string carrera);
	void setEstadoAlta(bool estado);

	int getLegajo() const;
	Fecha getFechaInscripcion() const;
	bool getEstadoRegular() const;
	std::string getCarrera() const;
	bool getEstado() const;
	~Alumno();
};

