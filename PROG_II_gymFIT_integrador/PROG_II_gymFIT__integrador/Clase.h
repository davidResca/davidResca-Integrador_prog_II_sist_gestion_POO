#pragma once
#include "Actividad.h"

class Clase :
    public Actividad
{
private:
    int _idClase;
    int cantidadInscriptos;
    int idListaAlumnos;



};

class ListaAlumnos {
private:
    int idLista;
    int listadoAlumnos[100];
};