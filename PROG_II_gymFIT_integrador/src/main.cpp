#include <iostream>
#include "Inscripciones.h"
#include "InscripcionesArchivo.h"
#include "Fecha.h"
#include "Actividad.h"
#include "ActividadesArchivo.h"
#include "Empleado.h"
#include "IArchivable.h"
#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "Profe.h"
#include "ProfesArchivo.h"
#include "Horario.h"
#include "HorarioArchivo.h"
#include "FuncionesFiltrado.h"
#include "Menu.h"   

using namespace std;


int main() {
	
    Menu menu;
    int opcion;

    do {
        menu.mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        menu.procesarOpcion(opcion);
    } while (opcion != 0);

    return 0;

}

























