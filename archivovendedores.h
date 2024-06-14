#pragma once
#include <vector>//AGREGUE ESTO
#include "vendedores.h"

class archivovendedores
{

public:
    archivovendedores() {
        FILE* p = fopen("vendedores.dat", "rb");
        if (p == nullptr) {
            p = fopen("vendedores.dat", "wb");
            if (p == nullptr) {
                cout << "Error al crear el archivo";
            }
            else {
                cout << "Archivo creado exitosamente";
                fclose(p);
            }
        }
        else {
            fclose(p);
        }
    }

    FILE* AbrirArchivo(string formaApertura) {
        FILE* p;
        p = fopen("vendedores.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    vendedores leerRegistro(int pos) {
        vendedores reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(vendedores);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(vendedores reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        vendedores reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getLegajo() + 1;
        }
        else {
            return 1;
        }
    }
//AGREGUE ESTO
std::vector<vendedores> LeerArchivoAlmacenarEnVector() {
		std::vector<vendedores> vectorVendedores;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorVendedores.push_back(leerRegistro(i));
		}
		return vectorVendedores;
	}


//AGREGO

    bool crearcopia() {
        vendedores reg;
        FILE* p = AbrirArchivo("rb");
        FILE* pbak;
        pbak = fopen("vendedores.bak", "wb");
        if (p == NULL) {
            return false;
        }
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            fwrite(&reg, sizeof reg, 1, pbak);
        }
        fclose(p);
        fclose(pbak);
    }

    bool restaurarcopia() {
        vendedores reg;
        FILE* p = AbrirArchivo("wb");
        FILE* pbak;
        pbak = fopen("vendedores.bak", "rb");
        if (p == NULL) {
            return false;
        }
        while (fread(&reg, sizeof reg, 1, pbak) == 1) {
            fwrite(&reg, sizeof reg, 1, p);
        }
        fclose(p);
        fclose(pbak);
    }

};

