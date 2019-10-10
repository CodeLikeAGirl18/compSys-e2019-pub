# Øvelser til 9. okt. 2019


Færdiggør eventuelle overskydende øvelser fra mandag

# Fra lærebogen

PP 5.5, 5.6 side 568

# Afviklingsplot (II)

Denne opgave er en variant af opgaven fra i mandags. Her er det bare en
mere kompliceret pipeline.

Nedenfor ses afviklingen af en stump x86prime kode på en 2-vejs superskalar pipeline:

Den viste kode er den indre løkke i en funktion som multiplicerer
alle elementer i en nul-termineret tabel med et argument.

Ved indgang til løkken indeholder `%r10` pointeren til tabellen og
`%r12` det tal alle elementer skal multipliceres med.

~~~
Loop:
    movq (%r10),%r11    FDXMYW
    cbe $0,%r11,Done    FDDDXMYW
    multq %r12,%r11      FDDXMYW
    movq %r11,(%r10)     FFFDDDXMYW
    addq $8,%r10          FFDDDXMYW
    jmp Loop                FFFDXMYW
Done:
~~~

Bogstaverne til højre viser hver instruktions passage gennem pipelinen.
Betydningen af bogstaverne er:

 * `F`: Fetch, instruktionhentning
 * `D`: Decode, afkodning, læsning af registre, evt venten på operander
 * `X`: eXecute, udførelse af ALU op, af adresseberegning eller af første del af multiplikation
 * `M`: Memory, læsning/skrivning af data fra data-cache, midterste del af multiplikation
 * `Y`: sidste del af multiplikation
 * `W`: Writeback, opdatering af registre

Alle instruktioner passerer gennem de samme 6 trin. Multiplikation udføres over 3 pipeline-trin,
`X`, `M` og `Y`. Et ubetinget hop udføres i `D`-trinnet, dvs. den instruktion der hoppes til kan blive
hentet i cyklussen efter. Et betinget hop udføres derimod først i `X`-trinnet.

Der er fuld forwarding af operander fra en instruktion til en afhængig instruktion.
Instruktioner venter i `D`-trinnet indtil operander er tilgængelige.

## Spg 1:

Vi indfører en særlig undtagelse for `movq` instruktioner som skriver til lageret.
De skal stadig vente i `D` på operander til adresseberegning, men skal først vente
i `X` på selve den værdi der skal skrives til lageret.

Gentegn afviklingsplottet ovenfor under hensyntagen til denne ændring.

### Svar:
Vi lægger mærke til at der "kun" er én skrivning til lageret i denne afvikling: fjerde instruktion. Altså er det første tre instruktioner uændret.

Jeg starter med at noterer afhængighederne.

~~~
Loop:
    movq (%r10),%r11    FDXMYW           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXMYW         -- depend(X,%r11)
    multq %r12,%r11      FDDXMYW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)     FFFDXXMYW       -- depend(X,%r10), depend(M,%r11)
    addq $8,%r10          FFDXXMYW       -- depend(X,%r10), produce(X,%r10)
    jmp Loop                FDDXMYW
Done:
~~~
Vi kan vente på `r10` i `D`, hvilket dog er klar med det samme. Dog afhænger vi af `%r11` som bliver produceret af `multq` i `Y`-fasen. Det var det samme som før, men vi kan nu vente i `X`. Læg mærke til at vi tidligere havde to stalls i `D` (altså tre `D`'er), mens vi nu kun behøver en enkelt (altså to `X`'er).

Da læsningen nu er nået en fase længere, kan en følgende addition ligledes flyttes frem, uden at vi bryder `inorder` kravet. Altså en clock periode hurtigere.

`jmp` behøver ikke at stalle i `F`, men har stadig én i `D`.

## Spg 2:

Hvor mange clock-cyklusser (sic) tager hvert gennemløb af løkken. Udvid eventuelt figuren
med instruktioner fra efterfølgende gennemløb, indtil du er sikker på dit svar.

### Svar:
Vi noterer her at `jmp` taget i `D`-trinnet. Selvom vi er nødt til at stalle instruktionen i dette trin for at den videre pipeline ikke er fyldt, kan vi stadig tage hoppet med det samme. Altså med en forsinkelse på to perioder.

~~~
Loop:
    movq (%r10),%r11    FDXMYW|           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXM|YW         -- depend(X,%r11)
    multq %r12,%r11      FDDXM|YW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)     FFFDX|XMYW       -- depend(X,%r10), depend(M,%r11)
    addq $8,%r10          FFDX|XMYW       -- depend(X,%r10), produce(X,%r10)
    jmp Loop                FD|DXMYW
Loop:
    movq (%r10),%r11          |FDXMYW|           -- produce(M,%r11), depend(X,%r10)
    cbe $0,%r11,Done          |FDDDXM|YW         -- depend(X,%r11)
    multq %r12,%r11           | FDDXM|YW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)          | FFFDX|XMYW       -- depend(X,%r10), depend(M,%r11)
    addq $8,%r10              |  FFDX|XMYW       -- depend(X,%r10), produce(X,%r10)
    jmp Loop                  |    FD|DXMYW
Done:
~~~

Her er de vigtigt at noterer (og tilføje) at vi nu har en afhængighed af fra læsningen i anden iteration i `X` på `%r10`. Havde vi en længere pipeline (sen `produce(X,%r10)` fra tidligere `addq`) kunne denne have betydning. Vi kan du se at denne klar lidt før.

Vi løber derefter efter anden iteration igennem for at se om det er nødventigt med opdateringer. Det er det ikke. Hvis der havde været opdateringer, var vi nødt til at udfolde en iteration mere.

Vi kan derfor se at hver iretation tager 6 SICs.


#### Sidebemærkning
Lad os lege at additionen (`addq`) havde været en multiplikation (`multq`):

~~~
Loop:
    movq (%r10),%r11    FDXMYW           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXMYW         -- depend(X,%r11)
    multq %r12,%r11      FDDXMYW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)     FFFDXXMYW       -- depend(X,%r10), depend(M,%r11)
    multq $5,%r10         FFDXXMYW       -- depend(X,%r10), produce(Y,%r10)
    jmp Loop                FDDXMYW
Done:
~~~

Vi tjekker efter og ser at der ikke er noget problem med vores tidligere udførsel, men husker at opdatere vores dataafhængighed, så `%r10` først er klar efter `Y`.


Lad os så udrulle første gang:

~~~
Loop:
    movq (%r10),%r11    FDXMYW|           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXM|YW         -- depend(X,%r11)
    multq %r12,%r11      FDDXM|YW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)     FFFDX|XMYW       -- depend(X,%r10), depend(M,%r11)
    multq $5,%r10         FFDX|XMYW       -- depend(X,%r10), produce(Y,%r10)
    jmp Loop                FD|DXMYW
Loop:
    movq (%r10),%r11          |FDDXMYW|           -- produce(M,%r11), depend(X,%r10)
    cbe $0,%r11,Done          |FDDDDXM|YW         -- depend(X,%r11)
    multq %r12,%r11           | FFDDXM|YW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)          | FFFFDX|XMYW       -- depend(X,%r10), depend(M,%r11)
    multq $5,%r10             |   FFDX|XMYW       -- depend(X,%r10), produce(X,%r10)
    jmp Loop                  |     FD|DXMYW
Done:
~~~

Her er vi nødt til at stalle læsningen i `D` i anden iteration, da `%r10` endnu ikke er klar. Denne stall laver krusninger (eng. ripple) hele vejen ned igennem udførslen.

Vi bør derefter lave en eksekvering mere, for at sikre at der ikke kommer flere ændringer. Det gør det ikke og jeg har undladt den her. Men dette er et eksempel på at det kan ske og hvis vores pipeline er meget længere kunne det have betydning.

## Spg 3:

Kan du optimere koden ved at flytte rundt på instruktionerne således at der er færre
instruktioner der skal vente på vej gennem pipelinen?

Vis den optimerede kode og tegn det tilsvarende afviklingsplot der viser hvordan den udføres 
i pipelinen. Hvor meget hurtigere er din optimerede kode?

### Svar:
Vores originale program.
~~~
Loop:
    movq (%r10),%r11    FDXMYW           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXMYW         -- depend(X,%r11)
    multq %r12,%r11      FDDXMYW         -- depend(X,%r11), produce(Y,%r11)
    movq %r11,(%r10)     FFFDXXMYW       -- depend(X,%r10), depend(M,%r11)
    addq $8,%r10          FFDXXMYW       -- depend(X,%r10), produce(X,%r10)
    jmp Loop                FDDXMYW
Done:
~~~

Vi kan starte med at noterer de stalls vi har:

* betinget hop venter på læsningen (første instruktion).
* multiplikation venter på læsningen (første instruktion). Vi venter også på `bce`, men har stadig afhængigheden til 
* skrivningen venter på multiplikationen.

Det bedste er at tegne en afhængighedsgraf som i BOH, så det gør jeg (linienumre før kolon):

~~~ text
    %r11  %r10
      |   /   \
      |  /     \
   1:movq       \
     /  |        |
   S/   |S      /|
2:cbe  3:multq / |
      /   |S  /  |
     /  4:movq  5:addq
    |            |
   %r11         %r10
~~~
Jeg har noteret et `S` ud for de tre afhængigheder, som skabte stalls.

Vi kan se at rækken at instruktioner fra 1 til 4 alle skaber stalls. Så vi kan desværre ikke gøre noget ved dette. Men da `addq` er uafhængig fra de andre, kan vi flytte den frem. Altså for eksempel:

~~~
Loop:
    movq (%r10),%r11    FDXMYW           -- produce(M,%r11)
    cbe $0,%r11,Done    FDDDXMYW         -- depend(X,%r11)
    multq %r12,%r11      FDDXMYW         -- depend(X,%r11), produce(Y,%r11)
    addq $8,%r10          FFDXMYW        -- depend(X,%r10), produce(X,%r10)
    movq %r11,-8(%r10)      FFDXXMYW     -- depend(X,%r10), depend(M,%r11)
    jmp Loop                FDDXXMYW
Done:
~~~

Vi huske at trække de 8 fra adressen når vi udfører vores læsning. Dette vil spare én periode.

Her vælger jeg kun at flytte `addq` frem foran `movq`, men kan også ligge den andre steder. Jeg kan flytte den helt frem foran `cbe`, hvilket dog kan være lidt farlig. Jeg ved her ikke om det videre program bruges vores array index i `%r10`, så det er muligt at dette ændre semantikken. I dette tilfælde kan jeg så sikre at trække 8 fra `%r10` efter jeg kommer ud at løkken. Dette er et lille eksempel på hvorfor optimerende oversættere har det svært.




# Ekstra opgaver, hvis der er tid

HP 5.17, BOH.
