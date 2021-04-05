#ifndef CALCDIAB_H_INCLUDED
#define CALCDIAB_H_INCLUDED

#include "pila.h"
#include <time.h>
#include "Usuarios.h"
#include "Alimentos.h"


typedef struct
{
    alimentos comida;
    char fechaYhora [30];
}dieta;

typedef struct
{
    int medicion;
    char fechaYhora [30];
}mediciones;

void imprimirCabecera(char cabecera[]);
void opciones();
void opciones2();
void menu(nodoUsu * listaUsu,nodoAli * listaAli);
void menuDiabe(nodoUsu * usuar,nodoUsu ** listaUsu,nodoAli ** listaAli);
void menu_inicio_de_sesion();

void cargarAmemoria(nodoUsu ** listaUsu,nodoAli ** listaAli);
alimentos cargarAlimentos(char nombreArchi[]);
void cargarParametros(char nombreArchi[]);
void cargarArchiUsuarios(usuario usu,char nombreArchi[]);

usuario registrarse(nodoUsu ** listaUsu);
nodoUsu * ingreso(nodoUsu ** listaUsu);

void ocultarContrasenia(char contra[21]);

void fechaYahora(char fechaYhora[]);
void cargarArchiDieta(char nombreArchi[],alimentos alim);
void cargarArchiHistMediciones(char nombreArchi[],int medi);
void mostrarDieta(char nombreArchi[]);
void mostrarHistMediciones(char nombreArchi[]);
void borrarHistorial(char nombreArchi[]);

void leerArchiYpasarList(nodoUsu ** listaUsu,char nombreArchi[]);

int calculoMedicion(nodoPa * lista,int medicion);
int alimentosIngeridos(nodoAli * listaAli,char usu[],int contHdc);
int sumaHidratos(char nombreArchi[],Pila posiciones);
int buscarUsuario(char nombreArchi[], char nombreU[]);
int calcHidratos(nodoAli * listaAli ,char usu[],Pila posiciones,int contHdc);


void bye();


#endif // CALCDIAB_H_INCLUDED
