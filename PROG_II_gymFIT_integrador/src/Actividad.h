#pragma once
#include <cstring>
#include <string>

class Actividad
{
private:
	static const std::string defaultValue;
	int _idActividad;
	int _idLugarDeDesarrollo;
	int _idProfe;
	int _cantMax;
	bool _estado;
	char _descripcion[150];
	char _nombreActividad[100];
public:
	// constructores
	Actividad();
	Actividad(int idActividad, std::string nombreActividad, int idLugarDeDesarrollo, int idProfe, int cantMax, std::string descripcion, bool estado);

	// getters
	int getId() const;
	int getIdProfe() const;
	int getIdLugarDeDesarrollo() const;
	std::string getNombreActividad() const;
	int getCantMax() const;
	std::string getDescripcion() const;
	bool getEstado() const;

	// setters
	void setId(int idActividad);
	void setIdProfe(int idProfe);
	void setIdLugarDeDesarrollo(int id);
	void setCantMax(int cantMax);
	void setEstado(bool estado);
	void setNombreActividad(std::string actividad);
	void setDescripcion(std::string descripcion);

	// interfaz
	void mostrar() const;
};

