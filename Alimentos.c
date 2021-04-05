#include "Alimentos.h"

void inicListaAlim (nodoAli ** lista){
    (*lista)= NULL;
}

nodoAli * crearNodoAlim(alimentos alim){

    nodoAli * aux = (nodoAli*) malloc(sizeof(nodoAli));

    aux->alim = alim;

    aux->siguiente = NULL;

 return aux;
}

void agregarAlFinalAlimentos(nodoAli ** lista,nodoAli * nuevoNodo){
    nodoAli * ultimo;

    if((*lista)==NULL)
        (*lista)=nuevoNodo;

    else{
        ultimo = buscarUltimoAli((*lista));

        ultimo->siguiente = nuevoNodo;
    }
}


nodoAli * buscarUltimoAli(nodoAli * lista){
    nodoAli * seg = lista;

    while(seg->siguiente != NULL){

        seg = seg->siguiente;
    }
return seg;
}

void cargarListaAlimentos(char nombreArchi[],nodoAli ** lista){   //Carga los parametros a una lista enlazada
    alimentos ali;
    nodoAli * nuevoNodo;
    FILE * archi;

    archi = fopen(nombreArchi,"rb");

    if(archi != NULL){

        while(fread(&ali,sizeof(alimentos),1,archi)>0){

            crearYagregarAlim(lista,ali);

        }

        fclose(archi);

    }

}

alimentos buscarAlimento(nodoAli * lista,int pos){

    int i = 1;

    while(lista != NULL && i != pos){

        lista=lista->siguiente;
        i++;

    }
return lista->alim;
}

void mostrarAlimentos(nodoAli * listaAli){  //Muestra la lista de los alimentos
    int i = 1;


        imprimirCabecera("Lista de alimentos");
        printf("\n\n");
        while(listaAli != NULL){

            printf("\n %i) %s\t  %.1f g/ml/u", i, listaAli->alim.alimento, listaAli->alim.porcion);
            i++;

            listaAli = listaAli->siguiente;
        }


}

void crearYagregarAlim(nodoAli ** listaAli,alimentos alim){
    nodoAli * nuevoNodo;

    nuevoNodo = crearNodoAlim(alim);

    agregarAlFinalAlimentos(listaAli,nuevoNodo);
}

void eliminarAlim(nodoAli ** listaAli,int pos){
    int i=1;
    nodoAli * ante;
    nodoAli * seg;

    if((*listaAli)!= NULL && i == pos){
        nodoAli * aux = (*listaAli);
        (*listaAli) = (*listaAli)->siguiente;
    }
    else{
        seg=(*listaAli);

        while((seg != NULL)&& i!=pos){
            ante = seg;
            seg = seg->siguiente;
            i++;
            }
        if(seg!=NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
            }
        }
    }

void pasarAlArchiLista(char nombreArchi[],nodoAli * lista){
    FILE * archi;
    alimentos ali;

    archi = fopen(nombreArchi,"ab");

    if(archi != NULL){

        while(lista != NULL){

            ali=lista->alim;

            fwrite(&ali,sizeof(alimentos),1,archi);

            lista=lista->siguiente;

        }

        fclose(archi);

    }
}



