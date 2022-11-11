/*----- bucstrei.c --------------------------------------------------------
 Description: Aufgabe 25.4.1 - Strings und char-Zeiger Teil1
     Project: Praktikum Informatik 2
      Author: hoeckch80619@th-nuernberg.de
        Date: 10-November-2022
-------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>


char string_einlesen(char *zeichenkette)
{
    fgets (zeichenkette, 1000, stdin);
    fflush (stdin);
    return *zeichenkette;
}

char zeichen_einlesen(char *loeschzeichen)
{
    *loeschzeichen = getchar();
    return *loeschzeichen;
}

void zeichen_loeschen(char zeichenkette[], char loeschzeichen)
{
    for(int i=0;i<1000;i++)
    {
        if(zeichenkette[i]==loeschzeichen)
        {
            zeichenkette[i]='0';
        } 
        else if(i==999)
        {
            printf("Ihre Neue Zeichenkette lautet:\n");
            for(int k=0; k<1000; k++)
            {
                if(zeichenkette[k] != '0')
                {
                    printf("%c",zeichenkette[k]);
                }
            }                
        }
    }
}


int main(){

    char zeichenkette[1001] = {0};
    char loeschzeichen ;

    printf("geben sie eine Zeichenkette von maximal 1000 zeichen ein.\n");

    string_einlesen(zeichenkette);

    printf("Ihre eingegebene Zeichenkette lautet:\n%s", zeichenkette);

    printf("welches Zeichen möchten Sie aus der Zeichenkette Löschen?\n");

    zeichen_einlesen(&loeschzeichen);

    printf("Ihr zeichen das zu löschen gilt lautet: %c\n",loeschzeichen);

    zeichen_loeschen(zeichenkette,loeschzeichen);

return 0;

}

