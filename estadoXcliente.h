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


    int getidEstado() { return idEstado; }
    int getidCliente() { return idCliente; }

    void setidEstado(int e) { idEstado = e; }
    void setidCliente(int c) { idCliente = c; }
};

