create view ImpiegatiAmminPoveri as
select *
from ImpiegatiAmmin
where Stipendio < 50