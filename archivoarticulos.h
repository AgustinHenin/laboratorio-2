#pragma once
#include "articulos.h"

class archivoarticulos {
private:
    char nombre[30];
public:
    archivoarticulos(const char* n) {
        strcpy(nombre, n);
    }
    articulos leerRegistro(int pos) {
        articulos reg;
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
        int cant = ftell(p) / sizeof(articulos);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(articulos reg) {
        FILE* p;
        p = fopen(nombre, "ab");
        if (p == NULL) return false;
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    int siguienteID() {
        articulos reg;
        int cant = contarRegistros();
        if (cant > 0) {
            reg = leerRegistro(cant - 1);
            return reg.getid() + 1;
        }
        else {
            return 1;
        }
    }
};




