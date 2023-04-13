select *
from Impiegato
where Dipart = any (select Nome
                    from Dipartimento
                    where Citta = 'Firenze')