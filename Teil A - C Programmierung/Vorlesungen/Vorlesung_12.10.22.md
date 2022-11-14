# Funktionen

## Rekursive Funktionen
 > **Definition:** Sichselbst aufrufende Funktionen, mit trivialfall in dem die Funktion einen Rückgabewert zurück gibt

Bevorzugt aber Schleifen nutzen (itterative Funktionen), da rekursive Funktion einen neuen Funktionsaufruf bekommen bei jeder Ausführung => Programm wartet.

Im Praktikum rekursiv bei Dual oder Binären zahlen hilfreich

## Zeiger auf Funktionen

```C
/*-----berech-----*/
float berech(float rad, float (*welch_funktion)(float rad) {
    return(rad* (*welch_funktion)(rad));
}
/*-----zyl_vol----*/
float zyl_vol(float r) {
    return(r*PI);
}
/*-----kug_vol----*/
float kug_vol(float r) {
    return(r*r*4/3*PI);
}
```
Aufruf:

```C
printf(" ---> Volumen (Zylinder): %f\n" berech(radius, zyl_vol)); 
```

Fehlerquellen:

```C
float *welch_funktion   // gibt Zeiger auf den float-Wert an die aufrufende Funktion zurück
float (*welch_funktion) // gibt den Zeiger auf die Funktion zurück 
```

> Zeiger übergeben die Anfangsaddressen von Funktionen, also Springt das Programm an die Anfangsaddresse dieser Funktion und führ diese aus.

## Strings- und `char`-Zeiger

Ein Array ist impliziter Zeiger auf eine Addresse => ist schon ein Zeiger, allerdings mit initalisiertem Speicher für definiertem Platzbedarf.
Ein Zeiger speichert nur die Anfangsaddresse ohne danach definiertem Speicher, die größe des Zeiger entspricht der Addressengröße.

Strings enden immer mit dem NULL-Charakter, ohne NULL ist es kein String mehr (\0).
In C können für Strings keine Operatoren (+, -, *, /) benutzt werden. 

Funktionen für Strings sind in  ` #include <string.h> `

**String Tokenicer**
```C
char *strtok(char *kett1, const char *kett2);
```
alle Zeichen die in dem zweiten String drin stehen dienen als Bruchstellen für den ersten String.
