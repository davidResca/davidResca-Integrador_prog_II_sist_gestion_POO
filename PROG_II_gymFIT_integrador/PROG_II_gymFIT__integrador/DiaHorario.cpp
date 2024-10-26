#include "DiaHorario.h"

//constructores
DiaHorario::DiaHorario() {
    _idActividad = -1;
    _diaSemana = lunes;
    _horaInicio = -1;
    _horaFin = -1;
}
DiaHorario::DiaHorario(int idActividad, DiaSemana diaSemana, int horaInicio, int horaFin) {
    _idActividad = idActividad;
    _diaSemana = diaSemana;
    _horaInicio = horaInicio;
    _horaFin = horaFin;
}

// getters
std::string DiaHorario::getDiaSemana() const {
    std::string dia = convertirDiaAString(_diaSemana);
    
    return dia;
}
int DiaHorario::getIdActividad() const {
    return _idActividad;
}
int DiaHorario::getHoraInicio() const {
    return _horaInicio;
}
int DiaHorario::getHoraFin() const {
    return _horaFin;
}

// setters
void DiaHorario::setDiaSemana(const std::string& diaSemana) {
    _diaSemana = convertirStringADia(diaSemana);
}
void DiaHorario::setHoraInicio(int horaInicio)
{
    _horaInicio = horaInicio;
}
void DiaHorario::setHoraFin(int horaFin) {
    _horaFin = horaFin;
}

// conversores
DiaHorario::DiaSemana DiaHorario::convertirStringADia(const std::string& diaStr) {
    std::string lowerStr = diaStr; // Copia de la cadena

    // Convertir a minúsculas
    convertirAMinusculas(lowerStr);

    // Comparar y retornar el valor del enum
    if (lowerStr == "lunes") return lunes;
    else if (lowerStr == "martes") return martes;
    else if (lowerStr == "miercoles") return miercoles;
    else if (lowerStr == "jueves") return jueves;
    else if (lowerStr == "viernes") return viernes;
    else if (lowerStr == "sabado") return sabado;
    else if (lowerStr == "domingo") return domingo;
    else throw std::invalid_argument("Día inválido."); // excepción
}
std::string DiaHorario::convertirDiaAString(const DiaSemana& dia) const {
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
void DiaHorario::convertirAMinusculas(std::string& dia) {
    for (int i = 0; i < dia.size(); i++) {
        dia[i] = std::tolower(dia[i]);
    }
}

// destructor
DiaHorario::~DiaHorario()
{
}

