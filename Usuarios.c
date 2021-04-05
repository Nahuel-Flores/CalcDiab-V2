#include "Usuarios.h"

nodoPa * inicLista(nodoPa * lista){  //Inicializa la lista de Parametros
    return NULL;
}

nodoPa * crearNodo(parametros p){ //Crea un nodo de la lista de Parametros

    nodoPa * aux = (nodoPa*) malloc(sizeof(nodoPa));

    aux->param = p;

    aux->siguiente = NULL;

 return aux;
}

nodoPa * agregarAlPpio(nodoPa * lista,nodoPa * nuevoNodo){   //Agrega al principio en la lista de Parametros

    if(lista==NULL)
        lista = nuevoNodo;
    else{
        nuevoNodo->siguiente=lista;
        lista=nuevoNodo;
    }

return lista;
}

nodoPa * cargarListaParametros(char nombreArchi[],nodoPa * lista){   //Carga los parametros a una lista enlazada
    parametros p;
    nodoPa * nuevoNodo;
    FILE * archi;

    archi = fopen(nombreArchi,"rb");

    if(archi != NULL){

        while(fread(&p,sizeof(parametros),1,archi)>0){

            nuevoNodo = crearNodo(p);
            lista = agregarAlPpio(lista,nuevoNodo);

        }

        fclose(archi);

    }

return lista;
}

nodoPa * borrarLista(nodoPa * lista){   //Borra la lista de Parametros
    nodoPa * siguiente;
    nodoPa * seguidor;
    seguidor = lista;
    while(seguidor != NULL){
        siguiente = seguidor->siguiente;
        free(seguidor);
        seguidor = siguiente;
        }
    return seguidor;
}



void inicListaUsuario(nodoUsu ** lista){    //Inicializa la lista de listas de Usuarios
    (*lista)=NULL;
}

nodoUsu * crearNodoUsu(usuario usu){ //Crea un nodo Usuario

    nodoUsu * aux = (nodoUsu*) malloc(sizeof(nodoUsu));

    aux->usu = usu;

    aux->listaParametros = NULL;

    aux->siguiente = NULL;

 return aux;
}

nodoUsu * buscarUltimo(nodoUsu * listaUsu){ //Busca el ultimo usuario de la lista de Usuarios

    while(listaUsu->siguiente != NULL){

        listaUsu = listaUsu->siguiente;

    }

return listaUsu;
}

void agregarAlFinal(nodoUsu ** listaUsu,nodoUsu * nuevoNodo){   //Agrega un nodo al final a la lista de listas de Usuarios

    nodoUsu * seg = (*listaUsu);

    if(seg == NULL)
        (*listaUsu) = nuevoNodo;
    else{
        seg = buscarUltimo((*listaUsu));

        seg->siguiente = nuevoNodo;

    }
}

void cargarListaUsu(nodoUsu ** listaUsu,usuario usu){   //Agrega un usuario y su lista de parametros a la lista

    nodoUsu * aux = crearNodoUsu(usu);

    aux->listaParametros = cargarListaParametros(aux->usu.usuario,aux->listaParametros);

    agregarAlFinal(listaUsu,aux);
}

nodoUsu * buscarUsuarioLista(nodoUsu * listaUsu,char nombre[]){ //Buscar usuario en la Lista de Usuarios

    nodoUsu * seg;
    seg = NULL;

    while(listaUsu != NULL){
        if(strcmpi(listaUsu->usu.usuario,nombre)==0)
            seg = listaUsu;

            listaUsu = listaUsu->siguiente;
    }
return seg;
}

int cantUsuarios(nodoUsu * listaUsu){   //Devuelve la cantidad de Usuarios que hay
    int cant = 0;

    while(listaUsu != NULL){

        listaUsu=listaUsu->siguiente;

        cant++;
    }
return cant;
}

