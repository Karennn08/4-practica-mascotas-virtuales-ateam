
#ifndef MASCOTA_H
#define MASCOTA_H
#include <string>
#include <vector>
#include "Habilidad.h"
#include "Cuidado.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

enum EstadoSalud { SANO, REGULAR, ENFERMO, MUY_ENFERMO };
enum EstadoEmocional { FELIZ, NEUTRAL, TRISTE, ENOJADO };

class Mascota {
public:
    Mascota();
    Mascota(string nombre, int edad);
    void aprenderHabilidad(Habilidad habilidad);
    void aumentarExperiencia(int cantidad);
    void cambiarEstadoEmocional(EstadoEmocional nuevoEstado);
    void cambiarEstadoSalud(EstadoSalud nuevoEstado);
    void alimentar(int cantidad);
    void mostrarInfo();
    void mostrarHabilidades();
    void mostrarHistorial();
    string getNombre();
    string getEstadoSalud();
    void registrarCuidado(string fecha, string tipoCuidado, string objetoUsado);
private:
    string nombre;
    int edad;
    int experiencia;
    int nivelEnergia;
    EstadoSalud estadoSalud;
    EstadoEmocional estadoEmocional;
    vector<Habilidad> habilidades;
    vector<Cuidado> historial;

};

#endif //MASCOTA_H
