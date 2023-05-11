select Dip
from BudgetStipendi
where TotaleStipendi = (select max(TotaleStipendi)
                        from BudgetStipendi)