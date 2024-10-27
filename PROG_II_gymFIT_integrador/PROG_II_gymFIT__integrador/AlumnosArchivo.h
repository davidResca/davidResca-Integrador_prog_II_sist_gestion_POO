#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "Alumno.h"


class ArchivoAlumnos : public IArchivable<Alumno>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	ArchivoAlumnos(int tamanioRegistro);
	Alumno leerRegistro(int pos) const override;
	bool listarRegistro() const override;
	bool guardar(const Alumno& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const Alumno& reg, int pos) const override;
	~ArchivoAlumnos() override {};
};
