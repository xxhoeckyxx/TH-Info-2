/*----- vielmax.c ---------------------------------------------------------
 Description: Aufgabe 22.4 - Ellipsen-Prototypen
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 28-Oktober-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>

int vielmax(int n, ...)
{
    va_list arg_zeiger_1;
    int wert_1, ergeb = 0;
    int i;
    va_start(arg_zeiger_1, n);                      // Zugriff auf 1.Argument (noch benamt, Anzahl der Argumente, die Uebergeben werden)

    for (i = 0; i < n; i++)                         // Lesen der restlichen Argumente (unbenamt) -> Schleife bis alle angegebenen Argumente bearbeitet sind
    {
        // printf("Zeahler I: %d\n", i);            /* -> Debug */
        wert_1 = va_arg(arg_zeiger_1, int);
        // printf("Wert1: %d\n", wert_1);           /* -> Debug */

        if(wert_1 > ergeb)
        {
            ergeb = wert_1;
        }
        // printf("Ergebnis: %d\n", ergeb);         /* -> Debug */
        
    }
    va_end(arg_zeiger_1);                           // Stack wieder in sauberen Zustand versetzen
    return (ergeb);
}

int main()
{


    printf("Testprogramm fuer Funktion vielmax()\n");
    printf("====================================\n\n\n");

    int ergebnis;

    ergebnis = vielmax(6, 12, 17, 3, 6, 24, 8);
    printf("Das Maximum der Zahlen 12, 17, 3, 6, 24, 8 ist: %d\n", ergebnis);
    ergebnis = vielmax(4, 105, 77, 3, 54);
    printf("Das Maximum der Zahlen 105, 77, 3, 54 ist: %d\n", ergebnis);

}   