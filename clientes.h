#pragma once
#include "persona.h"
class clientes :
    public persona
{
private:
    char domicilio[50], telefono[300], email[50];
    int idCliente;
public:
    clientes(int id = 0, string d = "-", string t = "-", string e = "-") {
        strcpy(domicilio, d.c_str());
        strcpy(telefono, t.c_str());
        strcpy(email, e.c_str());
        idCliente = id;
    }

    void cargar() {}

    void mostrar() {}


    const char* getdomicilio() { return domicilio; }
    const char* gettelefono() { return telefono; }
    const char* getemail() { return email; }
    int getidCliente() { return idCliente; }

    void setdomicilio(const char* d) { strcpy(domicilio, d); }
    void settelefono(const char* t) { strcpy(telefono, t); }
    void setemail(const char* e) { strcpy(email, e); }
    void setidCliente(int id) { idCliente = id; }
};

