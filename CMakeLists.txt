cmake_minimum_required(VERSION 3.30)
project(4_practica_mascotas_virtuales_kna)

set(CMAKE_CXX_STANDARD 20)

add_executable(4_practica_mascotas_virtuales_kna main.cpp
        src/Objeto.cpp
        src/Objeto.h
        src/Habilidad.cpp
        src/Habilidad.h
        src/Cuidado.cpp
        src/Cuidado.h
        src/Mascota.cpp
        src/Mascota.h
        src/Usuario.cpp
        src/Usuario.h
        src/Tienda.cpp
        src/Tienda.h)
