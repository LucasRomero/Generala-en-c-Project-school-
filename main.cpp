#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "libgenerala.h"



int main()
{   bool generalaservida,generalaservida2;
    bool seguir=true,seguir2=true;
    int total1=0,total2=0,total3=0,vecmax[3]; //poner en 0 afuera del while por que si lo pongo adentro cada ves q selecciono algun opcion me lo vuelve a 0 y no puedo sacar el maximo
    vectoren0(vecmax,3);
    bool juego=true;
    int puntajemaximo=0;
    while(juego){
    srand(time(NULL));
    int opcion, tam=5, vec_dados[5],acu_vec[6],puntaje[10],eleccion[10],turno; /// case 1
    int puntaje1[10],eleccion1[10];
    bool jugado1[10],usado1[10];
    vectoren0(puntaje,10);
    vectoren0(puntaje1,10);
    char nombre1[50], nombre2[50],nombremay1[50];
    bool jugado[10],usado[10];
    for(int c=0;c<=9;c++){
    jugado[c]=false;//ES SOLAMENTE PARA SABER QUE JUGADAS TENGO DISPONIBLES
    usado[c]=false;//ES PARA SABER EL CODIGO QUE TENGO DISPONIBLE EN LAS JUGADAS
    jugado1[c]=false;//ESTO ES LO MISMO SOLO QUE ES PARA OTRO JUGADOR
    usado1[c]=false;//ESTO ES LO MISMO SOLO QUE ES PARA OTRO JUGADOR
    }
    interfaz();//LLAMADO A LA INTERFAZ
    textcolor(1,15);gotoxy(0,12);cout << " Numero de opcion " << endl;
    textcolor(0,15);cin >> opcion;
    cin.ignore();
    system("cls");

    switch(opcion)
    {
        case 1:
            total1=0;
            vectoren0(vecmax,0);
            cout << "Ingrese el nombre:  ";
            cin.getline(nombre1, 50);
            system("cls");
            for(int j=1;j<=10;j++)
            {
                system("cls");
                //cout <<endl<<endl<< "Manipular los dados" <<endl<<endl;
               // manipulardados(vec_dados);
                tirar_dados(vec_dados,tam);
                for (int tiro=1;tiro<=3;tiro++)
                {
                    system("cls");
                    listadepuntaje(puntaje,jugado);
                    mostrarnombre1(tiro,j,nombre1);       ///LLAMADO A MOSTRAR NOMBRE (PEDIR NOMBRE Y MOSTRARLO)
                    if(tiro<3){
                    listadepuntaje(puntaje,jugado);
                    MostrarDados(vec_dados);  /// RECORRER EN VECTOR Y MOSTRAR EN PANTALLA y muestra los dibujos del dado
                    if(tiro==1){
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    generalaservida=generala(acu_vec,6);
                    }
                    if(generalaservida&&tiro==1){
                        cout <<endl<<endl<<endl<<endl<<"                 GANASTEEEEEEEEEEEEEEEEEEEEEE FELICITACIONES!!! "<<endl<<endl<<endl<<endl;
                        j=11;
                        tiro=4;
                        seguir=false;
                        system("pause");
                        system("cls");
                    }
                    if(seguir==true){
                    turno=dado_nuevo(vec_dados,acu_vec,&tiro);      /// elegir dados que tirar
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    }
                    }else{
                    MostrarDados(vec_dados);
                    }
                }
                if(seguir==true){
                generala(acu_vec,6);
                full(acu_vec,6);
                poker(acu_vec,6);
                bool hola=escalera(acu_vec,6);
                cout <<endl<<endl<< " Posibles Jugadas:  " << endl;
                seleccionarjuego(acu_vec,jugado,puntaje,eleccion,turno,&j,vec_dados);
                elegircodigo(eleccion,jugado,puntaje,usado);
                system("cls");
                listadepuntaje(puntaje,jugado);
                system("pause");
                }

            }///for de 10
                for(int p=0;p<=9;p++){ /// poner en funcion esto!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! seguir con esto
                total1+=puntaje[p];//esto es para saber la puntacion de este jugador
                }
                vecmax[0]=total1;
                system("cls");
                strcpy(nombremay1,nombre1);
/// --------------------------------------------------------------------------------------------------
    /// --------------------------------------------------------------------------------------------------
        /// --------------------------------------------------------------------------------------------------
           /// --------------------------------------------------------------------------------------------------
///-----------------------------------------------------------   !!!!!2 JUGADORES!!!!! ------------------------------------------------------------------------------------------
            break;
        case 2:
            vectoren0(vecmax,0);
            total2=0; total3=0;
            textcolor(6,15);cout<<"INGRESE EL NOMBRE DEL JUGADOR 1: "<<endl;
            textcolor(0,15);cin.getline(nombre1, 50);
            textcolor(9,15);cout<<"INGRESE EL NOMBRE DEL JUGADOR 2: "<<endl;
            textcolor(8,15);cin.getline(nombre2, 50);
            for (int j1y2=1;j1y2<=20;j1y2++)
            {
                if (j1y2%2==1)
                    ///    JUGADOR 1  -----------------------------------------------------------------------
                {
                    //manipulardados(vec_dados); /// manipular los dados
                    tirar_dados(vec_dados, tam);//LLAMO A LA FUNCION TIRAR DADOS
                    for (int tiro=1;tiro<=3;tiro++)
                    {
                        system("cls");
                        listadepuntaje(puntaje,jugado);
                        mostrarnombre1(tiro,j1y2/2+1, nombre1);///LLAMADO A MOSTRAR NOMBRE (PEDIR NOMBRE Y MOSTRARLO)
                        if (tiro<3)
                        {
                            listadepuntaje(puntaje,jugado);
                            MostrarDados(vec_dados);/// RECORRER EN VECTOR Y MOSTRAR EN PANTALLA Y MUESTRA DIBUJO DE DADOS
                    if(tiro==1){
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    generalaservida=generala(acu_vec,6);
                    }
                    if(generalaservida&&tiro==1){
                        cout <<endl<<endl<<endl<<endl<<"                 GANASTEEEEEEEEEEEEEEEEEEEEEE FELICITACIONES!!! "<<endl<<endl<<endl<<endl;
                        j1y2=11;
                        tiro=4;
                        seguir=false;
                        system("pause");
                        system("cls");
                    }
                    if(seguir==true){
                    turno=dado_nuevo(vec_dados,acu_vec,&tiro);      /// elegir dados que tirar
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    }
                        }else{
                            MostrarDados(vec_dados);/// RECORRER EN VECTOR Y MOSTRAR EN PANTALLA Y MUESTRA DIBUJO DE DADOS
                        }
                    }
                    if(seguir==true){
                    sacar_puntaje (acu_vec, vec_dados, tam+1); //TAM+1 XQE LO TENGO DEFINIDO COMO QUE TAM VALE 5
                    generala(acu_vec,6);
                    full(acu_vec,6);
                    poker(acu_vec,6);
                    escalera(acu_vec,6);
                    cout <<endl<<endl<< " Posibles Jugadas:  " << endl;
                    seleccionarjuego(acu_vec,jugado,puntaje,eleccion,turno,&j1y2,vec_dados);
                    elegircodigo(eleccion,jugado,puntaje,usado);
                    system("cls");
                    listadepuntaje(puntaje,jugado);
                    system("pause");
                    }
                    }


                ///         JUGADOR 2 ----------------------------------------------------------------------
                else
                {
                    //manipulardados(vec_dados); /// manipular los dados
                    tirar_dados(vec_dados, tam);//LLAMO A LA FUNCION TIRAR DADOS
                    for (int tiro=1;tiro<=3;tiro++)
                    {
                        system("cls");
                        listadepuntaje(puntaje1,jugado1);
                        mostrarnombre2(tiro,j1y2/2, nombre2);///LLAMADO A MOSTRAR NOMBRE (PEDIR NOMBRE Y MOSTRARLO)
                        if (tiro<3)
                        {
                            listadepuntaje(puntaje1,jugado1);
                            MostrarDados(vec_dados);/// RECORRER EN VECTOR Y MOSTRAR EN PANTALLA Y MUESTRA DIBUJO DE DADOS
                    if(tiro==1){
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    generalaservida2=generala(acu_vec,6);
                    }
                    if(generalaservida2&&tiro==1){
                        cout <<endl<<endl<<endl<<endl<<"                 GANASTEEEEEEEEEEEEEEEEEEEEEE FELICITACIONES!!! "<<endl<<endl<<endl<<endl;
                        j1y2=11;
                        tiro=4;
                        seguir=false;
                        system("pause");
                        system("cls");
                    }
                    if(seguir2==true){
                    turno=dado_nuevo(vec_dados,acu_vec,&tiro);      /// elegir dados que tirar
                    sacar_puntaje(acu_vec,vec_dados,tam+1);
                    }

                        }
                        else
                        {
                            MostrarDados(vec_dados);/// RECORRER EN VECTOR Y MOSTRAR EN PANTALLA Y MUESTRA DIBUJO DE DADOS
                        }
                    }
                    if(seguir2==true){
                    sacar_puntaje (acu_vec, vec_dados, tam+1); //TAM+1 XQE LO TENGO DEFINIDO COMO QUE TAM VALE 5
                    generala(acu_vec,6);
                    full(acu_vec,6);
                    poker(acu_vec,6);
                    escalera(acu_vec,6);
                    cout <<endl<<endl<< " Posibles Jugadas:  " << endl;
                    seleccionarjuego(acu_vec,jugado1,puntaje1,eleccion1,turno,&j1y2,vec_dados);
                    elegircodigo(eleccion1,jugado1,puntaje1,usado1);
                    system("cls");
                    listadepuntaje(puntaje1,jugado1);
                    system("pause");
                    }
                }
            }///for de 20
                for(int z=0;z<=9;z++){  /// sumar el puntaje en las variables para poder despues preguntar quien es mas grande
                total2+=puntaje[z];
                total3+=puntaje1[z];
                }
                vecmax[1]=total2;
                vecmax[2]=total3;
                system("cls");
                /// mostrar el ganador
                if(total2>total3){
                    textcolor(2,15);gotoxy(5,1);cout << "Puntaje total del jugador 1 es : " <<total2;
                    textcolor(6,15);gotoxy(7,3);cout << "Y el del jugador 2 el Puntaje es : " <<total3;
                    textcolor(2,15);gotoxy(10,6);cout<< "El GANADOR ES EL JUGADOR 1 :  " <<nombre1<<endl<<endl;
                    textcolor(12,15);cout<<"FELICITACIONES GANASTEEEEEEE!! "<<endl<<endl;textcolor(0,15);
                }else{
                    textcolor(2,15);gotoxy(5,1);cout << "El puntaje total del jugador 1 es: " <<total2;
                    textcolor(6,15);gotoxy(7,3);cout << "Y el puntaje del jugador 2 es : " <<total3;
                    textcolor(6,15);gotoxy(10,6);cout << "El GANADOR ES EL JUGADOR 2 :  " <<nombre2<<endl;
                    textcolor(12,15);cout << "FELICITACIONES GANASTEEEEEEE!! "<<endl<<endl;textcolor(0,15);

                }
                system("pause");
                system("cls");
            break;
        case 3: ///Mayor puntaje seguir con esto
            for(int i=0;i<20;i++){
                 if(vecmax[0]>puntajemaximo){
                    puntajemaximo=vecmax[0];
                    strcpy(nombremay1,nombre1);
                 }
                if(vecmax[1]>puntajemaximo){
                 puntajemaximo=vecmax[1];                   /// sacar el maximo numero y guardar el nombre
                 strcpy(nombremay1,nombre1);
                }if(vecmax[2]>puntajemaximo){
                 puntajemaximo=vecmax[2];
                 strcpy(nombremay1,nombre2); /// strcpy hace que el primer vector de char tenga lo mismo que el segundo
                }
            }
                char nombremayor[50];
                strcpy(nombremayor,nombremay1); /// guardo en otra variable por que, cada ves que cambie de nombre nunca me deja el nombre que tiene mas punto


            cout<<endl<<endl<<endl<<endl;
            if(puntajemaximo>0){
            textcolor(9,15);cout<< "                 PUNTACION MAS ALTA  DEL JUGADOR :   " <<nombremayor <<"       "<<puntajemaximo<<endl<<endl<<endl;
            system("pause");
            system("cls");
            }else{
            textcolor(9,15);cout<< "                       Todavia no hay PUNTAJE Maximo  :)" <<endl<<endl<<endl<<endl;
            cout<< "                                            Jugue almenos 1 vez  " <<endl<<endl<<endl<<endl;
            system("pause");
            system("cls");
            }
            break;
        case 0:
            juego=false;
            textcolor(9,15);cout <<endl<<endl<<endl<<endl<<endl;
            cout << "                                            GRACIAS POR JUGAR A MI JUEGO  " << endl<<endl;
            cout <<"                                                    Vuelve cuando quieras :D"<<endl<< endl;
            cout << "                               Creado por Lucas Romero y Daniel Riquel   "<<endl<<endl;
            break;
    ///for
     }/// switch
    }///while
    return 0;
}

