/*----- farben.c --------------------------------------------------------
 Description: Aufgabe 25.6.4 - Mischen von Farben
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 14-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_fkt(char *anzahl_grundfarbe, char *input)
{
  int pruefe;
  do                                                                                        /*  Schleife um die Eingabe zu ueberpruefen                         */
  {
    printf("%s Grundfarbe : ", *anzahl_grundfarbe);                                         /*  Text zum einlesen der Zahl                                      */
    pruefe = scanf("%s", input);                                                            /*  Einlesen der Zahl                                               */
    fflush(stdin);
    // printf("Pruefe %d\n\n", pruefe);                                                     /*  Debug                                                           */
    if (pruefe != 1 || *input != "Gruen" || *input != "Rot" || *input != "Violett" )        /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
    {
      printf("Erneut Versuchen!\n\n");
    }
  } while (pruefe != 1 || *input != "Gruen" || *input != "Rot" || *input != "Violett");     /*  Pruefbedingung                                                  */
}

void string_teilen(char *input)
{
  char *abschnitt[] = NULL,
       *naechsterAbschnitt[] = NULL;

       *input = strtok_r(input, ",", &naechsterAbschnitt);
}

void main()
{
  int farben_mischen[3][3] = {{1},{2},{3},
                              {2},{4},{5},
                              {3},{5},{6}};
  char farben[35] = {"Gruen,Gelb,Blau,Rot,Purpur,Violett"},
       anzahl_grundfarben[13] = {"Erste,Zweite"},
       input[8];

  string_teilen(anzahl_grundfarben);
  input_fkt(anzahl_grundfarben, input);

}