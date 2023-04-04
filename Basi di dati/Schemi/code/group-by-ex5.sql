select Dipart, count(*), D.Citta
from Impiegato I join Dipartimento D
     on (I.Dipart = D.Nome)
group by Dipart, D.Citta