#include "gestionpolizas.h"
#include "gestionclientes.h"

class gestionventas
{
private:
	gestionpolizas gp;
	gestionclientes gc;
public:

	void menuvendedor() {
		while (true) {
			system("cls");
			cout << "...............MENU VENDEDOR................." << endl << endl;
			cout << "1. Gestionar lista de clientes " << endl;
			cout << "2. Buscar ficha por ID" << endl;
			cout << "0. Salir" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese una opcion: ";
			int op;
			cin >> op;
			switch (op) {
			case 1:
				todos();
				system("pause");
				break;
			case 2:
				int id;
				cout << "ID del cliente: ";
				cin >> id;
				uno(id);
				system("pause");
				break;
			case 0:
				return;
				break;
			default:
				cout << "Opcion no valida" << endl;
				system("pause");
				break;
			}
		}
	}
	void todos() {
		clientes c;
		archivoclientes ac;
		estadoXcliente ec;
		archivoexc aec;
		int cant1 = ac.contarRegistros(), cant2 = aec.contarRegistros();
		bool volver = false;
		for (int i = 0; i < cant1; i++) {
			c = ac.leerRegistro(i);
			bool llamar = true;
			for (int j = 0; j < cant2; j++) {
				ec = aec.leerRegistro(j);
				if (c.getidCliente() == ec.getidCliente()) {
					if (ec.getidEstado() == 3 || ec.getidEstado() == 5) {
						llamar = false;
					}
				}
			}
			while (llamar == true) {
				system("cls");
				gc.fichacliente(i+1);
				cout << "MENU" << endl;
				cout << "1. Modificar datos de contacto " << endl;
				cout << "2. Cargar venta" << endl;
				cout << "3. Clasificar llamado y avanzar" << endl;
				cout << "0. Volver" << endl;
				cout << "------------------------------------" << endl;
				cout << "Ingrese una opcion: ";
				int op;
				cin >> op;
				switch (op) {
				case 1:
					gc.modificardatos(i + 1);
					system("pause");
					break;
				case 2:
					gp.cargadepoliza(i + 1);
					system("pause");
					break;
				case 3:
					gc.clasificar(i + 1);
					system("pause");
					llamar = false;
					break;
				case 0:
					return;
					break;
				default:
					cout << "Opcion no valida" << endl;
					system("pause");
					break;
				}

			}

		}
		cout << "no hay mas clientes";
	}

	void uno(int id) {
		bool llamar = true;
		while (llamar == true) {
			system("cls");
			gc.fichacliente(id);
			cout << "MENU" << endl;
			cout << "1. Modificar datos de contacto " << endl;
			cout << "2. Cargar venta" << endl;
			cout << "3. Clasificar llamado y avanzar" << endl;
			cout << "-------------------------------------" << endl;
			cout << "Ingrese una opcion: ";
			int op;
			cin >> op;
			switch (op) {
			case 1:
				gc.modificardatos(id);
				system("pause");
				break;
			case 2:
				gp.cargadepoliza(id);
				system("pause");
				break;
			case 3:
				gc.clasificar(id);
				system("pause");
				llamar = false;
				break;
			default:
				cout << "Opcion no valida" << endl;
				system("pause");
				break;
			}
		}
	}
};
