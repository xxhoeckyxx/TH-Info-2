/*----- nulleins.c --------------------------------------------------------
 Description: Aufgabe 25.3.2 - Zusammenhänge zwischen Arrays und Zeigern
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 9-November-2022
-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void input_fkt(int *var1)
{
    int pruefe, korrektur;
    do                                                      /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Leange der 0/1-Folge (max. 1000): ");       /*  Text zum einlesen der Zahl                                      */
        pruefe = scanf("%d", var1);                         /*  Einlesen der Zahl                                               */
        fflush(stdin);
        if (pruefe != 1 || (*var1) <= 0 || *var1 > 1000)    /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n");
        }
    } while (pruefe != 1 || *var1 <= 0 || *var1 > 1000);    /*  Pruefbedingung                                                  */
    (*var1)--;                                              /*  Damit bei 0 das Zeahlen angefangen wird                         */
}

void array_fuellen(int *array, int groesse)                 /*  Array wird befuellt                                             */
{
    for(int i = 0; i <= groesse; i++)                       /*  Einzelne Stellen des Arrays durchgehen                          */
    {
        array[i] = rand() % 2;                              /*  Stelle des Arrays befuellen                                     */
        //printf("Array %d: %d\n", i, array[i]);            /*  Debug */
    }
}

void print_array(int *array, int groesse)
{
    for (int i = 0; i <= groesse; i++)                      /*  Einzelne Stellen des Arrays durchgehen                          */
    {
        printf("%d", array[i]);                             /*  Stelle des Arrays ausgeben                                      */
        if((i + 1) % 2 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    //printf(" Groesse: %d\n", groesse);                      /*  Debug   */
}

void array_vergleichen(int *array, int *groesse)
{
    for(int j = 0, k = 1, l = 0; k <= *groesse; j = j + 2, k = k + 2, l++)
    {
        if(array[j] == array[k])
        {
            array[j - l] = 0;
        } else {
            array[j - l] = 1;
        }
    }
    *groesse = (*groesse)/2;
}

int main()
{
    srand(time(NULL));
    int array1[1000],
        input = 0;

    input_fkt(&input);
    //printf("Input: %d", input);       /*  Debug   */
    array_fuellen(array1, input);
    print_array(array1, input);
    do
    {
        array_vergleichen(array1, &input);
        print_array(array1, input);
    }while(input > 0);
    
    return 0;
}