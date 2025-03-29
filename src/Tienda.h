#ifndef TIENDA_H
#define TIENDA_H
#include <iostream>
#include <string>
#include "Habilidad.h"
#include "Objeto.h"
#include "Usuario.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Tienda {

public:
    Tienda();
    Tienda(string nombre, string pais);
    string getNombre();
    string getPais();
    void mostrarHabilidades();
    void mostrarObjetos();
    void mostrarUsuarios();

    void registrarHabilidades(Habilidad habilidad);
    void registrarObjetos(Objeto* objeto);
    void registrarUsuarios(Usuario usuario);

    vector<Objeto*>& getObjetos();
    vector<Usuario>& getUsuarios();
    vector<Habilidad>& getHabilidades();

private:
    string nombre;
    string pais;
    vector<Habilidad> habilidades;
    vector<Objeto*> objetos;
    vector<Usuario> usuarios;
};



#endif //TIENDA_H
