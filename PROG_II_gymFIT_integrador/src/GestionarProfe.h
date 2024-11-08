#pragma once

#include "Profe.h"
#include "ProfesArchivo.h"

class GestionarProfe
{
public:
	GestionarProfe();

private:
	ProfesArchivo archivoProfe;
	int obtenerIdNuevo();
};

