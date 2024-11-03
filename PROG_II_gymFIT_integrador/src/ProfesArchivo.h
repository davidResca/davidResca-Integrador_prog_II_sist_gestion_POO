#pragma once
#include <string>
#include "IArchivable.h"
#include "Profe.h"

class ProfesArchivo : public IArchivable<Profe> {
private:
    std::string _ruta;
    int _tamReg;

public:
    // Constructor
    ProfesArchivo(int tamanioRegistro);

    bool comprobarArchivo() const override;
    bool listarRegistro() const override;
    bool guardar(const Profe& reg) const override;
    int buscar(int id) const override;
    Profe leerRegistro(int ubi) const override;
    int contarRegistros() const override;
    bool modificarRegistro(const Profe& reg, int pos) const override;
    ~ProfesArchivo() override {};
};
