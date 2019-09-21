# Baggrundsstof 23/9 + 25/9

Læs introduktion til digitallogik her:

  * intro: https://da.wikipedia.org/wiki/Digital_elektronik, skip fra "Større digitale kredsløb"

Og følgende sider for underemner her:

  * https://da.wikipedia.org/wiki/Gate_(digital_elektronik), til og med "Digitale gates i praksis"
  * https://da.wikipedia.org/wiki/Inverter_(digital_elektronik)
  * https://da.wikipedia.org/wiki/Additionskredsl%C3%B8b_(digital_elektronik)
  * https://da.wikipedia.org/wiki/Multiplekser_(digital_elektronik)
  * https://da.wikipedia.org/wiki/Demultiplekser_(digital_elektronik)
  * https://da.wikipedia.org/wiki/Flip-flop_(digital_elektronik), skip J/K flipflop og T-flipflop.

BOH omhandler også emnet i afsnit 4.2, men det er vævet sammen med bogens særlige
hardvare beskrivelses-sprog, som vi ikke anvender. Det er nemmere at få lidt intro
fra Wikipedias artikler ovenfor.

Slides fra forelæsningerne bliver gjort tilgængelige ved selve forelæsningen
eller lige efter.

Læs igen: https://github.com/kirkedal/compSys-e2019-pub/blob/master/x86prime.md

Læs oversigten over indkodningen af x86prime instruktioner her: https://github.com/finnschiermer/x86prime/blob/master/encoding.txt

Besøg http://nandgame.com/ og brug tid på at løse opgaver der. Det er fantastisk til
at få en intuition for digitallogik. "Levels" til og med "ALU" er relevante, derefter
bliver det mere specifikt for lige den processor som nandgame fører frem til, og den
er anderledes end x86prime.

# Opgaver til 23/9-2019

## Opgave 1

Få installeret x86prime. Hvis du kører Windows eller Mac skal du formodentlig have
fat i en virtuel maskine med Linux. 

Se også https://github.com/finnschiermer/x86prime

## Opgave 2

Oversæt nedenstående C program til x86prime:
~~~
long fib(long n) {
  if (n < 2) return 1;
  return fib(n-1) + fib(n-2);
}
~~~

Spg 1: Prøv først at lave oversættelsen i hånden. 

Spg 2: Brug dernæst gcc til at lave et x86-assembler program, 
og oversæt så dette program manuelt til x86prime.

Spg 3: Brug x86prime til få oversat fra x86 assembler.
Svarer resultatet til din manuelle oversættelse? Hvis ikke,
hvad er forskellen?


## Opgave 3

Samme spørgsmål som opgave 2, men med nedenstående C program som udgangspunkt
~~~
long fib(long n) {
  if (n < 2) return 1;
  long a = 1;
  long b = 1;
  long k;
  while (n >= 2) {
    k = a + b;
    a = b;
    b = k;
    n++;
  }
  return k;
}
~~~

De følgende opgaver tager udgangspunkt i diagrammet over datavejen for x86prime.
(Det kan du finde i slides fra forelæsningen mandag 23/9)

## Opgave 4

Multiplexoren "IP-Select" vælger mellem 3 forskellige kilder.

Spg 1: Hvilken funktion har "IP-Select" ?

Spg 2: Hvilken sammenhæng er der mellem hvad IP-Select vælger, og instruktion der udføres?
Lav en tabel over de forskellige instruktioner og angiv for hver af dem, hvilken kilde IP-Select skal vælge


## Opgave 5

Multiplexoren "Result-Select" vælger mellem 3 forskellige kilder.

Spg 1: Hvilken funktion har "Result-Select" ?

Spg 2: Hvilken sammenhæng er der mellem hvad Result-Select vælger, og instruktion der udføres?
Lav en tabel over de forskellige instruktioner og angiv for hver af dem, hvilken kilde IP-Select skal vælge


## Opgave 6

Beskriv hvad de forskellige moduler i datavejen gør under udførelse af "movq 400(%r11),%r12"


## Opgave 7

Beskriv hvad de forskellige moduler i datavejen gør under udførelse af "movq %r10,400(%r11)"

