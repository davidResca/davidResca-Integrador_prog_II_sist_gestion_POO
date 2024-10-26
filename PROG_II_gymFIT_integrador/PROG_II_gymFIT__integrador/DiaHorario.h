#pragma once
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

class DiaHorario
{
private:
    enum DiaSemana { lunes, martes, miercoles, jueves, viernes, sabado, domingo };
    
    int _idActividad;
    DiaSemana _diaSemana;
    int _horaInicio;
    int _horaFin;

    static DiaSemana convertirStringADia(const std::string& diaStr);
    std::string convertirDiaAString(const DiaSemana& dia) const;
    static void convertirAMinusculas(std::string& dia);
public:
    DiaHorario();
    DiaHorario(int idActividad, DiaSemana diaSemana, int horaInicio, int horaFin);

    // getters
    int getIdActividad() const;
    std::string getDiaSemana() const;
    int getHoraInicio() const;
    int getHoraFin() const;

    // setters
    void setDiaSemana(const std::string& diaSemana);
    void setHoraInicio(int horaInicio);
    void setHoraFin(int horaFin);

    // destructor
    ~DiaHorario();

};