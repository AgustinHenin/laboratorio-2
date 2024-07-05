//agrego mostrar() 
//agrego const en los get

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

    void mostrar() const {
        cout << "LEGAJO: " << legajo << endl;
        cout << "NOMBRE: " << getNombre() << endl;
        cout << "APELLIDO: " << getApellido() << endl;
        cout << "DNI: " << getDNI() << endl;
        cout << "FECHA DE NACIMIENTO: ";
        getNacimiento().mostrar();
        cout << "SUELDO: " << sueldo << endl;
        cout << "FECHA DE INGRESO: ";
        getFechaDeIngreso().mostrar();
    }


    int getLegajo() const { return legajo; }
    float getSueldo() const { return sueldo; }
    Fecha getFechaDeIngreso() const { return fechaIngreso; }
    bool getActivo() const { return activo; }

    void setLegajo(int l) { legajo = l; }
    void setSueldo(float s) { sueldo = s; }
    void setfechaDeIngreso(Fecha f) { fechaIngreso = f; }
    void setActivo(bool a) { activo = a; }

//AGREGUE ESTO
	std::string toString() const {
		std::string str = "Nombre:  ";
		str += getNombre();
		str += "  Apellido:  ";
		str += getApellido();
		str += "  DNI:  ";
		str += std::to_string(getDNI());
		str += "  Fecha de nacimiento:  ";
		str += getNacimiento().toString();
		str += "  Legajo:  ";
		str += std::to_string(getLegajo());
		str += "  Sueldo:  ";
		str += std::to_string(getSueldo());
		str += "  Fecha de ingreso:  ";
		str += getFechaDeIngreso().toString();

		return str;
	}

	std::string toStringNombreYApellido() {
		std::string str = "Nombre:  ";
		str += getNombre();
		str += "  Apellido:  ";
		str += getApellido();

		return str;
	}
};

