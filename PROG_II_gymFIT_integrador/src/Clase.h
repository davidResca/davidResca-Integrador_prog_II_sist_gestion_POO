#pragma once
#include <iostream>
#include "DiaHorario.h"
#include "Actividad.h"

class Clase :
	public Actividad
{
private:
	static const std::string defaultValue;
	int _idClase;
	int _idProfe;
	int _cantidadInscriptos;
	int _cantMax;
	char _descripcion[200];
public:
	Clase();
	Clase(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo, int idClase, int idProfe, int cantidadInscriptos, int cantMax, std::string descripcion);

	// getters
	int getIdClase() const;
	int getIdProfe() const;
	int getCantidadInscriptos() const;
	int getCantMax() const;
	std::string getDescripcion() const;

	// setters
	void setIdProfe(int idProfe);
	void setIdClase(int idClase);
	void setCantidadInscriptos(int cantidadInscriptos);
	void setCantMax(int cantMax);
	void setDescripcion(std::string descripcion);

	// interfaz
	void mostrarClase() const;

	~Clase();
};


