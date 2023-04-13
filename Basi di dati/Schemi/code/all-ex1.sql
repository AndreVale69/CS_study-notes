select Nome
from Dipartimento
where Nome <> all (select Dipart
                   from Impiegato
                   where Cognome = 'Rossi')