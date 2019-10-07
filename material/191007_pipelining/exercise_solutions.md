# Øvelser til 7. okt. 2019


Færdiggør eventuelle overskydende øvelser i caching fra sidste uge.


# Afviklingsplot

Nedenfor ses afviklingen af en stump x86prime kode på en simpel pipeline:

Den viste kode er den indre løkke i en funktion som multiplicerer
alle elementer i en nul-termineret tabel med et argument.

Ved indgang til løkken indeholder %r10 pointeren til tabellen og
%r12 det tal alle elementer skal multipliceres med.

~~~
Loop:
    movq (%r10),%r11    FDXMYW
    cbe $0,%r11,Done     FDDXMYW
    multq %r12,%r11       FFDXMYW
    movq %r11,(%r10)        FDDDXMYW
    addq $8,%r10             FFFDXMYW
    jmp Loop                    FDXMYW
Done:
~~~

Bogstaverne til højre viser hver instruktions passage gennem pipelinen.
Betydningen af bogstaverne er:

 * F: Fetch, instruktionhentning
 * D: Decode, afkodning, læsning af registre, evt venten på operander
 * X: eXecute, udførelse af ALU op, af adresseberegning eller af første del af multiplikation
 * M: Memory, læsning/skrivning af data fra data-cache, midterste del af multiplikation
 * Y: sidste del af multiplikation
 * W: Writeback, opdatering af registre

Alle instruktioner passerer gennem de samme 6 trin. Multiplikation udføres over 3 pipeline-trin,
E, M og Y. Et ubetinget hop udføres i D-trinnet, dvs den instruktion der hoppes til kan blive
hentet i cyklussen efter. Et betinget hop udføres derimod først i X-trinnet.

Der er fuld forwarding af operander fra en instruktion til en afhængig instruktion.
Instruktioner venter i D-trinnet indtil operander er tilgængelige.

## Spg 1:

Vi indfører en særlig undtagelse for movq instruktioner som skriver til lageret.
De skal stadig vente i D på operander til adresseberegning, men skal først vente
i X på selve den værdi der skal skrives til lageret.

Gentegn afviklingsplottet ovenfor under hensyntagen til denne ændring.

### Løsning
Den sidste movq-instruktion venter nu på %r11 i X-stadiet i stedet for i D. Den
bruger kun en enkelt cyklus i D, da %r10 allerede er klar.
~~~
Loop:
    movq (%r10),%r11    FDXMYW
    cbe $0,%r11,Done     FDDXMYW
    multq %r12,%r11       FFDXMYW
    movq %r11,(%r10)        FDXXXMYW
    addq $8,%r10             FDDDXMYW
    jmp Loop                  FFFDXMYW
Done:
~~~
## Spg 2:

Hvor mange clock-cyklusser (sic) tager hvert gennemløb af løkken. Udvid eventuelt figuren
med instruktioner fra efterfølgende gennemløb, indtil du er sikker på dit svar.

### Løsning
jmp-instruktionen er i stand til, at ændre instruktionspegeren i slutningen af D-stadiet, så
den første instruktion i den næste iteration af loopet kan fetches i den efterfølgende cyklus.

De lodrette streger i plottet inkapsulerer cyklerne i en enkelt iteration.
~~~
Loop:
    movq (%r10),%r11    FDXMYW    |          |
    cbe $0,%r11,Done     FDDXMYW  |          |
    multq %r12,%r11       FFDXMYW |          |
    movq %r11,(%r10)        FDXXXM|YW        |
    addq $8,%r10             FDDDX|MYW       |
    jmp Loop                  FFFD|XMYW      |
                                  |          |
    movq (%r10),%r11           ***|FDXMYW    |  * = F-stadiet er ledigt, men IP'en peger ikke herhen endnu.
    cbe $0,%r11,Done              | FDDXMYW  |
    multq %r12,%r11               |  FFDXMYW |
    movq %r11,(%r10)              |    FDXXXM|YW
    addq $8,%r10                  |     FDDDX|MYW
    jmp Loop                      |      FFFD|XMYW
                                  |          |
    movq (%r10),%r11              |       ***|FDXMYW
    cbe $0,%r11,Done              |          | FDDXMYW
    multq %r12,%r11               |          |  FFDXMYW
    movq %r11,(%r10)              |          |    FDXXXMYW
    addq $8,%r10                  |          |     FDDDXMYW
    jmp Loop                      |          |        FDXMYW
Done:
~~~
Gennemløbstiden er den tid, der går, fra starten af en iteration og indtil næste iteration kan påbegyndes.
De lodrette streger i plottet Loopet gennemløber altså på 10 cykler.

## Spg 3:

Kan du optimere koden ved at flytte rundt på instruktionerne således at der er færre
instruktioner der skal vente på vej gennem pipelinen?

Vis den optimerede kode og tegn det tilsvarende afviklingsplot der viser hvordan den udføres 
i pipelinen. Hvor meget hurtigere er din optimerede kode?

### Løsning
Den sidste movq-instruktion staller, fordi den venter på resultatet fra multq.
addq-instruktionen kan med fordel rykkes op over den sidste movq-instruktion,
da denne er uafhængig af multq-resultatet. Til gengæld skal movq nu trække 8
fra adressen i %r10 for at kompensere for, at addq-instruktionen sker for tidligt.
Da ser afviklingsplottet for loopet sådan her:
~~~
Loop:
    movq (%r10),%r11    FDXMYW  |        | 
    cbe $0,%r11,Done     FDDXMYW|        |
    multq %r12,%r11       FFDXMY|W       |
    addq $8,%r10            FDXM|YW      |
    movq %r11,-8(%r10)       FDX|MYW     |
    jmp Loop                  FD|XMYW    |
                                |        |
    movq (%r10),%r11           *|FDXMYW  |  * = F-stadiet er ledigt, men IP'en peger ikke herhen endnu.
    cbe $0,%r11,Done            | FDDXMYW|
    multq %r12,%r11             |  FFDXMY|W
    addq $8,%r10                |    FDXM|YW
    movq %r11,-8(%r10)          |     FDX|MYW
    jmp Loop                    |      FD|XMYW
                                |        |
    movq (%r10),%r11            |       *|FDXMYW
    cbe $0,%r11,Done            |        | FDDXMYW
    multq %r12,%r11             |        |  FFDXMYW
    addq $8,%r10                |        |    FDXMYW
    movq %r11,-8(%r10)          |        |     FDXMYW
    jmp Loop                    |        |      FDXMYW
Done:
~~~
Gennemløbstiden er igen den tid, der går, fra starten af en iteration indtil den næste iteration kan påbegyndes.
Gennemløbstiden for det optimerede loop er altså 8 cykler.

# Ekstra Cache-opgaver, hvis der er tid

* PP 6.11 p. 660
* PP 6.18 p. 673
