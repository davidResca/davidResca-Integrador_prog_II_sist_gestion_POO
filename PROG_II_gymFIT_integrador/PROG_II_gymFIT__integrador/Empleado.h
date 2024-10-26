#pragma once
#include <cstring>
#include "Persona.h"

class Empleado : public Persona
{
private:
	static const std::string valorDefault;
	Fecha _fechaAlta;
	float _horasTrabajadas;
	int _CUIT;
	char _observaciones[200];
public:
	// constructor
	Empleado();
	Empleado(std::string nombre,std::string apellido,int dni,int edad,int diaNasc,int mesNasc,int anioNasc,std::string correoElectronico,int diaAlta,int mesAlta,int anioAlta,float horasTrabajadas,int CUIT,const std::string& observaciones);

	//setters
	void setFechaAlta(int dia, int mes, int anio);
	void setHorasTrabajadas(float horas);
	void setCUIT(int CUIT);
	void setObservaciones(std::string observaciones);

	//getters
	Fecha getFechaAlta() const;
	float getHorasTrabajadas() const;
	int getCUIT() const;
	std::string getObservaciones() const;

	//mostrar
	void mostrar();

	// destructor
	~Empleado();
};

