#include <iostream>
#include "Fecha.h"
#include "Empleado.h"
#include "Profe.h"


int main() {
	
	Profe javi("javier", "montiel", 17634972, 55, 10, 3, 1978, "javi@javi.com", 746, 2,4,2024, 0, 20176349722, "profe musculacion", "Debe prestar mas atencion a sus alumnos/as", 500000, 9500);

	javi.mostrar();
	std::cout << std::endl;
	Fecha nuevaFecha(10, 3, 1978);
	std::cout << nuevaFecha;


	return 0;
}                            