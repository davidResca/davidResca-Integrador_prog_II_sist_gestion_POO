#include "DiaHorario.h"

//constructores
DiaHorario::DiaHorario() {
    _idClase = -1;
    _idProfe = -1;
    _diaSemana = lunes;
    _horaInicio = -1;
    _horaFin = -1;
}
DiaHorario::DiaHorario(int idClase, int idProfe, std::string diaSemana, int horaInicio, int horaFin) {
    _idClase = idClase;
    _idProfe = idProfe;
    _diaSemana = convertirStringADia(diaSemana);
    _horaInicio = horaInicio;
    _horaFin = horaFin;
}

// getters
int DiaHorario::getIdClase() const {
    return _idClase;
}
int DiaHorario::getIdProfe() const
{
    return _idProfe;
}
std::string DiaHorario::getDiaSemana() const {
    std::string dia = convertirDiaAString(_diaSemana);

    return dia;
}
int DiaHorario::getHoraInicio() const {
    return _horaInicio;
}
int DiaHorario::getHoraFin() const {
    return _horaFin;
}

// setters
void DiaHorario::setIdClase(int idClase) {
    _idClase = idClase;
}
void DiaHorario::setIdProfe(int idProfe) {
    _idProfe = idProfe;
}
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

// interfaz 
void DiaHorario::mostrarDiaHorario() const {
    std::cout << "id Clase: " << getIdClase() << std::endl;
    std::cout << "id Profe: " << getIdProfe() << std::endl;
    std::cout << "Dia : " << getDiaSemana() << std::endl;
    std::cout << "Hora Comienzo: " << getHoraInicio() << std::endl;
    std::cout << "Hora Fin: " << getHoraFin() << std::endl;
}

// destructor
DiaHorario::~DiaHorario() {};

