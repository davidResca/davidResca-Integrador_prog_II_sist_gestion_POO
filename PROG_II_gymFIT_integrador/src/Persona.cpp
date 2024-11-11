#pragma once
#include "Persona.h"

// constructor
Persona::Persona() {
	setNombre("No hay datos");
	setApellido("No hay datos");
	_DNI = 0;
	_fechaNacimiento;
	setCorreoElectronico("No hay datos");
	_telefono = -1;
}
Persona::Persona(std::string nombre, std::string apellido, long long dni, int dia, int mes, int anio, std::string correoElectronico, std::string direccion, long long telefono) {
	strcpy_s(_nombre, sizeof(_nombre), nombre.c_str());
	strcpy_s(_apellido, sizeof(_apellido), apellido.c_str());
	_DNI = dni;
	_fechaNacimiento = Fecha(dia, mes, anio);
	strcpy_s(_correoElectronico, sizeof(_correoElectronico), correoElectronico.c_str());
	strcpy_s(_direccion, sizeof(_direccion), direccion.c_str());
	_telefono = telefono;
}

// setters
void Persona::setNombre(std::string nombre) {
	if (nombre.empty()) throw std::invalid_argument("El Nombre no puede estar vacio");
	strcpy_s(_nombre, sizeof(_nombre), nombre.c_str());
}
void Persona::setApellido(std::string apellido) {
	if (apellido.empty()) throw std::invalid_argument("El Apellido no puede estar vacio");
	strcpy_s(_apellido, sizeof(_apellido), apellido.c_str());
}
void Persona::setDNI(long long dni) {
	if (dni < 10000000LL || dni > 99999999LL) throw std::invalid_argument("El DNI debe tener exactamente 8 digitos");
	_DNI = dni;
}
void Persona::setCorreoElectronico(std::string correoElectronico) {
	strcpy_s(_correoElectronico, sizeof(_correoElectronico), correoElectronico.c_str());
}

void Persona::setDireccion(std::string direccion) {
	strcpy_s(_direccion, sizeof(_direccion), direccion.c_str());
}
void Persona::setTelefono(long long telefono) {
	if (telefono < 1000000000LL || telefono > 9999999999LL) throw std::invalid_argument("El N° de Telefono debe tener exactamente 10 digitos");
	_telefono = telefono;
}
void Persona::setEstado(bool estado) {
	_estado = estado;
}


// getters
std::string Persona::getNombre() const {
	return _nombre;
}
std::string Persona::getApellido() const {
	return _apellido;
}
long long Persona::getDNI() const {
	return _DNI;
}
Fecha Persona::getFechaNacimiento() const {
	return _fechaNacimiento;
}
std::string Persona::getCorreoElectronico() const {
	return _correoElectronico;
}
bool Persona::getEstado() const {
	return _estado;
}


//Metodos
void Persona::mostrarPersona() const {
	std::cout << std::endl;
	std::cout << "Nombre: " << getNombre() << std::endl;
	std::cout << "Apellido: " << getApellido() << std::endl;
	std::cout << "DNI: " << getDNI() << std::endl;
	std::cout << "Fecha Nacimiento: " << getFechaNacimiento() << std::endl;
	std::cout << "Correo electronico: " << getCorreoElectronico() << std::endl;
}
std::string Persona::getDireccion() {
	return _direccion;
}
long long Persona::getTelefono() {
	return _telefono;
}
Persona::~Persona() {};