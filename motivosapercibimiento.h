#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class motivosapercibimiento
{
private:
    char motivo[300];
    int idMotivo;
public:

    void cargar() {}

    void mostrar() {}


    const char* getmotivo() { return motivo; }
    int getidMotivo() { return idMotivo; }

    void setmotivo(const char* n) { strcpy(motivo, n); }
    void setidMotivo(int id) { idMotivo = id; }

std::string toString() const {
		std::string str = "IdMotivo:  ";
		str += std::to_string(getidMotivo());
		str += "  Motivo:  ";
		str += getmotivo();

		return str;
	}
};

