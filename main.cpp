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
		cout << "SISTEMA DE GESTION CALL CENTER" << endl << endl;
		cout << "........MENU PRINCIPAL........" << endl << endl;
		cout << "1. Iniciar como vendedor" << endl;
		cout << "2. Iniciar como supervisor" << endl;
		cout << "3. Copias de seguridad" << endl;
		cout << "0. Salir" << endl;
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


/*
    motivosapercibimiento c;
    archivomotivos ac;
    c.setidMotivo(ac.siguiente());
    c.setmotivo("Desobodecer indicaciones del supervisor");

    ac.grabarRegistro(c);
*/

	return 0;
}
