/*----- strilist.c --------------------------------------------------------
 Description: Aufgabe 27.1 - Strichliste
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 15-Dezember-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void check_fkt(char *input, int *counter, int check)
{
    if(check <= 9)
    {
        check++;
        if(input[*counter] != check)
        {
            printf("Dieses Zeichen wird entfernt - bitte Erneut versuchen\n");
            *counter--;
        } else {
            check_fkt(input, counter, check);
        }
    }
}
*/

void array_input_fkt(char *input)
{
    printf("Gib eine Zahlenfolge ein: \n");    /*  Text zum einlesen der Zahl                                      */
    for(int i = 0; input[i] != EOF; i++)
    {
        int check = 0;
        if(i >= 5)
        {
            input = (char *)malloc((i)*sizeof(char));
        }
        input[i] = fgetc(stdin);
        //check_fkt(input[i], &i, &check);
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
    array_input_fkt(input);
    frequency_evaluation(frequency, input);
    for(int i = 0; i <= 9; i++)
    {
        //printf("frequency[&d] = &d\n", i, frequency[i]);
        if(frequency[i] != 0)
        {
            tally_array(&i, frequency, array);
        }
    }
    free(*input);
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