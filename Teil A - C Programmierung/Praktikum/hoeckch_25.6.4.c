/*----- farben.c --------------------------------------------------------
 Description: Aufgabe 25.6.4 - Mischen von Farben
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 15-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_fkt(char *anzahl_grundfarbe, char *input, char *vorgegebene_farben, int funktions_zaehler)
{
  int pruefe,
      farben_pruefe = 1,
      farben_zaehler = 0;
  do                                                                                        /*  Schleife um die Eingabe zu ueberpruefen                         */
  {
    printf("%s Grundfarbe : ", &anzahl_grundfarbe[funktions_zaehler]);                      /*  Text zum einlesen der Zahl                                      */
    pruefe = scanf("%s", input);                                                            /*  Einlesen der Zahl                                               */
    do
    {
      farben_pruefe = strcmp(input, &vorgegebene_farben[farben_zaehler]);
      printf("Farben pruefen: %d\nInput: %s\nVorgegebene Farben: %s\n", farben_pruefe, input, &vorgegebene_farben[farben_zaehler]);
      printf("Farben zaehler: %d\n", farben_zaehler);
      farben_zaehler++;
    } while(farben_zaehler != 3);
    farben_zaehler = 0;
    fflush(stdin);
    // printf("Pruefe %d\n\n", pruefe);                                                     /*  Debug                                                           */
    if (pruefe != 1 || farben_pruefe != 0)                                                  /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
    {
      printf("Erneut Versuchen!\n\n");
    }
  } while (pruefe != 1 || farben_pruefe != 0);                                              /*  Pruefbedingung                                                  */
}

int main()
{
  char *farben_mischen[4][4] = {{   NULL,      "Gruen",    "Rot",    "Violett",   }, 
                                {   "Gruen",   "Gruen",    "Gelb",   "Blau",      },
                                {   "Rot",     "Gelb",     "Rot",    "Purpur"     },
                                {   "Violett", "Blau",     "Purpur", "Violett"    }},
       *anzahl_grundfarben[2] = {"Erste", "Zweite"},
       *vorgegebene_farben[3] = {"Rot", "Gruen", "Violett"},
       input[8];

  input_fkt(*anzahl_grundfarben, input, *vorgegebene_farben, 0);
  input_fkt(*anzahl_grundfarben, input, *vorgegebene_farben, 1);
}