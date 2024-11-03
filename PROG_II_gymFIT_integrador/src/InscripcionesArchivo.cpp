#define _CRT_SECURE_NO_WARNINGS
#include "InscripcionesArchivo.h"

InscripcionesArchivo::InscripcionesArchivo(int tamanioRegistro)
{
	_ruta = "archivos/inscripciones.dat";
	_tamReg = tamanioRegistro;
}

Inscripciones InscripcionesArchivo::leerRegistro(int pos) const
{
	FILE* pInsc;
	Inscripciones reg;
	pInsc = fopen(_ruta.c_str(), "rb");
	if (pInsc == nullptr) {
		return reg;
	}

	int cantBytes = pos * _tamReg;
	fseek(pInsc, cantBytes, SEEK_SET);
	fread(&reg, sizeof(Inscripciones), 1, pInsc);
	fclose(pInsc);
	return reg;
}

bool InscripcionesArchivo::comprobarArchivo() const {
	FILE* pInsc;
	bool lecturaExitosa = true;


	pInsc = fopen(_ruta.c_str(), "rb");
	if (pInsc == nullptr) {
		lecturaExitosa = false;
		// devuelve -2 si no puede abrir el archivo
	}
	else {
		fclose(pInsc);
	}
	return lecturaExitosa;
}

bool InscripcionesArchivo::listarRegistro() const
{
	Inscripciones reg;
	FILE* pInsc;

	pInsc = fopen(_ruta.c_str(), "rb");
	if (pInsc == nullptr) {
		return false;
	}

	while (fread(&reg, _tamReg, 1, pInsc) == 1) {
		reg.mostrar();
	};

	fclose(pInsc);
	return true;
}

bool InscripcionesArchivo::guardar(const Inscripciones& reg) const
{
	FILE* pInsc;
	pInsc = fopen(_ruta.c_str(), "ab");
	bool result;

	if (pInsc == nullptr) {
		return false;
	}

	result = fwrite(&reg, _tamReg, 1, pInsc) == 1;
	fclose(pInsc);

	return result;
}

int InscripcionesArchivo::buscar(int id) const
{
	FILE* pInsc;
	Inscripciones reg;
	int pos = 0;
	pInsc = fopen(_ruta.c_str(), "rb");
	if (pInsc == nullptr) {
		return -2;
	}
	while (fread(&reg, _tamReg, 1, pInsc) == 1) {
		if (reg.getIdAlumno() == id) {
			fclose(pInsc);
			return pos;
		}
		pos++;
	};

	fclose(pInsc);
	return -1;
}

int InscripcionesArchivo::contarRegistros() const
{
	FILE* pInsc;
	Inscripciones reg;
	pInsc = fopen(_ruta.c_str(), "rb");
	if (pInsc == nullptr) {
		return 0;
	}

	fseek(pInsc, 0, SEEK_END);
	int total = ftell(pInsc);

	fclose(pInsc);
	return total / _tamReg;
}

bool InscripcionesArchivo::modificarRegistro(const Inscripciones& reg, int pos) const
{
	FILE* pInsc;
	pInsc = fopen(_ruta.c_str(), "rb+");
	if (pInsc == nullptr) {
		return false;
	}

	fseek(pInsc, pos * _tamReg, SEEK_SET);
	bool escribio = fwrite(&reg, _tamReg, 1, pInsc);
	fclose(pInsc);
	return escribio;
}
