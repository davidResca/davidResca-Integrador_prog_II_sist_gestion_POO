#pragma once
#include <cstring>
#include <string>

class Actividad
{
private:
	static const std::string defaultValue;
	char _nombreActividad[100];
	int _idLugarDeDesarrollo;
public:
	// constructores
	Actividad();
	Actividad(std::string nombreActividad, int idLugarDeDesarrollo);
	
	// getters
	std::string getNombreActividad() const;
	int getIdLugarDeDesarrollo() const;

	// setters
	void setNombreActividad(std::string actividad);
	void setIdLugarDeDesarrollo(int id);
	
	// interfaz
	void mostrarActividad() const;
};

