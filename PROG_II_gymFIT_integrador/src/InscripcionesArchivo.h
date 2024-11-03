#pragma once
#include <cstdio>
#include <cstring>
#include "IArchivable.h"
#include "Inscripciones.h"


class InscripcionesArchivo : public IArchivable<Inscripciones>
{
private:
	//char _ruta[50];
	std::string _ruta;
	int _tamReg;
public:
	InscripcionesArchivo(int tamanioRegistro);
	Inscripciones leerRegistro(int pos) const override;
	bool comprobarArchivo() const override;
	bool listarRegistro() const override;
	bool guardar(const Inscripciones& reg) const override;
	int buscar(int id) const override;
	int contarRegistros() const override;
	bool modificarRegistro(const Inscripciones& reg, int pos) const override;
	~InscripcionesArchivo() override {};
};