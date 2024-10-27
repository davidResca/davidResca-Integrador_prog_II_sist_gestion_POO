#pragma once

template <typename T>

class IArchivable
{
	virtual bool listarRegistro() const = 0;
	virtual bool guardar(const T& reg) const = 0;
	virtual int buscar(int id) const = 0;
	virtual T leerRegistro(int pos) const = 0;
	virtual int contarRegistros() const = 0;
	virtual bool modificarRegistro(const T& reg, int pos) const = 0;
};
