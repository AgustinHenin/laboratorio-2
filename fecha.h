#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
using namespace std;


class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d = 0, int m = 0, int a = 0) {
        dia = d;
        mes = m;
        anio = a;
    }
    void cargar() {
        cout << "dia: ";
        cin >> dia;
        cout << "mes: ";
        cin >> mes;
        cout << "anio: ";
        cin >> anio;
    }
    void mostrar() {
        cout << dia << " / " << mes << " / " << anio << endl;
    }
    void setdia(int a) { dia = a; }
    void setmes(int a) { mes = a; }
    void setanio(int a) { anio = a; }
    int getdia() { return dia; }
    int getmes() { return mes; }
    int getanio() { return anio; }

};
