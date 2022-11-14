/*----- wortlen.c --------------------------------------------------------
 Description: Aufgabe 25.4.5 - Strings und char-Zeiger Teil2
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

void input_fkt(int *var1)
{
    int pruefe, korrektur;
    do                                                                                  /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Wie möchten Sie Einlesen?\n\t1.)\tTabelle\n\t2.)\tText\n");             /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%d", var1);                                                     /*  Einlesen der Zahl                                               */
        fflush(stdin);
        if (pruefe != 1 || (*var1) < 1 || *var1 > 2)                                    /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n");
        }
    } while (pruefe != 1 || (*var1) < 1 || *var1 > 2);                                  /*  Pruefbedingung                                                  */
}

void print_table(int *laenge, int array_groeße, int *mode)
{
    int anzahl = 0;
    printf("\n\n\tWortlaenge\t|\tAnzahl\t|\n");
    printf("------------------------+---------------|\n");
    do
    {
        if(laenge[anzahl] != 0 && anzahl != 0)
        {
            if(*mode == 1)
            {
                printf("\t\t%d\t|\t%d\t|\n", anzahl, laenge[anzahl]);
            } else if(*mode == 2)
            {
                printf("Zahlenwert %d an der Stelle %d\n", laenge[anzahl], anzahl);
            }
        }
        anzahl++;
    } while (anzahl <= array_groeße);
}

void einlesen_text(FILE *fp, char *strings, int *stellen, int *modus)
{
    int i = *stellen;
    fp = fopen("../hoeckch_25.4.5.c", "r");
    if(fp == NULL)
    {
        printf("Datei konnte nicht geoeffnet werden.\n");
    }
    else
    {
        while((strings[i] = fgetc(fp)) != EOF)                                                      /*  komplette Datei zeichenweise einlesen  */
        {
            //printf("%c ", strings[i]);                                                              /*  Debug   */
            i++;
        }
        fclose(fp);
    }

    input_fkt(modus);

    *stellen = i;                                                                                   /*  Debug   */
}

void wortlaenge_ermitteln_aus_Eingabe(char *strings, int *laengen_array, int *max_wortlaenge)
{
    int counter = 0,
        laenge = 0,
        max_laenge = *max_wortlaenge;
    char *abschnitt = NULL,
         *naechsterAbschnitt = NULL;

    //printf("Anfang\n");                                                                             /*  Debug   */

    abschnitt = strtok_r(strings, " ", &naechsterAbschnitt);
    laenge = strlen(abschnitt);
    max_laenge = laenge;
    counter = laengen_array[laenge];
    counter++;
    laengen_array[laenge] = counter;
    //printf("Stelle: %s\n", abschnitt);                                                              /*  Debug   */
    //printf("Laenge vor while: %d\tCounter Wert: %d\n", laenge, counter);                            /*  Debug   */

    while(naechsterAbschnitt != NULL)
    {
        abschnitt = strtok_r(NULL, " ", &naechsterAbschnitt);
        laenge = strlen(abschnitt);
        if(max_laenge < laenge)
        {
            max_laenge = laenge;
        }
        counter = laengen_array[laenge];
        counter++;
        laengen_array[laenge] = counter;
        //printf("Stelle: %s\n", abschnitt);                                                          /*  Debug   */
        //printf("Laenge vor while: %d\tCounter Wert: %d\n", laenge, counter);                        /*  Debug   */
    }
    *max_wortlaenge = max_laenge;
    //printf("Maximale Wortlaenge: %d\nEnde\n", max_wortlaenge);                                      /*  Debug   */
}

int main()
{
    FILE *file;
    char string[10000] = {0};
    int laengen_array[10000] = {1},
        einlese_modus = 1,
        max_wortlaenge = 0;

    einlesen_text(file, string, &max_wortlaenge, &einlese_modus);
    wortlaenge_ermitteln_aus_Eingabe(string, laengen_array, &max_wortlaenge);

    for(int i = 0; i <= max_wortlaenge; i++)
    {
        if(laengen_array[i] != 0)
        {
            
        }
    }
    //printf("%s \n", string);                                                                        /*  Debug      */

    print_table(laengen_array, max_wortlaenge, &einlese_modus);
    return 0;
}