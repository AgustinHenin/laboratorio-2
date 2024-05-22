#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
using namespace std;


class seguros {
private:
    char nombre[50], descripcion[300];
    int idSeguro;
public:
    seguros(int id = 0, string n = "-", string d = "-") {
        strcpy(nombre, n.c_str());
        strcpy(descripcion, d.c_str());
        idSeguro = id;
    }

    void cargar() {}

    void mostrar() {}
    

    const char* getdescripcion() { return descripcion; }
    const char* getnombre() { return nombre; }
    int getidSeguro() { return idSeguro; }

    void setdescripcion(const char* d) { strcpy(descripcion, d);}
    void setnombre(const char* n) { strcpy(nombre, n); }
    void setidSeguro(int id) { idSeguro = id; }

};

