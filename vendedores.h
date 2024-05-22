#pragma once
#include "persona.h"
class vendedores :
    public persona
{
private:
    int legajo;
    float sueldo;
    Fecha fechaIngreso;
    bool activo;
public:
    vendedores(Fecha f = { 0,0,0 }, int l = 0, float s = 0.0, bool a = true) {
        legajo = l;
        sueldo = s;
        activo = a;
        fechaIngreso.setdia(f.getdia());
        fechaIngreso.setmes(f.getmes());
        fechaIngreso.setanio(f.getanio());
    }

    void cargar() {}

    void mostrar() {}


    int getLegajo() { return legajo; }
    float getSueldo() { return sueldo; }
    Fecha getFechaDeIngreso() { return fechaIngreso; }
    bool getActivo() { return activo; }

    void setLegajo(int l) { legajo = l; }
    void setSueldo(float s) { sueldo = s; }
    void setfechaDeIngreso(Fecha f) { fechaIngreso = f; }
    void setActivo(bool a) { activo = a; }
};

