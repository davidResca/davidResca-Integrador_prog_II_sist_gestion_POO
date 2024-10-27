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
    bool listarRegistro() const;
    bool guardar(const Profe& reg) const;
    int buscar(int id) const;
    Profe leerRegistro(int ubi) const;
    int contarRegistros() const;
    bool modificarRegistro(const Profe& reg, int pos) const;
    ~ProfesArchivo() override {};
};
