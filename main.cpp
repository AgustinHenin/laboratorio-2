#include "gestionventas.h"
#include "gestionsupervisor.cpp"
#include "backup.h"

using namespace std;

int main() {
	
	gestionventas gv;
	GestionSupervisor gs;
	backup b;
	
	while (true) {
		system("cls");
		
		cout << "================================================================================" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                      SISTEMA DE GESTION CALL CENTER                          |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "================================================================================" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              MENU PRINCIPAL                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "================================================================================" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Iniciar como vendedor                                                    |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Iniciar como supervisor                                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  3. Copias de seguridad                                                      |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Salir                                                                    |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "================================================================================" << endl << endl;
		cout << "Ingrese una opcion: ";
		int op;
		cin >> op;
		switch (op) {
		case 1:
			gv.menuvendedor();
			system("pause");
			break;
		case 2:
			gs.menuSupervisor();
			system("pause");
			break;
		case 3:
			b.menubackup();
			system("pause");
			break;
		case 0:
                        return 0;
			break;
		}
	}

	return 0;
}
