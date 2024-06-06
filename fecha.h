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

//AGREGUE ESTE METODO
std::string toString() {
		std::string str = std::to_string(dia);
		if (str.size() == 1)
		{
			str = "0" + str;
		}
		str += " / ";
		std::string strMes = std::to_string(mes);
		if (strMes.size() == 1)
		{
			strMes = "0" + strMes;
		}
		str += strMes;
		str += " / ";
		str += std::to_string(anio);
		return str;
	}

	std::string toStringMes(int i) {
		switch (i) {
		case 1:
			return "Enero";
			break;
		case 2:
			return "Febrero";
			break;
		case 3:
			return "Marzo";
			break;
		case 4:
			return "Abril";
			break;
		case 5:
			return "Mayo";
			break;
		case 6:
			return "Junio";
			break;
		case 7:
			return "Julio";
			break;
		case 8:
			return "Agosto";
			break;
		case 9:
			return "Septiembre";
			break;
		case 10:
			return "Octubre";
			break;
		case 11:
			return "Noviembre";
			break;
		case 12:
			return "Diciembre";
			break;

		default:
			break;
		}
	}
};
