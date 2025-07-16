#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Curso {
    string nombre;
    vector<Curso*> siguientes;

    Curso(string n) : nombre(n) {}
};

// Buscar curso por nombre
Curso* buscarCurso(vector<Curso*>& cursos, const string& nombre) {
    for (auto c : cursos) {
        if (c->nombre == nombre) return c;
    }
    return nullptr;
}

// Mostrar cursos desbloqueados
void mostrarSiguientes(Curso* curso) {
    cout << "\nSi apruebas \"" << curso->nombre << "\" puedes llevar:\n";
    if (curso->siguientes.empty()) {
        cout << "  - Ninguno (es un curso terminal o aún no se ha vinculado)\n";
    } else {
        for (auto sig : curso->siguientes) {
            cout << "  - " << sig->nombre << endl;
        }
    }
}

int main() {
    vector<Curso*> cursos;

    // Crear cursos

     Curso* comprension = new Curso("COMPRENSION Y ARGUMENTACION");
     Curso* pensamiento = new Curso("PENSAMIENTO RACIONAL Y ETICA");
     Curso* matematica_basica = new Curso("MATEMATICA BASICA");
     Curso* estadistica_basica = new Curso("ESTADISTICA BASICA");
     Curso* taller_innovacion = new Curso("TALLER DE INNOVACION Y EMPRENDIMIENTO");
     Curso* ecologia = new Curso("ECOLOGIA Y DESARROLLO SOSTENIBLE");
     
     Curso* estrategias = new Curso("ESTRATEGIAS DE APRENDIZAJE");
     Curso* quimica = new Curso("QUIMICA GENERAL");
     Curso* calculo_diferencial = new Curso("CALCULO DIFERENCIAL");
     Curso* fisica = new Curso("FISICA GENERAL");
     Curso* calculo_probabilidades = new Curso("CALCULO DE PROBABILIDADES");
     Curso* analisis_algoritmos = new Curso("ANALISIS Y DISEÑOS DE ALGORITMOS");

     Curso* calculo_integral = new Curso("CALCULO INTEGRAL Y ECUACIONES DIFERENCIALES");
     Curso* seguridad_nacional = new Curso("SEGURIDAD Y DEFENSA NACIONAL");
     Curso* estructuras_datos = new Curso("ESTRUCTURA DE DATOS");
     Curso* muestreo = new Curso("MUESTREO");
     Curso* distribuciones = new Curso("DISTRIBUCIONES DE PROBABILIDAD");
     Curso* lenguajes_prog1 = new Curso("LENGUAJES DE PROGRAMACION I");
     Curso* ingles = new Curso("INGLES");
     
     Curso* sistemas_bd1 = new Curso("SISTEMAS DE GESTION DE BASE DE DATOS I");
     Curso* lenguajes_prog2 = new Curso("LENGUAJES DE PROGRAMACION II");
     Curso* programacion_numerica = new Curso("PROGRAMACION NUMERICA");
     Curso* inferencia_estadistica = new Curso("INFERENCIA ESTADISTICA");
     Curso* modelos_discretos = new Curso("MODELOS DISCRETOS");
     Curso* analisis_sistemas_info = new Curso("ANALISIS Y DISEÑO DE SISTEMAS DE INFORMACION");
     
     Curso* metodos_optimizacion = new Curso("METODOS DE OPTIMIZACION");
     Curso* lenguajes_prog3 = new Curso("LENGUAJES DE PROGRAMACION III");
     Curso* arquitectura_computadoras = new Curso("ARQUITECTURA DE COMPUTADORAS");
     Curso* estadistica_no_parametrica = new Curso("ESTADISTICA NO PARAMETRICA");
     Curso* estadistica_computacional = new Curso("ESTADISTICA COMPUTACIONAL");
     Curso* sistemas_bd2 = new Curso("SISTEMAS DE GESTION DE BASE DE DATOS II");
     
     Curso* aprendizaje_no_supervisado = new Curso("APRENDIZAJE NO SUPERVISADO");
     Curso* gestion_proyectos_tics = new Curso("GESTION DE PROYECTOS TICS");
     Curso* arquitectura_redes = new Curso("ARQUITECTURA DE REDES Y PROTOCOLOS");
     Curso* series_tiempo = new Curso("SERIES DE TIEMPO");
     Curso* regresion_lineal = new Curso("REGRESION LINEAL Y NO LINEAL");
     Curso* modelos_lineales = new Curso("MODELOS LINEALES");
     
     Curso* sistemas_distribuidos = new Curso("SISTEMAS DISTRIBUIDOS");
     Curso* estadistica_bayesiana = new Curso("ESTADISTICA BAYESIANA");
     Curso* ingenieria_software1 = new Curso("INGENIERIA DE SOFTWARE I");
     Curso* metodologia_investigacion = new Curso("METODOLOGIA DE LA INVESTIGACION");
     Curso* aprendizaje_supervisado = new Curso("APRENDIZAJE SUPERVISADO");
     Curso* administracion_redes = new Curso("ADMINISTRACION DE REDES");
     
    Curso* computacion_paralela = new Curso("COMPUTACION PARALELA");
    Curso* ingenieria_software2 = new Curso("INGENIERIA DE SOFTWARE II");
    Curso* marketing = new Curso("MARKETING");
    Curso* ciencia_datos1 = new Curso("CIENCIA DE DATOS I");
    Curso* disenos_experimentales1 = new Curso("DISEÑOS EXPERIMENTALES I");
    Curso* taller_software = new Curso("TALLER DE DESARROLLO DE SOFTWARE");
    Curso* control_estadistico = new Curso("CONTROL ESTADISTICO DE PROCESOS");
    
    Curso* seguridad_auditoria = new Curso("SEGURIDAD Y AUDITORIA INFORMATICA");
    Curso* ciencia_datos2 = new Curso("CIENCIA DE DATOS II");
    Curso* iot_nubes = new Curso("INTERNET DE LAS COSAS Y COMPUTACION EN LAS NUBES");
    Curso* disenos_experimentales2 = new Curso("DISEÑOS EXPERIMENTALES II");
    Curso* investigacion_mercados = new Curso("INVESTIGACION DE MERCADOS");
    Curso* inteligencia_artificial = new Curso("INTELIGENCIA ARTIFICIAL");
    Curso* taller_estadistica = new Curso("TALLER DE ESTADISTICA");
    
    Curso* taller_tesis = new Curso("TALLER DE TESIS");
    Curso* tecnologias_emergentes = new Curso("TECNOLOGIAS EMERGENTES");
    Curso* estadistica_espacial = new Curso("ESTADISTICA ESPACIAL");
    Curso* inteligencia_negocios = new Curso("INTELIGENCIA DE NEGOCIOS");
    Curso* practicas_profesionales = new Curso("PRACTICAS PRE PROFESIONALES");

    // Agregar cursos al vector
    cursos.push_back(comprension);
    cursos.push_back(pensamiento);
    cursos.push_back(matematica_basica);
    cursos.push_back(estadistica_basica);
    cursos.push_back(taller_innovacion);
    cursos.push_back(ecologia);
    
    cursos.push_back(estrategias);
    cursos.push_back(quimica);
    cursos.push_back(calculo_diferencial);
    cursos.push_back(fisica);
    cursos.push_back(calculo_probabilidades);
    cursos.push_back(analisis_algoritmos);
    
    cursos.push_back(calculo_integral);
    cursos.push_back(seguridad_nacional);
    cursos.push_back(estructuras_datos);
    cursos.push_back(muestreo);
    cursos.push_back(distribuciones);
    cursos.push_back(lenguajes_prog1);
    cursos.push_back(ingles);
    
    cursos.push_back(sistemas_bd1);
    cursos.push_back(lenguajes_prog2);
    cursos.push_back(programacion_numerica);
    cursos.push_back(inferencia_estadistica);
    cursos.push_back(modelos_discretos);
    cursos.push_back(analisis_sistemas_info);
    
    cursos.push_back(metodos_optimizacion);
    cursos.push_back(lenguajes_prog3);
    cursos.push_back(arquitectura_computadoras);
    cursos.push_back(estadistica_no_parametrica);
    cursos.push_back(estadistica_computacional);
    cursos.push_back(sistemas_bd2);
    
    cursos.push_back(aprendizaje_no_supervisado);
    cursos.push_back(gestion_proyectos_tics);
    cursos.push_back(arquitectura_redes);
    cursos.push_back(series_tiempo);
    cursos.push_back(regresion_lineal);
    cursos.push_back(modelos_lineales);
    
    cursos.push_back(sistemas_distribuidos);
    cursos.push_back(estadistica_bayesiana);
    cursos.push_back(ingenieria_software1);
    cursos.push_back(metodologia_investigacion);
    cursos.push_back(aprendizaje_supervisado);
    cursos.push_back(administracion_redes);
    
    cursos.push_back(computacion_paralela);
    cursos.push_back(ingenieria_software2);
    cursos.push_back(marketing);
    cursos.push_back(ciencia_datos1);
    cursos.push_back(disenos_experimentales1);
    cursos.push_back(taller_software);
    cursos.push_back(control_estadistico);
    
    cursos.push_back(seguridad_auditoria);
    cursos.push_back(ciencia_datos2);
    cursos.push_back(iot_nubes);
    cursos.push_back(disenos_experimentales2);
    cursos.push_back(investigacion_mercados);
    cursos.push_back(inteligencia_artificial);
    cursos.push_back(taller_estadistica);
    
    cursos.push_back(taller_tesis);
    cursos.push_back(tecnologias_emergentes);
    cursos.push_back(estadistica_espacial);
    cursos.push_back(inteligencia_negocios);
    cursos.push_back(practicas_profesionales);

    // Establecer relaciones de dependencias
    matematica_basica->siguientes.push_back(calculo_diferencial);
    estadistica_basica->siguientes.push_back(calculo_probabilidades);
    calculo_diferencial->siguientes.push_back(calculo_integral);
    analisis_algoritmos->siguientes.push_back(estructuras_datos);
    calculo_probabilidades->siguientes.push_back(distribuciones);
    analisis_algoritmos->siguientes.push_back(lenguajes_prog1);
    estructuras_datos->siguientes.push_back(sistemas_bd1); 
    estructuras_datos->siguientes.push_back(analisis_sistemas_info);
    lenguajes_prog1->siguientes.push_back(lenguajes_prog2);
    calculo_integral->siguientes.push_back(programacion_numerica);
    calculo_integral->siguientes.push_back(modelos_discretos);
    distribuciones->siguientes.push_back(inferencia_estadistica);
    programacion_numerica->siguientes.push_back(metodos_optimizacion);
    lenguajes_prog2->siguientes.push_back(lenguajes_prog3);
    fisica->siguientes.push_back(arquitectura_computadoras);
    muestreo->siguientes.push_back(estadistica_no_parametrica);
    inferencia_estadistica->siguientes.push_back(estadistica_computacional);
    sistemas_bd1->siguientes.push_back(sistemas_bd2);
    estadistica_computacional->siguientes.push_back(aprendizaje_supervisado);
    sistemas_bd2->siguientes.push_back(gestion_proyectos_tics);
    arquitectura_computadoras->siguientes.push_back(arquitectura_redes);
    estadistica_no_parametrica->siguientes.push_back(series_tiempo);
    metodos_optimizacion->siguientes.push_back(regresion_lineal);
    modelos_discretos->siguientes.push_back(modelos_lineales);
    arquitectura_redes->siguientes.push_back(sistemas_distribuidos);
    series_tiempo->siguientes.push_back(estadistica_bayesiana);
    lenguajes_prog3->siguientes.push_back(ingenieria_software1);
    gestion_proyectos_tics->siguientes.push_back(ingenieria_software1);
    modelos_lineales->siguientes.push_back(metodologia_investigacion);
    aprendizaje_no_supervisado->siguientes.push_back(aprendizaje_supervisado);
    arquitectura_redes->siguientes.push_back(administracion_redes);
    sistemas_distribuidos->siguientes.push_back(computacion_paralela);
    administracion_redes->siguientes.push_back(computacion_paralela);
    ingenieria_software1->siguientes.push_back(ingenieria_software2);
    estadistica_bayesiana->siguientes.push_back(marketing);
    aprendizaje_supervisado->siguientes.push_back(ciencia_datos1);
    regresion_lineal->siguientes.push_back(disenos_experimentales1);
    ingenieria_software1->siguientes.push_back(taller_software);
    metodologia_investigacion->siguientes.push_back(control_estadistico);
    computacion_paralela->siguientes.push_back(seguridad_auditoria);
    ciencia_datos1->siguientes.push_back(ciencia_datos2);
    ingenieria_software2->siguientes.push_back(iot_nubes);
    disenos_experimentales1->siguientes.push_back(disenos_experimentales2);
    control_estadistico->siguientes.push_back(investigacion_mercados);
    marketing->siguientes.push_back(investigacion_mercados);
    taller_software->siguientes.push_back(inteligencia_artificial);
    ciencia_datos1->siguientes.push_back(taller_estadistica);
    iot_nubes->siguientes.push_back(taller_tesis);
    inteligencia_artificial->siguientes.push_back(taller_tesis);
    taller_estadistica->siguientes.push_back(tecnologias_emergentes);
    ciencia_datos2->siguientes.push_back(tecnologias_emergentes);
    seguridad_auditoria->siguientes.push_back(estadistica_espacial);
    investigacion_mercados->siguientes.push_back(inteligencia_negocios);
    seguridad_auditoria->siguientes.push_back(practicas_profesionales);
    ciencia_datos2->siguientes.push_back(practicas_profesionales);
    iot_nubes->siguientes.push_back(practicas_profesionales);
    disenos_experimentales2->siguientes.push_back(practicas_profesionales);
    investigacion_mercados->siguientes.push_back(practicas_profesionales);
    inteligencia_artificial->siguientes.push_back(practicas_profesionales);
    taller_estadistica->siguientes.push_back(practicas_profesionales);

    // Interacción con el usuario
    string nombreBuscado;
    cout << "Ingrese el nombre del curso aprobado (por ejemplo: MATEMATICA BASICA): ";
    getline(cin, nombreBuscado); // Para permitir espacios

    Curso* encontrado = buscarCurso(cursos, nombreBuscado);
    if (encontrado) {
        mostrarSiguientes(encontrado);
    } else {
        cout << "Curso no encontrado. Verifique el nombre ingresado.\n";
    }

    for (auto c : cursos) delete c;

    return 0;
}