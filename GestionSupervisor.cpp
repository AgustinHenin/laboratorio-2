#include <iomanip>
#include "algorithm"
#include "GestionSupervisor.h"
using namespace std;

void GestionSupervisor::menuSupervisor() {
	while (true) {
		system("cls");
		cout << "1. Clientes" << endl;
		cout << "2. Vendedores" << endl;
		cout << "3. Seguros" << endl;
		cout << "4. Polizas" << endl;
		cout << "5. Ventas" << endl;
		cout << "6. Apercibimientos" << endl;
		cout << "7. Informes" << endl;
		cout << "8. Salir" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;

		switch (opcion) {
		case 1:
			SubMenuClientes();
			break;
		case 2:
			SubMenuVendedores();
			break;
		case 3:
			SubMenuSeguros();
			break;
		case 4:
			SubMenuPolizas();
			break;
		case 5:
			SubMenuVentas();
			break;
		case 6:
			SubMenuApercibimientos();
			break;
		case 7:
			SubMenuInformes();
			break;
		case 8:
			return;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
	//system("pause");
}

void GestionSupervisor::SubMenuClientes() {
	while (true) {
		system("cls");
		cout << "1. Listado por apellido" << endl;
		cout << "2. Listado por edad" << endl;
		cout << "3. Consulta de cliente por DNI" << endl;
		cout << "4. Consulta de cliente por rango de edad" << endl;
		cout << "5. Consulta de cliente por telefono" << endl;
		cout << "6. Consulta de cliente por estado de gestion" << endl;
		cout << "7. Volver" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorApellido);
			for (const clientes& cliente : vectorClientes) {
				cout << cliente.toString();
			}
		}break;
		case 2: {
			std::sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorNacimiento);
			for (const clientes& cliente : vectorClientes) {
				cout << cliente.toString();
			}
		}break;
		case 3: {
			cout << "Ingrese DNI del cliente: ";
			int dni;
			cin >> dni;
			for (const clientes& cliente : vectorClientes) {
				if (cliente.getDNI() == dni) {
					cout << cliente.toString2();
				}
				else { cout << "No se encontro el cliente" << endl; }
			}
		}break;
		case 4: {
			cout << "Ingrese rango de edad: ";
			int edad1, edad2;
			cin >> edad1 >> edad2;
			for (const clientes& cliente : vectorClientes) {
				if (cliente.getNacimiento().getanio() >= edad1 && cliente.getNacimiento().getanio() <= edad2) {
					cout << cliente.toString();
				}
			}
		}break;
		case 5: {
			cout << "Ingrese telefono del cliente: ";
			char telefono[50];
			cin >> telefono;
			for (const clientes& cliente : vectorClientes) {
				if (strcmp(cliente.gettelefono(), telefono) == 0) {
					cliente.toString2();
				}
			}
		}break;
		case 6:
			//Consulta de cliente por estado de gestion
			break;
		case 7:
			return;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
		system("pause");
	}
}

void GestionSupervisor::SubMenuVendedores() {
	system("cls");
	cout << "1. Listado por apellido" << endl;
	cout << "2. Consulta de vendedores por legajo" << endl;
	cout << "3 Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		std::sort(vectorVendedores.begin(), vectorVendedores.end(), GestionVectores::CompararPorApellido);
		for (const vendedores& vendedor : vectorVendedores) {
			cout << vendedor.toString();
		}
	}break;
	case 2: {
		cout << "Ingrese legajo del vendedor: ";
		int legajo;
		cin >> legajo;
		for (const vendedores& vendedor : vectorVendedores) {
			if (vendedor.getLegajo() == legajo) {
				cout << vendedor.toString();
			}
			else { cout << "No se encontro el vendedor" << endl; }
		}
	}break;
	case 3: {
		return;
	}	break;

		system("pause");
	}
}

void GestionSupervisor::SubMenuSeguros()
{
	system("cls");
	cout << "1. Listado por nombre" << endl;
	cout << "2. Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		std::sort(vectorSeguros.begin(), vectorSeguros.end(), GestionVectores::CompararPorNombre);
		for (const seguros& seguro : vectorSeguros) {
			cout << seguro.toString();

		}
	}break;
	case 2: {
		return;
	}	break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuPolizas() {
	system("cls");
	cout << "1.Consulta por numero de poliza" << endl;
	cout << "2.Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case	1: {
		cout << "Ingrese numero de poliza: ";
		int nro;
		cin >> nro;
		for (const polizas& poliza : vectorPolizas) {
			if (poliza.getNdePoliza() == nro) {

				cout << poliza.toString();
			}
		}
	}
	}
}

void GestionSupervisor::SubMenuVentas() {
	system("cls");
	cout << "1.Listado por fecha" << endl;
	cout << "2.Listado por vendedor" << endl;
	cout << "3.Listado por seguros" << endl;
	cout << "4.Consulta de ventas por rango de fechas" << endl;
	cout << "5.Consulta de ventas por seguro" << endl;
	cout << "6.Consulta de ventas por vendedor" << endl;
	cout << "7.Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorFecha);
		for (const polizas& poliza : vectorPolizas) {
			cout << poliza.toString();
		}

	}break;
	case 2: {
		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorLegajoVendedor);
		for (int i = 0; i < vectorPolizas.size(); i++) {
			if (i == 0) {
				cout << "Ventas de " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido();
				cout << vectorPolizas[i].toString();
			}
			else {
				if (vectorPolizas[i].getLegajoVendedor() == vectorPolizas[i - 1].getLegajoVendedor()) {
					cout << vectorPolizas[i].toString();
				}
				else {
					cout << "Ventas de " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido();
					cout << vectorPolizas[i].toString();
				}
			}
		}
	}break;
	case 3: {

		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorSeguro);
		for (int i = 0; i < vectorPolizas.size(); i++)
		{
			if (i == 0) {
				cout << "Ventas de " << vectorSeguros[i].getnombre();
				cout << vectorPolizas[i].toString();
			}
			else
			{
				if (vectorPolizas[i].getidSeguro() == vectorPolizas[i - 1].getidSeguro()) {
					cout << vectorPolizas[i].toString();
				}
				else {
					cout << "Ventas de " << vectorSeguros[i].getnombre();
					cout << vectorPolizas[i].toString();
				}
			}
		}

	}break;
	case 4: {
		cout << "Ingrese rango de fechas: ";
		Fecha f1, f2;
		f1.cargar();
		f2.cargar();

		for (const polizas& poliza : vectorPolizas) {
			if (poliza.getFechaDeVenta().getanio() >= f1.getanio() && poliza.getFechaDeVenta().getanio() <= f2.getanio()) {
				cout << poliza.toString();
			}
		}


	}break;
	case 5: {
		cout << "Ingrese el Id del seguro: ";
		int id;
		cin >> id;
		for (const polizas& poliza : vectorPolizas) {
			if (poliza.getidSeguro() == id) {
				cout << poliza.toString();
			}
		}
	}break;
	case 6: {
		cout << "Ingrese el legajo del vendedor:";
		int legajo;
		cin >> legajo;
		for (const polizas& poliza : vectorPolizas) {
			if (poliza.getLegajoVendedor() == legajo)
			{
				cout << poliza.toString();
			}
		}
	}break;
	case 7: { return; }break;


	default:
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuApercibimientos()
{
	system("cls");
	cout << "1.Consulta de apercibimientos por vendedor" << endl;
	cout << "2.Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1: {
		cout << "Ingrese legajo del vendedor: ";
		int legajo;
		cin >> legajo;
	}
		  break;
	case 2: {
		return;
	}
	default:
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuInformes()
{
	system("cls");
	cout << "1.Recaudacion Anual" << endl;
	cout << "2.Comisiones por vendedor" << endl;
	cout << "3.Recaudacion y cantidad de polizas por tipo de seguro" << endl;
	cout << "4.Volver" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion)
	{
	case 1: {
		cout << "Ingrese el anio: ";
		int anio;
		cin >> anio;

		vector<vector<float>> vectorRecaudacionesPorMes;
		vectorRecaudacionesPorMes.resize(12);

		for (const polizas& poliza : vectorPolizas) {
			if (poliza.getFechaDeVenta().getanio() == anio)
			{
				vectorRecaudacionesPorMes[poliza.getFechaDeVenta().getmes() - 1].push_back(poliza.getCuota());
			}

		}

		vector<float> recaudacionMensual;


		for (const vector<float>& RecaudacionPorMes : vectorRecaudacionesPorMes) {
			float recaudacion = 0;
			for (const float& cuota : RecaudacionPorMes)
			{
				recaudacion += cuota;
			}
			recaudacionMensual.push_back(recaudacion);
		}

		cout << left << setw(15) << "MES" << "|" << setw(15) << "RECAUDACION" << endl;
		cout << string(32, '-') << endl;  // Imprime una línea de 32 caracteres '-'

		for (int i = 0; i < recaudacionMensual.size(); i++)
		{
			cout << left << setw(15) << Fecha().toStringMes(i + 1) << "|" << setw(15) << recaudacionMensual[i] << endl;
		}


	}
		  break;
	case 2: {}
		  break;
	case 3: {
		cout << "Ingrese rango de fechas: ";
		Fecha f1, f2;
		f1.cargar();
		f2.cargar();

		archivoseguros archSeg;
		vector<int> vectorCantidadPorTipoSeguro;
		vector<float>vectorRecaudacion;



		for (const seguros& seguro : vectorSeguros) {
			int cont = 0;
			float recaudacion = 0;
			for (const polizas& poliza : vectorPolizas) {
				if (seguro.getidSeguro() == poliza.getidSeguro()) {
					//poliza.getFechaDeVenta().getdia() >= f1.getdia() && poliza.getFechaDeVenta().getmes() == f1.getmes() && poliza.getFechaDeVenta().getanio() == f1.getanio() && poliza.getFechaDeVenta().getdia() <= f2.getdia() && poliza.getFechaDeVenta().getmes() == f2.getmes() && poliza.getFechaDeVenta().getanio() == f2.getanio()
					if (poliza.getFechaDeVenta().toString() >= f1.toString() && poliza.getFechaDeVenta().toString() <= f1.toString()) {
						cont++;
						recaudacion += poliza.getCuota();
					}
				}
			}
			vectorCantidadPorTipoSeguro.push_back(cont);
			vectorRecaudacion.push_back(recaudacion);
		}

		cout << left << setw(15) << "SEGURO" << "|" << setw(15) << "CANTIDAD" << "|" << setw(15) << "RECAUDACION" << endl;
		cout << string(55, '-') << endl;

		for (const seguros& seguro : vectorSeguros)
		{
			int i = 0;
			cout << left << setw(15) << seguro.getnombre() << "|" << setw(15) << vectorCantidadPorTipoSeguro[i] << "|" << setw(15) << vectorRecaudacion[i] << endl;
		}
	}
		  break;
	case 4: { return; }
	default:
		break;

		system("pause");
	}
}

void GestionSupervisor::CargarVectores() {
	vectorClientes = archivoclientes().LeerArchivoAlmacenarEnVector();
	vectorSeguros = archivoseguros().LeerArchivoAlmacenarEnVector();
	vectorVendedores = archivovendedores().LeerArchivoAlmacenarEnVector();
	vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector();
}


