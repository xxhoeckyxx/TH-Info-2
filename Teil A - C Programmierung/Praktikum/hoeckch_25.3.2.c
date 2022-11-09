/*----- nulleins.c --------------------------------------------------------
 Description: Aufgabe 25.3.2 - Zusammenhänge zwischen Arrays und Zeigern
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 3-November-2022
-------------------------------------------------------------------------*/

/*  Aufgabe: 
Erstellen Sie ein Programm nulleins.c, das zunächst eine zufällige Folge von Nullen und Einsen erzeugt. 
Diese Folge soll dann in weiteren Schritten wie folgt komprimiert werden: 
Aus zwei gleiche aufeinanderfolgende Ziffern wird eine 0 und aus zwei unterschiedliche aufeinanderfolgende 
Ziffern wird eine 1. Diese Schritte werden solange wiederholt, bis nur noch eine Ziffer übrigbleibt. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int input_fkt(int var1)
{
    int pruefe, korrektur;
    do                                                      /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Leange der 0/1-Folge (max. 1000): ");       /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%d", &var1);                        /*  Einlesen der Zahl                                               */
        fflush(stdin);
        if (pruefe != 1 || var1 < 0 || var1 > 1000)         /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n");
        }
    } while (pruefe != 1 || var1 < 0 || var1 > 1000);       /*  Pruefbedingung                                                  */
    korrektur = var1 - 1;                                   /*  Damit bei 0 das Zeahlen angefangen wird                         */
    return korrektur;
}

int array_fuellen(int *array, int groesse, int input)
{
    for(int i = 0; i <= input; i++)
    {
        array[i] = rand() % 2;
        printf("I = %d; %d\n", i, array[i]);
    }
}

int array_vergleichen(int *array, int groesse, int input)
{
    for(int j = 0, k = 1, l = 0; k <= input; j = j + 2, k = k + 2, l++)
    {
        if(array[j] == array[k])
        {
            array[j-l] = 0;
        } else {
            array[j-l] = 1;
        }
    }
}

int main()
{
    srand(time(NULL));
    int array1[1000],
        input = 0,
        test = 1;

    input = input_fkt(input);
    
    if(test == 1)
    {
        input = 3;
        array1[0] = 0;
        array1[1] = 0;
        array1[2] = 1;
        array1[3] = 0;
    }

    printf("Array: ");

    printf("Array: ");
    for (int i = 0; i <= input/2; i++)
    {
        //array1[i] = rand() % 2;
        printf("I = %d; %d\n", i, array1[i]);
    }
    return 0;
}