#include "ClasesArchivo.h"

ClasesArchivo::ClasesArchivo(int tamanioRegistro) {
    _ruta = "archivos/clases.dat";
    _tamReg = tamanioRegistro;
}

bool ClasesArchivo::listarRegistro() const {
    Clase reg;
    FILE* pClase;

    pClase = fopen(_ruta.c_str(), "rb");
    if (pClase == nullptr) {
        return false;
    }

    while (fread(&reg, _tamReg, 1, pClase) == 1) {
        reg.mostrarClase(); 
    }

    fclose(pClase);
    return true;
}

bool ClasesArchivo::guardar(const Clase& reg) const {
    FILE* pClase;
    pClase = fopen(_ruta.c_str(), "ab");
    bool result;

    if (pClase == nullptr) {
        return false; 
    }

    result = fwrite(&reg, _tamReg, 1, pClase) == 1;
    fclose(pClase);
    return result;
}

int ClasesArchivo::buscar(int id) const {
    FILE* pClase;
    Clase reg;
    int pos = 0;

    pClase = fopen(_ruta.c_str(), "rb");
    if (pClase == nullptr) {
        return -2; 
    }

    while (fread(&reg, _tamReg, 1, pClase) == 1) {
        if (reg.getIdClase() == id) { 
            fclose(pClase);
            return pos;
        }
        pos++;
    }

    fclose(pClase);
    return -1; 
}

int ClasesArchivo::contarRegistros() const {
    FILE* pClase;
    pClase = fopen(_ruta.c_str(), "rb");

    if (pClase == nullptr) {
        return 0; 
    }

    fseek(pClase, 0, SEEK_END);
    int total = ftell(pClase); 

    fclose(pClase);
    return total / _tamReg; 
}

bool ClasesArchivo::modificarRegistro(const Clase& reg, int pos) const {
    FILE* pClase;
    pClase = fopen(_ruta.c_str(), "rb+");

    if (pClase == nullptr) {
        return false; 
    }

    fseek(pClase, pos * _tamReg, SEEK_SET);
    bool escribio = fwrite(&reg, _tamReg, 1, pClase) == 1;
    fclose(pClase);
    return escribio;
}

Clase ClasesArchivo::leerRegistro(int ubi) const {
    FILE* pClase;
    Clase reg;

    pClase = fopen(_ruta.c_str(), "rb");
    if (pClase == nullptr) {
        return reg; 
    }

    fseek(pClase, ubi * _tamReg, SEEK_SET);
    fread(&reg, _tamReg, 1, pClase);
    fclose(pClase);
    return reg;
}
