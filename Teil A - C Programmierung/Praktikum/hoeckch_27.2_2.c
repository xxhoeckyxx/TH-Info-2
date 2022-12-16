/*----- strilist.c --------------------------------------------------------
 Description: Aufgabe 27.1 - Strichliste
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 15-Dezember-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int_input_fkt(char *input)
{
    int check = 0;
    printf("Gib eine Zahlenfolge ein: \n");    /*  Text zum einlesen der Zahl                                      */
    for(int i = 0; input[i] != EOF; i++)
    {
        if(i >= 5)
        {
            input = (char *)malloc((i)*sizeof(char));
        }
        check = fgetc(input[i]);
        if(check != 1)
        {
            printf("Erneut Versuchen");
        }
        
        fflush(stdin);
    }
    printf("Die Zahlenfolge ist &d\n", *input);
}

void frequency_evaluation(int *frequency, char *input)
{
    
}

void tally_array(int *size, int *frequency, char *array)
{
    //printf("Speicher reservieren");
    array = (char *)malloc((frequency[*size]) * sizeof(char));
    memset(array, '|', frequency[*size]);

    printf("&d: %s\n", *size, array);

    //printf("&d %s, &d\n", frequency[*size], array, *size);

    free(array);
}

void programm_call(char *input, int *frequency, char *array, int *choice_input_fkt)
{
    
    frequency_evaluation(frequency, input);
    for(int i = 0; i <= 9; i++)
    {
        //printf("frequency[&d] = &d\n", i, frequency[i]);
        if(frequency[i] != 0)
        {
            tally_array(&i, frequency, array);
        }
    }
    //printf("--------------------------\n");
}

int main()
{
    int  frequency[10] = {0},
         choice_input_fkt = 0;
    char input[100] = {0},
         *array = NULL;

    programm_call(input, frequency, array, &choice_input_fkt);

    return 0;
}