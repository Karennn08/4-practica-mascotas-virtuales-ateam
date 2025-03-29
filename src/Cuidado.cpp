#include "Cuidado.h"
#include <iostream>

Cuidado::Cuidado(string fecha, string tipoCuidado, string objetoUsado, string estadoSalud)
{
    this->fecha = fecha;
    this->tipoCuidado = tipoCuidado;
    this->objetoUsado = objetoUsado;
    this->estadoSalud = estadoSalud;
}

void Cuidado::mostrarInfo(){
    cout << "Fecha: " << fecha << "\n";
    cout << "Tipo: " << tipoCuidado << "\n";
    if (!objetoUsado.empty()) {
        std::cout << "Objeto usado: " << objetoUsado << "\n";
    }
    cout << "Salud: " << estadoSalud << "\n";
    cout << "----------------\n";
}