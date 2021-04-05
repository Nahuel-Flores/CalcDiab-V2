#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char usuario[30];
    char contrasenia[21];
    int anioNaci;
    char genero;        //m o f
    int contHDC;        //Contador de hidratos de carbono
}usuario;

typedef struct
{
    int medicion;       //Parametro de medicion
    int dosis;          //Parametro de cant de u de insulina
}parametros;

typedef struct{
    parametros param;
    struct nodoPa * siguiente;
}nodoPa;

typedef struct{
    usuario usu;
    nodoPa * listaParametros;
    struct nodoUsu * siguiente;
}nodoUsu;


nodoPa * inicLista(nodoPa * lista);
nodoPa * crearNodo(parametros p);
nodoPa * agregarAlPpio(nodoPa * lista,nodoPa * nuevoNodo);
nodoPa * cargarListaParametros(char nombreArchi[],nodoPa * lista);
nodoPa * borrarLista(nodoPa * lista);


void inicListaUsuario(nodoUsu ** lista);
nodoUsu * crearNodoUsu(usuario usu);
nodoUsu * buscarUltimo(nodoUsu * listaUsu);
void agregarAlFinal(nodoUsu ** listaUsu,nodoUsu * nuevoNodo);
void cargarListaUsu(nodoUsu ** listaUsu,usuario usu);
nodoUsu * buscarUsuarioLista(nodoUsu * listaUsu,char nombre[]);
int cantUsuarios(nodoUsu * listaUsu);


#endif // USUARIOS_H_INCLUDED
