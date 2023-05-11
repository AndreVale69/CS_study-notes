create view DipartUffici(NomeDip, NroUffici) as
select Dipart, count(distinct Ufficio)
from Impiegato
group by Dipart