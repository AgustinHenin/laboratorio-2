#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class estados
{
private:
    char nombre[50];
    int idEstado;
public:
    
    void cargar() {}

    void mostrar() {}


    const char* getnombre() { return nombre; }
    int getidEstado() { return idEstado; }

    void setnombre(const char* n) { strcpy(nombre, n); }
    void setidEstado(int id) { idEstado = id; }
};

