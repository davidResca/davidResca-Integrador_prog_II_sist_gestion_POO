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
Empleado::Empleado(std::string nombre, std::string apellido, long long dni, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, long long CUIT, const std::string& observaciones, std::string direccion, long long telefono)
	: Persona(nombre, apellido, dni, diaNasc, mesNasc, anioNasc, correoElectronico, direccion, telefono)
{
	_fechaAlta = Fecha(diaAlta, mesAlta, anioAlta);
	_horasTrabajadas = horasTrabajadas;
	_CUIT = CUIT;
	strcpy_s(_observaciones, sizeof(_observaciones), observaciones.c_str()); 
}

// setters
void Empleado::setFechaAlta(int dia, int mes, int anio) {
	_fechaAlta = Fecha(dia, mes, anio);
}
void Empleado::setHorasTrabajadas(float horas) {
	if (horas < 0) throw std::invalid_argument("Las horas trabajadas no pueden ser negativas");
	_horasTrabajadas = horas;
}
void Empleado::setCUIT(long long CUIT) {
	// Esta validacion sirve para indicarle al compilador que el numero debe tratarse como un long long, el LL se utiliza para indicar que un n° literal es tipo long long.
	if (CUIT < 100000000000LL || CUIT > 99999999999LL) throw std::invalid_argument("El CUIT debe tener exactamente 11 digitos");
	_CUIT = CUIT;
}

void Empleado::setObservaciones(std::string observaciones) {
	if (observaciones.empty()) throw std::invalid_argument("Las Observaciones no pueden estar vacias");
	if (observaciones.size() >= sizeof(_observaciones)) throw std::invalid_argument("Las Observaciones exceden el tamaño permitido");
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
long long Empleado::getCUIT() const
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
