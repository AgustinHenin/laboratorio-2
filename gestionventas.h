#pragma once
#include "ventas.h"
#include "archivoventas.h"

class gestionventas
{
public:
    int menu() {
        int op;
        while (true) {
            system("cls");
            cout << "Menu" << endl;
            cout << "Elija una opcion: " << endl;
            cout << "1. Listar ventas" << endl;
            cout << "2. Agregar" << endl;
            cout << "3. Dar de baja" << endl;
            cout << "0. Salir" << endl;
            cin >> op;
            switch (op) {
            case 1:
                listarventas();
                break;
            case 2:
                cargararticulo();
                break;
            case 3:
                bajalogica();
                break;
            case 0:
                return 0;
            }
            system("pause");
        }

    }
private:
    void listarventas() {
        ventas ven;
        archivoventas archiven("ventas.dat");
        int i;
        int cant = archiven.contarRegistros();
        for (i = 0; i < cant; i++) {
            ven = archiven.leerRegistro(i);
            ven.mostrar();
        }
    }

    void cargararticulo() {
        ventas ven;
        archivoventas archiven("ventas.dat");
        ven.setidventa(archiven.siguienteID());
        ven.cargar();
        archiven.grabarRegistro(ven);
    }

    bool sobreescribir(ventas ven, int pos) {
        FILE* p;
        p = fopen("ventas.dat", "rb+");
        if (p == NULL) {
            return false;
        }
        fseek(p, sizeof ven * pos, 0);
        bool escribio = fwrite(&ven, sizeof ven, 1, p);
        fclose(p);
        return escribio;
    }

    void bajalogica() {
        ventas ven;
        archivoventas archiven("ventas.dat");
        int i, cant, id;
        cout << "ingrese ID de la venta a dar de baja: ";
        cin >> id;
        cant = archiven.contarRegistros();
        for (i = 0; i <= cant; i++) {
            ven = archiven.leerRegistro(i);
            if (ven.getidventa() == id) {
                ven.setestado(false);
                sobreescribir(ven, i);
            }
        }
    }
};

