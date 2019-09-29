# Øvelsesopgaver for 25/9-2019

Opgaver fra 23/9 såfremt I ikke allerede har løst dem.

Referencer til slides, er til slides fra 23/9 og 25/9


## Opgave 1

Antag at multiplexorne nederst til venstre på figuren over
single cycle x86Prime mikroarkitektur er implementeret efter
samme princip som illustreret på slide 11 fra 25/9.

Hvor mange styre-ledninger skal der trækkes til hver mux?


## Opgave 2

Vor adresse-generator modtager 3 64-bit operander.
To af de tre operander kommer fra registre, det sidste fra dekoderen.

Hvis du betragter ordre-indkodningen (slides fra 23/9 eller
encoding.txt udleveret sammen med A2) kan du se at instruktionerne
udpeger registre ved hjælp af bits benævnt "dddd", "ssss" og "zzzz"

Opstil en tabel som for hver instruktion angiver hvilket
register der skal udlæses fra registrene og gives videre som
hver af de to register-operander til adresse-generatoren


## Opgave 3

Vores regne-enheder modtager en 64-bit værdi fra afkodningen af instruktionen.
Men konstanterne indlejret i instruktionen er kun 32-bit.

Gennemgå de til A2 udleverede ".h" filer og find ud af hvordan du
kan forvandle en 32-bit værdi til en 64-bit værdi.


## Opgave 4

Konstanter indlejret i instruktioner kan være placeret forskellige
steder i forhold til starten af instruktionen.

Skitser et kredsløb som kan "udtage" en indlejret konstant fra det
rette sted (hint: det er noget med en mux)

Er der brug for ET eller TO sådanne kredsløb i mikroarkitekturen?
Begrund svaret.
