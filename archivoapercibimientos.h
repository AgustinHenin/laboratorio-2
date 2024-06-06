#pragma once
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
    
};

