#include "Horario.h"

//constructores
Horario::Horario() {
	_idHorario = -1;
	_idActividad = -1;
	_diaSemana = lunes;
	_horaInicio = -1;
	_horaFin = -1;
	_estado = false;
}
Horario::Horario(int idHorario, int idActividad, std::string diaSemana, int horaInicio, int horaFin, bool estado) {
	_idHorario = idHorario;
	_idActividad = idActividad;
	_diaSemana = convertirStringADia(diaSemana);
	_horaInicio = horaInicio;
	_horaFin = horaFin;
	_estado = estado;
}

// getters
int Horario::getId() const { return _idHorario; }
int Horario::getIdActividad() const {
	return _idActividad;
}
std::string Horario::getDiaSemana() const {
	std::string dia = convertirDiaAString(_diaSemana);

	return dia;
}
int Horario::getHoraInicio() const {
	return _horaInicio;
}
int Horario::getHoraFin() const {
	return _horaFin;
}

// setters
void Horario::setId(int idHorario) {
	_idHorario = idHorario;
}
void Horario::setIdActividad(int idActividad) {
	_idActividad = idActividad;
}
void Horario::setDiaSemana(const std::string& diaSemana) {
	_diaSemana = convertirStringADia(diaSemana);
}
void Horario::setHoraInicio(int horaInicio)
{
	_horaInicio = horaInicio;
}
void Horario::setHoraFin(int horaFin) {
	_horaFin = horaFin;
}

void Horario::setEstado(bool estado) {
	_estado = estado;
}

// conversores
Horario::DiaSemana Horario::convertirStringADia(const std::string& diaStr) {
	std::string lowerStr = diaStr;

	convertirAMinusculas(lowerStr);

	// Compara y retorna el valor del enum
	if (lowerStr == "lunes") return lunes;
	else if (lowerStr == "martes") return martes;
	else if (lowerStr == "miercoles") return miercoles;
	else if (lowerStr == "jueves") return jueves;
	else if (lowerStr == "viernes") return viernes;
	else if (lowerStr == "sabado") return sabado;
	else if (lowerStr == "domingo") return domingo;
	else throw std::invalid_argument("Día inválido."); // excepción
}
std::string Horario::convertirDiaAString(const DiaSemana& dia) const {
	switch (dia) {
	case lunes:     return "lunes";
	case martes:    return "martes";
	case miercoles: return "miercoles";
	case jueves:    return "jueves";
	case viernes:   return "viernes";
	case sabado:    return "sabado";
	case domingo:   return "domingo";
	default:        return "Día desconocido";
	}
}
void Horario::convertirAMinusculas(std::string& dia) {
	for (int i = 0; i < dia.size(); i++) {
		dia[i] = std::tolower(dia[i]);
	}
}

// interfaz 
void Horario::mostrarHorario() const {
	std::cout << "id registro: " << getId() << std::endl;
	std::cout << "id Clase: " << getIdActividad() << std::endl;
	std::cout << "Dia : " << getDiaSemana() << std::endl;
	std::cout << "Hora Comienzo: " << getHoraInicio() << std::endl;
	std::cout << "Hora Fin: " << getHoraFin() << std::endl;
}

// destructor
Horario::~Horario() {};