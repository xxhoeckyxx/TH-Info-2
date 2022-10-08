# Elliipsen-Prototypen

`printf()` ist ein Ellipsen-Prototyp:
```C
#include <stdio.h>
#include <stdarg.h>     // Wichtig für Ellipsen-Prototypen

int printf(const char *format, ...)
```
Versuch:
```C
#include <stdarg.h>

float viel_add1(int n, ...){
    va_list arg_zeiger;
    float   wert, ergeb=0;
    int     i;
    va_start(arg_zeiger, n);    // Zugriff auf 1.Argument (noch benamt)
    for  (i=1; i<=n; i++)       // Lesen der restlichen Argumente (unbenamt)
    {
        wert = va_arg(arg_zeiger, double);
        ergeb += wert;
    }
    va_end(arg_zeiger);     // Stack wieder in sauberen Zustand versetzen
    return(ergeb);
}
```
> Fallgruben 
> - `char`- und `short`-Parameter werden beim Aufruf in `int` und `float`-Parameter in `double` umgewandelt
> - Argumente müssen dem erwarteten Datentyp entsprechen
> ```C 
> summe = viel_add2(-10.5, 300, 20.5, -50.0, 10.3, 0.0);
> ```
> - Die `300` hat den falschen Datentyp 

# Funktionen

## Neuheiten in C99

- Inline Funktionen
- Der vordefinierte Name `__func__`
- Keine Unterstützung von implizitem `int`
- Einschränkungen bei `return`

## Rekursive Funktionen

rekursive _(sich selbstaufrufende)_ Funktionen sind langsamer als itterative _(Schleifen)_ Funktionen aber auch kürzer zu schreiben. Jedoch sollte auf Grund von Speicherbedarf und Speicherbelegung auf die itterative Methode zurückgegriffen werden _(braucht weniger Arbeitsspeicher => schneller Ausführbar)_. 

Typische Anwendungen für Rekursion

- Rekursion bei Baumstrukturen
- Rekursion bei rekursiv definierten mathematsichen Funktionen 
- Rekursion bei Fraktalen (Lindenmayer-Systeme)
