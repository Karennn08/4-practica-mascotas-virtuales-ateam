
#ifndef HABILIDAD_H
#define HABILIDAD_H
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Habilidad {
public:
    Habilidad();
    Habilidad(string nombre, string descripcion, int experiencia);
    string getNombre();
    string getDescripcion();
    int getExperiencia();
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setExperiencia(int experiencia);

    bool puedeAprender(int experiencia);

private:
    string nombre;
    string descripcion;
    int experiencia; //experiencia requerida para usar la habilidad
};

#endif //HABILIDAD_H
