
#include <iomanip>
#include <ctime>
#include "algorithm"
#include "GestionSupervisor.h"

using namespace std;

void GestionSupervisor::menuSupervisor() {
	while (true) {

		system("cls");
		cout << endl;
		cout << "...............MENU SUPERVISOR................." << endl;
		cout << endl;
		cout << "1. Clientes" << endl;
		cout << "2. Vendedores" << endl;
		cout << "3. Seguros" << endl;
		cout << "4. Polizas" << endl;
		cout << "5. Ventas" << endl;
		cout << "6. Apercibimientos" << endl;
		cout << "7. Informes" << endl;
		cout << "0. Salir" << endl;
		cout << "------------------------------------------------" << endl;
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
		case 0:
			return;
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	}
}

void GestionSupervisor::SubMenuClientes() {

	while (true) {
		vectorClientes = archivoclientes().LeerArchivoAlmacenarEnVector();  //agrego esto para que se vean los cambios que se hagan al usar el programa, sino hay que cerrar y volver a abrir
		system("cls");
		cout << endl;
		cout << "...............CLIENTES................." << endl;
		cout << endl;
		cout << "1. Listado por apellido" << endl;
		cout << "2. Listado por edad" << endl;
		cout << "3. Consulta de cliente por DNI" << endl;
		cout << "4. Consulta de cliente por rango de edad" << endl;
		cout << "5. Consulta de cliente por telefono" << endl;
		cout << "6. Consulta de cliente por estado de gestion" << endl;
		cout << "7. Modificar estado del cliente" << endl;
		cout << "0. Volver" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorApellido);
			for (const clientes& cliente : vectorClientes) {
				cout << cliente.toString() << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}break;
		case 2: {
			system("cls");
			std::sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorNacimiento);
			for (const clientes& cliente : vectorClientes) {
				cout << cliente.toString() << endl;;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}break;
		case 3: {
			system("cls");
			cout << "Ingrese DNI del cliente: ";
			bool B = true, B1 = true;
			int dni;
			while (B1) {

				if (ValidarEntradaTeclado(dni)) {
					for (const clientes& cliente : vectorClientes) {
						if (cliente.getDNI() == dni) {
							system("cls");
							cout << cliente.toString2() << endl;
							B = false;
							B1 = false;
							break;
						}
						B1 = false;
					}

				}
			}
			if (B) { cout << "El DNI ingresado no existe" << endl; }
		}break;
		case 4: {
			system("cls");
			cout << "Ingrese rango de edad" << endl;
			cout << "edad1: ";
			bool B = true, B1 = true, B2 = true;
			int edad1, edad2;

			while (B1) {

				if (ValidarEntradaTeclado(edad1)) {
					B1 = false;
					cout << "edad2: ";
					while (B2) {
						if (ValidarEntradaTeclado(edad2)) {
							B2 = false;

							cout << "----------------------------------------------" << endl;
							cout << endl;
							for (const clientes& cliente : vectorClientes) {
								if (calcularEdad(cliente.getNacimiento().getanio(), cliente.getNacimiento().getmes(), cliente.getNacimiento().getdia()) >= edad1 && calcularEdad(cliente.getNacimiento().getanio(), cliente.getNacimiento().getmes(), cliente.getNacimiento().getdia()) <= edad2) {
									B = false;
									cout << cliente.toString() << endl;
									cout << ".........................." << endl;

								}
							}

						}

					}
				}
			}
			if (B) { cout << "Ningun cliente pertenece al rango de edad seleccionado" << endl; }

		}break;
		case 5: {
			system("cls");
			cout << "Ingrese telefono del cliente: ";
			char telefono[50];
			cin >> telefono;
			bool b = true;

			for (const clientes& cliente : vectorClientes) {
				if (strcmp(cliente.gettelefono(), telefono) == 0) {
					b = false;
					cout << "----------------------------------------------" << endl;
					cout << cliente.toString2() << endl;
					break;
				}
			}

			if (b) {

				cout << "----------------------------------------------" << endl;
				cout << "NO SE ENCONTRO CLIENTE CON ESE NUMERO DE TELEFONO" << endl;
			}
		}break;
		case 6: {
			system("cls");
			//Consulta de cliente por estado de gestion
			cout << "LISTADO DE ESTADOS" << endl;
			cout << endl;
			for (const estados& estado : vectorEstados) {
				cout << estado.toString() << endl;
			}
			cout << "------------------------------------------------------------------------------" << endl;
			for (const estadoXcliente& estadoxcliente : vectorEstadoXcliente) {
				cout << estadoxcliente.toString() << endl << endl;
			}

			cout << "------------------------------------------------------------------------------" << endl;
			cout << "Ingrese el id del estado: ";
			int idEstado;
			if (ValidarEntradaTeclado(idEstado)) {
				for (const estadoXcliente& estadoXcliente : vectorEstadoXcliente) {
					if (estadoXcliente.getidEstado() == idEstado) {
						for (const clientes& cliente : vectorClientes) {
							if (cliente.getidCliente() == estadoXcliente.getidCliente()) {
								cout << cliente.toString() << endl;
								cout << endl;
								break;
							}
						}
					}
				}
			}

		}break;
		case 7: {
			system("cls");
			cout << "Ingrese el Id del cliente: ";
			int idCliente;
			bool b = true;
			if (ValidarEntradaTeclado(idCliente)) {
				for (estadoXcliente& estadoXcliente : vectorEstadoXcliente) {
					if (estadoXcliente.getidCliente() == idCliente) {
						b = false;
						cout << "Ingrese el codigo del nuevo estado del cliente: ";
						int idEstado;
						if (ValidarEntradaTeclado(idEstado)) {
							//hacer validacion del estado
							for (const estados& estado : vectorEstados) {
								if (estado.getidEstado() == idEstado) {
									estadoXcliente.setidEstado(idEstado);
									archivoexc().GuardarVectorEstadoXClienteEnArchivo(vectorEstadoXcliente);
								}
							}
						}
						break;
					}
				}
				if (b) {
					cout << "No se encontro cliente con ese id";
				}

			}
		} break;
		case 0:
			system("cls");
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
	cout << endl;
	cout << "...............VENDEDORES................." << endl;
	cout << endl;
	cout << "1. Listado por apellido" << endl;
	cout << "2. Consulta de vendedores por legajo" << endl;
	cout << "0 Volver" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		system("cls");
		std::sort(vectorVendedores.begin(), vectorVendedores.end(), GestionVectores::CompararPorApellido);
		for (const vendedores& vendedor : vectorVendedores) {
			cout << vendedor.toString() << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}break;
	case 2: {
		system("cls");
		cout << "Ingrese legajo del vendedor: ";
		int legajo;
		bool b = true, b1 = true;
		while (b) {
			if (ValidarEntradaTeclado(legajo)) {
				b = false;
				for (const vendedores& vendedor : vectorVendedores) {
					if (vendedor.getLegajo() == legajo) {
						b1 = false;
						cout << "---------------------------------------------" << endl;
						cout << vendedor.toString() << endl;
					}
				}
			}
		}
		if (b1) {
			cout << endl;
			cout << "NO SE ENCONTRO VENDEDOR CON ESE NUMERO DE LEGAJO" << endl;
		}
	}break;
	case 0: {
		system("cls");
		return;
	}break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuSeguros() {
	system("cls");
	cout << endl;
	cout << "...............SEGUROS................." << endl;
	cout << endl;
	cout << "1. Listado por nombre" << endl;
	cout << "2. Consultar seguros por cliente" << endl;
	cout << "0. Volver" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		std::sort(vectorSeguros.begin(), vectorSeguros.end(), GestionVectores::CompararPorNombre);
		for (const seguros& seguro : vectorSeguros) {
			cout << seguro.toString() << endl;;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}break;
	case 2: {
		system("cls");
		cout << "Ingrese el Id del cliente: ";
		int idCliente;
		bool b = true, b1 = true;
		//cout << "--------------------------------------------------------" << endl;
		// saco el ciclo while porque no es necesario y requiere pasos extra para salir despues de mostrar los seguros
		if (ValidarEntradaTeclado(idCliente)) {
			for (const segurosXcliente& segurosXcliente : vectorSegurosXcliente) {
				if (segurosXcliente.getidCliente() == idCliente) {
					b1 = false;
					for (const seguros& seguro : vectorSeguros) {
						if (segurosXcliente.getidSeguro() == seguro.getidSeguro()) {
							cout << seguro.getnombre() << endl;
							break;
						}
					}

				}
			}
		}
		
		if (b1) {
			cout << endl;
			cout << "NO SE ENCONTRARON SEGUROS PARA EL CLIENTE CON ESE ID" << endl; //cambio un poco el mensaje
		}
	}break;
	case 0: {
		system("cls");
		return;
	}	break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuPolizas() {
	vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector(); //agrego esto para que se vean las polizas que se creen al usar el programa, sino hay que cerrar y volver a abrir
	system("cls");
	cout << endl;
	cout << "...............POLIZAS................." << endl;
	cout << endl;
	cout << "1.Consulta por numero de poliza" << endl;
	cout << "2. Anular poliza" << endl;
	cout << "0.Volver" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;

	switch (opcion) {
	case 1: {
		system("cls");
		cout << "Ingrese numero de poliza: ";
		int nro;
		bool b = true, b1 = true;
		while (b1) {
			if (ValidarEntradaTeclado(nro)) {
				b1 = false;
				for (const polizas& poliza : vectorPolizas) {
					if (poliza.getNdePoliza() == nro) {

						cout << poliza.toString() << endl;
						b = false;
					}
				}
			}
		}
		if (b) {
			cout << endl;
			cout << "NO SE ENCONTRO POLIZA CON ESE NUMERO" << endl;
		}
	}break;
	case 2: {
		system("cls");
		cout << "Ingrese numero de poliza que desea anular: ";
		int nro;
		bool b = true, b1 = true;
		while (b1) {
			if (ValidarEntradaTeclado(nro)) {
				b1 = false;
				for (polizas& poliza : vectorPolizas) {
					if (poliza.getNdePoliza() == nro) {
						b = false;
						poliza.setAnulada(true);  //cambio false por true
						archivopolizas().GuardarVectorPolizaEnArchivoPoliza(vectorPolizas);
						cout << "Poliza anulada exitosamente" << endl;
						break;
					}
				}
			}
		}
		if (b) {
			cout << endl;
			cout << "NO SE ENCONTRO POLIZA CON ESE NUMERO" << endl;
		}

		/*archivopolizas archPol;
		polizas poliza;

		int cant = archPol.contarRegistros();
		for (int i = 0; i < cant; i++) {
			poliza = archPol.leerRegistro(i);
			if (poliza.getNdePoliza() == nro) {
				poliza.setAnulada(false);
				archPol.grabarRegistro(poliza);

				vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector();

				cout << "Poliza anulada exitosamente" << endl;
			} else { cout << "No se encontro la poliza" << endl; }
		}*/

	} break;
	case 0: {
		system("cls");
		return;
	}break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuVentas() {
	vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector(); //agrego esto para que se vean las polizas que se creen al usar el programa, sino hay que cerrar y volver a abrir
	system("cls");
	cout << endl;
	cout << "...............VENTAS................." << endl;
	cout << endl;
	cout << "1.Listado por fecha" << endl;
	cout << "2.Listado por vendedor" << endl;
	cout << "3.Listado por seguros" << endl;
	cout << "4.Consulta de ventas por rango de fechas" << endl;
	cout << "5.Consulta de ventas por tipo de seguro" << endl;
	cout << "6.Consulta de ventas por vendedor" << endl;
	cout << "0.Volver" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		system("cls");
		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorFecha);
		for (const polizas& poliza : vectorPolizas) {
			cout << poliza.toString() << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}

	}break;
	case 2: {
		system("cls");
		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorLegajoVendedor);
		for (int i = 0; i < vectorPolizas.size(); i++) {
			if (i == 0) {
				cout << "Ventas de " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido();
				cout << vectorPolizas[i].toString() << endl;
			}
			else {
				if (vectorPolizas[i].getLegajoVendedor() == vectorPolizas[i - 1].getLegajoVendedor()) {
					cout << vectorPolizas[i].toString() << endl;
				}
				else {
					cout << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					cout << "Ventas de " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido();
					cout << vectorPolizas[i].toString() << endl;;
				}
			}
		}
	}break;
	case 3: {
		system("cls");
		std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorSeguro);  //
		for (int i = 0; i < vectorSeguros.size(); i++) {                                            //cambie este metodo porque no funcionaba
			cout << endl << "Ventas de " << vectorSeguros[i].getnombre() << endl;               //el ciclo daba una vuelta por cada poliza y si
			for (const polizas& poliza : vectorPolizas) {                                       //habia 0 o mas de 1 poliza de algun seguro empezaba
				if (vectorSeguros[i].getidSeguro() == poliza.getidSeguro()) {               //a pedir el nombre en la posicion incorrecta del vector
					cout << poliza.toString() << endl << endl;                          //de seguros
				}                                                                           //
			}                                                                                   //
		}                                                                                           //

	}break;
	case 4: {
		system("cls");
		cout << "Ingrese rango de fechas: ";
		Fecha f1, f2;
		f1.cargar();
		f2.cargar();

		for (const polizas& poliza : vectorPolizas) {
			if (f1 <= poliza.getFechaDeVenta() && poliza.getFechaDeVenta() <= f2) {   //cambio forma de comparar, operador definido en clase fecha
				cout << poliza.toString() << endl;
			}
		}

	}break;
	case 5: {
		system("cls");
		cout << "Ingrese el Id del seguro: ";
		int id;
		bool b = true, b1 = true;
		while (b1) {
			if (ValidarEntradaTeclado(id)) {
				b1 = false;
				for (const polizas& poliza : vectorPolizas) {
					if (poliza.getidSeguro() == id) {
						cout << poliza.toString() << endl;
						cout << "--------------------------------------" << endl;
						b = false;

					}
				}
			}
		}
		if (b) {
			cout << endl;
			cout << "NO EXISTEN VENTAS CON ESE ID O EL ID INGRESADO NO ES VALIDO" << endl;
		}
	}break;
	case 6: {
		system("cls");
		cout << "Ingrese el legajo del vendedor:";
		int legajo;
		bool b = true, b1 = true;
		while (b1) {
			if (ValidarEntradaTeclado(legajo)) {
				b1 = false;
				for (const polizas& poliza : vectorPolizas) {
					if (poliza.getLegajoVendedor() == legajo) {
						b = false;
						cout << poliza.toString() << endl;
						cout << "--------------------------------------------" << endl;
					}
				}
			}
		}
		if (b) {
			cout << endl;
			cout << "NO EXISTEN VENTAS DE ESE VENDEDOR O EL LEGAJO INGRESADO NO ES VALIDO" << endl;
		}
	}break;
	case 0: {
		system("cls");
		return;
	}break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuApercibimientos() {
	system("cls");
	cout << endl;
	cout << "...............APERCIBIMIENTOS................." << endl;
	cout << endl;
	cout << "1.Consulta de apercibimientos por vendedor" << endl;
	cout << "2.Ingresar apercibimiento" << endl;
	cout << "0.Volver" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		system("cls");
		cout << "Ingrese legajo del vendedor: ";
		int legajo;
		bool b = true, b1 = true, b2 = true;
		while (b1) {
			if (ValidarEntradaTeclado(legajo)) {
				b1 = false;
				for (const vendedores& vendedor : vectorVendedores) {
					if (vendedor.getLegajo() == legajo) {
						b = false;
						system("cls");
						cout << ".........Motivos de apercibimientos.........." << endl;
						cout << endl;
						for (const motivosapercibimiento& motivo : vectorMotivosApercibimientos) {
							cout << motivo.toString() << endl;
						}
						cout << "---------------------------------------------------------------------------------------" << endl;
						cout << endl;
						cout << "Apercibimientos del vendedor " << vendedor.getApellido() << " " << vendedor.getNombre() << " " << " :" << endl << endl;
						for (const apercibimientos& apercibimiento : vectorApercibimientos) {
							if (apercibimiento.getlegajo() == legajo) {
								b2 = false;
								cout << apercibimiento.toString() << endl << endl;

							}
						}
					}

				}
			}
		}
		if (b) {

			cout << endl;
			cout << "NO EXISTE VENDEDOR CON ESE NUMERO DE LEGAJO" << endl;
		}
		if (b == false && b2) {
			cout << endl;
			cout << " NO TIENE APERCIBIMIENTOS" << endl << endl;;
		}

	}
		  break;
	case 2: {
		system("cls");
		cout << "Ingrese legajo del vendedor: ";
		int leg;
		bool b = true, b1 = true, b2 = true;
		while (b1) {
			if (ValidarEntradaTeclado(leg)) {
				b1 = false;
				for (vendedores& vendedor : vectorVendedores) {
					if (vendedor.getLegajo() == leg) {
						apercibimientos a;
						b = false;
						cout << "Ingrese la fecha" << endl;
						Fecha fecha;
						fecha.cargar();//validar entrada en este metodo
						cout << "Ingrese el motivo: ";
						int mot;
						while (b2) {
							if (ValidarEntradaTeclado(mot)) {
								b2 = false;
								a.setfecha(fecha);
								a.setlegajo(leg);
								a.setmotivo(mot);

								vectorApercibimientos.push_back(a);
								archivoapercibimientos().GuardarVectorApercibimientoEnArchivo(vectorApercibimientos);
								cout << "Apercibimiento cargado correctamente" << endl;

							}
						}
						break;
					}

				}
			}
		}
		if (b) {
			cout << "NO SE ENCONTRO VENDEDOR CON ESE NUMERO DE LEGAJO" << endl;
		}


	}break;
	case 0: {
		system("cls");
		return;
	}break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}

void GestionSupervisor::SubMenuInformes() {
	system("cls");
	cout << endl;
	cout << ".......................INFORMES......................." << endl;
	cout << endl;
	cout << "1.Recaudacion Anual" << endl;
	cout << "2.Comisiones por vendedor" << endl;
	cout << "3.Recaudacion y cantidad de polizas por tipo de seguro" << endl;
	cout << "0.Volver" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Ingrese una opcion: ";
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1: {
		system("cls");
		cout << "Ingrese el anio: ";
		int anio;
		if (ValidarEntradaTeclado(anio)) {

			vector<vector<float>> vectorRecaudacionesPorMes;
			vectorRecaudacionesPorMes.resize(12);

			for (const polizas& poliza : vectorPolizas) {
				if (poliza.getFechaDeVenta().getanio() == anio) {
					vectorRecaudacionesPorMes[poliza.getFechaDeVenta().getmes() - 1].push_back(poliza.getCuota());
				}
			}

			vector<float> recaudacionMensual;
			for (const vector<float>& RecaudacionPorMes : vectorRecaudacionesPorMes) {
				float recaudacion = 0;
				for (const float& cuota : RecaudacionPorMes) {
					recaudacion += cuota;
				}
				recaudacionMensual.push_back(recaudacion);
			}

			cout << left << setw(15) << "MES" << "|" << setw(15) << "RECAUDACION" << endl;
			cout << string(32, '-') << endl;  // Imprime una línea de 32 caracteres '-'

			for (int i = 0; i < recaudacionMensual.size(); i++) {
				cout << left << setw(15) << Fecha().toStringMes(i + 1) << "|" << setw(15) << recaudacionMensual[i] << endl;
			}

		}


	}break;
	case 2: {
		system("cls");
		cout << "Ingrese el anio: ";
		int anio;
		if (ValidarEntradaTeclado(anio)) {

			cout << "Ingrese el mes: ";
			int mes;
			if (ValidarEntradaTeclado(mes)) {

				system("cls");
				cout << "Los porcentajes de comisiones son:" << endl;
				cout << "10% si el total recaudado es menor a 100000" << endl;
				cout << "15% si el total recaudado es mayor a 100000 y menor a 200000" << endl;
				cout << "20% si el total recaudado es mayor a 200000" << endl;
				cout << "--------------------------------------------" << endl;
				cout << " Comisiones por vendedor en " << Fecha().toStringMes(mes) << " del " << anio << endl << endl;

				vector<float> vectorRecaudacionPorVendedor;

				for (const vendedores& vendedor : vectorVendedores) {

					float recaudacion = 0;
					for (const polizas& poliza : vectorPolizas) {
						if (vendedor.getLegajo() == poliza.getLegajoVendedor()) {
							if (poliza.getFechaDeVenta().getanio() == anio && poliza.getFechaDeVenta().getmes() == mes) {

								recaudacion += poliza.getCuota();
							}

						}
					}
					vectorRecaudacionPorVendedor.push_back(recaudacion);

				}
				cout << left << setw(30) << "VENDEDOR" << "|" << setw(15) << "TOTAL" << "|" << setw(15) << "% DE COMISION" << "|" << setw(15) << "COMISION" << endl;
				cout << string(75, '-') << endl;

				int i = 0;
				for (const vendedores& vendedor : vectorVendedores) {
					cout << left << setw(15) << vendedor.getApellido() << setw(15) << vendedor.getNombre() << "|" << setw(15) << ("$" + to_string(vectorRecaudacionPorVendedor[i])) << "|" << setw(15);
					if (vectorRecaudacionPorVendedor[i] > 0 && vectorRecaudacionPorVendedor[i] < 100000) {
						cout << "10%" << "|" << "$" << vectorRecaudacionPorVendedor[i] * 0.1 << endl;
					} else if (vectorRecaudacionPorVendedor[i] > 100000 && vectorRecaudacionPorVendedor[i] < 200000) {
						cout << "15%" << "|" << "$" << vectorRecaudacionPorVendedor[i] * 0.15 << endl;
					} else if (vectorRecaudacionPorVendedor[i] > 200000) {
						cout << "20%" << "|" << "$" << vectorRecaudacionPorVendedor[i] * 0.2 << endl;
					} else if (vectorRecaudacionPorVendedor[i] == 0) {
						cout << "0%" << "|" << "$" << 0 << endl;
					}
					i++;

				}
			}
			cout << endl;

		}

	}break;
	case 3: {
		system("cls");
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

					if (f1 <= poliza.getFechaDeVenta() && poliza.getFechaDeVenta() <= f2) { //cambio la forma de comparar, operador definido en clase fecha
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

		int i = 0;
		for (const seguros& seguro : vectorSeguros) {
			cout << left << setw(15) << seguro.getnombre() << "|" << setw(15) << vectorCantidadPorTipoSeguro[i] << "|" << setw(15) << vectorRecaudacion[i] << endl;
			i++;
		}
	}break;
	case 0: {
		system("cls");
		return;
	}break;
	default:
		cout << "Opcion no valida" << endl;
		break;
	}
	system("pause");
}


void GestionSupervisor::CargarVectores() {
	vectorClientes = archivoclientes().LeerArchivoAlmacenarEnVector();
	vectorSeguros = archivoseguros().LeerArchivoAlmacenarEnVector();
	vectorVendedores = archivovendedores().LeerArchivoAlmacenarEnVector();
	vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector();
	vectorApercibimientos = archivoapercibimientos().LeerArchivoAlmacenarEnVector();
	vectorEstados = archivoestados().LeerArchivoAlmacenarEnVector();
	vectorEstadoXcliente = archivoexc().LeerArchivoAlmacenarEnVector();
	vectorMotivosApercibimientos = archivomotivos().LeerArchivoAlmacenarEnVector();
	vectorSegurosXcliente = archivosxc().LeerArchivoAlmacenarEnVector();
}

int GestionSupervisor::calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento) {
	// Obtener el tiempo actual en formato de tiempo de Unix (segundos desde Epoch)
	std::time_t tiempoAhora = std::time(nullptr);
	// Convertir el tiempo de Unix a una estructura tm que representa el tiempo local
	std::tm* ahora = std::localtime(&tiempoAhora);

	// Año, mes y día actuales
	int anioActual = ahora->tm_year + 1900; // tm_year es el número de años desde 1900
	int mesActual = ahora->tm_mon + 1;      // tm_mon es el mes del año desde 0 (0 = enero)
	int diaActual = ahora->tm_mday;         // tm_mday es el día del mes

	int edad = anioActual - anioNacimiento;

	// Ajustar la edad si aún no hemos pasado el mes de nacimiento este año,
	// o si estamos en el mes pero aún no es el día de nacimiento
	if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento)) {
		edad--;
	}

	return edad;
}

template<typename T>
bool GestionSupervisor::ValidarEntradaTeclado(T& datoIngresar) {

	if (!(cin >> datoIngresar)) {
		// Limpia el estado de error de cin
		std::cin.clear();
		// Descarta la entrada inválida hasta el siguiente salto de línea
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		system("cls");
		std::cout << "Entrada invalida. Por favor, ingrese un tipo de dato valido: " << endl;
		return false;
	}
	return true;
}


