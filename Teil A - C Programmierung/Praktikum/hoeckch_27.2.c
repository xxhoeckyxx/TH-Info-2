/*----- strilist.c --------------------------------------------------------
 Description: Aufgabe 27.1 - Strichliste
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 09-Dezember-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_fkt(int *input)
{
    int pruefe = 1;
    do /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Gib eine Zahlenfolge ein: \n"); /*  Text zum einlesen der Zahl                                      */
        *input = getchar();               /*  Einlesen der Zahl                                               */
        //fflush(stdin);
        if (pruefe != 1) /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n\n");
        }
    } while (pruefe != 1); /*  Pruefbedingung                                                  */
    printf("Die Zahl ist %d\n", *input);
}

int main()
{
    int size = 0, 
        input = 0;
    char *array;

    printf("Array-Groesse eingeben: ");
    scanf("%d", &size);

    // Speicher reservieren
    array = (char *)malloc(size * sizeof(char));
    array[size] = ("|");

    if (array != NULL)
    {
        printf("\nSpeicher ist reserviert - Groesse ist %d\n", size);
    }
    else
    {
        printf("\nKein freier Speicher vorhanden.\n");
    }

    //input_fkt(&input);
    printf("%s", array);

    return 0;
}