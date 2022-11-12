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

void print_table(int *leange, int *anzahl)
{
    int i = 0;
    printf("Wortleange\t|\tAnzahl\t|\n");
    printf("----------------+---------------|\n");
    do
    {
        printf("\t%d\t|\t%d\t|\n", leange[i], anzahl[i]);
        i++;
    } while (anzahl[i] > 0);
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
        while((strings[i] = fgetc(fp)) != EOF)                                      /*  komplette Datei zeichenweise einlesen  */
        {
            //printf("%c ", strings[i]);                                            /*  Debug   */
            i++;
            //fflush(stdin);
        }
        fclose(fp);
    }
    *stellen = i;                                                                   /*  Debug   */
}

void wortleange_ermitteln_aus_Eingabe(char *strings, int *leangen_array)
{
    int array_speicher = 0,
        leange = 0;
    char *abschnitt = NULL,
         *neachsterAbschnitt = NULL;

    //printf("Anfang\n");                                                           /*  Debug   */

    abschnitt = strtok_r(strings, " ", &neachsterAbschnitt);
    leange = strlen(abschnitt);
    //printf("Leange vor while: %d\n", leange);                                     /*  Debug   */
    leangen_array[array_speicher] = leange;
    array_speicher++;
    //printf("%d.Array_Speicherstelle: %s\n", array_speicher, abschnitt);           /*  Debug   */

    while(neachsterAbschnitt != NULL)
    {
        abschnitt = strtok_r(NULL, " ", &neachsterAbschnitt);
        leange = strlen(abschnitt);
        //printf("Leange in while: %d\n", leange);                                  /*  Debug   */
        leangen_array[array_speicher] = leange;
        array_speicher++;
        //printf("%d.Array_Speicherstelle: %s\n", array_speicher, abschnitt);       /*  Debug   */
    }
    //printf("Ende\n");                                                             /*  Debug   */
}

void hueafigkeit_ermitteln(int *leangen_array, int *counter_array)
{
    int wortleange = 1,
        counter = 0,
        array_speicher = 0,
        array_zeahler = 0;

    while(leangen_array[array_speicher] != 0)
    {
        printf("%d.Speicherstelle_LeangenArray: %d\n", array_speicher, leangen_array[array_speicher]);
        if(wortleange == leangen_array[array_speicher])
        {
            counter++;
            printf("Counter: %d\n", counter);
            array_speicher++;
            printf("Array_Speicher: %d\n", array_speicher);
            array_zeahler++;
            counter_array[array_speicher] = counter;
            printf("%d.Speicherstelle_CounterArray: %d\n", array_speicher, counter_array[array_speicher]);
        }
        else
        {
            wortleange++;
            printf("Wortleange: %d\n", wortleange);
            array_speicher = 0;
            counter = 0;
        }
    }  
}

int main()
{
    FILE *file;
    char string[10000] = {0};
    int leangen_array[10000] = {1},
        counter_array[10000] = {0},
        buchstaben = 0;

    einlesen_text(file, string, &buchstaben);
    //printf("Stelle 290; %c\n", string[290]);                                      /*  Debug      */
    wortleange_ermitteln_aus_Eingabe(string, leangen_array);
    hueafigkeit_ermitteln(leangen_array, counter_array);

    //printf("Zahlen Array: %d\n", *leangen_array);                                 /*  Debug      */
    //printf("Zeichen im Text: %d\n", buchstaben);                                  /*  Debug      */
    //printf("%s \n", string);                                                      /*  Debug      */

    print_table(leangen_array, counter_array);
    return 0;
}