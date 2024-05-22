#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
#include "fecha.h"
using namespace std;


class persona {
private:
    char nombre[50], apellido[50];
    int DNI;
    Fecha nacimiento;
public:
    persona(Fecha f = { 0,0,0 }, int dni = 0, string n = "-", string a = "-") {
        strcpy(nombre, n.c_str());
        strcpy(apellido, a.c_str());
        DNI = dni;
        nacimiento.setdia(f.getdia());
        nacimiento.setmes(f.getmes());
        nacimiento.setanio(f.getanio());
    }

    void cargar() {}

    void mostrar() {}


    const char* getNombre() { return nombre; }
    const char* getApellido() { return apellido; }
    int getDNI() { return DNI; }
    Fecha getNacimiento() { return nacimiento; }

    void setNombre(const char* n) { strcpy(nombre, n); }
    void setApellido(const char* a) { strcpy(apellido, a); }
    void setDNI(int dni) { DNI = dni; }
    void setNacimiento(Fecha f) { nacimiento = f; }

};

