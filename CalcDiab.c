#include "CalcDiab.h"


void menu(nodoUsu * listaUsu,nodoAli * listaAli){        //Menu Principal
    char num;
    int error = 0;
    usuario nuevo;

    nodoUsu * usuar;

    imprimirCabecera("CalcDiab");
    opciones();
    printf("\n\n\n\t\t\t ");

    do{
        fflush(stdin);
        num = getch();

        switch (num){
            case 49:
                usuar = ingreso(&listaUsu);
                printf("\n\t%i",usuar->usu.anioNaci);
                menuDiabe(usuar,&listaUsu,&listaAli);

                break;

            case 50:
                nuevo = registrarse(&listaUsu);
                cargarArchiUsuarios(nuevo,"ListaDeUsuarios");
                cargarParametros(nuevo.usuario);
                cargarListaUsu(&listaUsu,nuevo);
                usuar = buscarUsuarioLista(listaUsu,nuevo.usuario);
                menuDiabe(usuar,&listaUsu,&listaAli);

                break;

            case 27:
                system("cls");
                bye();
                break;

            default:
                printf("\nNo es una opcion valida.Continuar...\n");

                error = 1;
                break;
            }
        }
    while(error==1);
    }

void menuDiabe(nodoUsu * usuar,nodoUsu ** listaUsu,nodoAli ** listaAli){    //Segundo menu
    char num;
    int medi,inyec;
    int error = 0;
    alimentos alim;


    do{
        system("cls");
        imprimirCabecera(usuar->usu.usuario);
        opciones2();
        printf("\n\n\n\t\t\t ");
        fflush(stdin);
        num = getch();

            switch(num){
        case 49:
            system("cls");
            imprimirCabecera(usuar->usu.usuario);
            printf("\nIngrese su valor de glucosa en sangre: ");
            scanf("%i",&medi);
            cargarArchiHistMediciones(usuar->usu.usuario,medi);
            inyec = calculoMedicion(usuar->listaParametros,medi);

            printf("\n\n\tDebe inyectarse: %i u\n\n",inyec);

            break;
        case 50:
            system("cls");
            imprimirCabecera(usuar->usu.usuario);
            inyec = alimentosIngeridos((*listaAli),usuar->usu.usuario,usuar->usu.contHDC);
            system("cls");
            printf("\n\n\tDebe inyectarse: %i u\n\n",inyec);
            break;
        case 51:
            system("cls");
            imprimirCabecera(usuar->usu.usuario);
            printf("\nIngrese su valor de glucosa en sangre: ");
            scanf("%i",&medi);

            cargarArchiHistMediciones(usuar->usu.usuario,medi);
            inyec = calculoMedicion(usuar->listaParametros,medi);

            inyec = inyec + alimentosIngeridos((*listaAli),usuar->usu.usuario,usuar->usu.contHDC);

            printf("\n\n\tDebe inyectarse: %i u\n\n",inyec);
            break;
        case 52:
            system("cls");
            imprimirCabecera("Historial de Mediciones");
            printf("\n\n");
            mostrarHistMediciones(usuar->usu.usuario);
            break;
        case 53:
            system("cls");
            imprimirCabecera("Dieta");
            mostrarDieta(usuar->usu.usuario);
            break;
        case 54:
            remove(usuar->usu.usuario);
            system("cls");
            usuar->listaParametros = borrarLista(usuar->listaParametros);
            imprimirCabecera("Cargar Parametros");
            printf("\n\n");
            cargarParametros(usuar->usu.usuario);
            usuar->listaParametros = inicLista(usuar->listaParametros);
            cargarListaParametros(usuar->usu.usuario,usuar->listaParametros);
            break;
        case 55:
            system("cls");
            borrarHistorial(usuar->usu.usuario);
            break;
        case 56:
            system("cls");
            mostrarAlimentos((*listaAli));
            alim = cargarAlimentos("ListaDeAlimentos");
            crearYagregarAlim(listaAli,alim);
            break;
        case 57:
            system("cls");
            int elim;
            mostrarAlimentos((*listaAli));
            printf("\n\nIngresa numero de Alimento a borrar: ");
            scanf("%i",&elim);
            eliminarAlim(listaAli,elim);
            remove("ListaDeAlimentos");
            pasarAlArchiLista("ListaDeAlimentos",(*listaAli));
            break;
        case 48:
            system("cls");
            menu((*listaUsu),(*listaAli));
            break;
        case 27:
            bye();
            break;
        default:
            printf("\nNo es una opcion valida.Continuar...\n");
            system("pause");
            break;
        }
            if(num != 27){
                printf("\n\n\t");
                system("pause");
                }

        }while(num != 27);
}

void imprimirCabecera(char cabecera[]){   //Imprime la cabecera dentro de un recuadro
    int i;
    printf("%c", 201);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c\n", 187);
    printf("%c%32s%19c\n", 186,cabecera,186);
    printf("%c", 200);
    for(i=0;i<50;i++){
        printf("%c",205);
    }
    printf("%c", 188);
}

void opciones(){    //Muestra las opciones del menu 1
    printf("\n\n\t");
    for(int i=0;i<33;i++){
        printf("%c", 219);
    }
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c\t(1) Iniciar sesion\t%c",219 , 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c\t  (2) Registrarse\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c\t    (ESC) Salir\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\n\t", 219, 219);
    for(int i=0;i<33;i++){
        printf("%c", 219);
    }
}

void opciones2(){   //Muestra las opciones del menu 2
    printf("\n\n\t");
    for(int i=0;i<33;i++){
        printf("%c", 219);
    }
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (1) Medida a inyectarse\t%c",219 , 219);
    printf("\n\t%c     segun glucosa en sangre\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (2) Medida a inyectarse\t%c", 219, 219);
    printf("\n\t%c     segun ingesta\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (3) Calcular ambos\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\t", 219, 219);
    printf("\n\t%c   (4) Mostrar historial \t%c", 219, 219);
    printf("\n\t%c      mediciones\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\t", 219, 219);
    printf("\n\t%c   (5) Mostrar dieta\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (6) Modificar parametros \t%c", 219, 219);
    printf("\n\t%c     de medicion\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\t", 219, 219);
    printf("\n\t%c   (7) Borrar Historiales\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\t", 219, 219);
    printf("\n\t%c   (8) Ingresar alimento\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (9) Borrar alimento\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c   (0) Cambiar de usuario\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c", 219, 219);
    printf("\n\t%c\t    (ESC) Salir\t\t%c", 219, 219);
    printf("\n\t%c\t\t\t\t%c\n\t", 219, 219);
    for(int i=0;i<33;i++){
        printf("%c", 219);
    }
}

void cargarAmemoria(nodoUsu ** listaUsu,nodoAli ** listaAli){   //Carga a memoria la Lista de listas de Usuarios y la Lista de alimentos

    inicListaUsuario(listaUsu);
    inicListaAlim(listaAli);

    leerArchiYpasarList(listaUsu,"ListaDeUsuarios");
    cargarListaAlimentos("ListaDeAlimentos",listaAli);
}

usuario registrarse(nodoUsu ** listaUsu){   //Registrarse

    int id;
    int cmp = 0;
    nodoUsu * busca;
    char verif[21];
    usuario u;


        id = cantUsuarios(*listaUsu) + 1;

        u.legajo = id;

        do{
            system("cls");
            imprimirCabecera("Registro");

            printf("\n\n\t\tUsuario: ");
            fflush(stdin);
            gets(u.usuario);
            u.usuario[0] = toupper(u.usuario[0]);

            busca = buscarUsuarioLista((*listaUsu),u.usuario);

            if(busca != NULL){
                printf("\n\n\tEl usuario ya existe. Vuelva a ingresar\n\n\t");
                system("pause");
                }
        }
        while(busca != NULL );

        do{
            system("cls");
            imprimirCabecera("Registro");

                    if(cmp != 0)
                printf("\n\n\tLas contasenias no coinciden. Vuelva a ingresar");

            printf("\n\n\t%c%c\t\t\t       %c%c", 219, 219, 219, 219);
            printf("\n\t%c\t\t\t\t%c\n\t", 219, 219);

            printf("\n\t\tUsuario: %s\n", u.usuario);

            printf("\n\t   Contrasenia:");
            ocultarContrasenia(u.contrasenia);
            printf("\n\t   Repita la contrasena:");
            fflush(stdin);
            ocultarContrasenia(verif);
            printf("\n\t%c\t\t\t\t%c\n", 219, 219);
            printf("\t%c%c\t\t\t       %c%c", 219, 219, 219, 219);


            cmp = strcmp(u.contrasenia,verif);
        }
        while(cmp != 0);

        printf("\n\n\tIngresar anio de nacimiento: ");
        fflush(stdin);
        scanf("%i",&u.anioNaci);


        printf("\n\tIngresar genero(m/f): ");
        fflush(stdin);
        scanf("%c",&u.genero);

        while(u.genero != 'm' && u.genero != 'f'){
            printf("\n\tGenero incorrecto. Vuelve a ingresar genero: ");
            fflush(stdin);
            scanf("%c",&u.genero);
            }

        printf("\n\tIngrese cant de Hidratos de carbono\n\tpor los que se inyecta 1 u de insulina: ");
        scanf("%i",&u.contHDC);



        system("cls");



return u;
}

nodoUsu * ingreso(nodoUsu ** listaUsu){       //Inicio de sesion

    usuario u;
    nodoUsu * usufin;
    int ing = -1;

    while(ing != 2){

        system("cls");
        imprimirCabecera("Inicio de sesion");
        if(ing != -1)
            printf("\n\tUsusuario/Contraseña incorrectos\n");

            printf("\n\t%c%c\t\t\t       %c%c", 219, 219, 219, 219);
            printf("\n\t%c\t\t\t\t%c\n\t", 219, 219);
            printf("\n\t\tUsuario: ");
            fflush(stdin);
            scanf("%s", &u.usuario);
            printf("\n\t\tContrasena: ");
            fflush(stdin);
            ocultarContrasenia(u.contrasenia);
            printf("\n\t%c\t\t\t\t%c\n", 219, 219);
            printf("\t%c%c\t\t\t       %c%c", 219, 219, 219, 219);

        ing = validacion((*listaUsu),u);
    }

    usufin = buscarUsuarioLista((*listaUsu),u.usuario);

return usufin;
}

void ocultarContrasenia(char contra[21]){   //Oculta los caracteres de la contraseña
    int i=0;

    do{
        fflush(stdin);
        contra[i]=getch();

        if(contra[i]>32 && i<21) {
             putchar('*');
             i++;
        }

        else
      if(contra[i]== 8 && i>0){
               putchar(8);
               putchar(' ');
               putchar(8);
               i--;
            }
    }
    while(contra[i]!=13);
    contra[i]='\0';

}

int validacion(nodoUsu * listaUsu,usuario u){      //Valida el usuario y la contraseña

    int flag = 0;

        while(listaUsu != NULL && flag == 0){

            if(strcmpi(u.usuario,listaUsu->usu.usuario) == 0)
                flag = 1;   //Usuario validado
            else{
                listaUsu = listaUsu->siguiente;
                    }

        }

        if (flag == 1){

            if(strcmpi(u.contrasenia,listaUsu->usu.contrasenia) == 0)
                flag = 2;   //Usuario y contraseña validados
                        }

return flag;    //Valores posibles 0(no existe el usuari),1(contraseña incorrecta) y 2(Ingreso con exito)
}

alimentos cargarAlimentos(char nombreArchi[]){      //Carga ARCHIVO de estura Alimentos

    FILE*archi;

    char salida;
    alimentos a;

    archi = fopen(nombreArchi,"ab");

    puts("\n--------------\n");

    if(archi != NULL){
        do{
            printf("Ingresar Alimento: ");
            fflush(stdin);
            gets(&a.alimento);

            a.alimento [0] = toupper (a.alimento [0]);

            printf("\nIngresar cant de la porcion: ");
            fflush(stdin);
            scanf("%f",&a.porcion);

            printf("\nIngresar hidratos de carbono que posee: ");
            scanf("%f",&a.HDC);

            printf("\n\tPresiona ESC si deseas dejar de cargar alimentos");
            salida = getch();

            fwrite(&a,sizeof(alimentos),1,archi);

            system("cls");
        }
        while(salida != 27);

        fclose(archi);
    }

 return a;
 }

void cargarParametros(char nombreArchi[]){     //Carga ARCHIVO de estura Parametros

    FILE*archi;

    char salida;
    int i = 1;
    parametros p;

    archi = fopen(nombreArchi,"ab");

    if(archi != NULL){

        do{
            printf("Ingresar valor a partir del que se inyecta %i u de insulina : ",i);
            scanf("%i",&p.medicion);

            p.dosis = i;

            i++;
            printf("\n\tPresione ESC si desea dejar de cargar parametros");
            salida = getch();

            fwrite(&p,sizeof(parametros),1,archi);

            system("cls");
        }
        while(salida != 27);

        fclose(archi);
    }
 }

int calculoMedicion(nodoPa * lista,int medicion){   //Calcula la cantidad de dosis que se deben aplicar segun el azucar en sangre

    int dosis = 0;


    while(lista != NULL  && dosis == 0){
        if(lista->param.medicion < medicion)
            dosis=lista->param.dosis;

        lista=lista->siguiente;
        }


return dosis;
 }

int alimentosIngeridos(nodoAli * listaAli,char usu[],int contHdc){  //Muestra los alimentos pide que se ingrese cuales comio y calcula en base a eso
    Pila a1;
    inicpila(&a1);

    int inyec;
    char salida;

    int ali;

    do{
        system("cls");

        mostrarAlimentos(listaAli);

        printf("\n\n\nIngrese el numero correspondiente al alimento  que consumio: ");
        scanf("%i", &ali);
        apilar(&a1,ali);

        printf("\n\tPresione ESC si desea dejar de cargar alimentos");
        salida = getch();
    }
    while(salida != 27);

    inyec = calcHidratos(listaAli,usu,a1,contHdc);

 return inyec;
}

int calcHidratos(nodoAli * listaAli ,char usu[],Pila posiciones,int contHdc){   //Calcula la cantidad de ml de insulina que hay que inyectarse segun lo que comio

    int hdc = 0;
    int posAl,inyec;

    alimentos ali;


        while(!pilavacia(&posiciones)){

            posAl = tope(&posiciones);
            desapilar(&posiciones);

            ali = buscarAlimento(listaAli,posAl);

            cargarArchiDieta(usu,ali);

            hdc = ali.HDC + hdc;
        }

    inyec = hdc/contHdc;

return inyec;
}

void fechaYahora(char fechaYhora[]){    //Convierte la fecha y hora actual al string
    time_t t;
    struct tm *tm;


      t=time(NULL);
      tm=localtime(&t);
      strftime(fechaYhora ,30, "%d/%m/%Y  %H:%M", tm);
}
void cargarArchiUsuarios(usuario usu,char nombreArchi[]){

    FILE * archi;

    archi = fopen(nombreArchi,"ab");

    if(archi != NULL){

        fwrite(&usu,sizeof(usuario),1,archi);

        fclose(archi);
    }

}

void cargarArchiDieta(char nombreArchi[],alimentos alim){   //Carga un Archivo con lo que come el usuario con fecha y hora(cada usuario tiene su archivo)
    char direccion [50];

    strcpy(direccion,nombreArchi);

    strcat(direccion," Dieta");

    dieta die;

    fechaYahora(die.fechaYhora);

    die.comida = alim;

    FILE * archi;

    archi = fopen(direccion,"ab");

    if(archi != NULL){

        fwrite(&die,sizeof(dieta),1,archi);

        fclose(archi);
    }

}

void cargarArchiHistMediciones(char nombreArchi[],int medi){    //Carga un Archivo con las mediciones del usuario con fecha y hora(cada usuario tiene su archivo)

    char direccion [50];
    strcpy(direccion,nombreArchi);

    strcat(direccion," Historial Mediciones");

    mediciones histMedi;

    fechaYahora(histMedi.fechaYhora);

    histMedi.medicion = medi;

    FILE * archi;

    archi = fopen(direccion,"ab");

    if(archi != NULL){

        fwrite(&histMedi,sizeof(mediciones),1,archi);

        fclose(archi);
    }

}

void mostrarDieta(char nombreArchi[]){  //Muestra Archivo de la dieta de un usuario

    char comparaFyH[30];

    char direccion [50];

    strcpy(direccion,nombreArchi);

    strcat(direccion," Dieta");

    dieta die;

    FILE * archi;

    archi = fopen(direccion,"rb");

    if(archi != NULL){

        while(fread(&die,sizeof(dieta),1,archi)>0){
            if(strcmp(die.fechaYhora,comparaFyH) != 0){
                puts("\n \t ---------------------------------------\n");
                printf ("\nFecha y Hora: %s\n", die.fechaYhora);

            }
            printf("\n     > %s\t  %.1f g/ml/u\n", die.comida.alimento,die.comida.porcion );


            strcpy(comparaFyH,die.fechaYhora);
        }

        fclose(archi);
    }

}

void mostrarHistMediciones(char nombreArchi[]){ //Muestra Archivo del historial de mediciones de un usuario

    char direccion [50];
    strcpy(direccion,nombreArchi);

    strcat(direccion," Historial Mediciones");

    mediciones histMedi;

    FILE * archi;

    archi = fopen(direccion,"rb");

    if(archi != NULL){

        while(fread(&histMedi,sizeof(mediciones),1,archi)>0){

            printf ("Fecha y Hora: %s\n", histMedi.fechaYhora);

            printf("\n     > Valor de Glucosa en Sangre: %i",histMedi.medicion);

            puts("\n \t ---------------------------------------\n");

        }

        fclose(archi);
    }

}

void leerArchiYpasarList(nodoUsu ** listaUsu,char nombreArchi[]){   //Lee el archivo de usuarios y los copia a una lista de listas

    FILE * archi;

    usuario usu;

    archi = fopen(nombreArchi,"rb");

    if(archi != NULL){

        while(fread(&usu,sizeof(usuario),1,archi)>0){

            cargarListaUsu(listaUsu,usu);


        }

    fclose(archi);
    }
}

void borrarHistorial(char nombreArchi[]){   //Borra los archivos donde se guarda el historial de Dieta y Mediciones de una persona

    char direccionDieta [50];
    char direccionHistM [50];
    strcpy(direccionHistM,nombreArchi);
    strcpy(direccionDieta,nombreArchi);

    strcat(direccionHistM," Historial Mediciones");
    strcat(direccionDieta," Dieta");

    remove(direccionDieta);
    remove(direccionHistM);
}

void bye(){     //Muestra el mensaje de salida
    system("cls");
    printf("\n\n\n%c%c%c%c%c%c%c%c\t%c%c%c%c\t    \t%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c%c%c%c%c\t%c%c%c%c\t    \t%c%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t%c%c%c%c\t    %c%c%c%c    %c%c%c%c\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t%c%c%c%c\t    %c%c%c%c    %c%c%c%c\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c%c%c%c\t\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c%c%c%c\t\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t    %c%c%c%c\t%c%c%c%c\t\t%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t    %c%c%c%c\t%c%c%c%c\t\t%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t    %c%c%c%c\t%c%c%c%c\t\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c\t    %c%c%c%c\t%c%c%c%c\t\t%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c%c%c%c\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c\t\t%c%c%c%c\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
    printf("\n\n\n");
}
