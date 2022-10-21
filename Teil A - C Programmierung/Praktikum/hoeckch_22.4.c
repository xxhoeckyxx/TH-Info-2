/*----- vielmax.c ---------------------------------------------------------
 Description: Aufgabe 22.4 - Ellipsen-Prototypen
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 21-Oktober-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

float vielmax(int n, ...)
{
    va_list arg_zeiger_1, arg_zeiger_2;
    float wert_1, wert_2, ergeb = 0;
    int i;
    va_start(arg_zeiger_1, n);      // Zugriff auf 1.Argument (noch benamt)
    va_start(arg_zeiger_2, n+1);    // Zugriff auf 2.Argument (unbenamt)
    for (i = 1; i <= n; i++)        // Lesen der restlichen Argumente (unbenamt)
    {
        wert_1 = va_arg(arg_zeiger_1, double);
        wert_2 = va_arg(arg_zeiger_2, double);

        if(wert_1 > wert_2){
            ergeb = wert_1;
        } else {
            ergeb = wert_2;
        }
    }
    va_end(arg_zeiger_1); // Stack wieder in sauberen Zustand versetzen
    va_end(arg_zeiger_2); // Stack wieder in sauberen Zustand versetzen
    return (ergeb);
}

int main(){


    printf("Testprogramm fuer Funktion vielmax()\n");
    printf("====================================\n\n\n");

    int ergebnis;

    ergebnis= vielmax(12, 17, 3, 6, 24, 8);
    printf("Das Maximum der Zahlen 12, 17, 3, 6, 24, 8 ist: %d", ergebnis);
    ergebnis= vielmax(105, 77, 3, 54);
    printf("Das Maximum der Zahlen 105, 77, 3, 54 ist: %d", ergebnis);

}   