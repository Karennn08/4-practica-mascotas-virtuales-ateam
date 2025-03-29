
#ifndef CUIDADO_H
#define CUIDADO_H
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;


class Cuidado {
public:
    Cuidado();
    Cuidado(string fecha, string tipoCuidado, string objetoUsado, string estadoSalud);
    void mostrarInfo();
private:
    string fecha;
    string tipoCuidado;
    string objetoUsado;
    string estadoSalud;
};



#endif //CUIDADO_H
