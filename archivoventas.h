#pragma once
#include "ventas.h"

class archivoventas {
private:
    char nombre[30];
public:
    archivoventas(const char* n) {
        strcpy(nombre, n);
    }
    ventas leerRegistro(int pos) {
        ventas reg;
        FILE* p = fopen(nombre, "rb");
        if (p == NULL) {
            return reg;
        }
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = fopen(nombre, "rb");
        if (p == NULL) {
            return -1;
        }
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(ventas);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(ventas reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguienteID() {
        ventas reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getidventa() + 1;
        }
        else {
            return 1;
        }
    }
};

