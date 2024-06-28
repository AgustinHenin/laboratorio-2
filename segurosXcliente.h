#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class segurosXcliente
{
private:
    int idSeguro, idCliente;
public:

    void cargar() {}

    void mostrar() {}


    int getidSeguro() const { return idSeguro; } //agrego const
    int getidCliente() const { return idCliente; } //agrego const

    void setidSeguro(int s) { idSeguro = s; }
    void setidCliente(int c) { idCliente = c; }
};

