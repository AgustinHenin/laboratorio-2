#pragma once
#include "clientes.h"
//AGREGUE ESTO
#include <vector> 

class archivoclientes
{

public:
    archivoclientes() {
        FILE* p = fopen("clientes.dat", "rb");
        if (p == nullptr) {
            p = fopen("clientes.dat", "wb");
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
        p = fopen("clientes.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    clientes leerRegistro(int pos) {
        clientes reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(clientes);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(clientes reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        clientes reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getidCliente() + 1;
        }
        else {
            return 1;
        }
    }

    bool sobreescribir(clientes obj, int pos) {
        FILE* p = AbrirArchivo("rb+");
        fseek(p, sizeof obj * pos, 0);
        bool escribio = fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return escribio;
    }
//AGREGUE ESTO
	std::vector<clientes> LeerArchivoAlmacenarEnVector() {
		std::vector<clientes> vectorClientes;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorClientes.push_back(leerRegistro(i));
		}
		return vectorClientes;
	}


//AGREGO

    bool crearcopia() {
        clientes reg;
        FILE* p = AbrirArchivo("rb");
        FILE* pbak;
        pbak = fopen("clientes.bak", "wb");
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
        clientes reg;
        FILE* p = AbrirArchivo("wb");
        FILE* pbak;
        pbak = fopen("clientes.bak", "rb");
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
