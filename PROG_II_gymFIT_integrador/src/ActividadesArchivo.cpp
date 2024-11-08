#include "ActividadesArchivo.h"


ActividadesArchivo::ActividadesArchivo(int tamanioRegistro)
{
    _ruta = "archivos/actividades.dat";
    _tamReg = tamanioRegistro;
}

bool ActividadesArchivo::comprobarArchivo() const {
    FILE* pActividad;
    Actividad reg;
    bool lecturaExitosa = true;


    pActividad = fopen(_ruta.c_str(), "rb");
    if (pActividad == nullptr) {
        lecturaExitosa = false;
        // devuelve -2 si no puede abrir el archivo
    }
    else {
        fclose(pActividad);
    }

    return lecturaExitosa;
}

bool ActividadesArchivo::listarRegistro() const {
    Actividad reg;
    FILE* pActividad;

    pActividad = fopen(_ruta.c_str(), "rb");
    if (pActividad == nullptr) {
        return false;
    }

    while (fread(&reg, _tamReg, 1, pActividad) == 1) {
        reg.mostrar();
    }

    fclose(pActividad);
    return true;
}

bool ActividadesArchivo::guardar(const Actividad& reg) const {
    FILE* pActividad;
    pActividad = fopen(_ruta.c_str(), "ab");
    bool result;

    if (pActividad == nullptr) {
        return false;
    }

    result = fwrite(&reg, _tamReg, 1, pActividad) == 1;
    fclose(pActividad);
    return result;
}

int ActividadesArchivo::buscar(int id) const {
    FILE* pActividad;
    Actividad reg;
    int pos = 0;

    pActividad = fopen(_ruta.c_str(), "rb");
    if (pActividad == nullptr) {
        return -2;
        // devuelve -2 si no puede abrir el archivo
    }

    while (fread(&reg, _tamReg, 1, pActividad) == 1) {
        if (reg.getId() == id) {
            fclose(pActividad);
            return pos;
            // devuelve la posici�n si lo encuentra
        }
        pos++;
    }

    fclose(pActividad);
    return -1;
    // devuelve -1 si no lo encuentra
}

int ActividadesArchivo::contarRegistros() const {
    FILE* pActividad;
    pActividad = fopen(_ruta.c_str(), "rb");

    if (pActividad == nullptr) {
        return 0;
    }

    fseek(pActividad, 0, SEEK_END);
    int total = ftell(pActividad);

    fclose(pActividad);
    return total / _tamReg;
}

bool ActividadesArchivo::modificarRegistro(const Actividad& reg, int pos) const {
    FILE* pActividad;
    pActividad = fopen(_ruta.c_str(), "rb+");

    if (pActividad == nullptr) {
        return false;
    }

    fseek(pActividad, pos * _tamReg, SEEK_SET);
    bool escribio = fwrite(&reg, _tamReg, 1, pActividad) == 1;
    fclose(pActividad);
    return escribio;
}

Actividad ActividadesArchivo::leerRegistro(int ubi) const {
    FILE* pActividad;
    Actividad reg;

    pActividad = fopen(_ruta.c_str(), "rb");
    if (pActividad == nullptr) {
        return reg;
    }

    fseek(pActividad, ubi * _tamReg, SEEK_SET);
    fread(&reg, _tamReg, 1, pActividad);
    fclose(pActividad);
    return reg;
}
