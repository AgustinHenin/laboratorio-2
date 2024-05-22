#pragma once
#include "polizas.h"
#include "archivopolizas.h"
#include "clientes.h"
#include "archivoclientes.h"
#include "vendedores.h"
#include "archivovendedores.h"
#include "seguros.h"
#include "archivoseguros.h"

class gestionpolizas
{
public:
    int menu() {
        int op;
        while (true) {
            system("cls");
            cout << "Menu" << endl;
            cout << "Elija una opcion: " << endl;
            cout << "1. Listar polizas" << endl;
            cout << "0. Salir" << endl;
            cin >> op;
            switch (op) {
            case 1:
                listarventas();
                break;
            case 0:
                return 0;
            }
            system("pause");
        }

    }
private:
    void listarventas() {
        polizas p;
        archivopolizas archipol;
        clientes c;
        archivoclientes archicli;
        vendedores v;
        archivovendedores archiven;
        seguros s;
        archivoseguros archiseg;

        int i, j, k, u;
        int cant1 = archipol.contarRegistros();
        for (i = 0; i < cant1; i++) {
            p = archipol.leerRegistro(i);
            if (p.getAnulada() == false) {
                int cant2 = archicli.contarRegistros();
                for (j = 0; j < cant2; j++) {
                    c = archicli.leerRegistro(j);
                    if (p.getidCliente() == c.getidCliente()) {
                        int cant3 = archiven.contarRegistros();
                        for (k = 0; k < cant3; k++) {
                            v = archiven.leerRegistro(k);
                            if (p.getLegajoVendedor() == v.getLegajo()) {
                                int cant4 = archiseg.contarRegistros();
                                for (u = 0; u < cant4; u++) {
                                    s = archiseg.leerRegistro(u);
                                    if (p.getidSeguro() == s.getidSeguro()) {
                                        cout << endl << "NUMERO DE POLIZA: " << p.getNdePoliza() << endl;
                                        cout << "FECHA DE EMICION: ";
                                        p.getFechaDeVenta().mostrar();
                                        cout << endl << endl;
                                        cout << "CLIENTE: " << c.getApellido() << ", " << c.getNombre() << endl << endl;
                                        cout << "SEGURO: " << s.getnombre() << endl;
                                        cout << "SUMA ASEGURADA: " << p.getSuma() << endl;
                                        cout << "CUOTA MENSUAL: " << p.getCuota() << endl << endl;
                                        cout << "MODO DE PAGO: " << p.getModoDePago() << endl;
                                        cout << "VENDEDOR: " << v.getApellido() << ", " << v.getNombre() << endl << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
};

