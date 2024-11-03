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
    Profe(std::string nombre, std::string apellido, long long dni, int edad, int diaNasc, int mesNasc, int anioNasc, std::string correoElectronico, int diaAlta, int mesAlta, int anioAlta, float horasTrabajadas, long long CUIT, const std::string& observaciones, int idProfe, float salarioHora);
    
    // setters
    void setSalarioHora(float salarioHora);
    void setIdProfe(int idProfe);

    //getters
    int getIdProfe() const;
    float getSalarioHora() const;
  
    // interfaz
    void mostrar();

    //destructor
    ~Profe();
};

