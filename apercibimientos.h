#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
#include "fecha.h"
using namespace std;


class apercibimientos {
private:
    int legajoVendedor, motivo;
    Fecha fecha;
public:
    apercibimientos(int lv = 0, int mot = 0, Fecha f = {0,0,0}) {
        legajoVendedor = lv;
        motivo = mot;
        fecha.setdia(f.getdia());
        fecha.setmes(f.getmes());
        fecha.setanio(f.getanio());
    }

    void cargar() {}

    void mostrar() {}


    int getlegajo() { return legajoVendedor; }
    int getmotivo() { return motivo; }
    Fecha getfecha() { return fecha; }

    void setlegajo(int lv) { legajoVendedor = lv; }
    void setmotivo(int mot) { motivo = mot; }
    void setfecha(Fecha f) { fecha = f; }

};

