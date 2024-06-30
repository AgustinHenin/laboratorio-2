#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
#include "fecha.h"
using namespace std;


class polizas {
private:
    char modoDePago[20];
    int NdePoliza, idCliente, idSeguro, legajoVen, suma;
    float cuota;
    Fecha fechaVenta;
    bool anulada;
public:
    polizas(Fecha f = { 0,0,0 }, int ndp = 0, int idcli = 0, int ids = 0, int leg = 0, int s = 0, string n = "n", float c = 0.0, bool a = false) {
        strcpy(modoDePago, n.c_str());
        NdePoliza = ndp;
        idCliente = idcli;
        idSeguro = ids;
        legajoVen = leg;
        suma = s;
        cuota = c;
        anulada = a;
        fechaVenta.setdia(f.getdia());
        fechaVenta.setmes(f.getmes());
        fechaVenta.setanio(f.getanio());
    }

    void cargar() {}

    void mostrar() {}


    const char* getModoDePago() { return modoDePago; }
    int getNdePoliza() { return NdePoliza; }
    int getidCliente() { return idCliente; }
    int getidSeguro() { return idSeguro; }
    int getLegajoVendedor() { return legajoVen; }
    int getSuma() { return suma; }
    float getCuota() { return cuota; }
    Fecha getFechaDeVenta() { return fechaVenta; }
    bool getAnulada() { return anulada; }

    void setModoDePago(const char* p) { strcpy(modoDePago, p); }
    void setNdePoliza(int ndp) { NdePoliza = ndp; }
    void setididCliente(int idc) { idCliente = idc; }
    void setidSeguro(int ids) { idSeguro = ids; }
    void setLegajo(int leg) { legajoVen = leg; }
    void setSuma(int s) { suma = s; }
    void setCuota(float c) { cuota = c; }
    void setfechaVenta(Fecha f) { fechaVenta = f; }
    void setAnulada(bool a) { anulada = a; }


//AGREGUE ESTE METODO

std::string toString() const {
		std::string str = "Modo de pago:  ";
		str += getModoDePago();
		str += "  Numero de poliza:  ";
		str += std::to_string(getNdePoliza());
		str += "  ID Cliente:  ";
		str += std::to_string(getidCliente());
		str += "  ID Seguro:  ";
		str += std::to_string(getidSeguro());
		str += "  Legajo del vendedor:  ";
		str += std::to_string(getLegajoVendedor());
		str += "  Suma asegurada: $ ";
		str += std::to_string(getSuma());
		str += "  Cuota: $ ";
		str += std::to_string(getCuota());
		str += "  Fecha de venta:  ";
		str += getFechaDeVenta().toString();

		return str;

	}


};
