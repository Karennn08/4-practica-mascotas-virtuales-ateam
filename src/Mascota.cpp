#include <iostream>
#include "Mascota.h"

Mascota::Mascota(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
    this->nivelEnergia = 100;
    this->experiencia = 0;
    this->estadoSalud = ENFERMO;
    this->estadoEmocional = TRISTE;
}

void Mascota::aprenderHabilidad(Habilidad habilidad) {
    if (habilidad.puedeAprender(experiencia)) {
        habilidades.push_back(habilidad);
        cout << nombre << " ha aprendido " << habilidad.getNombre() << "!\n";
    } else {
        cout << nombre << " no tiene suficiente experiencia para aprender " << habilidad.getNombre() << ".\n";
    }
}

void Mascota::aumentarExperiencia(int cantidad) {
    experiencia += cantidad;
    cout << nombre << " ha ganado " << cantidad << " puntos de experiencia!\n";
}

void Mascota::cambiarEstadoEmocional(EstadoEmocional nuevoEstado) {
    estadoEmocional = nuevoEstado;
}

void Mascota::cambiarEstadoSalud(EstadoSalud nuevoEstado) {
    estadoSalud = nuevoEstado;
}

void Mascota::alimentar(int cantidad) {
    nivelEnergia += cantidad;
    if (nivelEnergia > 100) nivelEnergia = 100;
}

void Mascota::mostrarInfo() {
    cout << "Nombre: " << nombre << "\n";
    cout << "Edad: " << edad << " dias\n";
    cout << "Energia: " << nivelEnergia << "%\n";

    cout << "Salud: ";
    switch(estadoSalud) {
        case SANO: cout << "Sano"; break;
        case REGULAR: cout << "Regular"; break;
        case ENFERMO: cout << "Enfermo"; break;
        case MUY_ENFERMO: cout << "Muy enfermo"; break;
    }
    cout << "\n";

    cout << "Emocion: ";
    switch(estadoEmocional) {
        case FELIZ: cout << "Feliz"; break;
        case NEUTRAL: cout << "Neutral"; break;
        case TRISTE: cout << "Triste"; break;
        case ENOJADO: cout << "Enojado"; break;
    }
    cout << "\n";

    cout << "Experiencia: " << experiencia << "\n";
}

void Mascota::mostrarHabilidades() {
    if (habilidades.empty()) {
        cout << nombre << " no ha aprendido ninguna habilidad aun.\n";
        return;
    }

    cout << "Habilidades de " << nombre << ":\n";
    for (auto& habilidad : habilidades) {
        cout << "- " << habilidad.getNombre() << ": " << habilidad.getDescripcion() << "\n";
    }
}

void Mascota::mostrarHistorial() {
    if (historial.empty()) {
        cout << nombre << " no tiene historial aun.\n";
        return;
    }
    cout << "Historial de " << nombre << ":\n";
    for (auto& cuidado : historial) {
        cuidado.mostrarInfo();
    }
}

string Mascota::getNombre() {
    return nombre;
}

string Mascota::getEstadoSalud()
{
    switch(estadoSalud) {
    case SANO: return "Sano";
    case REGULAR: return "Regular";
    case ENFERMO: return "Enfermo";
    case MUY_ENFERMO: return "Muy enfermo";
    }
}


void Mascota::registrarCuidado(string fecha, string tipoCuidado, string objetoUsado) {
    string salud;
    switch(estadoSalud) {
        case SANO: salud = "Sano"; break;
        case REGULAR: salud = "Regular"; break;
        case ENFERMO: salud = "Enfermo"; break;
        case MUY_ENFERMO: salud = "Muy enfermo"; break;
    }

    Cuidado cuidado(fecha, tipoCuidado, objetoUsado, salud);
    historial.push_back(cuidado);
}