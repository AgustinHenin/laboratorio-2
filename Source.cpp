#include <iostream>
#include <cstring>
#include<cstdio>
#include <cstdlib>
#include "articulos.h"
#include "gestionarticulos.h"
#include "ventas.h"
#include "gestionventas.h"


using namespace std;

int main() {
	gestionarticulos asdf;
	gestionventas qwer;
    int op;
    while (true) {
        system("cls");
        cout << "Menu" << endl;
        cout << "Elija una opcion: " << endl;
        cout << "1. articulos" << endl;
        cout << "2. ventas" << endl;
        cout << "3. " << endl;
        cout << "0. Salir" << endl;
        cin >> op;
        switch (op) {
        case 1:
            asdf.menu();
            break;
        case 2:
            qwer.menu();
            break;
        case 3:
            
            break;
        case 0:
            return 0;
        }
        system("pause");
    }
	
	return 0;
}