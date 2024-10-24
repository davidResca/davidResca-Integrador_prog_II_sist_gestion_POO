#include "Empleado.h"

const std::string Empleado::valorDefault = "NO HAY DATOS";

//constructor
Empleado::Empleado() : Persona() {
	_idEmpleado = -9;
	_fechaAlta = Fecha();
	_horasTrabajadas = .0f;
	_CUIT = 0;
	strcpy_s(_rol, sizeof(_rol), valorDefault.c_str());
	strcpy_s(_observaciones, sizeof(_observaciones), valorDefault.c_str());
	_ultimoSalario = .0f;
};
Empleado::Empleado(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idEmpleado, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, int CUIT, const std::string& rol, const std::string& observaciones, float ultimoSalario)
	: Persona(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico)
{
	_idEmpleado = idEmpleado;
	_fechaAlta = Fecha(diaAlta, mesAlta, anioAlta);
	_horasTrabajadas = horasTrabajadas;
	_CUIT = CUIT;
	strcpy_s(_rol, sizeof(_rol), rol.c_str());
	strcpy_s(_observaciones, sizeof(_observaciones), observaciones.c_str());
	_ultimoSalario = ultimoSalario;
}

// setters
void Empleado::setIdEmpleado(int id)
{
	_idEmpleado = id;
}
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
void Empleado::setRol(std::string rol)
{
}
void Empleado::setObservaciones(std::string observaciones)
{
}
void Empleado::setUltimoSalario(float salario)
{
	_ultimoSalario = salario;
}

// getters
int Empleado::getIdEmpleado() const
{
	return _idEmpleado;
}
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
std::string Empleado::getRol() const
{
	return _rol;
}
std::string Empleado::getObservaciones() const
{
	return _observaciones;
}
float Empleado::getUltimoSalario() const
{
	return _ultimoSalario;
}

// mostrar
void Empleado::mostrar() {
	std::cout << "		EMPLEADA / O ID: " << getIdEmpleado() << std::endl;
	std::cout << "*******************************" << std::endl;

	Persona::mostrarPersona();
	std::cout << "ID: " << getIdEmpleado() << std::endl;
	std::cout << "Fecha: " << getFechaAlta() << std::endl;
	std::cout << "Horas registradas: " << getHorasTrabajadas() << std::endl;
	std::cout << "Rol: " << getRol() << std::endl;
	std::cout << "Observaciones: " << getObservaciones() << std::endl;
	std::cout << "Ultimo salario: " << getUltimoSalario() << std::endl;
}