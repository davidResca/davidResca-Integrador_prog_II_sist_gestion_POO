#include <cstring>
#include <iostream>
#include "Actividad.h"

const std::string Actividad::defaultValue = "no hay datos";

Actividad::Actividad()
{
	_idActividad = -1;
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), defaultValue.c_str());
	_idLugarDeDesarrollo = -1;
}
Actividad::Actividad(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo)
{
	_idActividad = idActividad;
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), nombreActividad.c_str());
	_idLugarDeDesarrollo = idLugarDeDesarrollo;
}

// getters
int Actividad::getIdActividad() const { return _idActividad; }
std::string Actividad::getNombreActividad() const
{
	return _nombreActividad;
}
int Actividad::getIdLugarDeDesarrollo() const
{
	return _idLugarDeDesarrollo;
}

// setters
void Actividad::setIdActividad(int idActividad) {
	_idActividad = idActividad;
}
void Actividad::setNombreActividad(std::string actividad)
{
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), actividad.c_str());
}
void Actividad::setIdLugarDeDesarrollo(int idLugar)
{
	_idLugarDeDesarrollo = idLugar;
}

// interfaz
void Actividad::mostrar() const {
	std::cout << "id Actividad: " << getIdActividad() << std::endl;
	std::cout << "Nombre: " << getNombreActividad() << std::endl;
	std::cout << "Lugar: " << getIdLugarDeDesarrollo() << std::endl;
}
