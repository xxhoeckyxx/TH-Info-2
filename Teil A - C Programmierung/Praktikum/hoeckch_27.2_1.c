/*----- strilist.c --------------------------------------------------------
 Description: Aufgabe 27.1 - Strichliste
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 15-Dezember-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ulong unsigned long long int

void ulong_input_fkt(ulong *input)
{
    ulong check = 0;
    do                                             /*  Schleife um die Eingabe zu ueberpruefen                         */
    {
        printf("Gib eine Zahlenfolge ein: \n");    /*  Text zum einlesen der Zahl                                      */
        check = scanf("%llu", input);              /*  Einlesen der Zahl                                               */
        fflush(stdin);
        if (check != 1)                            /*  Wird solange wiederholt bis der Benutzer das richtige eingibt   */
        {
            printf("Erneut Versuchen!\n\n");
        }
    } while (check != 1);                          /*  Pruefbedingung                                                  */
    printf("Die Zahlenfolge ist %llu\n", *input);
}

// string_input_fkt funktioniert noch nicht - Zahlen die den Integerwert übersteigen werden nicht unterstützt !!

void string_input_fkt(ulong *input)
{
    printf("Gib eine Zahlenfolge ein: \n");         /*  Text zum einlesen der Zahl                                      */
    char *input_array = NULL,
         *test_pointer = "1234";
    input_array = (char *)malloc(54 * sizeof(char));
    //ulong check = 0;
    fgets(input_array, 54, stdin);
    printf("Input_Array:    %s\n", input_array);
    *input = atoi(input_array);
    printf("*Input:         %llu\n", *input);
}

void frequency_evaluation(ulong *frequency, ulong *input)
{
    while(*input > 0)
    {
        frequency[*input%10] = frequency[*input%10] + 1;
        //printf("frequency[%llu]      :   %llu\n", *input%10, frequency[*input%10]);
        *input = *input/10;
        //printf("*Input              :   %llu\n", *input);
    }
    //printf("--------------------------\n");
}

void tally_array(ulong *size, ulong *input, ulong *frequency, char *array)
{
    //printf("Speicher reservieren");
    array = (char *)malloc((frequency[*size]) * sizeof(char));
    memset(array, '|', frequency[*size]);

    printf("%llu: %s\n", *size, array);

    //printf("%llu %s, %llu\n", frequency[*size], array, *size);

    free(array);
}

void programm_call(ulong *input, ulong *frequency, char *array, ulong *choice_input_fkt)
{
    if(*choice_input_fkt == 1)
    {
        string_input_fkt(input);
    } else {
        ulong_input_fkt(input);
    }

    frequency_evaluation(frequency, input);
    for(ulong i = 0; i <= 9; i++)
    {
        //printf("frequency[%llu] = %llu\n", i, frequency[i]);
        if(frequency[i] != 0)
        {
            tally_array(&i, input, frequency, array);
        }
    }
    //printf("--------------------------\n");
}

int main()
{
    ulong input = 0,
         frequency[10] = {0},
         choice_input_fkt = 0;
    /*ulong  test = 01234512345,
         test_array[10] = {0};*/
    char *array = NULL;

    //programm_call(&test, test_array, array);
    programm_call(&input, frequency, array, &choice_input_fkt);

    return 0;
}