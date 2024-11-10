#pragma once
#include <cstring>
#include "Fecha.h"

class Persona
{
private:
	char _nombre[100];
	char _apellido[100];
	long long _DNI;
	int _edad;
	Fecha _fechaNacimiento;
	char _correoElectronico[100];
	char _direccion[150];
	long long _telefono;
	bool _estado;
public:
	Persona();
	Persona(std::string nombre, std::string apellido, long long dni, int edad, int dia, int mes, int anio, std::string correoElectronico, std::string direccion, long long telefono);
	
	// setters
	void setNombre(std::string nombre);
	void setApellido(std::string apellido);
	void setDNI(long long dni);
	void setCorreoElectronico(std::string correoElectronico);
	void setDireccion(std::string direccion);
	void setTelefono(long long telefono);
	
	// getters
	std::string getNombre() const;
	std::string getApellido() const;
	long long getDNI() const;
	Fecha getFechaNacimiento() const;
	int getEdad() const;
	std::string getCorreoElectronico() const;
	std::string getDireccion();
	long long getTelefono();
	bool getEstado() const;

	// setters
	void setEstado(bool estado);

	// interfaz
	void mostrarPersona() const;


	
	//destructor
	~Persona();
};

