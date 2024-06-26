#pragma once
#include "segurosXcliente.h"

class archivosxc
{
public:
    archivosxc() {
        FILE* p = fopen("segurosxcliente.dat", "rb");
        if (p == nullptr) {
            p = fopen("segurosxcliente.dat", "wb");
            if (p == nullptr) {
                cout << "Error al crear el archivo";
            }
            else {
                //cout << "Archivo creado exitosamente";
                fclose(p);
            }
        }
        else {
            fclose(p);
        }
    }

    FILE* AbrirArchivo(string formaApertura) {
        FILE* p;
        p = fopen("segurosxcliente.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    segurosXcliente leerRegistro(int pos) {
        segurosXcliente reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(segurosXcliente);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(segurosXcliente reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }


//AGREGO

    bool crearcopia() {
        segurosXcliente reg;
        FILE* p = AbrirArchivo("rb");
        FILE* pbak;
        pbak = fopen("segurosxcliente.bak", "wb");
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
        segurosXcliente reg;
        FILE* p = AbrirArchivo("wb");
        FILE* pbak;
        pbak = fopen("segurosxcliente.bak", "rb");
        if (p == NULL) {
            return false;
        }
        while (fread(&reg, sizeof reg, 1, pbak) == 1) {
            fwrite(&reg, sizeof reg, 1, p);
        }
        fclose(p);
        fclose(pbak);
    }

std::vector<segurosXcliente>  LeerArchivoAlmacenarEnVector() {
		std::vector<segurosXcliente> vectorSegurosXcliente;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorSegurosXcliente.push_back(leerRegistro(i));
		}
		return vectorSegurosXcliente;
	}

};

