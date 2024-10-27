	#include "Empleado.h"
	#include "Empleado.h"

const std::string Empleado::valorDefault = "NO HAY DATOS";

//constructor
Empleado::Empleado() : Persona() {
	_fechaAlta = Fecha();
	_horasTrabajadas = .0f;
	_CUIT = 0;
	strcpy_s(_observaciones, sizeof(_observaciones), valorDefault.c_str());
};
Empleado::Empleado(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, int CUIT, const std::string& observaciones)
	: Persona(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico)
{
	_fechaAlta = Fecha(diaAlta, mesAlta, anioAlta);
	_horasTrabajadas = horasTrabajadas;
	_CUIT = CUIT;
	strcpy_s(_observaciones, sizeof(_observaciones), observaciones.c_str()); 
}

// setters
void Empleado::setFechaAlta(int dia, int mes, int anio)
{
	_fechaAlta = Fecha(dia, mes, anio);
}
void Empleado::setHorasTrabajadas(float horas)
{
	_horasTrabajadas = horas;
}
void Empleado::setCUIT(int CUIT)
{
	_CUIT = CUIT;
}

void Empleado::setObservaciones(std::string observaciones)
{
	strcpy_s(_observaciones, sizeof(_observaciones), observaciones.c_str());
}

// getters
Fecha Empleado::getFechaAlta() const
{
	return _fechaAlta;
}
float Empleado::getHorasTrabajadas() const
{
	return _horasTrabajadas;
}
int Empleado::getCUIT() const
{
	return _CUIT;
}

std::string Empleado::getObservaciones() const
{
	return _observaciones;
}

// mostrar
void Empleado::mostrar() {
	Persona::mostrarPersona();
	std::cout << "Fecha: " << getFechaAlta() << std::endl;
	std::cout << "Horas registradas: " << getHorasTrabajadas() << std::endl;
	std::cout << "Observaciones: " << getObservaciones() << std::endl;
}

Empleado::~Empleado() {};
