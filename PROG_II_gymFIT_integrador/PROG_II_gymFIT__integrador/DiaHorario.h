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

    int _idClase;
    int _idProfe;
    DiaSemana _diaSemana;
    int _horaInicio;
    int _horaFin;

    static DiaSemana convertirStringADia(const std::string& diaStr);
    std::string convertirDiaAString(const DiaSemana& dia) const;
    static void convertirAMinusculas(std::string& dia);
public:
    DiaHorario();
    DiaHorario(int idClase, int idProfe, std::string diaSemana, int horaInicio, int horaFin);

    // getters
    int getIdClase() const;
    int getIdProfe() const;
    std::string getDiaSemana() const;
    int getHoraInicio() const;
    int getHoraFin() const;

    // setters
    void setIdClase(int idClase);
    void setIdProfe(int idProfe);
    void setDiaSemana(const std::string& diaSemana);
    void setHoraInicio(int horaInicio);
    void setHoraFin(int horaFin);

    // interfaz
    void mostrarDiaHorario() const;

    // destructor
    ~DiaHorario();
};