#pragma once
#include "estados.h"
class archivoestados
{
public:
    archivoestados() {
        FILE* p = fopen("estados.dat", "rb");
        if (p == nullptr) {
            p = fopen("estados.dat", "wb");
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
        p = fopen("estados.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    estados leerRegistro(int pos) {
        estados reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(estados);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(estados reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguiente() {
        estados reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getidEstado() + 1;
        }
        else {
            return 1;
        }
    }
};

