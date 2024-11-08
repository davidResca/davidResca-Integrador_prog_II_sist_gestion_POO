#pragma once

#include "Actividad.h"
#include "ActividadesArchivo.h"


class GestionarClase
{
	public:
		GestionarClase();
		void cargarClase();
		void bajaClase();
		void buscarClase();
		void listarClases();
private:
		ActividadesArchivo clasesArchivo;
		int obtenerIdNuevo();
};

