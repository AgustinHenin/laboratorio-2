#pragma once
#include <vector>
#include "clientes.h"
#include "vendedores.h"
#include "seguros.h"

class GestionVectores {
public:
	static bool CompararPorApellido(const persona& a, const persona& b) { return strcmp(a.getApellido(), b.getApellido()) < 0; }
	static bool CompararPorNacimiento(const persona& a, const persona& b) { return a.getNacimiento().getanio() < b.getNacimiento().getanio(); }
	static bool CompararPorNombre(const seguros& a, const seguros& b) { return strcmp(a.getnombre(), b.getnombre()) < 0; }
	static bool CompararPorFecha(const polizas& a, const polizas& b) { return a.getFechaDeVenta().toString() < b.getFechaDeVenta().toString(); }
	static bool CompararPorLegajoVendedor(const polizas& a, const polizas& b) { return a.getLegajoVendedor() < b.getLegajoVendedor(); }
	static bool CompararPorSeguro(const polizas& a, const polizas& b) { return a.getidSeguro() < b.getidSeguro(); }

	static vendedores BuscarVendedorPorLegajo(std::vector<vendedores>& vectorVendedores, int legajo) {
		for (const vendedores& vendedor : vectorVendedores) {
			if (vendedor.getLegajo() == legajo) {
				return vendedor;
			}
		}
	}

};

