/*----- wortlen.c --------------------------------------------------------
 Description: Aufgabe 25.4.5 - Strings und char-Zeiger Teil1
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 9-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Erstellen Sie ein Pragramm wortlen.c, das eine Häufigkeitsverteilung über die Wortlängen in 
einem Text ausgibt. Wendet man dieses Programm z.B.auf die Programmdatei wortlen.c selbst
an: wortlen <wortlen.c
*/
int main()
{
    int leange = 0, 
        anzahl = 10;
    printf("Wortleange  |   Anzahl  |\n");
    printf("------------+-----------|\n");
    do
    {
        printf("          %d |         %d |\n", leange, anzahl);
        anzahl--;
    }while(anzahl > 0);
    return 0;
}