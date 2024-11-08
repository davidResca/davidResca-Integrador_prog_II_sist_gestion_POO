#pragma once
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iostream>

class DiaHorario
{
private:
    enum DiaSemana { lunes, martes, miercoles, jueves, viernes, sabado, domingo };
    
    int _idHorario;
    int _idActividad;
    DiaSemana _diaSemana;
    int _horaInicio;
    int _horaFin;
    bool _estado;

    static DiaSemana convertirStringADia(const std::string& diaStr);
    std::string convertirDiaAString(const DiaSemana& dia) const;
    static void convertirAMinusculas(std::string& dia);
public:
    DiaHorario();
    DiaHorario(int idHorario, int idActividad, std::string diaSemana, int horaInicio, int horaFin, bool estado);

    // getters
    int getId() const;
    int getIdActividad() const;
    std::string getDiaSemana() const;
    int getHoraInicio() const;
    int getHoraFin() const;

    // setters
    void setId(int idHorario);
    void setIdActividad(int idActividad);
    void setDiaSemana(const std::string& diaSemana);
    void setHoraInicio(int horaInicio);
    void setHoraFin(int horaFin);

    // interfaz
    void mostrarDiaHorario() const;

    // destructor
    ~DiaHorario();
};