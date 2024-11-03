#include "DiaHoraArchivo.h"

DiaHoraArchivo::DiaHoraArchivo(int tamanioRegistro) {
    _ruta = "archivos/diahorario.dat";
    _tamReg = tamanioRegistro;
}

bool DiaHoraArchivo::comprobarArchivo() const {
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

bool DiaHoraArchivo::listarRegistro() const {
    DiaHorario reg;
    FILE* pDiaHora;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return false;
    }

    while (fread(&reg, _tamReg, 1, pDiaHora) == 1) {
        reg.mostrarDiaHorario();
    }

    fclose(pDiaHora);
    return true;
}

bool DiaHoraArchivo::guardar(const DiaHorario& reg) const {
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

int DiaHoraArchivo::buscar(int id) const {
    FILE* pDiaHora;
    DiaHorario reg;
    int pos = 0;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return -2; // No pudo leer el archivo.
    }

    while (fread(&reg, _tamReg, 1, pDiaHora) == 1) {
        if (reg.getIdClase() == id) {
            fclose(pDiaHora);
            return pos; // Caso éxito, retorna la posición del elemento;
        }
        pos++;
    }

    fclose(pDiaHora);
    return -1; // No lo encontró.
}

int DiaHoraArchivo::contarRegistros() const {
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

bool DiaHoraArchivo::modificarRegistro(const DiaHorario& reg, int pos) const {
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

DiaHorario DiaHoraArchivo::leerRegistro(int ubi) const {
    FILE* pDiaHora;
    DiaHorario reg;

    pDiaHora = fopen(_ruta.c_str(), "rb");
    if (pDiaHora == nullptr) {
        return reg;
    }

    fseek(pDiaHora, ubi * _tamReg, SEEK_SET);
    fread(&reg, _tamReg, 1, pDiaHora);
    fclose(pDiaHora);
    return reg;
}
