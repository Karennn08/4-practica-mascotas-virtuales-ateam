
#include "Habilidad.h"

Habilidad::Habilidad(string nombre, string descripcion, int experiencia)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->experiencia = experiencia;
}
string Habilidad::getNombre()
{
    return this->nombre;
}

string Habilidad::getDescripcion()
{
    return this->descripcion;
}

int Habilidad::getExperiencia()
{
    return this->experiencia;
}

void Habilidad::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Habilidad::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Habilidad::setExperiencia(int experiencia)
{
    this->experiencia = experiencia;
}

bool Habilidad::puedeAprender(int expMascota){
    return expMascota >= experiencia;
}
