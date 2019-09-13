#GDB-kommandoer

## fra kommandolinjen:
    gdb <eksekverbar>         -> kør gdb på den kompilerede kodefil <eksekverbar>.
-----------------------------------------------------------------------------------------------
## i gdb:                      
    quit                      -> gæt 1 gang.
-----------------------------------------------------------------------------------------------
    run <arg 1> ... <arg n>   -> kør den eksekvérbare med kommandolinjeargumenterne
                                 <arg 1> ... <arg n>.
-----------------------------------------------------------------------------------------------
    break <breakpoint>        -> sæt et breakpoint i koden, hvor debuggeren skal stoppe,
                                 når den når til. Et breakpoint kan enten være en funktion,
                                 f.eks "break main", eller en linje i koden: f.eks "break 10".
                                 Kan kaldes før run, eller efter der er stoppet ved et
                                 andet breakpoint.
-----------------------------------------------------------------------------------------------
    next                      -> hop videre fra et break, linje for linje.
-----------------------------------------------------------------------------------------------
    continue                  -> lad programmet fortsætte, hvor det slap, og køre indtil
                                 næste breakpoint (eller til programmet er slut).
-----------------------------------------------------------------------------------------------
    print <var>               -> vis værdien af en variabel <var> i koden på nuværende tidspunkt.
-----------------------------------------------------------------------------------------------
    print <var> = <val>       -> sæt variablen <var> til <val>. <var> vil selvfølgelig kun have
                                 denne værdi indtil <var> næste gang ændres i koden.
