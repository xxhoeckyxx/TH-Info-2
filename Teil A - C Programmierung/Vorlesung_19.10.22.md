## Strings und `char-` Zeiger
___
memcpy:

```C
void *memcpy(void *ziel, const void *quelle);
```

memmove

memset

memcmp

memchr

- Eine Umwandlung von 

strtol

atoi

atol

sscanf

sprintf

fgets:

```C
char *fgets(char *s, int size, FILE *stream);
```
- fgets() liest höchstens size -1 Zeichen von stream ein (für Standarteingabe stdin anzugeben) und speichert sie in dem Puffer, auf

Bsp Programm zu Charmanipulation mit pointer:
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *stringAsPtr1 = "Ich bin eine Zeichenkette";
    char stringAsArray[] = "Ich bin ebenfalls eine Zeichenkette";
    char *stringAsPtr2 = stringAsArray;

    stringAsArray[1] =  'W';

    printf("%s\n%s\n%s", strinngAsPtr1, stringAsArray, stringAsPtr2);

    stringAsPtr1[5] = 'w';

    printf("\nNach Bearbeitung:\n");
    printf("%s\n%s\n%s", stringAsPtr1, stringAsArray, stringAsPtr2);

    return 0;
}
```


Umwandlungen von String into:
long --> strtol()
	long int strtol(const char *zeichk, char **end_zeig, int basis);

float
int --> atoi()
long --> atol()
long long --> atoll()

String into numerische Werte --> scanf()
	int scanf(const char *zeichk, const char *format, ...);
Besonderheiten bei scanf:
	- scanf liest nur bis zum ersten white space --> bei langer chain muss man explizit sagen, wie viel eingelesen werden soll
	- dauer noetig ist eine Formatangabe mit %[^...] sowie dann ein pointer auf die Startadresse, die eingelesen wird
	  (pointer ist immer gleich gross, entweder 4 oder 8 Byte aber an dieser Stelle 8 Byte)
	
Numerische Werte into String --> sprintf()


# Zeiger und Arrays

## Array-Initialisierung

Speicher Initialisierung 

- Werteliste in geschweifte Klammern eingebettet werden
    ```C
    int investieren[3][4]{

    };
    ```
- Werte in Matrixform in Geschweiften Klammern eingebettet
    ```C
    int investieren[3][4]{
        {},
        {},
        {}
    };
    ```

## Lokale Arrays variabler Länge (C99)
```C
void funk(int dim1, int dim2)
{
    int tabelle[dim1][dim2]; // zwiedimensionales Array variabler Leange
}
```
**Bei uns VERBOTEN an der TH**