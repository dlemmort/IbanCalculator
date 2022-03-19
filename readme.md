# IbanCalculator

##De m-toets:
Bankrekeningnummers maken gebruik van een checksum systeem, dit betekent dat niet elk 9-cijferig
nummer een geldig bankrekeningnummer is. Om te testen of een rekeningnummer geldig is
gebruiken we een aangepaste 11-proef:
In de 11-proef worden alle cijfers van het rekeningnummer opgeteld met een gewicht op
basis van hun positie. Daarna wordt gecontroleerd of het cijfer deelbaar is door 11. Het laatste getal
wordt vermenigvuldigd met 1, het een-voor-laatste met 2, enzovoort. Een voorbeeld met het
bankrekeningnummer 23.12.43.138:

2*9 + 3*8 + 1* 7 + 2 * 6 + 4 * 5 + 3 * 4 + 1 * 3 + 3 * 2 + 8 * 1 = 110 = 10 * 11

In de m-proef moet de uiteindelijke som dus een veelvoud van m zijn (dus niet altijd 11). Let op dat
een bankrekeningnummer niet per se uit 9 cijfers hoeft te bestaan.

##Invoer:
Je moet bij deze opdracht een programma schrijven dat in- en uitvoer via de console doet. Het
programma moet vragen om invoer. De invoer bestaat uit 6 getallen:
1. Een integer b met 0 ≤ 𝑏 ≤ 2
   31 − 1, de inclusieve ondergrens van het zoekbereik.
2. Een integer e met 𝑏 < 𝑒 ≤ 2
   31 − 1, de exclusieve bovengrens van het zoekbereik.
3. Een integer m met 1 ≤ 𝑚 ≤ 256, de modulus die gebruikt wordt in de m-proef.
4. Een integer p met 1 ≤ 𝑝 ≤ 256, het aantal threads dat je programma moet gebruiken om te
   rekenen.
5. Een integer u, de programmamodus die opgestart moet worden: 0 staat voor telmodus, 1
   voor lijstmodus en 2 voor zoekmodus.
6. Een optioneel getal s die alleen gebruikt wordt bij de zoekmodus.
   Locking:
   Het programma moet met meerdere threads tegelijk kunnen zoeken. De gehele range moet eerlijk
   verdeeld worden over de verschillende threads, zonder gaten of overlap. Als het bereik niet deelbaar
   is door het aantal threads mag het verschil tussen het aantal rekeningnummers dat iedere thread
   bekijkt maximaal 1 zijn (zo eerlijk mogelijk).

##Programmamodus:
Afhankelijk van het getal u, moet het programma verschillende taken kunnen uitvoeren:
###u = 0 - Telmodus
In deze modus moet je het aantal gehele getallen x met 𝑏 ≤ 𝑥 < 𝑒 tellen dat aan de m-proef
voldoet. De threads moeten een gedeelde teller bijhouden waarin het antwoord wordt opgeslagen.
Uiteindelijk is de uitvoer één getal.
###u = 1 - Lijstmodus
De lijstmodus lijkt op de telmodus, maar in plaats van 1 getal is de uitvoer een lijst van alle geldige
bankrekeningnummers in het bereik. Per geldig rekeningnummer wordt 1 regel op de uitvoer
geschreven, bestaande uit twee getallen: het volgnummer, gevolgd door een spatie, gevolgd door
het gevonden rekeningnummer (zie voorbeelden voor meer details). Als een geldig rekeningnummer
wordt gevonden moet het direct weggeschreven worden, je mag niet alles tot het eind opsparen.
###u = 2 - Zoekmodus
In de zoekmodus is het de bedoeling dat je een geldig rekeningnummer (komt uit het gegeven bereik
en voldoet aan de m-proef) u vindt. Wanneer een thread het u gevonden heeft moet het programma
zo snel mogelijk afsluiten. (De andere threads mogen niet veel verder zoeken) Als het
rekeningnummer niet wordt gevonden dan moet het programma -1 printen.