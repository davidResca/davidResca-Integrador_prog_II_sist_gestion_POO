#pragma once
#include <iostream>
#include <string> 
#include <stdexcept>

class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

    bool esDiaValido(int dia, int mes, int anio);
    bool esMesValido(int mes);
    bool esAnioValido(int anio);
    bool esAnioBisiesto(int anio);

    int getCantidadDiasDelMes(int mes, int anio);
    void setFechaDefault();
    void validarIngreso(int dia, int mes, int anio);
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    std::string toString();
    int getDia();
    int getMes();
    int getAnio();
    void aumentarDia();
    void restarDia();


    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
};