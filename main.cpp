#include <iostream>
#include <vector>
#include "src/Mascota.h"
#include "src/Objeto.h"
#include "src/Usuario.h"
#include "src/Habilidad.h"
#include "src/Tienda.h"


using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;

void mostrarMenuPrincipal();
void mostrarMenuUsuario(Usuario& usuario, vector<Mascota*>& mascotasDisponibles, vector<Habilidad>& habilidadesDisponibles, vector<Objeto*>& objetosDisponibles);
void registrarUsuario(vector<Usuario>& usuarios);
void adoptarMascota(Usuario& usuario, vector<Mascota*>& mascotasDisponibles);
void adquirirObjeto(Usuario& usuario, vector<Objeto*>& objetosDisponibles);
void ensenarHabilidad(Mascota* mascota, vector<Habilidad>& habilidadesDisponibles);
void aumentarExperiencia(Mascota* mascota);
void consultarHistorial(Mascota* mascota);

int main() {

    Tienda miTienda("PixelPets","Colombia");
    vector<Mascota*> mascotasDisponibles;

    // Crear algunas mascotas iniciales
    mascotasDisponibles.push_back(new Mascota("Pixel", 10));
    mascotasDisponibles.push_back(new Mascota("Sparky", 5));
    mascotasDisponibles.push_back(new Mascota("Fluffy", 8));
    mascotasDisponibles.push_back(new Mascota("Zappy", 3));
    mascotasDisponibles.push_back(new Mascota("Glitch", 15));

    miTienda.registrarObjetos(new Objeto("pelota", "juguete",20));
    miTienda.registrarObjetos(new Objeto("cuido", "comida",20));
    miTienda.registrarObjetos(new Objeto("vitaminas", "medicina",20));
    miTienda.registrarObjetos(new Objeto("peluche", "juguete",20));
    miTienda.registrarObjetos(new Objeto("pollo", "comida",20));
    miTienda.registrarObjetos(new Objeto("hierbas", "medicina",20));
    miTienda.registrarObjetos(new Objeto("cuerda", "juguete",20));
    miTienda.registrarObjetos(new Objeto("hueso", "comida",20));

    // Crear habilidades disponibles
    miTienda.registrarHabilidades(Habilidad("Bailar", "Puede bailar al ritmo de la musica", 50));
    miTienda.registrarHabilidades(Habilidad("Buscar", "Encuentra objetos escondidos", 30));
    miTienda.registrarHabilidades(Habilidad("Emojis", "Se comunica con emojis", 20));
    miTienda.registrarHabilidades(Habilidad("Saltar", "Salta muy alto", 40));
    miTienda.registrarHabilidades(Habilidad("Cantar", "Canta melodias hermosas", 60));

    vector<Objeto*> objetosDisponibles = miTienda.getObjetos();
    vector<Habilidad> habilidadesDisponibles = miTienda.getHabilidades();
    vector<Usuario> usuarios = miTienda.getUsuarios();


    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: { // Registrar usuario
                registrarUsuario(usuarios);
                break;
            }
            case 2: { // Seleccionar usuario
                if (usuarios.empty()) {
                    std::cout << "No hay usuarios registrados.\n";
                    break;
                }

                std::cout << "Usuarios disponibles:\n";
                for (size_t i = 0; i < usuarios.size(); ++i) {
                    std::cout << i+1 << ". " << usuarios[i].getNombre() << "\n";
                }

                int seleccion;
                std::cout << "Seleccione un usuario: ";
                std::cin >> seleccion;
                std::cin.ignore();

                if (seleccion > 0 && seleccion <= static_cast<int>(usuarios.size())) {
                    mostrarMenuUsuario(usuarios[seleccion-1], mascotasDisponibles, habilidadesDisponibles, objetosDisponibles);
                } else {
                    std::cout << "Seleccion invalida.\n";
                }
                break;
            }
            case 3: // Salir
                std::cout << "Saliendo de PixelPets...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    // Liberar memoria de las mascotas
    for (auto mascota : mascotasDisponibles) {
        delete mascota;
    }
    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "\n=== PixelPets ===\n";
    std::cout << "1. Registrar nuevo usuario\n";
    std::cout << "2. Seleccionar usuario existente\n";
    std::cout << "3. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

void mostrarMenuUsuario(Usuario& usuario, vector<Mascota*>& mascotasDisponibles, vector<Habilidad>& habilidadesDisponibles, vector<Objeto*>& objetosDisponibles) {
    int opcion;
    do {
        std::cout << "\n=== Menu de " << usuario.getNombre() << " ===\n";
        std::cout << "1. Adoptar mascota\n";
        std::cout << "2. Ver mis mascotas\n";
        std::cout << "3. Adquirir objeto\n";
        std::cout << "4. Usar objeto con mascota\n";
        std::cout << "5. Ensenar habilidad a mascota\n";
        std::cout << "6. Aumentar experiencia de mascota\n";
        std::cout << "7. Consultar historial de mascota\n";
        std::cout << "8. Volver al menu principal\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch(opcion) {
            case 1:
                adoptarMascota(usuario, mascotasDisponibles);
                break;
            case 2:
                usuario.mostrarMascotas();
                break;
            case 3:
                adquirirObjeto(usuario, objetosDisponibles);
                break;
            case 4:{
                usuario.mostrarObjetos();
                int seleccionObjeto;
                std::cout << "Seleccione un objeto (0 para cancelar): ";
                std::cin >> seleccionObjeto;
                std::cin.ignore();

                usuario.mostrarMascotas();
                int seleccionMascota;
                std::cout << "Seleccione una mascota (0 para cancelar): ";
                std::cin >> seleccionMascota;
                std::cin.ignore();

                if (seleccionMascota > 0 && seleccionMascota <= usuario.getMascotas().size()) {
                    usuario.usarObjeto(usuario.getObjetos()[seleccionObjeto-1],usuario.getMascotas()[seleccionMascota-1]);
                }
                break;
            }
            case 5: {
                usuario.mostrarMascotas();
                int seleccion;
                std::cout << "Seleccione una mascota (0 para cancelar): ";
                std::cin >> seleccion;
                std::cin.ignore();

                if (seleccion > 0 && seleccion <= usuario.getMascotas().size()) {
                    ensenarHabilidad(usuario.getMascotas()[seleccion-1], habilidadesDisponibles);
                }
                break;
            }
            case 6: {
                usuario.mostrarMascotas();
                int seleccion;
                std::cout << "Seleccione una mascota (0 para cancelar): ";
                std::cin >> seleccion;
                std::cin.ignore();

                if (seleccion > 0 && seleccion <= usuario.getMascotas().size()) {
                    aumentarExperiencia(usuario.getMascotas()[seleccion-1]);
                }
                break;
            }
            case 7: {
                usuario.mostrarMascotas();
                int seleccion;
                std::cout << "Seleccione una mascota para ver su historial (0 para cancelar): ";
                std::cin >> seleccion;
                std::cin.ignore();

                if (seleccion > 0 && seleccion <= usuario.getMascotas().size()) {
                    consultarHistorial(usuario.getMascotas()[seleccion-1]);
                }
                break;
            }
            case 8:
                std::cout << "Volviendo al menu principal...\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 7);
}

void registrarUsuario(vector<Usuario>& usuarios) {
    string nombre;
    cout << "Ingrese el nombre del nuevo usuario: ";
    getline(std::cin, nombre);

    usuarios.emplace_back(nombre, usuarios.size() + 1);
    cout << "Usuario registrado exitosamente!\n";
}

void adoptarMascota(Usuario& usuario, vector<Mascota*>& mascotasDisponibles) {
    if (mascotasDisponibles.empty()) {
        std::cout << "No hay mascotas disponibles para adoptar.\n";
        return;
    }

    std::cout << "Mascotas disponibles para adoptar:\n";
    for (size_t i = 0; i < mascotasDisponibles.size(); ++i) {
        std::cout << i+1 << ". ";
        mascotasDisponibles[i]->mostrarInfo();
        std::cout << "----------------\n";
    }

    int seleccion;
    std::cout << "Seleccione una mascota para adoptar (0 para cancelar): ";
    std::cin >> seleccion;
    std::cin.ignore();

    if (seleccion > 0 && seleccion <= static_cast<int>(mascotasDisponibles.size())) {
        usuario.adoptarMascota(mascotasDisponibles[seleccion-1]);
        mascotasDisponibles.erase(mascotasDisponibles.begin() + seleccion - 1);
    }
}

void adquirirObjeto(Usuario& usuario, vector<Objeto*>& objetosDisponibles) {
    if (objetosDisponibles.empty()) {
        std::cout << "No hay objetos disponibles para adquirir.\n";
        return;
    }

    std::cout << "Objetos disponibles para adquirir:\n";
    for (size_t i = 0; i < objetosDisponibles.size(); ++i) {
        std::cout << i+1 << ". ";
        objetosDisponibles[i]->mostrarInfo();
        std::cout << "----------------\n";
    }

    int seleccion;
    std::cout << "Seleccione un objeto para adquirir (0 para cancelar): ";
    std::cin >> seleccion;
    std::cin.ignore();

    if (seleccion > 0 && seleccion <= static_cast<int>(objetosDisponibles.size())) {
        usuario.agregarObjeto(objetosDisponibles[seleccion-1]);
        objetosDisponibles.erase(objetosDisponibles.begin() + seleccion - 1);
    }
}

void ensenarHabilidad(Mascota* mascota, vector<Habilidad>& habilidadesDisponibles) {
    std::cout << "Habilidades disponibles para ensenar:\n";
    for (size_t i = 0; i < habilidadesDisponibles.size(); ++i) {
        std::cout << i+1 << ". " << habilidadesDisponibles[i].getNombre() << " (Req: "
                  << habilidadesDisponibles[i].getExperiencia() << " exp)\n";
    }

    int seleccion;
    std::cout << "Seleccione una habilidad para ensenar (0 para cancelar): ";
    std::cin >> seleccion;
    std::cin.ignore();

    if (seleccion > 0 && seleccion <= static_cast<int>(habilidadesDisponibles.size())) {
        mascota->aprenderHabilidad(habilidadesDisponibles[seleccion-1]);
    }
}

void aumentarExperiencia(Mascota* mascota) {
    int cantidad;
    std::cout << "Ingrese la cantidad de experiencia a agregar: ";
    std::cin >> cantidad;
    std::cin.ignore();

    mascota->aumentarExperiencia(cantidad);
}

void consultarHistorial(Mascota* mascota) {
    mascota->mostrarHistorial();
}