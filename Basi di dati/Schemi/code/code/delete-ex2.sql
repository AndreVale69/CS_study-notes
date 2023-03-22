delete from Dipartimento
       where Nome not in (select Dipart
                          from Impiegato)