#include <cstring>
#include <iostream>
#include "Actividad.h"

const std::string Actividad::defaultValue = "no hay datos";

Actividad::Actividad()
{
	_idActividad = -1;
	_idLugarDeDesarrollo = -1;
	_idProfe = -1;
	_cantMax = -1;
	_estado = false;
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), defaultValue.c_str());
	strcpy_s(_descripcion, sizeof(_descripcion), defaultValue.c_str());
}
Actividad::Actividad(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo, int idProfe, int cantMax, std::string descripcion, bool estado)
{
	_idActividad = idActividad;
	_idLugarDeDesarrollo = idLugarDeDesarrollo;
	_idProfe = idProfe;
	_cantMax = cantMax;
	_estado = estado;
	strcpy_s(_nombreActividad, sizeof(_nombreActividad), nombreActividad.c_str());
	strcpy_s(_descripcion, sizeof(_descripcion), descripcion.c_str());
}

// getters
int Actividad::getId() const { return _idActividad; }
int Actividad::getIdProfe() const { return _idProfe; }
int Actividad::getIdLugarDeDesarrollo() const { return _idLugarDeDesarrollo; }
int Actividad::getCantMax() const { return _cantMax; }
bool Actividad::getEstado() const { return _estado; }
std::string Actividad::getNombreActividad() const { return _nombreActividad; }
std::string Actividad::getDescripcion() const { return _descripcion; }

// setters
void Actividad::setId(int idActividad) {
	if (idActividad < 0) throw std::invalid_argument("El ID de la Actividad debe ser un numero positivo");
	_idActividad = idActividad;
}
void Actividad::setIdProfe(int idProfe) {
	if (idProfe < 0) throw std::invalid_argument("El ID del Profesor debe ser un numero positivo");
	_idProfe = idProfe;
}
void Actividad::setIdLugarDeDesarrollo(int idLugar) {
	if (idLugar < 0) throw std::invalid_argument("El ID del Lugar debe ser un numero positivo");
	_idLugarDeDesarrollo = idLugar;
}
void Actividad::setCantMax(int cantMax) {
	if (cantMax <= 0) throw std::invalid_argument("La Cantidad Maxima debe ser un número positivo");
	_cantMax = cantMax;
}
void Actividad::setEstado(bool estado) {
	_estado = estado;
}
void Actividad::setNombreActividad(std::string actividad) {
	if (actividad.size() >= sizeof(_nombreActividad)) throw std::invalid_argument("El nombre de la actividad es demasiado largo");
	strncpy_s(_nombreActividad, actividad.c_str(), sizeof(_nombreActividad) - 1); // modifique strcpy a strncpy por que esta sirve para copiar un n° especifico de caracteres.
	_nombreActividad[sizeof(_nombreActividad) - 1] = '\0';
}
void Actividad::setDescripcion(std::string descripcion) {
	if (descripcion.size() >= sizeof(_descripcion)) throw std::invalid_argument("La descripcion de la actividad es demasiado larga");
	strncpy_s(_descripcion, descripcion.c_str(), sizeof(_descripcion) - 1);
	_descripcion[sizeof(_descripcion) - 1] = '\0';
}

// interfaz
void Actividad::mostrar() const {
	std::string claseActiva;
	claseActiva = getEstado() ? "Activa" : "Dada de baja";

	std::cout << "Clase: " << getId() << std::endl;
	std::cout << "Nombre: " << getNombreActividad() << std::endl;
	std::cout << "Sala: " << getIdLugarDeDesarrollo() << std::endl;
	std::cout << "Profe: " << getIdProfe() << std::endl;
	std::cout << "Cant Maxima alumnos: " << getCantMax() << std::endl;
	std::cout << "Descripcion: " << getDescripcion() << std::endl;
	std::cout << "Estado: " << claseActiva << std::endl;
}
