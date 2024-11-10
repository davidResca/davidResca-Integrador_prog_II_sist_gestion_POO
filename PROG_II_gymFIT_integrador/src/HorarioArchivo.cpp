#include "HorarioArchivo.h"
#include <iostream>


HorarioArchivo::HorarioArchivo(int tamanioRegistro) {
    _ruta = "archivos/Horario.dat";
    _tamReg = tamanioRegistro; 
}

bool HorarioArchivo::comprobarArchivo() const {
    FILE* pDiaHora;
    bool lecturaExitosa = true;


    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        lecturaExitosa = false;
        // devuelve -2 si no puede abrir el archivo
    }
    else {
        fclose(pDiaHora);
    }
    return lecturaExitosa;
}

bool HorarioArchivo::listarRegistro() const {
    Horario reg;
    FILE* pDiaHora;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return false;
    }

    while (fread(&reg, _tamReg, 1, pDiaHora) == 1) {
        reg.mostrarHorario();
    }

    fclose(pDiaHora);
    return true;
}

bool HorarioArchivo::guardar(const Horario& reg) const {
    FILE* pDiaHora;
    pDiaHora = fopen(_ruta.c_str(), "ab");
    bool result;

    if (pDiaHora == nullptr) {
        return false;
    }

    result = fwrite(&reg, _tamReg, 1, pDiaHora) == 1;
    fclose(pDiaHora);
    return result;
}

int HorarioArchivo::buscar(int id) const {
    FILE* pDiaHora;
    Horario reg;
    int pos = 0;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return -2; // No pudo leer el archivo.
    }

    while (fread(&reg, _tamReg, 1, pDiaHora) == 1) {
        if (reg.getIdActividad() == id) {
            fclose(pDiaHora);
            return pos; // Caso éxito, retorna la posición del elemento;
        }
        pos++;
    }

    fclose(pDiaHora);
    return -1; // No lo encontró.
}

int HorarioArchivo::contarRegistros() const {
    FILE* pDiaHora;
    pDiaHora = fopen(_ruta.c_str(), "rb");

    if (pDiaHora == nullptr) {
        return 0;
    }

    fseek(pDiaHora, 0, SEEK_END);
    int total = ftell(pDiaHora);

    fclose(pDiaHora);
    return total / _tamReg;
}

bool HorarioArchivo::modificarRegistro(const Horario& reg, int pos) const {
    FILE* pDiaHora;
    pDiaHora = fopen(_ruta.c_str(), "rb+");

    if (pDiaHora == nullptr) {
        return false;
    }

    fseek(pDiaHora, pos * _tamReg, SEEK_SET);
    bool escribio = fwrite(&reg, _tamReg, 1, pDiaHora) == 1;
    fclose(pDiaHora);
    return escribio;
}

Horario HorarioArchivo::leerRegistro(int ubi) const {
    FILE* pDiaHora;
    Horario reg;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return reg;
    }

    fseek(pDiaHora, ubi * _tamReg, SEEK_SET);
    fread(&reg, _tamReg, 1, pDiaHora);
    fclose(pDiaHora);
    return reg;
}
