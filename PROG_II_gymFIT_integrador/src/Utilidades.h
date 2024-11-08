#pragma once
#include <algorithm>
#include <iostream>


using namespace std;



class Utilidades {
public:
    template <typename Archivo, typename Entidad>
    static int obtenerIdNuevo(Archivo& archivo) {
        int maxID = 0;
        int totalRegistros = archivo.contarRegistros();

        for (int i = 0; i < totalRegistros; ++i) {
            Entidad entidad = archivo.leerRegistro(i);
            maxID = max(maxID, entidad.getId());
        }

        return maxID + 1;
    }
};
