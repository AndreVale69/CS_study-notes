select Nome
from Impiegato
where Dipart <> 'Amministrazione'
    union all
select Cognome
from Impiegato
where Dipart <> 'Amministrazione'