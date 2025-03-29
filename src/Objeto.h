
#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <string>
#include "Mascota.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Objeto {
public:
    Objeto();
    Objeto(string nombre, string tipo, int efecto);
    string getNombre();
    string getTipo();
    int getEfecto();
    void setNombre(string nombre);
    void setTipo(string tipo);
    void setEfecto(int efecto);
    void mostrarInfo();

    //métodos
    void aplicarEfecto(Mascota* mascota);
private:
    string nombre;
    string tipo;
    int efecto;
};

#endif //OBJETO_H
