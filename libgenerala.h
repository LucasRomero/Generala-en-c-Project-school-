#ifndef LIBGENERALA_H_INCLUDED
#define LIBGENERALA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
int manipulardados(int *vec_dados)
{
    /// MANIPULAR DADOS DE FORMA MANUAL PARA PROBAR LOS JUEGOS
    cout<< "1 dado ";
    cin>>vec_dados[0];
    cout<< "2 dado ";
    cin>>vec_dados[1];
    cout<< "3 dado ";
    cin>>vec_dados[2];
    cout<< "4 dado ";
    cin>>vec_dados[3];
    cout<< "5 dado ";
    cin>>vec_dados[4];

}

void gotoxy (int x, int y)///PARA LAS POSICIONES DE LOS DADOS
{

    COORD coord = {0,0}; // ESTA ES LA VARIABLE GLOBAL DONDE INICIO LAS COORDENADAS X, Y.
    // EL CENTRO DEL EJE SE UBICA EN LA ESQUINA SUPERIOR IZQUIERDA DE LA PANTALLA
    coord.X = x; //DEFINO LAS VARIABLES PARA LAS COORDENADAS X
    coord.Y = y; //DEFINO LAS VARIABLES PARA LAS COORDENADAS Y
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord); //DETALLO LA POSICION DEL CURSOR
}

void textcolor(short colorTexto=15, short colorFondo=0)
{
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
    /*cNEGRO=0,
    cAZUL=1,
    cVERDE=2,
    cCIAN=3,
    cROJO=4,
    cMAGENTA=5,
    cMARRON=6,
    cGRIS_CLARO=7,
    cGRIS=8,
    cAZUL_CLARO=9,
    cVERDE_CLARO=10,
    cCIAN_CLARO=11,
    cROJO_CLARO=12,
    cMAGENTA_CLARO=13,
    cAMARILLO=14,
    cBLANCO=15*/
}

 void sacar_puntaje(int *acu_vec,int *vec_dados,int tam)/// SACAR PUNTAJE
 {
     for (int k=0;k<tam;k++)
     {
         acu_vec[k]=0;  ///PONGO EN CERO TODO EL ACUMULADOR
     }
     for (int i=0;i<5;i++)
     {
         switch(vec_dados[i])///-ACA LLENAMOS EL ACU_VEC DEPENDIENDO DEL VALOR DE VEC_DADOS
         {
         case 1:
            acu_vec[0]++;
            break;
         case 2:
            acu_vec[1]++;
            break;
         case 3:
            acu_vec[2]++;
            break;
         case 4:
            acu_vec[3]++;
            break;
         case 5:
            acu_vec[4]++;
            break;
         case 6:
            acu_vec[5]++;
            break;
         }
     }
 }


void interfaz()
{
    ///INTERFAZ DE TITULO Y MENU
    textcolor(9,15);cout<<"           ------------------------------"<<endl;
    cout<<"          |";textcolor(8,15);cout<<"          GENE";textcolor(9,15);cout<<"RALA";textcolor(8,15);cout<<"            |"<<endl;
    cout<<"           ------------------------------"<< endl<<endl;

    textcolor(12,15);cout<< " -------------------------------------------------------"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                                                       |"<< endl;
    cout<<"|                                                       |"<< endl;
    cout<<"|                                                       |"<< endl;
    cout<<"|                                                       |"<< endl;
    cout<<"|                                                       |"<<endl;
    cout<< " -------------------------------------------------------"<<endl<<endl;
    textcolor(5,15);gotoxy(3,6);cout<<"1)  juego para 1 jugador";
    gotoxy(3,7);cout<<"2)  juego para 2 jugadores";
    gotoxy(3,8);cout<<"3)  Puntacion mas alta ";
    gotoxy(3,9);cout<<"0)  Salir del juego";
}

void mostrarnombre1(int tiro,int j,char *nombre1)
{
    /// CHAR NOMBRE ESTA ASI COMO PUNTERO XQE LLAMA A LA VARIABLE NOMBRE QUE INGRESO EN EL MAIN
    system("cls");/// BORRO EL MENU PRINCIPAL DONDE ELIJO LOS JUGADORES
    textcolor(0,15);cout <<" -----------------------------------------------------------"<<endl;
    cout<<"|                                                           |"<<endl;
    textcolor(10,15);cout<<" Nombre del jugador 1: " <<"\t"<<"            Ronda: "<<"\t"<<"  Tiro: "<<endl;
    textcolor(0,15);/// EN ESTA LINEA INDICO EL NOMBRE QUE LLAMÉ Y LAS VARIABLES DE LA RONDA Y EL TURNO DEL MAIN
    cout<<"|                                                           |"<<endl;
    cout <<" -----------------------------------------------------------"<<endl;
    textcolor(9,15);gotoxy(22,2);cout<<nombre1;
    gotoxy(43,2);cout<<j;
    gotoxy(56,2);cout<<tiro;
}

void mostrarnombre2(int tiro,int turno,char *nombre2)
{
    /// CHAR NOMBRE ESTA ASI COMO PUNTERO XQE LLAMA A LA VARIABLE NOMBRE QUE INGRESO EN EL MAIN
    system("cls");/// BORRO EL MENU PRINCIPAL DONDE ELIJO LOS JUGADORES
    textcolor(0,15);cout <<" -----------------------------------------------------------"<<endl;
    cout<<"|                                                           |"<<endl;
    textcolor(10,15);cout<<" Nombre del jugador 2: " <<"\t"<<"            Ronda: "<<"\t"<<"  Tiro: "<<endl;
    textcolor(0,15);/// EN ESTA LINEA INDICO EL NOMBRE QUE LLAMÉ Y LAS VARIABLES DE LA RONDA Y EL TURNO DEL MAIN
    cout<<"|                                                           |"<<endl;
    cout <<" -----------------------------------------------------------"<<endl;
    textcolor(9,15);gotoxy(22,2);cout<<nombre2;
    gotoxy(43,2);cout<<turno;
    gotoxy(56,2);cout<<tiro;
}

void tirar_dados(int *vec_dados,int tam) //vec_dado es puntero xqe en el for declaro lo que hay en vec_dado con random y cuando llamo la variable llama a lo que hay en el puntero
{ // tirar los dados con el modo rand
    for(int i=0;i<tam;i++)
    {
        vec_dados[i]=rand()%6+1;
    }
}

void MostrarDados(int *vec_dados)
{
    ///LLAMO AL VECTOR -VEC_DADOS- DE LA FUNCION /"TIRAR_DADOS"/
    int x=0, k=0;//ACUMULADORES PARA MODIFICAR LOS GOTOXY
    for (int i=0;i<5 ;i++ )//PARA DIBUJAR 5 DADOS
    {
        textcolor(2,15);gotoxy(x+4, 5); cout<<"Dado " <<i+1 <<endl;//INDICO EL NUMERO DEL DADO
        gotoxy(x+1, 6); cout<<" __________" <<endl;
        gotoxy(x+1, 7); cout<<"|          |"<<endl;
        gotoxy(x+1, 8); cout<<"|          |"<<endl;
        gotoxy(x+1, 9); cout<<"|          |"<<endl;
        gotoxy(x+1,10); cout<<"|          |"<<endl;
        gotoxy(x+1,11); cout<<" ---------- "<<endl;
        cout<<endl;
        x+=14; //ACUMULADOR PARA MODIFICAR LA POSICION DEL DADO
        switch(vec_dados[i])//ESTE SWITCH ES PARA DIBUJAR LOS VALORES DE LOS DADOS
        {
        case 1:
            textcolor(12,15);gotoxy(k+6,9);cout<<"*"<<endl;
            break;
        case 2:
            textcolor(12,15);gotoxy(k+4,8);cout<<"*" <<endl;
            gotoxy(k+8,10);cout<<"*"<<endl;
            break;
        case 3:
            textcolor(12,15);gotoxy(k+4,8);cout<<"*" <<endl;
            gotoxy(k+6,9);cout<<"*" <<endl;
            gotoxy(k+8,10);cout<<"*"<<endl;
            break;
        case 4:
            textcolor(12,15);gotoxy(k+3, 8); cout<<"*     *" <<endl;
            gotoxy(k+3,10); cout<<"*     *"<<endl;
            break;
        case 5:
            textcolor(12,15);gotoxy(k+3, 8); cout<<"*     *" <<endl;
            gotoxy(k+6,9);cout<<"*"<<endl;
            gotoxy(k+3,10); cout<<"*     *"<<endl;
            break;
        case 6:
            textcolor(12,15);gotoxy(k+3, 8); cout<<"*     *" <<endl;
            gotoxy(k+3,9);cout<<"*     * "<<endl;
            gotoxy(k+3,10); cout<<"*     *"<<endl;
            break;
        }
        k+=14;// ESTE ACUMULADOR ES PARA MODIFICAR LA POSICION DE LOS VALORES DE LOS DADOS

    }
}

int dado_nuevo(int *vec_dados,int *acu_vec, int *tiro)
{
    ///TIRO ES PUNTERO XQE LLAMO AL TIRO DEL MAIN
    ///LLAMO AL -VEC_DADOS- PARA CAMBIAR EL DADO QUE QUIERO VOLVER A TIRAR, SERIA MODIFICAR LOS VALORES DEL VECTOR
        int dados_a_tirar, tomar_dado, i, tam=5;
        textcolor(6,15);gotoxy(0,15);cout<<"CUANTOS DADOS VAS A VOLVER A TIRAR?" <<endl;
        textcolor(0,15);cin >> dados_a_tirar; //ACA PIDO CUANTOS DADOS VOY A CAMBIAR
       int dadoant,dadoant2,dadoant3,dadoant4;

        bool seguir=true;
        bool seguir2=false;
        int c=1,ll=0, pdado, parar=0, turulo=0;
            switch(dados_a_tirar) //SWITCH PARA TOCAR EL -VEC_DADOS- MEDIANTE LOS DADOS QUE QUIERO CAMBIAR

            {
                case 1:
                    ///ACA DIGO CUAL DADO VOY A CAMBIAR
                    textcolor(6,15);cout << "Ingrese el numero de Dado que vuelve a tirar: "<<endl;
                    textcolor(0,15);cin>>tomar_dado;//INDICO EL NUMERO DEL DAO QUE QUIERO CAMBIAR
                    vec_dados[tomar_dado-1]=rand()%6+1;//ACA MODIFICO DEL -VEC_DADOS- EL VALOR DE LA POSICION QUE QUIEOR CAMBIAR
                    cout<<endl;
                    break;
                case 2:
                    ///ACA DIGO CUAL DADO VOY A CAMBIAR

                    while (c!=0){
                        textcolor(6,15);cout << "Ingrese el numero de Dado que vuelve a tirar: "<<endl;
                        textcolor(0,15);cin>>tomar_dado;
                        if (tomar_dado>5)
                        {
                            cout<<"el dado no existe"<<endl;
                        }
                        else
                        {
                            ll++;
                            if (ll==1)
                            {

                                pdado=tomar_dado;
                                vec_dados[tomar_dado-1]=rand()%6+1;
                            }
                            else
                            {
                                if (tomar_dado==pdado)
                                {
                                    cout<<"Vuelve a intentar y tire un dado diferente"<<endl<<endl<<endl;
                                }
                                else
                                {
                                    vec_dados[tomar_dado-1]=rand()%6+1;
                                    c=0;
                                }

                            }
                        }
                    }
                    break;
                case 3:
                    ///ACA DIGO CUAL DADO VOY A CAMBIAR
                        ll=0;
                        c=1;
                        while (c!=0||parar<2)
                        {
                            textcolor(6,15);cout << "Ingrese el numero de Dado que vuelve a tirar: "<<endl;
                            textcolor(0,15);cin>>tomar_dado;
                            if (tomar_dado>5)
                            {
                                cout<<"el dado no existe"<<endl;
                            }
                            else
                            {
                                ll++;

                                if (ll==1)
                                {
                                    pdado=tomar_dado;
                                    vec_dados[tomar_dado-1]=rand()%6+1;
                                }else{
                                    if (tomar_dado==pdado){
                                        cout<<"Vuelve a intentar y tire un dado diferente"<<endl<<endl<<endl;
                                    }else{
                                        vec_dados[tomar_dado-1]=rand()%6+1;
                                        parar++;
                                    }
                                }
                                if (parar==2){
                                    c=0;
                                }
                                pdado=tomar_dado;
                            }
                        }

                    break;
                case 4:
                      ll=0;
                        c=1;
                        while (c!=0||parar<3){
                            textcolor(6,15);cout << "Ingrese el numero de Dado que vuelve a tirar: "<<endl;
                            textcolor(0,15);cin>>tomar_dado;
                            if (tomar_dado>5){
                                cout<<"el dado no existe"<<endl;
                            }else{

                                    ll++;

                                    if (ll==1){

                                        pdado=tomar_dado;
                                        vec_dados[tomar_dado-1]=rand()%6+1;
                                    }else{
                                        if (tomar_dado==pdado){
                                           cout<<"Vuelve a intentar y tire un dado diferente"<<endl<<endl<<endl;
                                        }else{
                                            vec_dados[tomar_dado-1]=rand()%6+1;

                                            parar++;
                                        }

                                    }
                                    if(parar==3){
                                        c=0;
                                    }
                                    pdado=tomar_dado;
                            }
                        }
                    break;
                case 5:
                /// COMO CAMBIO LOS 5 DADOS, LLAMO A LA FUNCION TIRAR DADOS PARA MODIFICAR TODOS
                tirar_dados(vec_dados, tam);
                break;
                case 0:
                int guardarturno=*tiro;//ACA GUARDARTURNO GUARDO EL VALOR DE TIRO PARA SABER QUE VUELTA ES PARA SABER JUGADAS SI ES SERVIDA O NO
                *tiro=3;
                return (int) guardarturno;
                //MODIFICO LA VARIABLE TIRO DEL main
                    break;
        }

}

bool generala(int *acu_vec,int tam)
{
    bool bandera=false;
    for(int i=0;i<tam;i++)
    {
        if(acu_vec[i]==5)
        {
            bandera=true;
        }
    }
    return bandera;

}

bool full(int *acu_vec,int tam){
    for(int i=0;i<tam;i++){
        if(acu_vec[i]==1||acu_vec[i]==4||acu_vec[i]==5){//SACO FULL POR ABSURDO FUL ES DOS IGUALES Y 3 IGUALES
            return false;
        }else if(acu_vec[i]==2 && acu_vec[i]==3){ //ACA PREGUNTO POR FULL
            return true;
        }
    }

}

bool poker(int *acu_vec,int tam){
    int es4=false;//PARA SABER SI EN ALGUNA POSICION DEL ACU_VEC  ES 4
    int es1=false;//PARA SABER SI EN ALGUNA POSICION DEL ACU_VEC  ES 1
    for(int i=0;i<tam;i++){
        if(acu_vec[i]==4){
        es4=true;//DIGO QUE EN ALGUNA POSICION DEL ACU_VEC HAY 4 DADOS IGUALES
        }
        if(acu_vec[i]==1){
            es1=true;//DIGO QUE EN ALGUNA POSICION DEL ACU_VEC HAY 1 DADO NO IMPORTA CUAL
        }
    }
    if(es4==true && es1==true){
        return true; //ACA PREGUNTO SI LO DE ARRIBA ES TRUE Y SI ES TRUE RETORNO TRUE EN LA FUNCION POKER
    }else{
        return false;
    }

}

bool escalera(int *acu_vec,int tam){
    if(acu_vec[0]==1 && acu_vec[tam-1]==1){
        return false;
    }
    for(int i=1;i<tam-1;i++){
        if(acu_vec[i]!=1){
            return false;
        }
    }
    return true;//ES TRUE ACA DIRECTAMENTE PORQUE SI PASA POR ALGUN FALSE DE ARRIBA NO HAY ESCALERA
}
int seleccionarjuego(int *acu_vec,bool *jugado,int *puntaje,int *eleccion,int turno,int *j,int *vec_dados)
{
  bool esfull=full(acu_vec,6);//ACA GUARDAS EN UNA VARIABLE LO QUE RETORNA LA FUNCION
  bool espoker=poker(acu_vec,6);//ACA GUARDAS EN UNA VARIABLE LO QUE RETORNA LA FUNCION
  bool esescalera=escalera(acu_vec,6);//ACA GUARDAS EN UNA VARIABLE LO QUE RETORNA LA FUNCION
  bool esgenerala=generala(acu_vec,6);//ACA GUARDAS EN UNA VARIABLE LO QUE RETORNA LA FUNCION
  for(int k=0;k<10;k++){
        eleccion[k]=0;//ACA PONES ELECCION EN CERO
  }
    for(int i=0;i<6;i++){
        if(jugado[i]==false && acu_vec[i]!=0){
        eleccion[i]=acu_vec[i]*(i+1);//ACA PREGUNTO PORLAS JUGADAS QUE TENGO DEL 1 AL 6
        cout <<" COD " <<i+1<<"  Puntos Disponibles  " <<eleccion[i]<< " al  "<<i+1<<endl; /// PREGUNTO SOBRE JUGADO SI ESTA EN FALSE Y SI EL ACU_VEC ESTA EN DIFERENTE DE 0 YA QUE SI NO ES ASI NO PODRIA HACERLE UN CALCULO Y MOSTRARLE AL USUARIO
        }
    }// ACA SE CIERRA EL FOR PARA SABER EL PUNTAJE DEL 1 AL 6
    if(jugado[6]==false&&esgenerala){//DIGO JUGADO[6]==FALSE && ESGENERALA.. PREGUNTO SOLO ESGENERALA XQE YA LO PREGUNTE ANTES EN LA FUNCION DE GENERALA
        //ESGENERALA TIENE QUE ESTAR EN TRUE PARA ENTRAR
        if(turno==1){
        }else{
        eleccion[6]=60;
        cout <<" COD 7 "<<eleccion[6]<<" Puntos a la Generala " << endl;
        }
    }

    if(jugado[7]==false&&esfull){
        if(turno==1){ //ACA ES PARA SABER SI ES SERVIDA
        eleccion[7]=35;
        cout <<" COD 8 "<<eleccion[7] <<" puntos al Full "<<endl;
        }else{
         eleccion[7]=30;
         cout<<" COD 8 "<<eleccion[7] <<" Puntos al Full"<<endl;
    }
    }
    if(jugado[8]==false&&espoker){
        if(turno==1){
        eleccion[8]=45;
        cout <<" COD 9 "<< eleccion[8] <<" Puntos al Poker " << endl;
        }else{
            eleccion[8]=40;
        cout <<" COD 9 "<< eleccion[8] <<" Puntos al Poker " << endl;
    }
    }

    if(jugado[9]==false&&esescalera){
        if(turno==1){
        eleccion[9]=25;
        cout <<" COD 10 "<<eleccion[9]<< " Puntos a la Escalera " << endl;
        }else{
        eleccion[9]=20;
        cout <<" COD 10 "<<eleccion[9]<< " Puntos a la Escalera " << endl;
    }
    }
    cout <<endl<< "O inserte el COD del premio que desea ANULAR" << endl << endl << endl;
}

int elegircodigo(int *eleccion,bool *jugado,int *puntaje,bool *usado){
    int codigo;
    int pregunta;
    bool seguir=true;
    cout << "Eliga el CODIGO que desea marcar " << endl<< endl; ///fijarse como hacer para ver que solo seleccione donde eleccion tenga valores y no pueda seleccionar cualquiEr cosa fijarse
    cin >> codigo;
    while(usado[codigo-1]==true){
        cout << " Vuelva a elegir un CODIGO valido " << endl; //ACA VALIDO QUE EL PELOTUDO DEL JUGADOR NO ELIJA EL CODIGO QUE YA ELIGIO
        cin >> codigo;
         }
    while(codigo<1||codigo>10){ ///pido el codigo que desea marcar.. si es codigo esta entre 1 y 10 no entra al while y sigue. si es lo contrario te pide un numero que este entre esos valores mencionados
    cout << " Vuelva a elegir un CODIGO valido " << endl;
    cin >> codigo;
    }
         cout<<"Seguro que desea marcar ese COD? "<<endl<<endl;
         cout << "Marque con 1 si es SI y con 0 si es NO"<<endl<<endl;
         cin>>pregunta;
         if(pregunta==1){ /// pregunto si es 1
            usado[codigo-1]=true;//SI ES CODIGO VALIDO ES TRUE, si es 1 pongo en usado en true
         }
         if(pregunta==0){ // pregunto si la pregunta en 0
        cout << " Vuelva a elegir un CODIGO valido " << endl<<endl; //ACA VALIDO QUE EL PELOTUDO DEL JUGADOR NO ELIJA EL CODIGO QUE YA ELIGIO
        cin >> codigo;  // si es 0 vuelvo a preguntar en codigo
        while(seguir){//pongo una bandera en true
        //cout << " Vuelva a elegir un CODIGO valido " << endl<<endl; //ACA VALIDO QUE EL PELOTUDO DEL JUGADOR NO ELIJA EL CODIGO QUE YA ELIGIO
       // cin >> codigo;
        cout<<"Seguro que desea marcar ese COD? "<<endl<<endl;
        cout << "Marque con 1 si es SI y con 0 si es NO"<<endl<<endl;
        cin>>pregunta; // vuelvo a preguntar sobre la pregunta para ver si quiere seguir con ese codigo nuevo
        if(pregunta==1){ /// pregunto si es 1
            usado[codigo-1]=true;// si es 1 pongo en usado lo pongo en true
            seguir=false; // y seguir en false para terminar el while
         }
        }//while de seguir
        }//if de pregunta 0

        if(jugado[codigo-1]==false){//PREGUNTO SI ESE PUNTAJE ESTA DISPONIBLE, SI LO ESTA ENTRA ACA Y MUESTRA PUNTAJE
        puntaje[codigo-1]=eleccion[codigo-1];
        jugado[codigo-1]=true;//ACA CIERRO TODO PARA QUE NO ENTRE MAS EN ESTA OPCION DE PUNTAJE
    }
}
void listadepuntaje(int *puntaje,bool *jugado){
    int sum=0;
    for(int i=0;i<10;i++){
         sum+=puntaje[i];
        }
	gotoxy(80,1);cout<<"------------------------------------------------------"<<endl;
        gotoxy(80,2);cout<<"  COD  |          PREMIO                 |   PUNTOS   "<<endl;
        gotoxy(80,3);cout<<"------------------------------------------------------"<<endl;
        gotoxy(80,4);cout<<"  1    |           AS                    |"<<endl;gotoxy(127,4);if(jugado[0]==false){cout<<"";}else{cout<<puntaje[0];}
        gotoxy(80,5);cout<<"------------------------------------------------------";
        gotoxy(80,6);cout<<"  2    |           DOS                   |"<<endl;gotoxy(127,6);if(jugado[1]==false){cout<<"";}else{cout<<puntaje[1];}
        gotoxy(80,7);cout<<"------------------------------------------------------";
        gotoxy(80,8);cout<<"  3    |           TRES                  |"<<endl;gotoxy(127,8);if(jugado[2]==false){cout<<"";}else{cout<<puntaje[2];}
        gotoxy(80,9);cout<<"------------------------------------------------------";
        gotoxy(80,10);cout<<"  4    |           CUATRO                |"<<endl;gotoxy(127,10);if(jugado[3]==false){cout<<"";}else{cout<<puntaje[3];}
        gotoxy(80,11);cout<<"------------------------------------------------------";
        gotoxy(80,12);cout<<"  5    |           CINCO                 |"<<endl;gotoxy(127,12);if(jugado[4]==false){cout<<"";}else{cout<<puntaje[4];}
        gotoxy(80,13);cout<<"------------------------------------------------------";
        gotoxy(80,14);cout<<"  6    |           SEIS                  |"<<endl;gotoxy(127,14);if(jugado[5]==false){cout<<"";}else{cout<<puntaje[5];}
        gotoxy(80,15);cout<<"------------------------------------------------------";
        gotoxy(80,16);cout<<"  7    |           GENERALA              |"<<endl;gotoxy(127,16);if(jugado[6]==false){cout<<"";}else{cout<<puntaje[6];}
        gotoxy(80,17);cout<<"------------------------------------------------------";
        gotoxy(80,18);cout<<"  8    |           FUL                   |"<<endl;gotoxy(127,18);if(jugado[7]==false){cout<<"";}else{cout<<puntaje[7];}
        gotoxy(80,19);cout<<"------------------------------------------------------";
        gotoxy(80,20);cout<<"  9    |           POKER                 |"<<endl;gotoxy(127,20);if(jugado[8]==false){cout<<"";}else{cout<<puntaje[8];}
        gotoxy(80,21);cout<<"------------------------------------------------------";
        gotoxy(80,22);cout<<"  10   |           ESCALERA              |"<<endl;gotoxy(127,22);if(jugado[9]==false){cout<<"";}else{cout<<puntaje[9];}
        gotoxy(80,23);cout<<"------------------------------------------------------"<<endl;
        gotoxy(80,24);textcolor(1,7);cout<<"                   TOTAL                 |"<<endl;gotoxy(127,24);cout<<sum;
        gotoxy(80,25);textcolor(2,15);cout<<"------------------------------------------------------"<<endl;

            }
void vectoren0(int *vec,int tam){ //poner un vector en 0 vector en entero EN EL MAIN
    for(int i=0;i<tam;i++){
    vec[i]=0;
    }
}
#endif // LIBGENERALA_H_INCLUDED
