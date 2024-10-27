#include <cstring>
#include <iostream>
#include "Actividad.h"

const std::string Actividad::defaultValue = "no hay datos";

Actividad::Actividad()
{
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), defaultValue.c_str());
	_idLugarDeDesarrollo = -1;
}
Actividad::Actividad(std::string nombreActividad, int idLugarDeDesarrollo)
{
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), nombreActividad.c_str());
	_idLugarDeDesarrollo = idLugarDeDesarrollo;
}

// getters
std::string Actividad::getNombreActividad() const
{
	return _nombreActividad;
}
int Actividad::getIdLugarDeDesarrollo() const
{
	return _idLugarDeDesarrollo;
}

// setters
void Actividad::setNombreActividad(std::string actividad)
{
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), actividad.c_str());
}
void Actividad::setIdLugarDeDesarrollo(int idLugar)
{
	_idLugarDeDesarrollo = idLugar;
}

// interfaz
void Actividad::mostrarActividad() const {
	std::cout << std::endl;
	std::cout << "Nombre: " << getNombreActividad() << std::endl;
	std::cout << "Lugar: " << getIdLugarDeDesarrollo() << std::endl;
}
