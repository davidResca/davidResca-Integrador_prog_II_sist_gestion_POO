#include <iostream>
#include "Fecha.h"
#include "Actividad.h"
#include "Empleado.h"
#include "IArchivable.h"
#include "Alumno.h"
#include "AlumnosArchivo.h"
#include "Profe.h"
#include "ProfesArchivo.h"
#include "Clase.h"
#include "ClasesArchivo.h"
#include "DiaHorario.h"
#include "DiaHoraArchivo.h"



template<typename T, typename Archivo>
bool darAltaRegistro(T& reg){
    Archivo archivo(sizeof(T));
    reg.mostrar();
    system("pause");
    return archivo.guardar(reg);
}


int main() {

    Profe laura("laura", "pavese", 35450984, 35, 20, 12, 1989, "lau@profesgym.com", 4, 4, 2023, 345, 14354509849, "Excelente", 2, 9500);
    darAltaRegistro<Profe, ProfesArchivo>(laura);





	return 0;
}











//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA ACTIVIDAD" << std::endl;
//Actividad fiesta("fiesta en el bunker (SUM 4)", 4);
//fiesta.mostrarActividad();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA CLASE" << std::endl;
//// nombreActividad, idLugarDeDesarrollo, idProfe, idClase, cantidadInscriptos
//Clase rpm("rpm", 6, 2, 6500, 10);
//rpm.mostrarClase();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA PERSONA" << std::endl;
//Persona javier("javier", "montiel", 17634972, 55, 10, 3, 1978, "javi@javi.com");
//javier.mostrarPersona();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA EMPLEADO" << std::endl;
//Empleado franco("franco", "servini", 39882349, 30, 2, 9, 1996, "francoservini@mantenimientogim.com", 9, 9, 2024, 300, 20398823492, "Excelente trabajo, no descuidar los espejos");
//franco.mostrar();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA PROFE" << std::endl;
//Profe laura("laura", "pavese", 35450984, 35, 20, 12, 1989, "lau@profesgym.com", 4, 4, 2023, 345, 14354509849, "Excelente", 2, 9500);
//laura.mostrarProfe();
//std::cout << "-----------------------------------------------" << std::endl;
//
//std::cout << std::endl;
//
//std::cout << "-----------------------------------------------" << std::endl;
//std::cout << "INSTANCIA DIA HORARIO" << std::endl;
//DiaHorario rpmLunes(2, 2, "lunes", 15, 16);
//rpmLunes.mostrarDiaHorario();
//std::cout << "-----------------------------------------------" << std::endl;