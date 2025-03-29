#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
#include "Mascota.h"
#include "Objeto.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Usuario {
public:
    Usuario();
    Usuario(string nombre, int id);
    void adoptarMascota(Mascota* mascota);
    void mostrarMascotas();
    void mostrarObjetos();
    void usarObjeto(Objeto* objeto, Mascota* mascota);
    void agregarObjeto(Objeto* objeto);
    string getNombre();
    vector<Mascota*>& getMascotas();
    vector<Objeto*>& getObjetos();
    void eliminarObjeto(std::string& nombre);

private:
    string nombre;
    int id;
    vector<Mascota*> mascotas;
    vector<Objeto*> inventario;
};



#endif //USUARIO_H
