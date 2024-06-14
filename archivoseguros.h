#pragma once
#include <vector>//AGREGUE ESTO
#include "seguros.h"

class archivoseguros {

public:
    archivoseguros() {
        FILE* p = fopen("seguros.dat", "rb");
        if (p == nullptr) {
            p = fopen("seguros.dat", "wb");
            if (p == nullptr) {
                std::cout << "Error al crear el archivo";
            }
            else {
                std::cout << "Archivo creado exitosamente";
                fclose(p);
            }
        }
        else {
            fclose(p);
        }
    }

    FILE* AbrirArchivo(string formaApertura) {
        FILE* p;
        p = fopen("seguros.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    seguros leerRegistro(int pos) {
        seguros reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(seguros);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(seguros reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        seguros reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getidSeguro() + 1;
        }
        else {
            return 1;
        }
    }

//AGREGUE ESTO
std::vector<seguros> LeerArchivoAlmacenarEnVector() {
		std::vector<seguros> vectorSeguros;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorSeguros.push_back(leerRegistro(i));
		}
		return vectorSeguros;
	}


//AGREGO

    bool crearcopia() {
        seguros reg;
        FILE* p = AbrirArchivo("rb");
        FILE* pbak;
        pbak = fopen("seguros.bak", "wb");
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
        seguros reg;
        FILE* p = AbrirArchivo("wb");
        FILE* pbak;
        pbak = fopen("seguros.bak", "rb");
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




