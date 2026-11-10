#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int main() {
int modoJuego = 0, turno = 0, numero = 0;
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
switch (modoJuego) {
case 1: printf("Modo de juego: Multiplos de 3 \n");
Sleep(1500);
system("cls");
printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al 90,\npero se el numero es multiplo de 3 el jugador debe escribir BOOM\n");
Sleep(5000);
system("cls");
break;
case 2: printf("Modo de juego: Multiplos de 7\n");
Sleep(1500);
system("cls");
printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al 210,\npero se el numero es multiplo de 7 el jugador debe escribir BOOM\n");
Sleep(5000);
system("cls");
break;    
}
printf("Preparence para jugar...\n");
Sleep(2000);
system("cls");


system("pause");
return 0;
}