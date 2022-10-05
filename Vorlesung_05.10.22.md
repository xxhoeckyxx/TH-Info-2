# Elliipsen-Prototypen

`printf()` ist ein Ellipsen-Prototyp:
```C
#include <stdio.h>
#include <stdarg.h>

int printf(const char *format, ...)
```
Versuch:
```C
#include <stdarg.h>

float viel_add1(int n, ...){
    va_list arg_zeiger;
    float   wert, ergeb=0;
    int     i;
    va_start(arg_zeiger, n); // Zugriff auf 1.Argument (noch benamt)
    for  (i=1; i<=n; i)
}
```
# Funktionen

## Neuheiten in C99

- Inline Funktionen
- Der vordefinierte Name `__func__`
- Keine Unterstützung von implizitem `int`
- 

## Rekursive Funktionen

rekursive (sich selbstaufrufende) Funktionen sind langsamer als itterative (Schleifen) Funktionen aber auch kürzer zu schreiben. 