#ifndef ALIMENTOS_H_INCLUDED
#define ALIMENTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char alimento[50];
    float porcion;
    float HDC;      //Cant de HDC
}alimentos;

typedef struct
{
    alimentos alim;
    struct nodoAli * siguiente;
}nodoAli;

void inicListaAlim (nodoAli ** lista);
nodoAli * crearNodoAlim(alimentos alim);
nodoAli * buscarUltimoAli(nodoAli * lista);
void agregarAlFinalAlimentos(nodoAli ** lista,nodoAli * nuevoNodo);
void cargarListaAlimentos(char nombreArchi[],nodoAli ** lista);
void mostrarAlimentos(nodoAli * listaAli);

alimentos buscarAlimento(nodoAli * lista,int pos);
void crearYagregarAlim(nodoAli ** listaAli,alimentos alim);
void eliminarAlim(nodoAli ** listaAli,int pos);
void pasarAlArchiLista(char nombreArchi[],nodoAli * lista);


#endif // ALIMENTOS_H_INCLUDED
