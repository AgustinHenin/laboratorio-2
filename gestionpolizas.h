#pragma once
#include "archivopolizas.h"
#include "archivoclientes.h"
#include "archivovendedores.h"
#include "archivoseguros.h"
#include "archivosxc.h"
#include "archivoestados.h"
#include "archivoexc.h"

class gestionpolizas
{
public:
    void listarpolizas() {
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
                                        cout << endl;
                                        cout << "CLIENTE: " << c.getApellido() << ", " << c.getNombre() << endl << endl;
                                        cout << "SEGURO: " << s.getnombre() << endl;
                                        cout << "SUMA ASEGURADA: " << p.getSuma() << endl;
                                        cout << "CUOTA MENSUAL: " << p.getCuota() << endl << endl;
                                        cout << "MODO DE PAGO: " << p.getModoDePago() << endl;
                                        cout << "VENDEDOR: " << v.getApellido() << ", " << v.getNombre() << endl;
                                        cout << "..............................." << endl;
                                    }
                                }
                            }
                        }
                    }
                }
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

    void cargadepoliza(int id) {
        polizas p;
        archivopolizas ap;
        segurosXcliente sxc;
        archivosxc asc;
        int legajo, seguro, suma;
        char mediopago[20];
        Fecha f;
        p.setididCliente(id);
        p.setNdePoliza(ap.siguiente());
        system("cls");
        cout << "CARGA DE VENTAS" << endl << endl;
        cout << "-----------------------------------" << endl;
        cout << "ID DEL CLIENTE: " << p.getidCliente() << endl;
        cout << "LEGAJO DEL VENDEDOR: ";
        cin >> legajo;
        p.setLegajo(legajo);
        cout << "ID DEL SEGURO: ";
        cin >> seguro;
        p.setidSeguro(seguro);
        cout << "SUMA ASEGURADA: $";
        cin >> suma;
        p.setSuma(suma);
        cout << "MONTO A PAGAR: $";
        cout << cuotaseguro(suma, seguro) << endl;
        p.setCuota(cuotaseguro(suma, seguro));
        cout << "FECHA: " << endl;
        f.cargar();
        p.setfechaVenta(f);
        cout << "MEDIO DE PAGO: ";
        cargarcadena(mediopago, 19);
        p.setModoDePago(mediopago);
        cout << "   -----------------------------------" << endl;
        cout << "Guaddar o Cancelar: " << endl;
        cout << "1. Guardar y volver" << endl;
        cout << "2. Cancelar y volver" << endl;
        int op;
        cin >> op;
        switch (op) {
        case 1:
            ap.grabarRegistro(p);
            sxc.setidCliente(id);
            sxc.setidSeguro(seguro);
            asc.grabarRegistro(sxc);
            cout << "CARGA EXITOSA" << endl;
            system("pause");
            break;
        case 2:
            break;
        }
    }

    float cuotaseguro(int suma, int id) {
        float cuota;
        switch (id) {
        case 1:
            cuota = suma * 0.001;
            return cuota;
        case 2:
            cuota = suma * 0.00075;
            return cuota;
        case 3:
            cuota = suma * 0.0005;
            return cuota;
        case 4:
            cuota = suma * 0.0015;
            return cuota;
        }
    }

};
