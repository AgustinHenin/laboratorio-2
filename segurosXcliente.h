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


    int getidSeguro() { return idSeguro; }
    int getidCliente() { return idCliente; }

    void setidSeguro(int s) { idSeguro = s; }
    void setidCliente(int c) { idCliente = c; }
};

