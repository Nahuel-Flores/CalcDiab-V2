#include "CalcDiab.h"


int main()
{
    system("COLOR 61");

    nodoUsu * listaUsu;
    nodoAli * listaAli;
    cargarAmemoria(&listaUsu,&listaAli);

    menu(listaUsu,listaAli);

    return 0;
}

