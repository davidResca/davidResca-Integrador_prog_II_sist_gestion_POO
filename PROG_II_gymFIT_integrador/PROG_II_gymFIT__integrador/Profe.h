#pragma once
#include "Empleado.h"
class Profe :
    public Empleado
{
private:
    int _idProfe;
    float _salarioHora;
public: 
    Profe();
    Profe(std::string nombre, std::string apellido, int dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, int CUIT, const std::string& observaciones, int idProfe, float salarioHora);
    
    // setters
    void setSalarioHora(float salarioHora);
    void setIdProfe(int idProfe);

    //getters
    int getIdProfe() const;
    float getSalarioHora() const;
  
    // interfaz
    void mostrar() {
        Empleado::mostrar();
        std::cout << "id profe: " << getIdProfe();
        std::cout << "Salario por hora: " << getSalarioHora();
    }

    //destructor
    ~Profe();
};

