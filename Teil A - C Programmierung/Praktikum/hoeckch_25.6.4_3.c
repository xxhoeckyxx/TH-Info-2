/*----- farben.c --------------------------------------------------------
 Description: Aufgabe 25.6.4 - Mischen von Farben
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 14-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int string_vergleichen(char *farbe1, char *farbe2)
{
    int result;
    result = strcmp(farbe1, farbe2);
    //printf("\n%d\n", result);
    return result;
}

int farbe_pruefen(int pruefe, char *input)
{
    if(pruefe != 0)
    {
        pruefe = string_vergleichen(input, "gruen");
        if(pruefe != 0)
        {
            pruefe = string_vergleichen(input, "rot");
            if(pruefe != 0)
            {
                pruefe = string_vergleichen(input, "violett");
            }
        }
    }
    return pruefe;
}

void input_fkt(char *anzahl_grundfarbe, char *input)
{
    int pruefe,
        farbe_ok = 0;
    do                                                  /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("%s Grundfarbe : ", anzahl_grundfarbe);  /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%s", input);                    /*  Einlesen der Zahl                                               */
        fflush(stdin);
        *input = tolower(*input);                       /*  Imput to lower - auch Große Anfangsbuchstaben moeglich          */
        farbe_ok = farbe_pruefen(farbe_ok, input);      /*  Pruefe ob es eine Farbe ist und welche                          */
        //printf("Farbe OK? %d\n", farbe_ok);

        // printf("Pruefe %d\n\n", pruefe);             /*  Debug                                                           */
        if (pruefe != 1 || farbe_ok != 0)               /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n\n");
        }
    } while (pruefe != 1 || farbe_ok != 0);             /*  Pruefbedingung                                                  */
    printf("Die %s Farbe ist %s\n", anzahl_grundfarbe, input);
}

void mischfarbe_ausgeben(char *farbe)
{
    printf("Ihre Mischfarbe ist %s!\n", farbe);
}

void farben_mischen(char *farbe1, char *farbe2)
{
    int pruefen_farbe1 = 1,
        pruefen_farbe2 = 1,
        i, 
        j;
    char *mischfarben[3][3] =   {{"gruen", "gelb", "blau"},
                                {"gelb", "rot", "purpur"},
                                {"blau", "purpur", "violett"}};

    pruefen_farbe1 = string_vergleichen(farbe1, farbe2);
    if(pruefen_farbe1 == 0)
    {
        mischfarbe_ausgeben(farbe1);
    }
    else
    {
        //printf("Pruefen vor `for` %d\n", pruefen_farbe1);
        for(i= 0; pruefen_farbe1 != 0; i++)
        {
            pruefen_farbe1 = string_vergleichen(farbe1, mischfarben[i][i]);
            //printf("Pruefen = %d\n", pruefen_farbe1); 
            //mischfarbe_ausgeben(mischfarben[i][i]);
        }
        for(j= 0; pruefen_farbe2 != 0; j++)
        {
            pruefen_farbe2 = string_vergleichen(farbe2, mischfarben[j][j]);
            //printf("Pruefen = %d\n", pruefen_farbe2); 
            //mischfarbe_ausgeben(mischfarben[j][j]);
        }
        i--;
        j--;
        //printf("I = %d, J = %d\n", i, j);
        mischfarbe_ausgeben(mischfarben[i][j]);
    }
}

int main()
{
    char speicher[2][8],
         funktionsaufruf[2][7] = {"Erste", "Zweite"};

    input_fkt(funktionsaufruf[0], speicher[0]);
    input_fkt(funktionsaufruf[1], speicher[1]);
    farben_mischen(speicher[0], speicher[1]);
    return 0;
}