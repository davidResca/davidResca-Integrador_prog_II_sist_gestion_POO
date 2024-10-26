#pragma once
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
    Clase(int idProfe, int idClase, int cantidadInscriptos);
    int getIdClase() const;
    int getCantidadInscriptos() const;
    int getIdProfe() const;

    ~Clase();
};


