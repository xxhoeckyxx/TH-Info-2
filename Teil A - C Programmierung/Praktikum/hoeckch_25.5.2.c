/*----- wochetag.c --------------------------------------------------------
 Description: Aufgabe 25.5.2 - Wochentag zu bestimmten Datum
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 14-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**     Pseudocode: 
        jh_koeff [4] = ( 4, 2, 0, 5 )
        monat_koeff[12] = ( 2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0 )

        Eingabe: tag, monat, jahr (wie z.B. 2.11.1997)
        jh = Jahrhundert (vorderen beiden Ziffern der Jahreszahl)
        ja = Jahr im Jahrhundert (hinteren beiden Ziffern der Jahreszahl)

        if (monat > 2)
            schaltjahr = 0
        else
            if (jahr%400==0)
                schaltjahr = 1
            else
                if (jahr%100==0)
                    schaltjahr = 0
                else
                    if (jahr%4==0)
                        schaltiahr = 1
                    else
                        schaltjahr = 0

        wochentag = (tag+monat_koeff[monat-1]-schaltjahr+jh_koeff[jh%4) + ja + ja/4 ) %7
        Nr. in "wochentag' ist Wochentag: (0 = Sonntag, 1 = Montag, ..., 6 = Samstag)
        **/

void input_fkt(int *tag, int *monat, int *jahr, int *jh, int *ja)
{
    int pruefe;
    do                                                                      /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Gib das Datum ein (tt.mm.jjjj): ");                         /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%2d.%2d.%4d", tag, monat, jahr);                    /*  Einlesen der Zahl                                               */
        fflush(stdin);
        //printf("Pruefe %d\n\n", pruefe);                                    /*  Debug                                                           */
        if (pruefe != 3 || *tag > 31 || *monat > 12 || *jahr < 0)           /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n\n");
        }
    } while (pruefe != 3 || *tag > 31 || *monat > 12 || *jahr < 0);         /*  Pruefbedingung                                                  */
    *ja = *jahr % 100;
    //printf("%d Ja\n", *ja);
    *jh = (*jahr - *ja) / 100;
    //printf("%d Jh\n", *jh);
}

void schaltjahr_ermitteln(int *monat, int *jahr, int *schaltjahr)
{
    if (*monat > 2)
    {
        *schaltjahr = 0;
    } else
    {
        if (*jahr % 400 == 0)
        {
            *schaltjahr = 1;
        } else if (*jahr % 100 == 0)
        {
            *schaltjahr = 0;
        } else if (*jahr % 4 == 0)
        {
            *schaltjahr = 1;
        } else 
        {
            *schaltjahr = 0;
        }
    } 
}

void wochentag_ermitteln(int *tag, int *monat, int *ja, int *schaltjahr, int *jh, int *jh_koeff, int *monat_koeff, int *wochentag)
{
    *wochentag = (*tag + monat_koeff[*monat - 1] - *schaltjahr + jh_koeff[*jh % 4] + *ja + (*ja / 4) ) %7;
}

void print_fkt(char *wochentag, int * wochentag_suche, int *tag, int *monat, int *jh, int *jahr, int *schaltjahr)
{
    char *abschnitt = NULL,
         *naechsterAbschnitt = NULL;

    abschnitt = strtok_r(wochentag, ",", &naechsterAbschnitt);
    //printf("%d tag\t%d monat\t%d jh\t%d jahr\t%d schaltjahr\t%d wochentag", *tag, *monat, *jh, *jahr, *schaltjahr, *wochentag_suche);
    for(int i = *wochentag_suche; i > 0; i--)
    {
        abschnitt = strtok_r(NULL, ",", &naechsterAbschnitt);
    }
    printf("\n\nDas Datum %2d.%2d.%4d ist ein ", *tag, *monat, *jahr);
    printf("%s", abschnitt);
}

int main()
{
    int tag = 0,
        wochentag_suche = 0,
        monat = 0,
        jahr = 0,
        schaltjahr = 0,
        ja = 0,
        jh = 0,
        jh_koeff[4] = {4, 2, 0, 5},
        monat_koeff[12] = {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0};
    char wochentag[61]= {"Sonntag,Montag,Dienstag,Mittwoch,Donnerstag,Freitag,Samstag"};

    input_fkt(&tag, &monat, &jahr, &jh, &ja);
    schaltjahr_ermitteln(&monat, &jahr, &schaltjahr);
    wochentag_ermitteln(&tag, &monat, &ja, &schaltjahr, &jh, jh_koeff, monat_koeff, &wochentag_suche);
    print_fkt(wochentag, &wochentag_suche, &tag, &monat, &jh, &jahr, &schaltjahr);
}