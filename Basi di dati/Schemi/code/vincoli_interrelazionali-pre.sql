create table Impiegato
(
    Matricola   character(6) primary key,
    Nome        varchar(20) not null,
    Cognome     varchar(20) not null,
    Dipart      varchar(15)
                references Dipartimento(NomeDip),
    Ufficio     numeric(3),
    Stipendio   numeric(9) default 0,
    unique (Cognome, Nome)
)