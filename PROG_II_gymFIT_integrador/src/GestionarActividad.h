#pragma once
#include "Actividad.h"
#include "ActividadesArchivo.h" // Clase de archivo que maneja la persistencia de Actividad
#include "Utilidades.h"

class GestionarActividad
{
public:
    GestionarActividad();
    //Todo-Jesus: Revisar lo de alta y carga
    Actividad cargarActividad();
    void altaActividad();
    void bajaActividad();
    void listarActividades();
    void buscarActividad();

private:
    ActividadesArchivo archivoActividades;
    int obtenerIdNuevo();
};
