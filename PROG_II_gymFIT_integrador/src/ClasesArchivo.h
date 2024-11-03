#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "Clase.h"


class ClasesArchivo : public IArchivable<Clase>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	ClasesArchivo(int tamanioRegistro);
	Clase leerRegistro(int pos) const override;
	bool comprobarArchivo() const override;
	bool listarRegistro() const override;
	bool guardar(const Clase& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const Clase& reg, int pos) const override;
	~ClasesArchivo() override {};
};
