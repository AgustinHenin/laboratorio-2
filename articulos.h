#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
using namespace std;


class articulos {
private:
    char descripcion[100];
    int ID, PU, stock;
    bool estado;
public:
    articulos(int id = 0, int pu = 0, int st = 0, std::string n = "a", bool est = true) {
        strcpy(descripcion, n.c_str());
        ID = id;
        PU = pu;
        stock = st;
        estado = est;
        
    }

    void cargar() {
        string n;
        cin.ignore();
        cout << "ingresar descripcion del producto: ";
        getline(cin, n);
        strcpy(descripcion, n.c_str());
        cout << "ingrese precio unitario: ";
        cin >> PU;
        cout << "ingrese stock: ";
        cin >> stock;

    }

    void mostrar() {
        if (estado == true) {
            cout << "ID: " << ID << endl;
            cout << "descripcion: " << descripcion << endl;
            cout << "Precio: " << PU << endl;
            cout << "Stock: " << stock << endl;
            cout << endl;
        }
    }
    

    const char* getdescripcion() { return descripcion; }
    int getid() { return ID; }
    int getprecio() { return PU; }
    int getstock() { return stock; }
    bool getestado() { return estado; }

    void setdescripcion(const char* d) { strcpy(descripcion, d);}
    void setid(int id) { ID = id; }
    void setprecio(int pu) { PU = pu; }
    void setstock(int s) { stock = s; }
    void setestado(bool a) { estado = a; }

};

