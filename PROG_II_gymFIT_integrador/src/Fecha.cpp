#include "Fecha.h"

Fecha::Fecha()
{
    setFechaDefault();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
    validarIngreso(dia, mes, anio);
}
 
// getters
int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}

int Fecha::getCantidadDiasDelMes(int mes, int anio) {
    int cantidadDias = 0;
    int diasDelMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    esAnioBisiesto(anio) ? diasDelMes[1] = 29 : diasDelMes[1] = 28;

    cantidadDias = diasDelMes[mes - 1];

    return cantidadDias;
}

// setters
void Fecha::setFechaDefault() {
    _dia = 1;
    _mes = 1;
    _anio = 2023;
}

// validacion
void Fecha::validarIngreso(int dia, int mes, int anio) {
    bool diaValido = esDiaValido(dia, mes, anio);
    bool mesValido = esMesValido(mes);
    bool anioValido = esAnioValido(anio);

    if (!diaValido || !mesValido || !anioValido) {
        setFechaDefault();
        throw std::invalid_argument("Mensaje de error");
    }
}

bool Fecha::esAnioValido(int anio) {
    bool anioValido = false;
    if (anio >= 1) {
        anioValido = true;
    }
    return anioValido;
}
bool Fecha::esMesValido(int mes) {
    bool mesValido = false;
    if (mes >= 1 && mes <= 12) {
        mesValido = true;
    }
    return mesValido;
}
bool Fecha::esDiaValido(int dia, int mes, int anio)
{
    bool esValido = false;
    int cantidadDiasEnElMes = getCantidadDiasDelMes(mes, anio);

    if (dia >= 1 && dia <= cantidadDiasEnElMes) {
        esValido = true;
    }
    return esValido;
}
bool Fecha::esAnioBisiesto(int anio)
{
    bool esBisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    return esBisiesto;
};

// conversion
std::string Fecha::toString() {
                                 //donde,     cuántos digitos,             qué ingresa
    return std::to_string(_dia).insert(0, 2 - std::to_string(_dia).length(), '0') + "/" +
        std::to_string(_mes).insert(0, 2 - std::to_string(_mes).length(), '0') + "/" +
        std::to_string(_anio);
}

// contadores
void Fecha::aumentarDia() {
    int cantidadDiasDelMes = getCantidadDiasDelMes(_mes, _anio);

    if (_dia == cantidadDiasDelMes && _mes == 12) {
        _anio += 1;
        _dia = 1;
        _mes = 1;
    }
    else if (_dia == cantidadDiasDelMes) {
        _dia = 1;
        _mes += 1;
    }
    else {
        _dia += 1;
    }
}
void Fecha::restarDia() {
    int cantidadDiasDelMes = getCantidadDiasDelMes(_mes, _anio);

    if (_dia == 1 && _mes == 1 && _anio == 1) {
        std::cout << "No podemos registrar esa fecha, aplicando fecha por defecto..." << std::endl;
        setFechaDefault();
    }
    else if (_dia == 1 && _mes == 1) {
        _anio -= 1;
        _mes = 12;
        _dia = 31;
    }
    else if (_dia == 1) {
        int mesNuevo = _mes - 1;
        _dia = getCantidadDiasDelMes(mesNuevo, _anio);
        _mes -= 1;
    }
    else {
        _dia -= 1;
    }
}

Fecha::~Fecha()
{
}

// Imp. sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
    os << fecha._dia << "/" << fecha._mes << "/" << fecha._anio;
    return os;
}