#pragma once
#include <vector>
#include <algorithm> // Para std::transform
#include <cctype>    // Para std::toupper
#include "clientes.h"
#include "vendedores.h"
#include "seguros.h"
#include "polizas.h"

class GestionVectores {
public:
	static bool CompararPorApellido(const persona& a, const persona& b) { return strcmp(a.getApellido(), b.getApellido()) < 0; }
	static bool CompararPorNacimiento(const persona& a, const persona& b) { 
		return calcularEdad(a.getNacimiento().getanio(), a.getNacimiento().getmes(), a.getNacimiento().getdia()) < calcularEdad(b.getNacimiento().getanio(), b.getNacimiento().getmes(), b.getNacimiento().getdia()); }
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
static int calcularEdad(int anioNacimiento, int mesNacimiento, int diaNacimiento) {
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


};

