#include <iostream>
#include "Objeto.h"

Objeto::Objeto() : nombre(""){}
Objeto::Objeto(string nombre, string tipo, int efecto)
{
    this->nombre = nombre;
    this->tipo = tipo;
    this->efecto = efecto;
}
string Objeto::getNombre()
{
    return nombre;
}
string Objeto::getTipo()
{
    return tipo;
}
int Objeto::getEfecto()
{
    return efecto;
}
void Objeto::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Objeto::setTipo(string tipo)
{
    this->tipo = tipo;
}
void Objeto::setEfecto(int efecto)
{
    this->efecto = efecto;
}

void Objeto::mostrarInfo() {
    cout << "Nombre: " << nombre << "\n";
    cout << "tipo: " << tipo << "\n";
    string ans;
    if (tipo == "comida") {
        ans = "Aumenta la energia +" + std::to_string(efecto);
    } else if (tipo == "medicina") {
        ans = "Cambia estado de salud a sano";
    } else if (tipo == "juguete") {
        ans = "Cambia estado de animo a feliz";
    }
    cout << "efecto: " << ans << "\n";
}

void Objeto::aplicarEfecto(Mascota* mascota) {
    cout << "Usando " << nombre << " en " << mascota->getNombre() << "...\n";
    cout << "Efecto: " << efecto << "\n";

    string fecha;
    cout << "Ingrese la fecha: ";
    cin >> fecha;

    if (tipo == "comida") {
        mascota->alimentar(efecto);
    } else if (tipo == "medicina") {
        mascota->cambiarEstadoSalud(SANO);
    } else if (tipo == "juguete") {
        mascota->cambiarEstadoEmocional(FELIZ);
    }
    mascota->registrarCuidado(fecha,tipo, nombre);
}
