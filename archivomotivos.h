#pragma once
#include "motivosapercibimiento.h"

class archivomotivos {

public:
    archivomotivos() {
        FILE* p = fopen("motivos.dat", "rb");
        if (p == nullptr) {
            p = fopen("motivos.dat", "wb");
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
        p = fopen("motivos.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    motivosapercibimiento leerRegistro(int pos) {
        motivosapercibimiento reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(motivosapercibimiento);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(motivosapercibimiento reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        motivosapercibimiento reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getidMotivo() + 1;
        }
        else {
            return 1;
        }
    }

std::vector<motivosapercibimiento> LeerArchivoAlmacenarEnVector() {
		std::vector<motivosapercibimiento> vectorMotivosApercibimientos;
		int cant = contarRegistros();
		for (int i = 0; i < cant; i++) {
			vectorMotivosApercibimientos.push_back(leerRegistro(i));
		}
		return vectorMotivosApercibimientos;
	}
};

