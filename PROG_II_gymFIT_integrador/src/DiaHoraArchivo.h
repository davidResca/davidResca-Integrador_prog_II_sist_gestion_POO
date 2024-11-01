#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "DiaHorario.h"


class DiaHoraArchivo : public IArchivable<DiaHorario>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	DiaHoraArchivo(int tamanioRegistro);
	DiaHorario leerRegistro(int pos) const override;
	bool listarRegistro() const override;
	bool guardar(const DiaHorario& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const DiaHorario& reg, int pos) const override;
	~DiaHoraArchivo() override {};
};
