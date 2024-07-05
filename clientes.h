//hice los mismos cambios que en el zoom, agregue lso const y cambie el 300 por 50
//agrego mostrar()

#pragma once
#include "persona.h"
class clientes :
    public persona
{
private:
    char domicilio[50], telefono[50], email[50];
    int idCliente;
public:
    clientes(int id = 0, string d = "-", string t = "-", string e = "-") {
        strcpy(domicilio, d.c_str());
        strcpy(telefono, t.c_str());
        strcpy(email, e.c_str());
        idCliente = id;
    }

    void cargar() {}

    void mostrar() const {
		cout << "ID: " << idCliente << endl;
		cout << "NOMBRE: " << getNombre() << endl;
		cout << "APELLIDO: " << getApellido() << endl;
		cout << "DNI: " << getDNI() << endl;
		cout << "FECHA DE NACIMIENTO: ";
		getNacimiento().mostrar();
		cout << "TEL: " << telefono << endl;
		cout << "MAIL: " << email << endl;
		cout << "DOMICILIO: " << domicilio;
	}


    const char* getdomicilio()  const { return domicilio; }
    const char* gettelefono() const { return telefono; }
    const char* getemail() const { return email; }
    int getidCliente() const { return idCliente; }

    void setdomicilio(const char* d) { strcpy(domicilio, d); }
    void settelefono(const char* t) { strcpy(telefono, t); }
    void setemail(const char* e) { strcpy(email, e); }
    void setidCliente(int id) { idCliente = id; }

//Agregue esto 
std::string toString() const {
		std::string str = "Apellido: ";
		str += getApellido();
		str += "   Nombre:";
		str += getNombre();
		str += "  DNI:  ";
		str += std::to_string(getDNI());
		str += "  Fecha de nacimiento:  ";
		str += getNacimiento().toString();
		//str += "  Domicilio:  ";
		//str += getdomicilio();
		str += "  Telefono:  ";
		str += gettelefono();
		str += "  Email:  ";
		str += getemail();
		//str += "  ID Cliente:  ";
		//str += std::to_string(getidCliente());

		return str;
	}

	std::string toString2() const {
		std::string str = "Nombre:  ";
		str += getNombre();
		str += "\nApellido:  ";
		str += getApellido();
		str += "\nDNI:  ";
		str += std::to_string(getDNI());
		str += "\nFecha de nacimiento:  ";
		str += getNacimiento().toString();
		str += "\nDomicilio:  ";
		str += getdomicilio();
		str += "\nTelefono:  ";
		str += gettelefono();
		str += "\nEmail:  ";
		str += getemail();
		str += "\nID Cliente:  ";
		str += std::to_string(getidCliente());

		return str;
	}
};

