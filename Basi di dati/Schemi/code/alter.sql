alter domain NomeDominio < set default ValoreDefault |
             drop default |
             add constraint DefVincolo |
             drop constraint NomeVincolo >
alter table NomeTabella <
      alter column NomeAttributo < set default NuovoDefault |
                                   drop default > |
      add constraint DefVincolo |
      drop constraint NomeVincolo |
      add column DefAttributo |
      drop column NomeAttributo >