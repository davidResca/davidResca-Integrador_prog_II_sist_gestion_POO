#include "FuncionesFiltrado.h"

void filtrarClasesPorProfesor(int idProfe) {
    ActividadesArchivo clasesArchivo(sizeof(Actividad));
    ProfesArchivo profesArchivo(sizeof(Profe));

    bool leyoArchClases = clasesArchivo.comprobarArchivo();
    bool leyoArchProfes = profesArchivo.comprobarArchivo();
    if (!leyoArchClases || !leyoArchProfes) {
        std::cout << "No se pudo leer el arhivo" << std::endl;
        return;
    }


    int posProfe = profesArchivo.buscar(idProfe);
    if (posProfe == -1) {
        std::cerr << "No se encontro el Profesor. " << std::endl;
        return;
    }

    Profe profesor = profesArchivo.leerRegistro(posProfe);
    std::cout << "Clases del profesor: " << profesor.getNombre() << " " << profesor.getApellido() << std::endl;

    bool encontrado = false;
    for (int i = 0; i < clasesArchivo.contarRegistros(); i++) {
        Actividad clase = clasesArchivo.leerRegistro(i);
        if (clase.getIdProfe() == idProfe) {
            clase.mostrar();
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron clases del Profesor." << std::endl;
    }
}

void verListaProfesPorClase(int idClase) {
    ActividadesArchivo clasesArchivo(sizeof(Actividad));
    ProfesArchivo profesArchivo(sizeof(Profe));

    Actividad clase;
    Profe profesor;

    bool claseEncontrada = false;

    std::cout << "Lista de Profesores para la Clase con ID: " << idClase << std::endl;

    for (int i = 0; i < clasesArchivo.contarRegistros(); i++) {
        clase = clasesArchivo.leerRegistro(i);

        if (clase.getId() == idClase) {
            claseEncontrada = true;

            std::cout << "Clase: " << clase.getNombreActividad() << std::endl;
            std::cout << "Profesor ID: " << clase.getIdProfe() << std::endl;

            for (int x = 0; x < profesArchivo.contarRegistros(); x++) {
                profesor = profesArchivo.leerRegistro(x);

                if (profesor.getIdProfe() == clase.getIdProfe()) {
                    profesor.mostrar();
                    break;
                }
            }
        }
    }

    if (!claseEncontrada) {
        std::cout << "No se encontraron Profesores para la clase con ID: " << idClase << std::endl;
    }
}

void verListadoTotalProfesores() {
    ProfesArchivo profesArchivo(sizeof(Profe));
    Profe profesor;

    std::cout << "Listado Total de Profesores: " << std::endl;

    int totalProfesores = profesArchivo.contarRegistros();

    if (totalProfesores == 0) {
        std::cout << "No hay profesores registrados en el sistema." << std::endl;
        return;
    }

    for (int i = 0; i < totalProfesores; i++) {
        profesor = profesArchivo.leerRegistro(i);
        profesor.mostrar();
    }

}

void buscarProfe(int idProfe) {
    ProfesArchivo profesArchivo(sizeof(Profe));
    Profe profesor;

    int pos = profesArchivo.buscar(idProfe);

    if (pos != -1) {
        profesor = profesArchivo.leerRegistro(pos);
        std::cout << "Profesor encontrado" << std::endl;
        profesor.mostrar();
    }
    else {
        std::cout << "No se encontro un Profesor con el ID: " << idProfe << std::endl;
    }

}

void buscarAlumno(int idAlumno) {
    ArchivoAlumnos alumnoArchivos(sizeof(Alumno));
    Alumno alumno;

    int pos = alumnoArchivos.buscar(idAlumno);

    if (pos != -1) {
        alumno = alumnoArchivos.leerRegistro(pos);
        std::cout << "Alumno encontrado" << std::endl;
        alumno.mostrar();

    }
    else {
        std::cout << "No se encontro un Alumno con el ID: " << idAlumno << std::endl;
    }
}

void altaProfe() {
    ProfesArchivo profesArchivo(sizeof(Profe));
    Profe profeNuevo;

    long long dni, CUIT, telefono;
    float horasTrabajadas = 0, salarioHora;
    int idProfe, edad, diaNac, mesNac, anioNac, diaAlta, mesAlta, anioAlta;
    std::string nombre, apellido, correoElectronico, observaciones, direccion;

    std::cout << " ALTA PROFE: " << std::endl;
    std::cout << " --------------------- " << std::endl;
    std::cout << std::endl;

    std::cout << "Nombre: " << std::endl;
    std::cin >> nombre;

    std::cout << "Apellido: " << std::endl;
    std::cin >> apellido;

    std::cin.ignore();
    std::cout << "Observaciones: " << std::endl;
    std::getline(std::cin, observaciones);
    
    std::cout << "Direccion: " << std::endl;
    std::getline(std::cin, direccion);

    std::cout << "DNI: " << std::endl;
    std::cin >> dni;

    std::cout << "CUIT: " << std::endl;
    std::cin >> CUIT;

    std::cout << "Edad: " << std::endl;
    std::cin >> edad;

    std::cout << "Fecha Nacimiento: " << std::endl;
    std::cout << "dia: " << std::endl;
    std::cin >> diaNac;
    std::cout << "mes: " << std::endl;
    std::cin >> mesNac;
    std::cout << "anio: " << std::endl;
    std::cin >> anioNac;

    std::cout << "Asignar ID: " << std::endl;
    std::cin >> idProfe;

    std::cout << "Fecha Alta: " << std::endl;
    std::cout << "dia: " << std::endl;
    std::cin >> diaAlta;
    std::cout << "mes: " << std::endl;
    std::cin >> mesAlta;
    std::cout << "anio: " << std::endl;
    std::cin >> anioAlta;

    std::cout << "telefono: " << std::endl;
    std::cin >> telefono;

    std::cout << "Salario a cobrar por hora: " << std::endl;
    std::cin >> salarioHora;

    profeNuevo = Profe(nombre, apellido, dni, edad, diaNac, mesNac, anioNac, correoElectronico, diaAlta, mesAlta, anioAlta, horasTrabajadas, CUIT, observaciones, idProfe, salarioHora, direccion, telefono);

    system("cls");
    int guardaRegistro;
    std::cout << "Usted está por guardar el siguiente registro:" << std::endl;
    profeNuevo.mostrar();
    std::cout << "Desea guardar?" << std::endl;
    std::cout << "1. SI" << std::endl;
    std::cout << "2. NO" << std::endl;
    std::cin >> guardaRegistro;
    system("pause");

    if (guardaRegistro == 2) {
        return;
    }


    profesArchivo.guardar(profeNuevo);
    profesArchivo.listarRegistro();
}

void altaClase() {
    ActividadesArchivo clasesArchivo(sizeof(Actividad));
    DiaHoraArchivo diaHoraClaseArchivo(sizeof(DiaHorario));

    Actividad clase;
    DiaHorario diaHorarioClase;

    int idHorario, idActividad, idProfe, idLugarDeDesarrollo, cantMax, horaInicio, horaFin, cantInscriptos = 0;
    std::string descripcion, actividadNombre, dia;
    bool estado = true;

    std::cout << " REGISTRAR NUEVA CLASE: " << std::endl;
    std::cout << " --------------------- " << std::endl;
    std::cout << std::endl;

    std::cout << "Id de actividad: " << std::endl;
    std::cin >> idActividad;

    std::cin.ignore();

    std::cout << "Nombre de la clase: " << std::endl;
    std::getline(std::cin, actividadNombre);
    std::cout << "Descripcion: " << std::endl;
    std::getline(std::cin, descripcion);
    std::cout << "Dia de dictado: " << std::endl;
    std::getline(std::cin, dia);

    std::cout << "Identificador de Horario  (id): " << std::endl;
    std::cin >> idHorario;

    std::cout << "hora inicio (ingresar enteros): " << std::endl;
    std::cin >> horaInicio;
    std::cout << "hora fin (ingresar enteros): " << std::endl;
    std::cin >> horaFin;

    std::cout << "Id del Profesor/a: " << std::endl;
    std::cin >> idProfe;
    std::cout << "Id salon: " << std::endl;
    std::cin >> idLugarDeDesarrollo;
    std::cout << "Cantidad maxima alumnos: " << std::endl;
    std::cin >> cantMax;

    // int idActividad, std::string nombreActividad, int idLugarDeDesarrollo, int idProfe, int cantMax, std::string descripcion, bool estado
    clase = Actividad(idActividad, actividadNombre, idLugarDeDesarrollo, idProfe, cantMax, descripcion, estado);
    //clase = Clase(1, "rpm", 4, 2, 4, 0, 30, "clase divertida de rpm");
    diaHorarioClase = DiaHorario(idHorario, idActividad, dia, horaInicio, horaFin, estado);
    //diaHorarioClase = DiaHorario(2, 2, "lunes", 15, 16);

    system("cls");
    int guardaRegistro;
    std::cout << "Usted está por guardar el siguiente registro:" << std::endl;
    clase.mostrar();
    std::cout << "Desea guardar?" << std::endl;
    std::cout << "1. SI" << std::endl;
    std::cout << "2. NO" << std::endl;
    std::cin >> guardaRegistro;
    system("pause");

    if (guardaRegistro == 2) {
        return;
    }

    clasesArchivo.guardar(clase);
    diaHoraClaseArchivo.guardar(diaHorarioClase);

    clasesArchivo.listarRegistro();
    std::cout << std::endl;
    diaHoraClaseArchivo.listarRegistro();

    /*darAltaRegistro(clasesArchivo, clase);
    darAltaRegistro(diaHoraClaseArchivo, diaHorarioClase);
    mostrarListarRegistros(clasesArchivo);
    mostrarListarRegistros(diaHoraClaseArchivo);*/
}

