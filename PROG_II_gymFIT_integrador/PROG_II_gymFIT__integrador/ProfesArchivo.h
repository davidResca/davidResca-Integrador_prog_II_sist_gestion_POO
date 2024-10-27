#include <string>
#include "Profe.h"

class ProfesArchivo {
private:
    std::string _ruta;
    int _tamReg;

public:
    // Constructor
    ProfesArchivo(int tamanioRegistro);

    bool listarRegistro() const;
    bool guardar(const Profe& reg) const;
    int buscar(int id) const;
    int contarRegistros() const;
    bool modificarRegistro(const Profe& reg, int pos) const;
    Profe leerRegistro(int ubi) const;
};
