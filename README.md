Stundenplan
===========

Stundenplan in Qt

![Bild](https://raw.githubusercontent.com/MassiveProgramming/Stundenplan/master/Example/Example.png "ScreenShot")

Die Daten werden in ~/.stundenplan/data gespeichert. Der aufbau:

* /even
	* Hier liegen die Daten für gerade Wochen
	
* /odd
	* Hier liegen die Daten für ungerade Wochen
	
Die Dateien werden wie folgt benannt:

	1 -> Montag
	2 -> Dienstag
	3 -> Mittwoch
	4 -> Donnerstag
	5 -> Freitag
	
Der Aufbau der Dateien:

	NameDesTages {
	
		Fach,Lehrer,Raum;
		
	}

Der Name des Tages wird ignoriert und dient nur zur Lesbarkeit. Er darf aber nicht ausgelassen werden!
