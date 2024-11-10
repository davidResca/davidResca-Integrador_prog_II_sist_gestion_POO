#pragma once
#include "Persona.h"

// constructor
Persona::Persona() {
	setNombre("No hay datos");
	setApellido("No hay datos");
	_DNI = 0;
	_fechaNacimiento;
	setCorreoElectronico("No hay datos");
	_edad = 0;
	_telefono = -1;
}
Persona::Persona(std::string nombre, std::string apellido, long long dni, int edad, int dia, int mes, int anio, std::string correoElectronico, std::string direccion, long long telefono) {
	strcpy_s(_nombre, sizeof(_nombre), nombre.c_str());
	strcpy_s(_apellido, sizeof(_apellido), apellido.c_str());
	_DNI = dni;
	_edad = edad;
	_fechaNacimiento = Fecha(dia, mes, anio);
	strcpy_s(_correoElectronico, sizeof(_correoElectronico), correoElectronico.c_str());
	strcpy_s(_direccion, sizeof(_direccion), direccion.c_str());
	_telefono = telefono;
}

// setters
void Persona::setNombre(std::string nombre) {
	strcpy_s(_nombre, sizeof(_nombre), nombre.c_str());
}
void Persona::setApellido(std::string apellido) {
	strcpy_s(_apellido, sizeof(_apellido), apellido.c_str());
}
void Persona::setDNI(long long dni) {
	_DNI = dni;
}
void Persona::setCorreoElectronico(std::string correoElectronico) {
	strcpy_s(_correoElectronico, sizeof(_correoElectronico), correoElectronico.c_str());
}

void Persona::setDireccion(std::string direccion) {
	strcpy_s(_direccion, sizeof(_direccion), direccion.c_str());
}
void Persona::setTelefono(long long telefono) {
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
int Persona::getEdad() const {
	return _edad;
};
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
	std::cout << "Edad: " << getEdad() << std::endl;
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