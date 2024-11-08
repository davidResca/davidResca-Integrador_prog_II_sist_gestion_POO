#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "Actividad.h"


class ActividadesArchivo : public IArchivable<Actividad>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	ActividadesArchivo(int tamanioRegistro);
	Actividad leerRegistro(int pos) const override;
	bool comprobarArchivo() const override;
	bool listarRegistro() const override;
	bool guardar(const Actividad& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const Actividad& reg, int pos) const override;
	~ActividadesArchivo() {};
};
