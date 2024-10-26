#include "Actividad.h"

// setters
void Actividad::setIdActividad(int idActividad)
{
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

// getters
int Actividad::getIdActividad()
{
	return _idActividad;
}
std::string Actividad::getNombreActividad()
{
	return _nombreActividad;
}
int Actividad::getIdLugarDeDesarrollo()
{
	return _idLugarDeDesarrollo;
}

 