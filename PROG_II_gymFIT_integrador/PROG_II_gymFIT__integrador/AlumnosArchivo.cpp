#define _CRT_SECURE_NO_WARNINGS
#include "AlumnosArchivo.h"

ArchivoAlumnos::ArchivoAlumnos(int tamanioRegistro) {
	_ruta = "alumnos.dat";
	_tamReg = tamanioRegistro;
}
bool ArchivoAlumnos::listarRegistro() const {
	Alumno reg;
	FILE* pAlumno;

	pAlumno = fopen(_ruta.c_str(), "rb");
	if (pAlumno == nullptr) {
		return false;
	}

	while (fread(&reg, _tamReg, 1, pAlumno) == 1) {
		reg.mostrar();
	};

	fclose(pAlumno);
	return true;
}
bool ArchivoAlumnos::guardar(const Alumno& reg) const {
	FILE* pAlumno;
	pAlumno = fopen(_ruta.c_str(), "ab");
	bool result;

	if (pAlumno == nullptr) {
		return false;
	}

	result = fwrite(&reg, _tamReg, 1, pAlumno) == 1;
	fclose(pAlumno);

	return result;
}
int ArchivoAlumnos::buscar(int idAlumno)const {
	FILE* pAlumno;
	Alumno reg;
	int pos = 0;
	pAlumno = fopen(_ruta.c_str(), "rb");
	if (pAlumno == nullptr) {
		return -2;
	}
	while (fread(&reg, _tamReg, 1, pAlumno) == 1) {
		if (reg.getIdAlumno() == idAlumno && reg.getEstado()) {
			fclose(pAlumno);
			return pos;
		};
		pos++;
	};

	fclose(pAlumno);
	return -1;
}
int ArchivoAlumnos::contarRegistros()const
{
	FILE* pAlumno;
	Alumno reg;
	pAlumno = fopen(_ruta.c_str(), "rb");
	if (pAlumno == nullptr) {
		return 0;
	}

	fseek(pAlumno, 0, SEEK_END); // puntero al final del reg
	int total = ftell(pAlumno); // cantidad de bytes en registro

	fclose(pAlumno);
	return total / _tamReg;
}
bool ArchivoAlumnos::modificarRegistro(const Alumno& reg, int pos)const
{
	FILE* pAlumno;
	pAlumno = fopen(_ruta.c_str(), "rb+");
	if (pAlumno == nullptr) {
		return false;
	}

	fseek(pAlumno, pos * _tamReg, SEEK_SET);
	bool escribio = fwrite(&reg, _tamReg, 1, pAlumno);
	fclose(pAlumno);
	return escribio;
}
Alumno ArchivoAlumnos::leerRegistro(int ubi)const {
	FILE* pAlumno;
	Alumno reg;
	pAlumno = fopen(_ruta.c_str(), "rb");
	if (pAlumno == nullptr) {
		return reg;
	}

	int cantBytes = ubi * _tamReg;
	fseek(pAlumno, cantBytes, SEEK_SET);
	fread(&reg, sizeof(Alumno), 1, pAlumno);
	fclose(pAlumno);
	return reg;
}
