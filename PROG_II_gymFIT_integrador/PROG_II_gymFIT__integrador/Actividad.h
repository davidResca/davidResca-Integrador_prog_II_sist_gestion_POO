#pragma once
#include <cstring>;
#include <string>;

class Actividad
{
private:
	int _idActividad;
	char _nombreActividad[20];
	int _idLugarDeDesarrollo;
public:
	void setIdActividad(int idActividad);
	void setNombreActividad(std::string actividad);
	void setIdLugarDeDesarrollo(int id);
	
	int getIdActividad();
	std::string getNombreActividad();
	int getIdLugarDeDesarrollo();

		
};

