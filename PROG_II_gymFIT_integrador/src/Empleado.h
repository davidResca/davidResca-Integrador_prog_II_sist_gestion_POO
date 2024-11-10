#pragma once
#include <cstring>
#include "Persona.h"

class Empleado : public Persona
{
private:
	static const std::string valorDefault;
	Fecha _fechaAlta;
	float _horasTrabajadas;
	long long _CUIT;
	char _observaciones[200];
	bool _estado;
public:
	// constructor
	Empleado();
	Empleado(std::string nombre,std::string apellido,long long dni,int edad,int diaNasc,int mesNasc,int anioNasc,std::string correoElectronico,int diaAlta,int mesAlta,int anioAlta,float horasTrabajadas,long long CUIT,const std::string& observaciones, std::string direccion, long long telefono);

	//setters
	void setFechaAlta(int dia, int mes, int anio);
	void setHorasTrabajadas(float horas);
	void setCUIT(long long CUIT);
	void setObservaciones(std::string observaciones);

	//getters
	Fecha getFechaAlta() const;
	float getHorasTrabajadas() const;
	long long getCUIT() const;
	std::string getObservaciones() const;

	//mostrar
	void mostrar();

	// destructor
	~Empleado();
};

