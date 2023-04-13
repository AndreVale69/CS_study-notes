select Nome
from Impiegato
where Nome = any (select Nome
                  from Impiegato
                  where Dipart = 'Produzione')