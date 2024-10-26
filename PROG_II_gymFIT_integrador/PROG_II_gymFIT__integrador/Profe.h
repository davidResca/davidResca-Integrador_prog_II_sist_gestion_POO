#pragma once
#include "Empleado.h"
class Profe :
    public Empleado
{
private:
    float _salarioHora;

public: 
    Profe(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, int CUIT, const std::string& observaciones, float ultimoSalario, float salarioHora);
    float getSalarioHora();
    void mostrar() {
        Empleado::mostrar();
        std::cout << "Salario por hora: " << getSalarioHora();
    }
};

