#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//Funcion para iniciar el juego en el modo de multiplos de 3
void JuegoMult3( char jugadores[2][20]){ 
int numero = 1, vidasJ1 = 3, vidasJ2 = 3;
char respuesta[10] = "1",jugada[10];

printf("Preparence para jugar...\n");
Sleep(2000);
system("cls");
int turno = rand() % 2;
if (turno == 0) {
printf("El jugador %s empieza primero\n", jugadores[0]);
//Ciclo para el juego
do{
    //Comprobacion de si el numero es multiplo de 3
    if(numero % 3 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
    //Turno del jugador 1
printf("Turno de: %s\n", jugadores[0]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ1--;
    Sleep(1000);
    system("cls");
}
numero++;
//Comprobacion de si el numero es multiplo de 3
if(numero % 3 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
//Turno del jugador 2
printf("Turno de: %s\n", jugadores[1]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ2--;
    Sleep(1000);
    system("cls");
}
numero++;
}while (vidasJ1 > 0 && vidasJ2 > 0);
} else {
printf("El jugador %s empieza primero\n", jugadores[1]);
do{
    //Comprobacion de si el numero es multiplo de 3
    if(numero % 3 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
    //Turno del jugador 1
printf("Turno de: %s\n", jugadores[1]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ1--;
    Sleep(1000);
    system("cls");
}
numero++;
//Comprobacion de si el numero es multiplo de 3
if(numero % 3 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
//Turno del jugador 2
printf("Turno de: %s\n", jugadores[0]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ2--;
    Sleep(1000);
    system("cls");
}
numero++;
}while (vidasJ1 > 0 && vidasJ2 > 0);

}
}
//Funcion para iniciar el juego en el modo de multiplos de 7
void JuegoMult7( char jugadores[2][20]){
int numero = 1, vidasJ1 = 3, vidasJ2 = 3;
char respuesta[10] = "1",jugada[10];

printf("Preparence para jugar...\n");
Sleep(2000);
system("cls");
int turno = rand() % 2;
if (turno == 0) {
printf("El jugador %s empieza primero\n", jugadores[0]);
//Ciclo para el juego
do{
    //Comprobacion de si el numero es multiplo de 7
    if(numero % 7 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
    //Turno del jugador 1
printf("Turno de: %s\n", jugadores[0]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ1--;
    Sleep(1000);
    system("cls");
}
numero++;
//Comprobacion de si el numero es multiplo de 7
if(numero % 7 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
//Turno del jugador 2
printf("Turno de: %s\n", jugadores[1]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ2--;
    Sleep(1000);
    system("cls");
}
numero++;
}while (vidasJ1 > 0 && vidasJ2 > 0);
} else {
printf("El jugador %s empieza primero\n", jugadores[1]);
do{
    //Comprobacion de si el numero es multiplo de 7
    if(numero % 7 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
    //Turno del jugador 1
printf("Turno de: %s\n", jugadores[1]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ1--;
    Sleep(1000);
    system("cls");
}
numero++;
//Comprobacion de si el numero es multiplo de 7
if(numero % 7 == 0){
        strcpy(respuesta, "BOOM");
    }else{
        sprintf(respuesta, "%d", numero);
    }
//Turno del jugador 2
printf("Turno de: %s\n", jugadores[0]);
scanf("%s", jugada);
if (_stricmp(jugada, respuesta) == 0) {
    printf("Correcto!\n");
    Sleep(1000);
    system("cls");
}else{
    printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
    vidasJ2--;
    Sleep(1000);
    system("cls");
}
numero++;
}while (vidasJ1 > 0 && vidasJ2 > 0);

}

}
int main(){
int modoJuego;
srand(time(NULL));
//Arreglo para almacenar los nombres de los jugadores
char jugadores[2][20]; 
printf("Ingrese el nombre del jugador 1: ");
scanf("%s", jugadores[0]);
printf("Ingrese el nombre del jugador 2: ");
scanf("%s", jugadores[1]);

//Menu para elejir el modo de juego
do{
printf("Modo de juego:\n\n Elije un modo de juego:\n\n1. Multiplos de 3 \n2. Multiplos de 7\n");
scanf("%d", &modoJuego);
if (modoJuego <= 0 || modoJuego > 2) {
printf("Opcion invalida, intente de nuevo\n");
Sleep(1000);
system("cls");
}
}while (modoJuego <= 0 || modoJuego > 2);
Sleep(1000);
system("cls");

//Inicio del juego dependiendo del modo de juego elegido
switch (modoJuego) {
case 1: printf("Modo de juego: Multiplos de 3 \n"); //Multiplos de 3
Sleep(1500);
system("cls");
printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al 90,\npero se el numero es multiplo de 3 el jugador debe escribir BOOM\n");
Sleep(5000);
system("cls");
JuegoMult3(jugadores);
break;
case 2: printf("Modo de juego: Multiplos de 7\n"); //Multiplos de 7
Sleep(1500);
system("cls");
printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al 210,\npero se el numero es multiplo de 7 el jugador debe escribir BOOM\n");
Sleep(5000);
system("cls");
JuegoMult7(jugadores);
break;    
}

system("pause");
return 0;
}