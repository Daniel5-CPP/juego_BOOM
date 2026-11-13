#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void ElejirTurno(){
    printf("Preparence para jugar...\n");
Sleep(2000);
system("cls");

srand(time(NULL));
int turno = rand() % 2;
if (turno == 0) {
printf("El jugador 1 empieza primero\n");
}else {
printf("El jugador 2 empieza primero\n");
}
}
int main() {
int modoJuego = 0, numero = 1,jugada = 0, vidasJ1 = 3, vidasJ2 = 3;

/*char juagdores[2][20];
printf("Ingrese el nombre del jugador 1: ");
scanf("%s", juagdores[0]);
printf("Ingrese el nombre del jugador 2: ");
scanf("%s", juagdores[1]);
*/
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
ElejirTurno();
break;
case 2: printf("Modo de juego: Multiplos de 7\n");
Sleep(1500);
system("cls");
printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al 210,\npero se el numero es multiplo de 7 el jugador debe escribir BOOM\n");
Sleep(5000);
system("cls");
ElejirTurno();
break;    
}

system("pause");
return 0;
}