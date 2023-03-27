create table Impiegato
(
    Matricola   character(6) primary key,
    Nome        varchar(20) not null,
    Cognome     varchar(20) not null,
    Dipart      varchar(15)
                references Dipartimento(NomeDip),
                on delete set null,
                on update cascade,
    Ufficio     numeric(3),
    Stipendio   numeric(9) default 0,
    primary key(Matricola),
    unique (Cognome, Nome)
)