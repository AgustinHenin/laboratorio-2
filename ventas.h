#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
#include "fecha.h"
using namespace std;


class ventas {
private:
    char TipoDeFactura[2];
    int IDventa, IDcliente, IDarticulo;
    float importe;
    Fecha fecha;
    bool estado;
public:
    ventas(int idven = 0, int idcli = 0, int idart = 0, string n = "n", float imp = 0.0, bool est = true) {
        strcpy(TipoDeFactura, n.c_str());
        IDventa = idven;
        IDcliente = idcli;
        IDarticulo = idart;
        importe = imp;
        estado = est;

    }

    void cargar() {
        string n;
        cout << "ingrese ID del cliente: ";
        cin >> IDcliente;
        cout << "ingrese ID del articulo: ";
        cin >> IDarticulo;
        cin.ignore();
        cout << "ingresar tipo de factura: ";
        getline(cin, n);
        strcpy(TipoDeFactura, n.c_str());
        cout << "ingrese importe: ";
        cin >> importe;
        cout << "ingrese fecha de la operacion: ";
        fecha.cargar();

    }

    void mostrar() {
        if (estado == true) {
            cout << "ID de la venta: " << IDventa << endl;
            cout << "ID del cliente: " << IDcliente << endl;
            cout << "ID del articulo: " << IDarticulo << endl;
            cout << "Importe: " << importe << endl;
            cout << "Tipo de farcura: " << TipoDeFactura << endl;
            cout << "Fecha: ";
            fecha.mostrar();
            cout << endl << endl;
        }
    }


    const char* gettipofac() { return TipoDeFactura; }
    int getidventa() { return IDventa; }
    int getidcliente() { return IDcliente; }
    int getidart() { return IDarticulo; }
    float getimporte() { return importe; }
    Fecha getfecha() { return fecha; }
    bool getestado() { return estado; }

    void settipofac(const char* d) { strcpy(TipoDeFactura, d); }
    void setidventa(int idv) { IDventa = idv; }
    void setidcliente(int idc) { IDcliente = idc; }
    void setidart(int ida) { IDarticulo = ida; }
    void setimporte(float s) { importe = s; }
    void setfecha(Fecha f) { fecha = f; }
    void setestado(bool a) { estado = a; }

};