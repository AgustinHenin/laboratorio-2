//agrego otro metodo de validacion que verifica que, en el archivo correpondiante, exista
//un registro que coincida con el dato ingresado
// agrego validaciones de fechas 
//agrego algo de memoria dinamica en los casos 2 y 3 del menu informes
//cambio un poco la validacion de mes porque en algunos casos no funcionaba y agrego validacion de año
//cambio forma en qye se muestran vendedores, clientes y polizas usando metodo mostrar de las clases vend y clientes y metodo mostrarpoliza de la clase gestion poliza
//cambio forma de validar fecha

#include <iomanip>
#include <ctime>
#include "algorithm"
#include "GestionSupervisor.h"
#include "gestionventas.h"

using namespace std;

void GestionSupervisor::menuSupervisor() {
	while (true) {

		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              MENU SUPERVISOR                                 |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Clientes                                                                 |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Vendedores                                                               |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  3. Seguros                                                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  4. Polizas                                                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  5. Ventas                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  6. Apercibimientos                                                          |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  7. Informes                                                                 |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Salir                                                                    |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
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
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              CLIENTES                                        |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Listado por apellido                                                     |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Listado por edad                                                         |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  3. Consulta de cliente por DNI                                              |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  4. Consulta de cliente por rango de edad                                    |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  5. Consulta de cliente por telefono                                         |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  6. Consulta de cliente por estado de gestion                                |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  7. Modificar estado del cliente                                             |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorApellido);
			for (const clientes& cliente : vectorClientes) {
				cout << endl;
				cliente.mostrar();
				cout << endl;
				cout << "--------------------------------------------------" << endl;
			}
		}break;
		case 2: {
			system("cls");
			std::sort(vectorClientes.begin(), vectorClientes.end(), GestionVectores::CompararPorNacimiento);
			for (const clientes& cliente : vectorClientes) {
				//cout << cliente.toString() << endl;
				cliente.mostrar();
				cout << endl;
				cout << "---------------------------------------------------" << endl;
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
							//cout << cliente.toString2() << endl;
							cliente.mostrar();
							cout << endl;
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
									//cout << cliente.toString() << endl;
									cliente.mostrar();
									cout << endl;
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
					//cout << cliente.toString2() << endl;
					cliente.mostrar();
					cout << endl;
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
			cout << "Ingrese el id del estado: ";
			int idEstado;
			archivoestados ae;
			bool b = true, b1 = true;
			while (b1) { // agrego while para que deje volver a intentar si se ingresa un dato invalido
				if (ValidarEntradaTeclado(idEstado)) {
					if (ae.validarestado(idEstado)) {
						b1 = false;
						for (const estadoXcliente& estadoXcliente : vectorEstadoXcliente) {
							
							if (estadoXcliente.getidEstado() == idEstado) {
								b = false;
								for (const clientes& cliente : vectorClientes) {
									if (cliente.getidCliente() == estadoXcliente.getidCliente()) {
										//cout << cliente.toString() << endl;
										cout << endl;
										cliente.mostrar();
										cout << endl;
										break;
									}
								}
							}
						}
					}
					else {
						cout << "No se encontro estado con ese ID, intente de nuevo: ";
					}
				}
			}
			if (b) {
				cout << "No se encontraron clientes con ese estado" << endl; // agrego
			}

		}break;
		case 7: {
			system("cls");
			cout << "Ingrese el Id del cliente: ";
			int idCliente;
			bool b = true, b1 = true, b2 = true;
			archivoclientes ac;
			archivoestados ae;
			while (b1) {// agrego while para que deje volver a intentar si se ingresa un dato invalido
				if (ValidarEntradaTeclado(idCliente)) {
					if (ac.validarcliente(idCliente)) {
						b1 = false;
						for (estadoXcliente& estadoXcliente : vectorEstadoXcliente) {
							if (estadoXcliente.getidCliente() == idCliente) {
								b = false;
								cout << "Ingrese el codigo del nuevo estado del cliente: ";
								int idEstado;
								while (b2) {
									if (ValidarEntradaTeclado(idEstado)) {
										if (ae.validarestado(idEstado)) {
											b2 = false;
											//hacer validacion del estado
											for (const estados& estado : vectorEstados) {
												if (estado.getidEstado() == idEstado) {
													estadoXcliente.setidEstado(idEstado);
													archivoexc().GuardarVectorEstadoXClienteEnArchivo(vectorEstadoXcliente);
												}
											}
										}
										else {
											cout << "No se encontro estado con ese ID, intente de nuevo: ";
										}
									}

								}
							}
						}
					}
					else {
						cout << "No se encontro cliente con ese ID, intente de nuevo: ";
					}
				}
			}
			if (b) {
				cout << "El cliente no fue contactado y no tiene un estado para cambiar" << endl;
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
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              VENDEDORES                                      |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Listado por apellido                                                     |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Consulta de vendedores por legajo                                        |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			std::sort(vectorVendedores.begin(), vectorVendedores.end(), GestionVectores::CompararPorApellido);
			for (const vendedores& vendedor : vectorVendedores) {
				cout << endl;
				vendedor.mostrar();
				cout << endl;
				cout << "------------------------------------------------" << endl;
			}
		}break;
		case 2: {
			system("cls");
			cout << "Ingrese legajo del vendedor: ";
			int legajo;
			bool b = true, b1 = true;
			archivovendedores av;
			while (b) {
				if (ValidarEntradaTeclado(legajo)) {
					if (av.validarvendedor(legajo)) {
						b = false;
						for (const vendedores& vendedor : vectorVendedores) {
							if (vendedor.getLegajo() == legajo) {
								//b1 = false;
								cout << "---------------------------------------------" << endl;
								//cout << vendedor.toString() << endl;
								vendedor.mostrar();
								cout << endl;
							}
						}
					}
					else {
						cout << "No se encontro vendedor con ese legajo, intente de nuevo: ";
					}
				}
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
}

void GestionSupervisor::SubMenuSeguros() {
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              SEGUROS                                         |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Listado por nombre                                                       |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Consultar seguros por cliente                                            |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			system("cls");
			std::sort(vectorSeguros.begin(), vectorSeguros.end(), GestionVectores::CompararPorNombre);
			cout << "......Listado de seguros......" << endl << endl;
			for (const seguros& seguro : vectorSeguros) {
				cout << seguro.toString() << endl << endl;

			}
		}break;
		case 2: {
			system("cls");
			cout << "Ingrese el Id del cliente: ";
			int idCliente;
			bool b = true, b1 = true;
			archivoclientes ac;
			//cout << "--------------------------------------------------------" << endl;
			while (b) { // vuelvo a poner el while, me di cuenta de que si sirve
				if (ValidarEntradaTeclado(idCliente)) {
					if (ac.validarcliente(idCliente)) {
						b = false;
						cout << endl;
						cout << "SEGUROS: " << endl;
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
					else {
						cout << "No se encontro clinte con ese ID, intente de nuevo: ";
					}
					//cout << endl;
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
}

void GestionSupervisor::SubMenuPolizas() {
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector(); //agrego esto para que se vean las polizas que se creen al usar el programa, sino hay que cerrar y volver a abrir
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              POLIZAS                                         |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Consulta por numero de poliza                                            |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Anular poliza                                                            |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;

		switch (opcion) {
		case 1: {
			system("cls");
			cout << "Ingrese numero de poliza: ";
			int nro;
			bool b = true, b1 = true;
			archivopolizas ap;
			gestionpolizas gp;
			while (b1) {
				if (ValidarEntradaTeclado(nro)) {
					if (ap.validarpoliza(nro)) {
						b1 = false;
						for (const polizas& poliza : vectorPolizas) {
							if (poliza.getNdePoliza() == nro) {
								cout << "-------------------------------------------------------" << endl;
								gp.mostrarpoliza(nro);
								//cout << poliza.toString() << endl;
								//b = false;
							}
						}
					}
					else {
						cout << "No se encontro poliza con ese numero, intente de nuevo: ";
					}
				}
			}
		}break;
		case 2: {
			system("cls");
			cout << "Ingrese numero de poliza que desea anular: ";
			int nro;
			bool b = true, b1 = true;
			archivopolizas ap;
			while (b1) {
				if (ValidarEntradaTeclado(nro)) {
					if (ap.validarpoliza(nro)) {
						b1 = false;
						for (polizas& poliza : vectorPolizas) {
							if (poliza.getNdePoliza() == nro) {
								//b = false;
								poliza.setAnulada(true);  //cambio false por true
								archivopolizas().GuardarVectorPolizaEnArchivoPoliza(vectorPolizas);
								cout << "Poliza anulada exitosamente" << endl;
								break;
							}
						}
					}
					else {
						cout << "No se encontro poliza con ese numero, intente de nuevo: ";
					}
				}
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
}

void GestionSupervisor::SubMenuVentas() {
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector(); //agrego esto para que se vean las polizas que se creen al usar el programa, sino hay que cerrar y volver a abrir
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              VENTAS                                          |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Listado por fecha                                                        |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Listado por vendedor                                                     |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  3. Listado por seguros                                                      |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  4. Consulta de ventas por rango de fechas                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  5. Consulta de ventas por tipo de seguro                                    |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  6. Consulta de ventas por vendedor                                          |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			gestionpolizas gp;
			std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorFecha);
			for (const polizas& poliza : vectorPolizas) {
				//cout << poliza.toString() << endl;
				gp.mostrarpoliza(poliza.getNdePoliza());
				cout << "----------------------------------------------------" << endl;
			}

		}break;
		case 2: {
			system("cls");
			gestionpolizas gp;
			std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorLegajoVendedor);
			for (int i = 0; i < vectorPolizas.size(); i++) {
				if (i == 0) {
					cout << "	VENTAS DE  " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido() << endl << endl;
					//cout << vectorPolizas[i].toString() << endl;
					gp.mostrarpoliza(vectorPolizas[i].getNdePoliza());
					cout << endl;
				}
				else {
					if (vectorPolizas[i].getLegajoVendedor() == vectorPolizas[i - 1].getLegajoVendedor()) {
						//cout << vectorPolizas[i].toString() << endl << endl;
						gp.mostrarpoliza(vectorPolizas[i].getNdePoliza());
						cout << endl << endl;
					}
					else {
						cout << endl;
						cout << "---------------------------------------------------------" << endl;
						cout << "	VENTAS DE  " << GestionVectores::BuscarVendedorPorLegajo(vectorVendedores, vectorPolizas[i].getLegajoVendedor()).toStringNombreYApellido() << endl << endl;

						//cout << vectorPolizas[i].toString() << endl << endl;
						gp.mostrarpoliza(vectorPolizas[i].getNdePoliza());
						cout << endl << endl;
					}
				}
			}

		}break;
		case 3: {
			system("cls");
			gestionpolizas gp;
			std::sort(vectorPolizas.begin(), vectorPolizas.end(), GestionVectores::CompararPorSeguro);  //
			for (int i = 0; i < vectorSeguros.size(); i++) {                                            //cambie este metodo porque no funcionaba
				cout << endl << endl << "Ventas de seguros de " << vectorSeguros[i].getnombre() << endl;
				cout << "--------------------------------------------------------------------------" << endl;//el ciclo daba una vuelta por cada poliza y si
				for (const polizas& poliza : vectorPolizas) {                                       //habia 0 o mas de 1 poliza de algun seguro empezaba
					if (vectorSeguros[i].getidSeguro() == poliza.getidSeguro()) {               //a pedir el nombre en la posicion incorrecta del vector
						//cout << poliza.toString() << endl << endl;                          //de seguros
						gp.mostrarpoliza(poliza.getNdePoliza());
					}                                                                           //
				}                                                                                   //
			}                                                                                           //

		}break;
		case 4: {
			system("cls");
			gestionpolizas gp;
			cout << "Ingrese rango de fechas: ";
			Fecha f1, f2;
			int dia, mes, anio;
			bool b = true, b1 = true;
			while (b) {
				cout << "Fecha 1 " << endl;
				cout << "Dia: ";
				if (ValidarEntradaTeclado(dia)) {
					cout << "Mes: ";
					if (ValidarEntradaTeclado(mes)) {
						cout << "Anio: ";
						if (ValidarEntradaTeclado(anio)) {
							f1.setdia(dia);
							f1.setmes(mes);
							f1.setanio(anio);
							if (f1.validar()) {
								b = false;
							}
						}
					}
				}
			}
			while (b1) {
				cout << "Fecha 2 " << endl;
				cout << "Dia: ";
				if (ValidarEntradaTeclado(dia)) {
					cout << "Mes: ";
					if (ValidarEntradaTeclado(mes)) {
						cout << "Anio: ";
						if (ValidarEntradaTeclado(anio)) {
							f2.setdia(dia);
							f2.setmes(mes);
							f2.setanio(anio);
							if (f2.validar()) {
								b1 = false;
							}
						}
					}
				}
			}
			for (const polizas& poliza : vectorPolizas) {
				if (f1 <= poliza.getFechaDeVenta() && poliza.getFechaDeVenta() <= f2) {   //cambio forma de comparar, operador definido en clase fecha
					//cout << poliza.toString() << endl;
					gp.mostrarpoliza(poliza.getNdePoliza());
				}
			}

		}break;
		case 5: {
			system("cls");
			gestionpolizas gp;
			cout << "Ingrese el Id del seguro: " << endl;
			cout << "--------------------------------------" << endl;
			int id;
			bool b = true, b1 = true;
			archivoseguros as;
			while (b1) {
				if (ValidarEntradaTeclado(id)) {
					if (as.validarseguro(id)) {
						b1 = false;
						for (const polizas& poliza : vectorPolizas) {
							if (poliza.getidSeguro() == id) {
								//cout << poliza.toString() << endl;
								gp.mostrarpoliza(poliza.getNdePoliza());
								cout << "--------------------------------------" << endl;
								b = false;

							}
						}
					}
					else {
						cout << "No se encontro seguro con ese ID, intente de nuevo: ";
					}
				}
			}
			if (b) {
				cout << endl;
				cout << "Aun no se relizaron ventas de ese seguro" << endl;
			}
		}break;
		case 6: {
			system("cls");
			cout << "Ingrese el legajo del vendedor:";
			cout << endl;
			int legajo;
			bool b = true, b1 = true;
			archivovendedores av;
			gestionpolizas gp;
			while (b1) {
				if (ValidarEntradaTeclado(legajo)) {
					if (av.validarvendedor(legajo)) {
						b1 = false;
						for (const polizas& poliza : vectorPolizas) {
							if (poliza.getLegajoVendedor() == legajo) {
								b = false;
								//cout << poliza.toString() << endl;
								gp.mostrarpoliza(poliza.getNdePoliza());
								cout << "--------------------------------------------" << endl;
							}
						}
					}
					else {
						cout << "No se encontro vendedor con ese legajo, intente de nuevo: ";
					}
				}
			}
			if (b) {
				cout << endl;
				cout << "Aun no hay ventas de ese vendedor" << endl;
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
}

void GestionSupervisor::SubMenuApercibimientos() {
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              APERCIBIMIENTOS                                 |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Consulta de apercibimientos por vendedor                                 |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Ingresar apercibimiento                                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			cout << "Ingrese legajo del vendedor: ";
			int legajo;
			bool b = true, b1 = true, b2 = true;
			archivovendedores av;
			while (b1) {
				if (ValidarEntradaTeclado(legajo)) {
					if (av.validarvendedor(legajo)) {
						b1 = false;
						for (const vendedores& vendedor : vectorVendedores) {
							if (vendedor.getLegajo() == legajo) {
								//b = false;
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
					else {
						cout << "No se encontro vendedor/a con ese legajo, intente de nuevo: ";
					}
				}
			}
			if (b2) {
				cout << endl;
				cout << "Vendedor/a no tiene apercibimientos" << endl << endl;;
			}

		}
			  break;
		case 2: {
			system("cls");
			cout << "Ingrese legajo del vendedor: ";
			int leg, dia, mes, anio;
			bool b = true, b1 = true, b2 = true;
			archivovendedores av;
			archivomotivos am;
			while (b1) {
				if (ValidarEntradaTeclado(leg)) {
					if (av.validarvendedor(leg)) {
						b1 = false;
						for (vendedores& vendedor : vectorVendedores) {
							if (vendedor.getLegajo() == leg) {
								apercibimientos a;
								Fecha fecha;
								while (b) {
									cout << "Ingrese la fecha" << endl;
									cout << "Dia: ";
									if (ValidarEntradaTeclado(dia)) {
										cout << "Mes: ";
										if (ValidarEntradaTeclado(mes)) {
											cout << "Anio: ";
											if (ValidarEntradaTeclado(anio)) {
												fecha.setdia(dia);
												fecha.setmes(mes);
												fecha.setanio(anio);
												if (fecha.validar()) {
													b = false;
												}
											}
										}
									}
								}
								cout << "Ingrese ID del motivo: ";
								int mot;
								while (b2) {
									if (ValidarEntradaTeclado(mot)) {
										if (am.validarmotivo(mot)) {
											b2 = false;
											a.setfecha(fecha);
											a.setlegajo(leg);
											a.setmotivo(mot);

											vectorApercibimientos.push_back(a);
											archivoapercibimientos().GuardarVectorApercibimientoEnArchivo(vectorApercibimientos);
											cout << "Apercibimiento cargado correctamente" << endl;
										}
										else {
											cout << "No se encontro motivo con ese ID, intente de nuevo: ";
										}
									}
								}

							}

						}
					}
					else {
						cout << "No se encontro vendedor/a con ese legajo, intente de nuevo: ";
					}
				}
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
}

void GestionSupervisor::SubMenuInformes() {
	while (true) { //agrego para que al terminar cada caso vuelva al submenu y no al menu supervisor
		vectorPolizas = archivopolizas().LeerArchivoAlmacenarEnVector(); //agrego esto para que se tengan en cuenta las polizas que se creen al usar el programa, sino hay que cerrar y volver a abrir
		system("cls");
		cout << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|                              INFORMES                                        |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  1. Recaudacion Anual                                                        |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  2. Comisiones por vendedor                                                  |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  3. Recaudacion y cantidad de polizas por tipo de seguro                     |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "|  0. Volver                                                                   |" << endl;
		cout << "|                                                                              |" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Ingrese una opcion: ";
		int opcion;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			system("cls");
			cout << "Ingrese el anio: ";
			int anio;
			bool b = true;
			while (b) {
				if (validarAnio(anio)) {
						b = false;
						cout << "--------------------------------" << endl;
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
						cout << string(32, '-') << endl;

						for (int i = 0; i < recaudacionMensual.size(); i++) {
							cout << left << setw(15) << Fecha().toStringMes(i + 1) << "|$" << setw(15) << recaudacionMensual[i] << endl;
						}
					
					cout << endl;

				}

			}

		}break;
		case 2: {
			system("cls");
			archivovendedores av;
			float *RecaudacionPorVendedor;
			int cant = av.contarRegistros();
			RecaudacionPorVendedor = new float[cant];
			for (int i = 0; i < cant; i++) {
				RecaudacionPorVendedor[i] = 0;
			}
			cout << "Ingrese el anio: ";
			int anio;
			bool b = true;
			while (b) {
				if (validarAnio(anio)) {
					b = false;
					int mes;
					bool mesValido = false;
					do {
						cout << "Ingrese el mes: ";
						if (validarMes(mes)) {
								
								mesValido = true;
								
						}
						else {
							cout << "Mes invalido. Por favor, ingrese un valor entre 1 y 12." << endl;
						}
					} while (!mesValido);

					system("cls");
					cout << "Los porcentajes de comisiones son:" << endl << endl;
					cout << "10% si el total recaudado es menor a $100000" << endl;
					cout << "15% si el total recaudado es mayor a $100000 y menor a $200000" << endl;
					cout << "20% si el total recaudado es mayor a $200000" << endl;
					cout << "--------------------------------------------" << endl;
					cout << " Comisiones por vendedor en " << Fecha().toStringMes(mes) << " del " << anio << endl << endl;

					for (const vendedores& vendedor : vectorVendedores) {

						float recaudacion = 0;
						for (const polizas& poliza : vectorPolizas) {
							if (vendedor.getLegajo() == poliza.getLegajoVendedor()) {
								if (poliza.getFechaDeVenta().getanio() == anio && poliza.getFechaDeVenta().getmes() == mes) {
									RecaudacionPorVendedor[vendedor.getLegajo() - 1] += poliza.getCuota();
								}
							}
						}
					}
					cout << left << setw(30) << "VENDEDOR" << "|" << setw(15) << "TOTAL" << "|" << setw(15) << "% DE COMISION" << "|" << setw(15) << "COMISION" << endl;
					cout << string(75, '-') << endl;

					int i = 0;
					for (const vendedores& vendedor : vectorVendedores) {
						cout << left << setw(15) << vendedor.getApellido() << setw(15) << vendedor.getNombre() << "|" << setw(15) << ("$" + to_string(RecaudacionPorVendedor[i])) << "|" << setw(15);
						if (RecaudacionPorVendedor[i] > 0 && RecaudacionPorVendedor[i] < 100000) {
							cout << "10%" << "|" << "$" << RecaudacionPorVendedor[i] * 0.1 << endl;
						}
						else if (RecaudacionPorVendedor[i] > 100000 && RecaudacionPorVendedor[i] < 200000) {
							cout << "15%" << "|" << "$" << RecaudacionPorVendedor[i] * 0.15 << endl;
						}
						else if (RecaudacionPorVendedor[i] > 200000) {
							cout << "20%" << "|" << "$" << RecaudacionPorVendedor[i] * 0.2 << endl;
						}
						else if (RecaudacionPorVendedor[i] == 0) {
							cout << "0%" << "|" << "$" << 0 << endl;
						}
						i++;
					}
					cout << endl;
				}
			}
			delete RecaudacionPorVendedor;

		}break;
		case 3: {
			system("cls");
			cout << "Ingrese rango de fechas: " << endl;
			Fecha f1, f2;
			int dia, mes, anio;
			bool b = true, b1 = true;
			while (b) {
				cout << "Fecha 1 " << endl;
				cout << "Dia: ";
				if (ValidarEntradaTeclado(dia)) {
					cout << "Mes: ";
					if (ValidarEntradaTeclado(mes)) {
						cout << "Anio: ";
						if (ValidarEntradaTeclado(anio)) {
							f1.setdia(dia);
							f1.setmes(mes);
							f1.setanio(anio);
							if (f1.validar()) {
								b = false;
							}
						}
					}
				}
			}
			cout << "---------------------------------" << endl;
			while (b1) {
				cout << "Fecha 2 " << endl;
				cout << "Dia: ";
				if (ValidarEntradaTeclado(dia)) {
					cout << "Mes: ";
					if (ValidarEntradaTeclado(mes)) {
						cout << "Anio: ";
						if (ValidarEntradaTeclado(anio)) {
							f2.setdia(dia);
							f2.setmes(mes);
							f2.setanio(anio);
							if (f2.validar()) {
								b1 = false;
							}
						}
					}
				}
			}
			archivoseguros archSeg;
			int * CantidadPorTipoSeguro;
			float* RecaudacionPorSeguro;
			int cant = archSeg.contarRegistros();
			CantidadPorTipoSeguro = new int[cant];
			RecaudacionPorSeguro = new float[cant];
			for (int i = 0; i < cant; i++) {
				CantidadPorTipoSeguro[i] = 0;
				RecaudacionPorSeguro[i] = 0;
			}

			cout << string(55, '-') << endl;

			for (const seguros& seguro : vectorSeguros) {
				int cont = 0;
				float recaudacion = 0;
				for (const polizas& poliza : vectorPolizas) {
					if (seguro.getidSeguro() == poliza.getidSeguro()) {

						if (f1 <= poliza.getFechaDeVenta() && poliza.getFechaDeVenta() <= f2) { //cambio la forma de comparar, operador definido en clase fecha
							CantidadPorTipoSeguro[seguro.getidSeguro() - 1] ++;
							RecaudacionPorSeguro[seguro.getidSeguro() - 1] += poliza.getCuota();
						}
					}
				}
			}
			cout << left << setw(15) << "SEGURO" << "|" << setw(15) << "CANTIDAD" << "|" << setw(15) << "RECAUDACION" << endl;
			cout << string(55, '-') << endl;

			int i = 0;
			for (const seguros& seguro : vectorSeguros) {
				cout << left << setw(15) << seguro.getnombre() << "|" << setw(15) << CantidadPorTipoSeguro[i] << "|" << setw(15) << RecaudacionPorSeguro[i] << endl;
				i++;
			}
			delete CantidadPorTipoSeguro;
			delete RecaudacionPorSeguro;
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
		//system("cls");
		std::cout << "Entrada invalida. Por favor, ingrese un tipo de dato valido: " << endl;
		return false;
	}
	return true;
}

bool GestionSupervisor::validarMes(int& mes) {
	while (!ValidarEntradaTeclado(mes) || mes < 1 || mes > 12) {
		cout << "Mes no válido. Por favor, ingrese un mes entre 1 y 12: ";
		cin >> mes;
	}
	return true;
}
bool GestionSupervisor::validarAnio(int& anio) {
	while (!ValidarEntradaTeclado(anio) || anio < 1) {
		cout << "Anio no valido. Por favor, intente de nuevo: ";
		cin >> anio;
	}
	return true;
}





