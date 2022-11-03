/*----- quersumm.c --------------------------------------------------------
 Description: Aufgabe 22.5.4 - Rekursive Funktionen
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 3-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>

int addQuersum(int zahl, int reverseOn)                         /* Zahl und ein Argument zum ausgeben der Rueckwertsfunktion wird uebergeben                */
{
    if(zahl >= 1)                                               /*  Ueberpruefen wie groß die Zahl noch ist                                                 */
    {
        int speicher = zahl%10;                                 /*  Einzelne Stellen aus der Zahl bekommen -> 12345 % 10 => 5                               */
        if(reverseOn == 1)
        {
            printf("%d", speicher);                             /*  Die Zahl rueckwerts ausgeben                                                            */
        }
        // printf("Debug 1: %d \n", zahl);                         /* -> Debug */
        // printf("Debug 2: %d \n", speicher);                     /* -> Debug */
        zahl = speicher + addQuersum(zahl/10, reverseOn);       /*  Stelle hinten entfernen, mit /10,  um weiter rekursiv mit Modulo durchgehen zu koennen  */
                                                                /*  und mit dem vorher abgelgetem Speicher addieren um das Ergebnis in Zahl zu speichern    */
    }
    return zahl;                                                /*  Zahl zurueck geben                                                                      */
}

int main()
{
    int input, quersum, reverse, pruefe;
    do                                                          /*  Schleife um die Eingabe zu ueberpruefen                                                 */
    {
        printf("Gib eine Dezimalzahl ein: ");                   /*  Text zum einlesen der Zahl                                                              */
        pruefe = scanf("%d", &input);                           /*  Einlesen der Zahl                                                                       */
        fflush(stdin);
        if (pruefe !=1 )                                        /*  Wird solange wiederholt bis der Benutzer das richtige eingibt                           */
        {
            printf("Erneut Versuchen!\n");
        }
    } while (pruefe != 1);                                      /*  Pruefbedingung                                                                          */

    quersum = addQuersum(input, 0);                             /*  Quersumme berechnen lassen                                                              */
    printf("Quersumme %d\n", quersum);                          /*  Quersumme ausgeben                                                                      */

    printf("Rueckwerts ");                                      /*  Rueckwerts ausgeben                                                                     */
    reverse = addQuersum(input, 1);
    
}