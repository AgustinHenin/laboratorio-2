#pragma once
#include "polizas.cpp"
#include "polizas.h"

class archivopolizas {
private:
    char nombre[30];
public:
    archivopolizas() {
        FILE* p = fopen("polizas.dat", "rb");
        if (p == nullptr) {
            p = fopen("polizas.dat", "wb");
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
        p = fopen("polizas.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    polizas leerRegistro(int pos) {
        polizas reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(polizas);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(polizas reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        polizas reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getNdePoliza() + 1;
        }
        else {
            return 1;
        }
    }
};

