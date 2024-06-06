#pragma once
#include <iostream>
#include "GestionVectores.h"
#include "archivoclientes.h"
#include "archivoseguros.h"
#include "archivovendedores.h"
#include "archivopolizas.h"
#include "seguros.h"
#include "polizas.h"


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
	void CargarVectores();


};
