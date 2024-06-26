#pragma once
#include <vector>
#include "apercibimientos.h"

class archivoapercibimientos {

public:
    archivoapercibimientos() {
        FILE* p = fopen("apercibimientos.dat", "rb");
        if (p == nullptr) {
            p = fopen("apercibimientos.dat", "wb");
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
        p = fopen("apercibimientos.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    apercibimientos leerRegistro(int pos) {
        apercibimientos reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(apercibimientos);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(apercibimientos reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }

std::vector<apercibimientos> LeerArchivoAlmacenarEnVector() {
		std::vector<apercibimientos> vectorApercibimientos;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorApercibimientos.push_back(leerRegistro(i));
		}
		return vectorApercibimientos;
	}

	void GuardarVectorApercibimientoEnArchivo(const std::vector<apercibimientos>& vectorApercibimientos) {
		FILE* p = AbrirArchivo("wb");
		for (const apercibimientos& apercibimiento : vectorApercibimientos) {
			fwrite(&apercibimiento, sizeof apercibimiento, 1, p);
		}
		fclose(p);
	}

    //AGREGO

    bool crearcopia() {
        apercibimientos reg;
        FILE* p = AbrirArchivo("rb");
        FILE* pbak;
        pbak = fopen("apercibimientos.bak", "wb");
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
        apercibimientos reg;
        FILE* p = AbrirArchivo("wb");
        FILE* pbak;
        pbak = fopen("apercibimientos.bak", "rb");
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

