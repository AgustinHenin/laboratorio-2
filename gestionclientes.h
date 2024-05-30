#pragma once
#include "archivopolizas.h"
#include "archivoclientes.h"
#include "archivovendedores.h"
#include "archivoseguros.h"
#include "archivosxc.h"
#include "archivoestados.h"
#include "archivoexc.h"

class gestionclientes
{
public:
    void fichacliente(int id) {
        clientes c;
        archivoclientes ac;
        c = ac.leerRegistro(id - 1);
        cout << endl;
        cout << "GESTION DE CLIENTES" << endl << endl;
        cout << "----------------------------" << endl;
        cout << "NOMBRE: " << c.getNombre() << endl;
        cout << "APELLIDO: " << c.getApellido() << endl;
        cout << "DNI: " << c.getDNI() << endl;
        cout << "TEL: " << c.gettelefono() << endl;
        cout << "MAIL: " << c.getemail() << endl << endl;
        cout << "SEGUROS CONTRATADOS: " << endl;
        seguroscontratados(id);
        cout << endl;
        cout << "ESTADO: ";
        estadocliente(id);
        cout << endl << "----------------------------" << endl << endl;

    }

    void seguroscontratados(int id) {
        segurosXcliente sc;
        archivosxc asc;
        seguros s;
        archivoseguros as;
        int cant = asc.contarRegistros();
        for (int i = 0; i < cant; i++) {
            sc = asc.leerRegistro(i);
            if (sc.getidCliente() == id) {
                s = as.leerRegistro(sc.getidSeguro() - 1);
                cout << "   " << s.getnombre() << endl;
            }
        }
    }

    void estadocliente(int id) {
        estadoXcliente ec;
        archivoexc aec;
        estados e;
        archivoestados ae;
        int cant = aec.contarRegistros();
        for (int i = 0; i < cant; i++) {
            ec = aec.leerRegistro(i);
            if (ec.getidCliente() == id) {
                e = ae.leerRegistro(ec.getidEstado() - 1);
                cout << e.getnombre() << endl;
            }
        }
    }

    void cargarcadena(char* palabra, int tam) {
        int i = 0;
        fflush(stdin);
        for (i = 0; i < tam; i++) {
            palabra[i] = cin.get();
            if (palabra[i] == '\n') break;
        }
        palabra[i] = '\0';
        fflush(stdin);
    }

    void modificardatos(int id) {
        clientes c;
        archivoclientes ac;
        c = ac.leerRegistro(id - 1);
        cout << "Dato a modificar: " << endl;
        cout << "1. Telefono" << endl;
        cout << "2. Email" << endl;
        cout << "3. Domicilio" << endl;
        int op;
        cin >> op;
        switch (op) {
        case 1:
            char tel[50];
            cout << "telefono actual: " << c.gettelefono() << endl;
            cout << "Nueno telefono: ";
            cargarcadena(tel, 49);
            c.settelefono(tel);
            break;
        case 2:
            char mail[50];
            cout << "Email actual: " << c.getemail() << endl;
            cout << "Nueno email: ";
            cargarcadena(mail, 49);
            c.setemail(mail);
            break;
        case 3:
            char dom[50];
            cout << "Domicilio actual: " << c.getdomicilio() << endl;
            cout << "Nueno domicilio: ";
            cargarcadena(dom, 49);
            c.setdomicilio(dom);
            break;
        }
        ac.sobreescribir(c, id - 1);
    }

    void clasificar(int id) {
        estadoXcliente ec;
        archivoexc aec;
        cout << "Clasificar como: " << endl;
        cout << "1. Venta" << endl;
        cout << "2. Posible venta" << endl;
        cout << "3. No interesado" << endl;
        cout << "4. Contestador" << endl;
        cout << "5. Imposible contactar" << endl;
        int op;
        bool noesta = true;
        cin >> op;
        int cant = aec.contarRegistros();
        for (int i = 0; i < cant; i++) {
            ec = aec.leerRegistro(i);
            if (ec.getidCliente() == id) {
                ec.setidEstado(op);
                aec.sobreescribir(ec, i);
                noesta = false;
            }
        }
        if (noesta == true) {
            ec.setidCliente(id);
            ec.setidEstado(op);
            aec.grabarRegistro(ec);
        }

    }
};

