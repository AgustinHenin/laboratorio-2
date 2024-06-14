#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include<cstdio>
#include <cstdlib>
#include "archivoclientes.h"
#include "archivovendedores.h"
#include "archivopolizas.h"
#include "archivoseguros.h"
#include "archivoapercibimientos.h"

using namespace std;

class backup
{
public:
	void menubackup() {
		archivopolizas ap;
		archivoclientes ac;
		archivovendedores av;
		archivoseguros as;
		archivoapercibimientos aa;
		while (true) {
			system("cls");
			cout << "1. Crear copia de seguridad " << endl;
			cout << "2. Restaurar copia de seguridad" << endl;
			cout << "3. Volver" << endl;
			int op;
			cin >> op;
			switch (op) {
			case 1:
				system("cls");
				cout << "Seleccione archivo a copiar" << endl;
				cout << "1. Polizas" << endl;
				cout << "2. Vendedores" << endl;
				cout << "3. Clientes" << endl;
				cout << "4. Seguros" << endl;
				cout << "5. Apercibimientos" << endl;
				cout << "6. Todos" << endl;
				cout << "7. Volver" << endl;
				cout << "Ingrese una opcion: ";
				int op2;
				cin >> op2;

				switch (op2) {
				case 1:
					ap.crearcopia();
					break;
				case 2:
					av.crearcopia();
					break;
				case 3:
					ac.crearcopia();
					break;
				case 4:
					as.crearcopia();
					break;
				case 5:
					aa.crearcopia();
					break;
				case 6:
					ap.crearcopia();
					av.crearcopia();
					ac.crearcopia();
					as.crearcopia();
					aa.crearcopia();
					break;
				case 7:
					return;
					break;
				default:
					cout << "Opcion no valida" << endl;
					break;
				}

				system("pause");
				break;
			case 2:
				system("cls");
				cout << "Seleccione archivo a restaurar" << endl;
				cout << "1. Polizas" << endl;
				cout << "2. Vendedores" << endl;
				cout << "3. Clientes" << endl;
				cout << "4. Seguros" << endl;
				cout << "5. Apercibimientos" << endl;
				cout << "6. Todos" << endl;
				cout << "7. Volver" << endl;
				cout << "Ingrese una opcion: ";
				int op3;
				cin >> op3;

				switch (op3) {
				case 1:
					ap.restaurarcopia();
					break;
				case 2:
					av.restaurarcopia();
					break;
				case 3:
					ac.restaurarcopia();
					break;
				case 4:
					as.restaurarcopia();
					break;
				case 5:
					aa.restaurarcopia();
					break;
				case 6:
					ap.restaurarcopia();
					av.restaurarcopia();
					ac.restaurarcopia();
					as.restaurarcopia();
					aa.restaurarcopia();
					break;
				case 7:
					return;
					break;
				default:
					cout << "Opcion no valida" << endl;
					break;
				}
				system("pause");
				break;
			case 3:
				return;
				break;
			}
		}
	}
};

