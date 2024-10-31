#pragma once
#include <cstring>
#include <string>

class Actividad
{
private:
	static const std::string defaultValue;
	int _idActividad;
	char _nombreActividad[100];
	int _idLugarDeDesarrollo;
public:
	// constructores
	Actividad();
	Actividad(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo);
	
	// getters
	int getIdActividad() const;
	std::string getNombreActividad() const;
	int getIdLugarDeDesarrollo() const;

	// setters
	void setIdActividad(int idActividad);
	void setNombreActividad(std::string actividad);
	void setIdLugarDeDesarrollo(int id);
	
	// interfaz
	void mostrarActividad() const;
};

