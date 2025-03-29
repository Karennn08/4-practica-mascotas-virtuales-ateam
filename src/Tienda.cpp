#include "Tienda.h"

Tienda::Tienda(string nombre, string pais)
{
    this->nombre = nombre;
    this->pais = pais;
}
string Tienda::getNombre()
{
    return this->nombre;
}
string Tienda::getPais()
{
    return this->pais;
}

void Tienda::mostrarHabilidades()
{
    if (habilidades.empty()) {
        cout << nombre << " no hay ninguna habilidad en"+ nombre +"\n";
        return;
    }

    cout << "Habilidades de " << nombre << ":\n";
    for (auto& habilidad : habilidades) {
        cout << "- " << habilidad.getNombre() << ": " << habilidad.getDescripcion() << "\n";
    }
}
void Tienda::mostrarUsuarios()
{
    std::cout << "Usuarios de " << nombre << ":\n";
    for (auto usuario : usuarios) {
        usuario.getNombre();
    }
}
void Tienda::mostrarObjetos()
{
    std::cout << "Objetos de " << nombre << ":\n";
    for (auto objeto : objetos) {
        objeto->mostrarInfo();
    }
}

void Tienda::registrarHabilidades(Habilidad habilidad)
{
    habilidades.push_back(habilidad);
    std::cout << nombre << " ha agregado " << habilidad.getNombre() << "!\n";
}
void Tienda::registrarUsuarios(Usuario usuario)
{
    usuarios.push_back(usuario);
    std::cout << nombre << " ha agregado " << usuario.getNombre() << "!\n";
}
void Tienda::registrarObjetos(Objeto* objeto)
{
    objetos.push_back(objeto);
    std::cout << nombre << " ha agregado " << objeto->getNombre() << "!\n";
}

vector<Habilidad>& Tienda::getHabilidades()
{
    return habilidades;
}
vector<Usuario>& Tienda::getUsuarios()
{
    return usuarios;
}
vector<Objeto*>& Tienda::getObjetos()
{
    return objetos;
}