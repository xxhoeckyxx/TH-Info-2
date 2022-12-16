
# Informatik 2 Praktikum

## Aufgabe 27.2

    Erstellen Sie ein Programm strilist.c, das Ziffernfolgen (bis EOF) einliest und dann eine Strichliste über die Häufigkeit der einzelnen Ziffern ausgibt. Die einzelnen Strichlisten sind dabei als String zu speichern, der immer dynamisch zu erweitern ist. Zu Übungszwecken sollte dabei aber nicht realloc () verwendet werden, sondern der entsprechende Speicherplatz erst mit free () freigegeben werden, bevor mit malloc () seine neue Größe allokiert wird.

- [x] Array anlegen [input] -> Größe unbestimmt (mindestens 10 Stellen) 
- [ ] Input (mit getchar) in das Array schreiben (beliebig lange Zahl) + Array dynamisch erweitern ~~(realloc ?)~~ __(muss malloc sein !)__, falls die Größe nicht reicht

        Funktioniert mehr oder weniger ... 

- [ ] Bei jeder Eingabe prüfen, ob es sich um eine Zahl handelt [check_fkt]

        Wie funktioniert die check_fkt? -> Prüfen ob die Eingabe eine Zahl ist, aber wie?

- [x] Abbruchbedingung ist EOF - wenn EOF kommt wird aufgehört einzulesen [if "char" != EOF]
- [x] Array erstellen, dass die Häufigkeit ermittelt [frequency] (hat feste Größe, da nur Ziffern von 1 bis 9 -> 10)
- [x] Funktion erstellen die die Häufigkeit ermittelt und in das "Häufigkeits-Array" einträgt
- [x] Funktion erstellen die die Häufigkeit als Strichliste ausgibt (mit memset)


## Aufgabe 28.2.2

- [ ] Überlegen ...
- [ ] Anfangen ...
