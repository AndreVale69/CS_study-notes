create table Impiegato
(
    Matricola   character(6) primary key,
    Nome        varchar(20) not null,
    Cognome     varchar(20) not null,
    Dipart      varchar(15)
                references Dipartimento(NomeDip),
    Ufficio     numeric(3),
    Stipendio   numeric(9) default 0,
    Superiore   character(6),
    check   (Matricola like '1%' or
             Dipart = (select Dipart
                       from Impiegato I
                       where I.Matricola = Superiore))
    unique (Cognome, Nome)
)