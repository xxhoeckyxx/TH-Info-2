/*----- wortlen.c --------------------------------------------------------
 Description: Aufgabe 24.4.5 - Strings und char-Zeiger Teil2
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 11-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Erstellen Sie ein Pragramm wortlen.c, das eine Häufigkeitsverteilung über die Wortlängen in 
einem Text ausgibt. Wendet man dieses Programm z.B.auf die Programmdatei wortlen.c selbst
an: wortlen <wortlen.c
*/

void print_table(int leange, int anzahl)
{
    printf("Wortleange\t|\tAnzahl\t|\n");
    printf("----------------+---------------|\n");
    do
    {
        printf("\t%d\t|\t%d\t|\n", leange, anzahl);
    } while (anzahl < 0);
}

void einlesen_text(FILE *fp, char *strings, int *stellen)
{
    int i = *stellen;
    fp = fopen("../hoeckch_25.4.5.c", "r");
    if(fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }
    else
    {
        while((strings[i] = fgetc(fp)) != EOF)                  /*  komplette Datei zeichenweise einlesen  */
        {
            //printf("%c ", strings[i]);                        /*  Debug   */
            i++;
            fflush(stdin);
        }
        fclose(fp);
    }
    *stellen = i;                                               /*  Debug   */
}

void wortleange_ermitteln(char *strings, int *leange)
{
    *leange = strlen(strings);
}

void string_teilen(char *strings, int *wortanzahl, int *leange)
{
    int i = *wortanzahl;
    char *abschnitt = NULL;
    char *neachsterAbschnitt = NULL;

    abschnitt = strtok_r(strings, " ", &neachsterAbschnitt);

    while(abschnitt != NULL)
    {
        abschnitt = strtok_r(NULL, " ", &neachsterAbschnitt);
        i++;
        wortleange_ermitteln(abschnitt, leange);
    }
    *wortanzahl = i;
}

int main()
{
    FILE *file;
    char string[10000];
    int leange = 0, 
        anzahl = 0,
        komplette_wortanzahl = 0,
        buchstaben = 0;

    einlesen_text(file, string, &buchstaben);
    string_teilen(string, &komplette_wortanzahl, &leange);

    printf("Zeichen im Text: %d\n", buchstaben);                /*  Debug   */
    printf("%s \n", string);                                    /*  Debug   */

    print_table(leange, anzahl);
    return 0;
}