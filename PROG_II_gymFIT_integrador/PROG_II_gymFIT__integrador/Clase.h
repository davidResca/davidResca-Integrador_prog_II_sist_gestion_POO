#pragma once
#include <iostream>
#include "DiaHorario.h"
#include "Actividad.h"

class Clase :
    public Actividad
{
private: 
    int _idProfe;
    int _idClase;
    int _cantidadInscriptos;
public:
    Clase();
    Clase(std::string nombreActividad, int idLugarDeDesarrollo,int idProfe, int idClase, int cantidadInscriptos);
    int getIdClase() const;
    int getCantidadInscriptos() const;
    int getIdProfe() const;

    // interfaz
    void mostrarClase() const;

    ~Clase();
};


