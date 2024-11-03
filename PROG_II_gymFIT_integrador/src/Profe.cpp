#include "Profe.h"

// constructores
Profe::Profe() : Empleado() {
	_idProfe = -1;
	_salarioHora = .0f;
}
Profe::Profe(std::string nombre, std::string apellido, long long dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, long long CUIT, const std::string& observaciones, int idProfe, float salarioHora)
	: Empleado(nombre, apellido, dni, edad, diaNasc, mesNasc, anioNasc, correoElectronico, diaAlta, mesAlta, anioAlta, horasTrabajadas, CUIT, observaciones)
{
	_idProfe = idProfe;
	_salarioHora = salarioHora;
}

// setters
void Profe::setSalarioHora(float salarioHora)
{
	_salarioHora = salarioHora;
}
void Profe::setIdProfe(int idProfe)
{
	_idProfe = idProfe;
}

// getters
int Profe::getIdProfe() const {
	return _idProfe;
}
float Profe::getSalarioHora() const {
	return _salarioHora;
}

// interfaz
void Profe::mostrar() {
	Empleado::mostrar();
	std::cout << "id profe: " << getIdProfe() << std::endl;
	std::cout << "Salario por hora: " << getSalarioHora() << std::endl;
}

//destructor
Profe::~Profe() {};
