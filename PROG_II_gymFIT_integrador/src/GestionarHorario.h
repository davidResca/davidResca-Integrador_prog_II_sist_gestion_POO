#pragma once
#include "Horario.h" // Asegúrate de que el nombre del archivo y la clase sean correctos
#include "HorarioArchivo.h" // Clase de archivo que maneja la persistencia de DiaHorario
#include "Utilidades.h"

class GestionarHorario
{
public:
    GestionarHorario();
    Horario cargarHorario();
    void altaHorario();
    void bajaHorario();
    void listarHorarios();
    void buscarHorario();

private:
    HorarioArchivo archivoHorarios;
    int obtenerIdNuevo();
};
