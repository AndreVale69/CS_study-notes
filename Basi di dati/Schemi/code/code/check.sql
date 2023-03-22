create table Impiegato
(
    Matricola   character(6)
                check  (Matricola is not null and
                        1 = (select count(*)
                             from Impiegato I
                             where Matricola = I.Matricola)),
    Cognome     character(20) check (Cognome is not null),
    Nome        character(20) check (Nome is not null and
                        2 > (select count(*)
                             from Impiegato I
                             where Nome = I.Nome
                             and Cognome = I.Cognome)),
    Dipart      character(15) check (Dipart in
                            (select NomeDip
                             from Dipartimento))
)