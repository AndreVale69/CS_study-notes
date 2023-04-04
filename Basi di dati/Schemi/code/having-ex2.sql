select Dipart
from Impiegato
where Ufficio = 20
group by Dipart
having sum(Stipendio) > 25