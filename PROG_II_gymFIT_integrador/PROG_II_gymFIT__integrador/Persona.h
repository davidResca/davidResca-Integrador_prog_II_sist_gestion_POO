#pragma once
#include <cstring>
#include "Fecha.h"

class Persona
{
private:
	char _nombre[100];
	char _apellido[100];
	int _DNI;
	int _edad;
	Fecha _fechaNacimiento;
	char _correoElectronico[100];
public:
	Persona();
	Persona(std::string nombre, std::string apellido, int dni, int edad, int dia, int mes, int anio, std::string correoElectronico);
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setDNI(int dni);
	void setCorreoElectronico(std::string correoElectronico);
	std::string getNombre() const;
	std::string getApellido() const;
	int getDNI() const;
	Fecha getFechaNacimiento() const;
	int getEdad() const;
	std::string getCorreoElectronico() const;
	void mostrarPersona() const;
};

