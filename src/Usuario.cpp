#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, int id)
{
    this->nombre = nombre;
    this->id = id;
}

void Usuario::adoptarMascota(Mascota* mascota) {
    mascotas.push_back(mascota);
    std::cout << nombre << " ha adoptado a " << mascota->getNombre() << "!\n";
}

void Usuario::mostrarMascotas() {
    std::cout << "Mascotas de " << nombre << ":\n";
    for (auto mascota : mascotas) {
        mascota->mostrarInfo();
    }
}

void Usuario::mostrarObjetos() {
    std::cout << "Objetos de " << nombre << ":\n";
    for (auto objeto : inventario) {
        objeto->mostrarInfo();
    }
}

void Usuario::usarObjeto(Objeto* objeto, Mascota* mascota) {

    objeto->aplicarEfecto(mascota);
}

void Usuario::agregarObjeto(Objeto* objeto) {
    inventario.push_back(objeto);
    std::cout << nombre << " ha agregado " << objeto->getNombre() << "!\n";
}

string Usuario::getNombre(){
    return nombre;
}

vector<Mascota*>& Usuario::getMascotas(){
    return mascotas;
}

vector<Objeto*>& Usuario::getObjetos(){
    return inventario;
}
