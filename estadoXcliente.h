#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class estadoXcliente
{
private:
    int idEstado, idCliente;
public:
    
    void cargar() {}

    void mostrar() {}


    int getidEstado() const { return idEstado; } //agrego const para que compile
    int getidCliente() const { return idCliente; } //lo mismo

    void setidEstado(int e) { idEstado = e; }
    void setidCliente(int c) { idCliente = c; }

std::string toString() const {
	std::string str = "id Estado:  ";
	str += std::to_string(idEstado);
	str += "\nid cliente  ";
	str += std::to_string(idCliente);
	return str;
}

};

