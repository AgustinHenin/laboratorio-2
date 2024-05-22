#pragma once
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
};




