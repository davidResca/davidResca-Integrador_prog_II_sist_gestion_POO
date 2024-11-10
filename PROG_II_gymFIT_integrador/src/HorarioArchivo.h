#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "Horario.h"


class HorarioArchivo : public IArchivable<Horario>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	HorarioArchivo(int tamanioRegistro);
	bool comprobarArchivo() const override;
	Horario leerRegistro(int pos) const override;
	bool listarRegistro() const override;
	bool guardar(const Horario& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const Horario& reg, int pos) const override;
	~HorarioArchivo() override {};
};
