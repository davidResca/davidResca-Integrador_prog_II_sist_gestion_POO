#pragma once
#include <cstring>
#include "Persona.h"

class Empleado : public Persona
{
private:
	static const std::string valorDefault;
	int _idEmpleado;
	Fecha _fechaAlta;
	float _horasTrabajadas = .0f;
	int _CUIT;
	char _rol[50];
	char _observaciones[200];
	float _ultimoSalario;
		
public:
	Empleado();
	
	Empleado(
		std::string nombre,
		std::string apellido,
		int dni,
		int edad,
		int diaNasc,
		int mesNasc,
		int anioNasc,
		std::string correoElectronico,
		int idEmpleado,
		int diaAlta,
		int mesAlta,
		int anioAlta,
		float horasTrabajadas,
		int CUIT,
		const std::string& rol,
		const std::string& observaciones,
		float ultimoSalario
	);

	//setters
	void setIdEmpleado(int id);
	void setFechaAlta(int dia, int mes, int anio);
	void setHorasTrabajadas(float horas);
	void setCUIT(int CUIT);
	void setRol(std::string rol);
	void setObservaciones(std::string observaciones);
	void setUltimoSalario(float salario);

	//getters
	int getIdEmpleado() const;
	Fecha getFechaAlta() const;
	float getHorasTrabajadas() const;
	int getCUIT() const;
	std::string getRol() const;
	std::string getObservaciones() const;
	float getUltimoSalario() const;

	//mostrar
	void mostrar();
	//Actividades clasesACargo[10];

};

