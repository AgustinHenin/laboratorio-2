#pragma once
#include "articulos.h"
#include "archivoarticulos.h"

class gestionarticulos
{
public:
	int menu() {
        int op;
        while (true) {
            system("cls");
            cout << "Menu" << endl;
            cout << "Elija una opcion: " << endl;
            cout << "1. Listar articulos" << endl;
            cout << "2. Agregar" << endl;
            cout << "3. Dar de baja" << endl;
            cout << "0. Salir" << endl;
            cin >> op;
            switch (op) {
            case 1:
                listararticulos();
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
	void listararticulos() {
		articulos art;
		archivoarticulos archiart("articulos.dat");
		int i;
		int cant = archiart.contarRegistros();
		for (i = 0; i < cant; i++) {
			art = archiart.leerRegistro(i);
			art.mostrar();
		}
	}

	void cargararticulo() {
		articulos art;
		archivoarticulos archiart("articulos.dat");
		art.setid(archiart.siguienteID());
		art.cargar();
		archiart.grabarRegistro(art);
	}

    bool sobreescribir(articulos art, int pos) {
        FILE* p;
        p = fopen("articulos.dat", "rb+");
        if (p == NULL) {
            return false;
        }
        fseek(p, sizeof art * pos, 0);
        bool escribio = fwrite(&art, sizeof art, 1, p);
        fclose(p);
        return escribio;
    }

    void bajalogica() {
        articulos art;
        archivoarticulos archiart("articulos.dat");
        int i, cant, id;
        cout << "ingrese ID del articulo a dar de baja: ";
        cin >> id;
        cant = archiart.contarRegistros();
        for (i = 0; i <= cant; i++) {
            art = archiart.leerRegistro(i);
            if (art.getid() == id) {
                art.setestado(false);
                sobreescribir(art, i);
            }
        }
    }
};

