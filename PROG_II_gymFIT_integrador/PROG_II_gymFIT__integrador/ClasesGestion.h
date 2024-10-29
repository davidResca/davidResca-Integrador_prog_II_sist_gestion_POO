//#pragma once
//#include "ClasesArchivo.h"
//#include "ProfesArchivo.h"
//#include "DiaHoraArchivo.h"
//#include "Clase.h"
//#include "Profe.h"
//#include "DiaHorario.h"
//
//class GestionClases {
//private:
//    ClasesArchivo claseArchivo;
//    ProfesArchivo profeArchivo;
//    DiaHoraArchivo diaHorarioArchivo;
//public:
//    GestionClases();
//
//    //// Crea una nueva clase con una actividad, un profesor, y un horario específico
//    //bool agregarClase(int actividadID, int profeID, DiaHorario diaHorario);
//    ///*
//    //* Validar ids: 
//    //*       - ¿Existen la actividad y el profesor en sus respectivos archivos?
//    //*       - ¿El profesor ya esta asignado en ese horario a otra clase?
//    //* 
//    //* Si no existen / el profesor está libre: 
//    //*       - Creo objeto, y asigno los valores. 
//    //*            - Crea un registro para DiaHorario. Ej: idClase = 1, idProfe = 6, dia = "martes", horaInicio = 9, horaFin = 10.
//    //*            - Crea un registro para Clase.
//    //*       - controlarHorarios() valida que el horario de la nueva clase no entre en conflicto con otros horarios del mismo profe.
//    //*       - si todo sale bien se guarda en los archivos correspondientes (ClasesArchivo, DiaHorarioArchivo)
//    //* 
//    //* Si se verifica alguna superposición se lanza una excepción.
//    //*/
//    //
//    //// Modifica los datos de una clase específica
//    //bool modificarClase(int claseID, int nuevaClaseID, int nuevoProfeID, DiaHorario nuevoDiaHorario);
//
//
//
//
//
//
//
//    //// Verifica que el horario no entre en conflicto con otras clases del mismo profesor
//    //bool controlarHorarios(int profeID, DiaHorario diaHorario);
//    //
//    //// Muestra información detallada de una clase específica.
//    //void mostrarDatosPorClase(int claseID);
//
//    //// Consulta y muestra los horarios de una actividad específica con un profesor en particular
//    //void consultarHorarioPorActividadYProfesor(int actividadID, int profeID);
//
//};