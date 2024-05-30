#pragma once
#include "estadoXcliente.h"
class archivoexc
{
public:
    archivoexc() {
        FILE* p = fopen("estadoxcliente.dat", "rb");
        if (p == nullptr) {
            p = fopen("estadoxcliente.dat", "wb");
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
        p = fopen("estadoxcliente.dat", formaApertura.c_str());
        if (p == nullptr) { exit(-1); }
        else {
            return p;
        }
    }

    estadoXcliente leerRegistro(int pos) {
        estadoXcliente reg;
        FILE* p = AbrirArchivo("rb");
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p = AbrirArchivo("rb");
        fseek(p, 0, 2);
        int cant = ftell(p) / sizeof(estadoXcliente);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(estadoXcliente reg) {
        FILE* p = AbrirArchivo("ab");
        int escribio = fwrite(&reg, sizeof reg, 1, p);
        fclose(p);
        return escribio;
    }
    bool sobreescribir(estadoXcliente obj, int pos) {
        FILE* p = AbrirArchivo("rb+");
        fseek(p, sizeof obj * pos, 0);
        bool escribio = fwrite(&obj, sizeof obj, 1, p);
        fclose(p);
        return escribio;
    }
};

