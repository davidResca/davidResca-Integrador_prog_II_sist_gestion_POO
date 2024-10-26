#include "Profe.h"



Profe::Profe(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int idEmpleado, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, int CUIT, const std::string& rol, const std::string& observaciones, float ultimoSalario, float salarioHora) 
	: Empleado(nombre,apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico, idEmpleado, diaAlta, mesAlta, anioAlta, horasTrabajadas, CUIT, rol, observaciones, ultimoSalario)
{
	_salarioHora = salarioHora;
}

float Profe::getSalarioHora()
{
	return _salarioHora;
}
