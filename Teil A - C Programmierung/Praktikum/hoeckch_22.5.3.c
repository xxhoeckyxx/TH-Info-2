/*----- dualwand.c --------------------------------------------------------
 Description: Aufgabe 22.5.3 - Rekursive Funktionen
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 2-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#define INVERTIERUNG 0xFFFF

void DezToBin(int dezimal)
{
    int rest;
    if (dezimal != 1)           // Feststellen ob die Zahl schon 1 ist
    {
        rest = dezimal % 2;     // Rest ermitteln und Zwischenspeichern
        DezToBin(dezimal / 2);  // Funktion ruft sich selbst wieder auf mit der Hälfte der Dezimalzahl (zahl = dezimalzahl / 2)
        printf("%d", rest);
    }
    else
    {
        printf("%d", dezimal);
    }
}

int main()
{
    int input;
    printf("Gib eine Dezimalzahl ein:");
    scanf("%d", &input);
    if(input < 0)
    {
        input = INVERTIERUNG + 1 + input;
    }
    DezToBin(input);
}
