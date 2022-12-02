/*----- farben.c --------------------------------------------------------
 Description: Aufgabe 25.6.4 - Mischen von Farben
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 14-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**void string_teilen(char *input)
{
    char *abschnitt[] = NULL,
         *naechsterAbschnitt[] = NULL;

    *input = strtok_r(input, ",", &naechsterAbschnitt);
}**/

int string_vergleichen(char *input, char *farbe)
{
    int result;
    result = strcmp(input, farbe);
    return result;
}

void input_fkt(char *anzahl_grundfarbe, char *input)
{
    int pruefe;
    do /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("%s Grundfarbe : ", *anzahl_grundfarbe); /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%s", input);                    /*  Einlesen der Zahl                                               */
        fflush(stdin);
        
        // printf("Pruefe %d\n\n", pruefe);                                                     /*  Debug                                                           */
        if (pruefe != 1 || string_vergleichen(input, "gruen") || string_vergleichen(input, "rot") || string_vergleichen(input, "violett")) /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n\n");
        }
    } while (pruefe != 1 || string_vergleichen(input, "gruen") || string_vergleichen(input, "rot") || string_vergleichen(input, "violett")); /*  Pruefbedingung                                                  */
}

int main()
{
    int gruen = 1,
        rot = 2,
        violett = 3,
        gelb = 4,
        blau = 5,
        purpur = 6;

    char speicher[8],
         funktionsaufruf[2][7] = {"Erste", "Zweite"};

    input_fkt(funktionsaufruf, speicher);
    return 0;
}