create view BudgetStipendi(Dip, TotaleStipendi) as
select Dipart, sum(Stipendio)
from Impiegato
group by Dipart