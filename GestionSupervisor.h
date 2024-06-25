#pragma once
#include <iostream>
#include <vector>
#include "GestionVectores.h"
#include "archivoclientes.h"
#include "archivoseguros.h"
#include "archivovendedores.h"
#include "archivopolizas.h"
#include "archivoapercibimientos.h"
#include "archivoestados.h"
#include "archivoexc.h"
#include "archivomotivos.h"
#include "archivosxc.h"



class GestionSupervisor {
public:
	GestionSupervisor() { CargarVectores(); }
	void menuSupervisor();

private:
	void SubMenuClientes();
	void SubMenuVendedores();
	void SubMenuSeguros();
	void SubMenuPolizas();
	void SubMenuVentas();
	void SubMenuApercibimientos();
	void SubMenuInformes();

	std::vector<clientes> vectorClientes;
	std::vector<seguros> vectorSeguros;
	std::vector<vendedores> vectorVendedores;
	std::vector<polizas> vectorPolizas;
        std::vector<apercibimientos>vectorApercibimientos;
	std::vector<estados>vectorEstados;
	std::vector<estadoXcliente>vectorEstadoXcliente;
	std::vector<motivosapercibimiento>vectorMotivosApercibimientos;
	std::vector<segurosXcliente>vectorSegurosXcliente;

	void CargarVectores();

        template<typename T>
	bool ValidarEntradaTeclado(T& datoIngresar);

	int calcularEdad(int, int, int);

};
