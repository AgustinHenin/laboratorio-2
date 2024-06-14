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
			cout << "1. GESTIONAR LISTA DE CLIENTES " << endl;
			cout << "2. BUSCAR FICHA POR ID" << endl;
			cout << "3. VOLVER" << endl;
			int op;
			cin >> op;
			switch (op) {
			case 1:
				todos();
				system("pause");
				break;
			case 2:
				int id;
				cout << "ID DEL CLIENTE: ";
				cin >> id;
				
				gc.fichacliente(id);
				system("pause");
				break;
			case 3:
				return;
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
				cout << "1. MODIFICAR DATOS DE CONTACTO " << endl;
				cout << "2. CARGAR VENTA" << endl;
				cout << "3. CLASIFICAR LLAMADO Y AVANZAR" << endl;
				cout << "4. VOLVER" << endl;
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
				case 4:
					volver = true;
					break;
				case 5:
					gp.listarpolizas();
					system("pause");
					break;
				}
				
			}

		}
		cout << "no hay mas clientes";
	}
};
