select Dipart, sum(Stipendio) as SommaStipendi
from Impiegato
group by Dipart
having sum(Stipendio) > 100